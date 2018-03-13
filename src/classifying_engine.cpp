#include <iostream>
#include "image_data.h"
#include "training_data.h"
#include "model.h"


int main() {

    // All file names.
    std::string training_images_file_name = "../data/trainingimages";
    std::string training_labels_file_name = "../data/traininglabels";
    std::string test_images_file_name = "../data/testimages";
    std::string test_labels_file_name = "../data/testlabels";
    std::string model_file_name = "../data/model";

    TrainingData training_data;
    Model model;
    TestData test_data;

    // Populate TrainingData object.
    training_data.ReadTrainingDataFromFileToVector(training_images_file_name);
    training_data.ReadTrainingLabelsFromFileToVector(training_labels_file_name);

    // Create model using TrainingData object.
    model.CalculateProbabilities(training_data, model_file_name);

    // Populate TestData object.
    test_data.ReadTestDataFromFileToVector(test_images_file_name);
    test_data.ReadTestLabelsFromFileToVector(test_labels_file_name);

    // Calculate probabilities of TestData object.
    model.CalculateProbabilitiesOfTestData(test_data);

    // Classify each ImageData with class with highest posterior probability.
    test_data.PopulateClassifiedLabels();

    // Print classified labels and confusion matrix.
    test_data.PrintClassifiedLabels();
    test_data.PrintConfusionMatrix();

    return 0;
}