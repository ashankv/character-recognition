//
// Created by Ashank Verma on 3/11/18.
//

#include <map>
#include "model.h"


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
            bool current_feature = features.at(i);

            // Corresponding class to jth ImageData
            int current_class = image_labels.at(j);

            if (current_feature) {
                probabilities_[i][current_class][1] += 1;
            } else {
                probabilities_[i][current_class][0] += 1;
            }
        }
    }

    for (int i = 0; i < NUMBER_OF_PIXELS; i++) {
        for (int j = 0; j < NUMBER_OF_CLASSES; j++) {
            for (int k = 0; k < FEATURE_OPTIONS; k++) {
                double current_probability = probabilities_[i][j][k];

                probabilities_[i][j][k] = (current_probability + K_LAPLACE_SMOOTHER) /
                        ((double) label_frequencies[j] + (2 * K_LAPLACE_SMOOTHER));

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
        class_probabilities[entry.first] = (((double) entry.second) / (double) training_labels.size());
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





