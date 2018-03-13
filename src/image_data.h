//
// Created by Ashank Verma on 3/11/18.
//

#ifndef NAIVEBAYES_IMAGE_DATA_H
#define NAIVEBAYES_IMAGE_DATA_H

#include <iostream>
#include <vector>
#include <map>

const int SMALL_CONSTANT = -10000000;
const int IMAGE_DIMENSION = 784;

class ImageData {

    std::vector<bool> pixels_;
    std::map<int, double> posterior_probabilities_;

public:

    ImageData() = default;

    void addToPixelVector(bool pixel);
    std::vector<bool>& getPixels();
    void addMapOfPosteriorProbabilities(std::map<int, double> posterior_probabilities);
    int getClassWithHighestProbabilityFromPosteriors();


};


#endif //NAIVEBAYES_IMAGE_DATA_H
