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

private:

    /** An array of frequencies of each pixel given number of class and type of feature. */
    int feature_frequencies_[NUMBER_OF_PIXELS][NUMBER_OF_CLASSES][FEATURE_OPTIONS];

    /** An array of probabilities of each pixel given number of class and type of feature. */
    double probabilities_[NUMBER_OF_PIXELS][NUMBER_OF_CLASSES][FEATURE_OPTIONS];

    /** A map of class to frequency of class that appears. */
    std::map<int, int> label_frequencies_;

    /** A map of class to class probabilities based on the frequency of class that appears. */
    std::map<int, double> class_probabilities_;

public:
    void CalculateProbabilities(TrainingData &training_data, std::string &model_file_name);
    void CalculateClassFrequencyAndProbabilities(TrainingData &training_data);
    void CalculateProbabilitiesOfTestData(TestData &test_data);

    double GetSpecificProbability(int i, int j, int k);

    void LoadProbabilitiesToFile(std::string &file_name);
    void LoadProbabilitiesFromFile(std::string &file_name);

};


#endif //NAIVEBAYES_MODEL_H
