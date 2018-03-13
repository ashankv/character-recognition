//
// Created by Ashank Verma on 3/11/18.
//

#include <fstream>
#include "image_data.h"
#include <math.h>

/** Adds a boolean pixel to the boolean vector.
 *
 * @param pixel the pixel to add.
 */
void ImageData::addToPixelVector(bool pixel) {
    pixels_.push_back(pixel);
}

/** Retrieves the boolean pixel vector.
 *
 * @return the boolean pixel vector.
 */
std::vector<bool>& ImageData::getPixels() {
    return pixels_;
}

void ImageData::addMapOfPosteriorProbabilities(std::map<int, double> posterior_probabilities) {
    posterior_probabilities_ = posterior_probabilities;
}

int ImageData::getClassWithHighestProbabilityFromPosteriors() {

    int best_class = 0;
    double best_probability = -10000000;

    for (const auto& pair : posterior_probabilities_) {
        if (pair.second > best_probability) {
            best_probability = pair.second;
            best_class = pair.first;
        }
    }
    return best_class;
}



