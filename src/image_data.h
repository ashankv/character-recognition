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

private:

    /** A vector of booleans that represent foreground or background of the Image Data object. */
    std::vector<bool> features_;

    /** A map of class to each posterior probability of an Image Data object. */
    std::map<int, double> posterior_probabilities_;

public:

    explicit ImageData() = default;

    void AddToFeatureVector(bool feature);
    std::vector<bool>& GetFeatures();
    void AddMapOfPosteriorProbabilities(std::map<int, double> posterior_probabilities);
    int GetClassWithHighestProbabilityFromPosteriors();


};


#endif //NAIVEBAYES_IMAGE_DATA_H
