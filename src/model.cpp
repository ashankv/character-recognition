//
// Created by Ashank Verma on 3/11/18.
//

#include <map>
#include "model.h"
#include "math.h"


/** Calculates and populates the 3 dimensional probability array of the model.
 *
 * @param training_data the data to calculate the probability from.
 */
void Model::CalculateProbabilities(TrainingData& training_data, std::string& model_file_name) {

    CalculateClassFrequencyAndProbabilities(training_data);

    std::ifstream model_file(model_file_name);
    std::vector<ImageData> image_data = training_data.GetTrainingImageDataVector();
    std::vector<int> image_labels = training_data.GetTrainingImageLabelVector();

    // If model file is empty, calculate all probabilities and load to file, else load probabilities from file.
    if (model_file.peek() == std::ifstream::traits_type::eof()) {

        for (int i = 0; i < NUMBER_OF_PIXELS; i++) {

            for (int j = 0; j < image_data.size(); j++) {

                ImageData current_image = image_data.at(j);
                std::vector<bool> features = current_image.GetFeatures();

                // Current pixel (F11, F12...etc)
                bool is_foreground = features.at(i);

                // Corresponding class to jth ImageData
                int current_class = image_labels[j];

                // If it is a foreground pixel, go to the foreground position, else the background position.
                if (is_foreground) {
                    feature_frequencies_[i][current_class][1] += 1.0;
                } else {
                    feature_frequencies_[i][current_class][0] += 1.0;
                }
            }
        }

        // Iterate through each element in the probability array
        for (int i = 0; i < NUMBER_OF_PIXELS; i++) {
            for (int j = 0; j < NUMBER_OF_CLASSES; j++) {
                for (int k = 0; k < FEATURE_OPTIONS; k++) {
                    int current_probability = feature_frequencies_[i][j][k];

                    // Divide each probability frequency by total frequency
                    // Accounts for LaPlace smoothing as well
                    probabilities_[i][j][k] = ((double) current_probability + (double) K_LAPLACE_SMOOTHER) /
                                              ((double) label_frequencies_[j] + (double) (2 * K_LAPLACE_SMOOTHER));
                }
            }
        }

        LoadProbabilitiesToFile(model_file_name);

    } else {
        LoadProbabilitiesFromFile(model_file_name);
    }
}

/** Calculates and populates a map of class to frequency and a map of class to probability for the training data.
 *
 * @param training_data the data to calculate class frequency from.
 * @param label_frequencies the map to populate.
 */
void Model::CalculateClassFrequencyAndProbabilities(TrainingData& training_data) {

    std::vector<int> training_labels = training_data.GetTrainingImageLabelVector();

    // Calculate label frequencies given a training data.
    for (int i = 0; i < training_labels.size(); i++) {
        label_frequencies_[training_labels.at(i)] += 1;
    }

    // Calculate the class probability based on the frequencies and store it in the private attribute.
    for (auto entry : label_frequencies_) {
        double class_probability = (((double) entry.second) / (double) training_labels.size());
        class_probabilities_[entry.first] = class_probability;
    }
}

/** Gets the specific probability at a given dimension.
 *
 * @param i the pixel dimension.
 * @param j the class dimension.
 * @param k the feature type dimension.
 * @return the probability at the i, j, kth position.
 */
double Model::GetSpecificProbability(int i, int j, int k) {
    return probabilities_[i][j][k];
}

/** Calculates all the posterior probabilities given a test data object.
 *
 * @param test_data the test data to calculate all the posterior probabilities of.
 */
void Model::CalculateProbabilitiesOfTestData(TestData& test_data) {

    // Iterate through each Image Data object.
    for (auto& image : test_data.GetTestImageDataVector()) {

        std::vector<bool> features = image.GetFeatures();
        std::map<int, double> posterior_probabilities;

        // Iterate through each class.
        for (int i = 0; i < NUMBER_OF_CLASSES; i++) {

            double probability = log10(class_probabilities_[i]);

            for (int j = 0; j < NUMBER_OF_PIXELS; j++) {

                // Get specific feature and check to see if it's foreground and do according calculations
                bool is_foreground = features.at(j);

                if (is_foreground) {
                    probability += log10(GetSpecificProbability(j, i, 1));
                } else {
                    probability += log10(GetSpecificProbability(j, i, 0));
                }
            }

            posterior_probabilities[i] = probability;
        }

        // Add to each ImageData object a map of class to probability
        image.AddMapOfPosteriorProbabilities(posterior_probabilities);
        posterior_probabilities.clear();

    }
}

/** Load probabilities to file given the probability array.
 *
 * @param file_name the file to load to.
 */
void Model::LoadProbabilitiesToFile(std::string& file_name) {

    std::ofstream model_file(file_name);

    if(!model_file) {
        return;
    }

    // Print probabilities to file
    for (int i = 0; i < NUMBER_OF_PIXELS; i++) {
        for (int j = 0; j < NUMBER_OF_CLASSES; j++) {
            model_file << probabilities_[i][j][1];
            model_file << std::endl;
            model_file << probabilities_[i][j][0];
            model_file << std::endl;
        }
    }

    model_file.close();
}

/** Load probabilities from file given a file name.
 *
 * @param file_name the file to load from.
 */
void Model::LoadProbabilitiesFromFile(std::string& file_name) {

    std::ifstream model_file(file_name);

    if(!model_file) {
        return;
    }

    // Load each line of probability to the probability array.
    for (int i = 0; i < NUMBER_OF_PIXELS; i++) {
        for (int j = 0; j < NUMBER_OF_CLASSES; j++) {

            if (!model_file.eof()) {
                model_file >> probabilities_[i][j][1];
                model_file >> probabilities_[i][j][0];
            }
        }
    }

    model_file.close();
}





