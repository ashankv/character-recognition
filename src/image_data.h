//
// Created by Ashank Verma on 3/11/18.
//

#ifndef NAIVEBAYES_IMAGE_DATA_H
#define NAIVEBAYES_IMAGE_DATA_H

#include <iostream>
#include <vector>
#include <map>

// Forward declaration of Model class
class Model;

const int IMAGE_DIMENSION = 784;

class ImageData {

    std::vector<bool> pixels_;
    std::map<int, double> posterior_probabilities_;

public:

    ImageData() = default;

    void addToPixelVector(bool pixel);
    std::vector<bool>& getPixels();
    void calculatePosteriorProbabilitiesUsingModel(Model* model);


    //TODO: for each image data object within test data object, put map of class to probability in image data. this method should be in the model (takes test data reference)
};


#endif //NAIVEBAYES_IMAGE_DATA_H
