//
// Created by Ashank Verma on 3/11/18.
//

#ifndef NAIVEBAYES_MODEL_H
#define NAIVEBAYES_MODEL_H


#include <vector>
#include <map>
#include "training_data.h"

const int NUMBER_OF_CLASSES = 10;
const int FEATURE_OPTIONS = 2;
const int K_LAPLACE_SMOOTHER = 5;

class Model {

    double probabilities_[NUMBER_OF_PIXELS][NUMBER_OF_CLASSES][FEATURE_OPTIONS];

public:
    void calculateProbabilities(TrainingData& training_data);
    void calculateClassFrequency(TrainingData& training_data, std::map<int, int>& label_frequencies);
    double getSpecificProbability(int i, int j, int k);

};


#endif //NAIVEBAYES_MODEL_H
