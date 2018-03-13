//
// Created by Ashank Verma on 3/11/18.
//

#ifndef NAIVEBAYES_MODEL_H
#define NAIVEBAYES_MODEL_H


#include <vector>
#include <map>
#include "training_data.h"
#include "test_data.h"

const int FEATURE_OPTIONS = 2;
const int K_LAPLACE_SMOOTHER = 1;

class Model {

    int probability_frequencies_[NUMBER_OF_PIXELS][NUMBER_OF_CLASSES][FEATURE_OPTIONS];
    double probabilities_[NUMBER_OF_PIXELS][NUMBER_OF_CLASSES][FEATURE_OPTIONS];

    std::map<int, int> label_frequencies;
    std::map<int, double> class_probabilities;


public:
    void calculateProbabilities(TrainingData& training_data, std::string& model_file_name);
    void calculateClassFrequencyAndProbabilities(TrainingData& training_data);
    void calculateProbabilitiesOfTestData(TestData& test_data);

    double getSpecificProbability(int i, int j, int k);

    void loadProbabilitiesToFile(std::string& file_name);
    void loadProbabilitiesFromFile(std::string& file_name);

};


#endif //NAIVEBAYES_MODEL_H
