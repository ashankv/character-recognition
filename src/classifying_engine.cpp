#include <iostream>
#include "image_data.h"
#include "training_data.h"
#include "model.h"


int main() {

    std::string file_name = "../data/trainingimages";
    std::string file_name_2 = "../data/traininglabels";
    std::string file_name3 = "../data/testimages";
    std::string file_name4 = "../data/testlabels";

    TrainingData training_data;
    Model model;
    TestData test_data;

    training_data.readTrainingDataFromFileToVector(file_name);
    training_data.readTrainingLabelsFromFileToVector(file_name_2);

    model.calculateProbabilities(training_data);

    test_data.readTestDataFromFileToVector(file_name3);
    test_data.readTestLabelsFromFileToVector(file_name4);

    model.calculateProbabilitiesOfTestData(test_data);
    test_data.populateClassifiedLabels();

    test_data.printClassifiedLabels();
    test_data.printConfusionMatrix();

    return 0;
}