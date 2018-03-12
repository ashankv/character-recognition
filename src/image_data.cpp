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

/*void ImageData::calculatePosteriorProbabilitiesUsingModel(Model* model) {

    for (int i = 0; i < 10; i++) {
        double probability = 0.0;

        for (int j = 0; j < 784; j++) {
            bool is_foreground = pixels_[j];
            if (is_foreground) {
                probability += log10(model.getSpecificProbability(j, i, 1));
            } else {
                probability += log10(model.getSpecificProbability(j, i, 0));
            }
        }
    }


    //return std::map<int, double>();
} */


