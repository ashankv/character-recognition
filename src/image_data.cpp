//
// Created by Ashank Verma on 3/11/18.
//

#include <fstream>
#include "image_data.h"
#include <math.h>

/** Adds a boolean pixel to the boolean vector.
 *
 * @param feature the pixel to add.
 */
void ImageData::AddToFeatureVector(bool feature) {
    features_.push_back(feature);
}

/** Retrieves the boolean pixel vector.
 *
 * @return the boolean pixel vector.
 */
std::vector<bool>& ImageData::GetFeatures() {
    return features_;
}

/** Add a copy map of posterior probabilities to the image data (class to posterior probability).
 *
 * @param posterior_probabilities the map of posterior probabilities to add.
 */
void ImageData::AddMapOfPosteriorProbabilities(std::map<int, double> posterior_probabilities) {
    posterior_probabilities_ = posterior_probabilities;
}

/** Retrieve the class with the highest probability (classification).
 *
 * @return the class with the highest probability.
 */
int ImageData::GetClassWithHighestProbabilityFromPosteriors() {

    int best_class = 0;
    double best_probability = SMALL_CONSTANT;

    for (const auto& pair : posterior_probabilities_) {
        if (pair.second > best_probability) {
            best_probability = pair.second;
            best_class = pair.first;
        }
    }
    return best_class;
}

/** Retrieves the posterior probabilities map.
 *
 * @return the posterior probability map.
 */
std::map<int, double>& ImageData::GetPosteriorProbabilityMap() {
    return posterior_probabilities_;
}



