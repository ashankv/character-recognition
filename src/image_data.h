//
// Created by Ashank Verma on 3/11/18.
//

#ifndef NAIVEBAYES_IMAGE_DATA_H
#define NAIVEBAYES_IMAGE_DATA_H


#include <vector>

const int IMAGE_DIMENSION = 784;

class ImageData {

    std::vector<bool> pixels_;

public:

    ImageData() = default;

    void addToPixelVector(bool pixel);
    std::vector<bool>& getPixels();



};


#endif //NAIVEBAYES_IMAGE_DATA_H
