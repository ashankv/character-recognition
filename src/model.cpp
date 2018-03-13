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
void Model::calculateProbabilities(TrainingData& training_data) {


    calculateClassFrequencyAndProbabilities(training_data);

    std::vector<ImageData> image_data = training_data.getTrainingImageDataVector();
    std::vector<int> image_labels = training_data.getTrainingImageLabelVector();

    for (int i = 0; i < NUMBER_OF_PIXELS; i++) {

        for (int j = 0; j < image_data.size(); j++) {

            ImageData current_image = image_data.at(j);
            std::vector<bool> features = current_image.getPixels();

            // Current pixel (F11, F12...etc)
            bool is_foreground = features.at(i);

            // Corresponding class to jth ImageData
            int current_class = image_labels[j];

            if (is_foreground) {


                probability_frequencies_[i][current_class][1] += 1.0;

                /*if (probability_frequencies_[i][current_class][1] >= 5000) {

                } */


            } else {

                probability_frequencies_[i][current_class][0] += 1.0;

                /*if (probabilities_[i][current_class][0] >= 5000) {
                    std::cout << i << "|" << current_class << std::endl;
                }*/

            }
        }

        //for (int num = 0; num < 10; num++) {
        //    std::cout << probabilities_[i][num][0] << "|" << probabilities_[i][num][1] << std::endl;
        //}

    }

    for (int i = 0; i < NUMBER_OF_PIXELS; i++) {
        for (int j = 0; j < NUMBER_OF_CLASSES; j++) {
            for (int k = 0; k < FEATURE_OPTIONS; k++) {
                int current_probability = probability_frequencies_[i][j][k];

                //std::cout << probabilities_[i][j][k] << std::endl;

                probabilities_[i][j][k] = ((double) current_probability + (double) K_LAPLACE_SMOOTHER) /
                        ((double) label_frequencies[j] + (double) (2 * K_LAPLACE_SMOOTHER));

                //std::cout << probabilities_[i][j][k] << std::endl;

            }
        }
    }
}

/** Calculates and populates a map of class to frequency and a map of class to probability for the training data.
 *
 * @param training_data the data to calculate class frequency from.
 * @param label_frequencies the map to populate.
 */
void Model::calculateClassFrequencyAndProbabilities(TrainingData& training_data) {

    std::vector<int> training_labels = training_data.getTrainingImageLabelVector();

    for (int i = 0; i < training_labels.size(); i++) {
        label_frequencies[training_labels.at(i)] += 1;
    }

    for (auto entry : label_frequencies) {

        double class_probability = (((double) entry.second) / (double) training_labels.size());

        class_probabilities[entry.first] = class_probability;
        //std::cout<< entry.first << "|" << class_probability << "|" << log10(class_probability) << std::endl;
    }



}

/** Gets the specific probability at a given dimension.
 *
 * @param i the pixel dimension.
 * @param j the class dimension.
 * @param k the feature type dimension.
 * @return the probability at the i, j, kth position.
 */
double Model::getSpecificProbability(int i, int j, int k) {
    return probabilities_[i][j][k];
}

void Model::calculateProbabilitiesOfTestData(TestData& test_data) {

    for (auto& image : test_data.getTestImageDataVector()) {

        std::vector<bool> features = image.getPixels();
        std::map<int, double> posterior_probabilities;

        for (int i = 0; i < 10; i++) {

            double probability = log10(class_probabilities[i]);
            //std::cout << probability << std::endl;

            for (int j = 0; j < 784; j++) {
                bool is_foreground = features.at(j);
                if (is_foreground) {
                    //std::cout << log10(getSpecificProbability(j, i, 1)) << std:: endl;
                    //std::cout << getSpecificProbability(j, i, 1) << std:: endl;
                    probability += log10(getSpecificProbability(j, i, 1));
                } else {
                    probability += log10(getSpecificProbability(j, i, 0));
                    //std::cout << log10(getSpecificProbability(j, i, 0)) << std:: endl;
                }
            }

            //std::cout << probability << std::endl;
            posterior_probabilities[i] = probability;
        }

        image.addMapOfPosteriorProbabilities(posterior_probabilities);
        posterior_probabilities.clear();

    }


}





