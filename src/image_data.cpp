//
// Created by Ashank Verma on 3/11/18.
//

#include <fstream>
#include "image_data.h"

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


