#include <iostream>
#include "image_data.h"
#include "training_data.h"
#include "model.h"


int main() {

    TrainingData training_data;
    std::string file_name = "../data/trainingimages";
    std::string file_name_2 = "../data/traininglabels";

    training_data.readTrainingDataFromFileToVector(file_name);
    training_data.readTrainingLabelsFromFileToVector(file_name_2);

    std::vector<ImageData> image_data_vector = training_data.getTrainingImageDataVector();
    std::vector<int> image_data_labels = training_data.getTrainingImageLabelVector();

    Model model;
    model.calculateProbabilities(training_data);

    TestData test_data;
    std::string file_name3 = "../data/testimages";
    std::string file_name4 = "../data/testlabels";

    test_data.readTestDataFromFileToVector(file_name3);
    test_data.readTestLabelsFromFileToVector(file_name4);
    std::vector<int> test_labels = test_data.getTestImageLabelVector();

    model.calculateProbabilitiesOfTestData(test_data);
    test_data.populateClassifiedLabels();

    std::vector<int> classified_labels = test_data.getClassifiedLabels();

    for (int i = 0; i < classified_labels.size(); i++) {
        std::cout << classified_labels[i] << "|" << test_labels[i] << std::endl;
    }

    std::cout << std::endl;

    test_data.printConfusionMatrix();



    return 0;
}