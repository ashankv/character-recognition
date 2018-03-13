#include <iostream>
#include "image_data.h"
#include "training_data.h"
#include "model.h"


int main() {

    std::string training_images_file_name = "../data/trainingimages";
    std::string training_labels_file_name = "../data/traininglabels";
    std::string test_images_file_name = "../data/testimages";
    std::string test_labels_file_name = "../data/testlabels";
    std::string model_file_name = "../data/model";

    TrainingData training_data;
    Model model;
    TestData test_data;

    training_data.readTrainingDataFromFileToVector(training_images_file_name);
    training_data.readTrainingLabelsFromFileToVector(training_labels_file_name);

    model.calculateProbabilities(training_data, model_file_name);

    test_data.readTestDataFromFileToVector(test_images_file_name);
    test_data.readTestLabelsFromFileToVector(test_labels_file_name);

    model.calculateProbabilitiesOfTestData(test_data);
    test_data.populateClassifiedLabels();

    test_data.printClassifiedLabels();
    test_data.printConfusionMatrix();

    return 0;
}