//
// Created by Ashank Verma on 3/13/18.
//

#include "model_test.h"
#include "../catch.hpp"



TEST_CASE("Populate Training Data With Correct File Path Test") {

    TrainingData training_data;
    std::string file_1 = "../data/trainingimages";
    std::string file_2 = "../data/traininglabels";

    training_data.ReadTrainingDataFromFileToVector(file_1);
    training_data.ReadTrainingLabelsFromFileToVector(file_2);

    REQUIRE(5000 == training_data.GetTrainingImageLabelVector().size());
    REQUIRE(5000 == training_data.GetTrainingImageDataVector().size());
}

TEST_CASE("Populate Training Data With Incorrect File Path Test") {

    TrainingData training_data;
    std::string file_1 = "not a filename";
    std::string file_2 = "../data/nonexistentfile";

    training_data.ReadTrainingDataFromFileToVector(file_1);
    training_data.ReadTrainingLabelsFromFileToVector(file_2);

    REQUIRE(0 == training_data.GetTrainingImageLabelVector().size());
    REQUIRE(0 == training_data.GetTrainingImageDataVector().size());
}

TEST_CASE("Populate Test Data With Correct File Path Test") {

    TestData test_data;
    std::string file_1 = "../data/testimages";
    std::string file_2 = "../data/testlabels";

    test_data.ReadTestDataFromFileToVector(file_1);
    test_data.ReadTestLabelsFromFileToVector(file_2);

    REQUIRE(1000 == test_data.GetTestImageLabelVector().size());
    REQUIRE(1000 == test_data.GetTestImageDataVector().size());
}

TEST_CASE("Populate Test Data With Inorrect File Path Test") {

    TestData test_data;
    std::string file_1 = "not a filename";
    std::string file_2 = "../data/nonexistentfile";

    test_data.ReadTestDataFromFileToVector(file_1);
    test_data.ReadTestLabelsFromFileToVector(file_2);

    REQUIRE(0 == test_data.GetTestImageLabelVector().size());
    REQUIRE(0 == test_data.GetTestImageDataVector().size());
}

TEST_CASE("Load Probabilities To File With Correct Path Test") {

    TrainingData training_data;
    std::string file_1 = "../data/trainingimages";
    std::string file_2 = "../data/traininglabels";

    training_data.ReadTrainingDataFromFileToVector(file_1);
    training_data.ReadTrainingLabelsFromFileToVector(file_2);

    Model model;
    std::string test_file = "../catch_test_data/loading_test_file";
    model.CalculateProbabilities(training_data, test_file);

    std::ifstream file(test_file);
    double first_probability;

    file >> first_probability;

    REQUIRE(0.002079 == first_probability);
}

TEST_CASE("Add Posterior Probability Map To Image Data Correctly Test") {

    ImageData image_data;
    std::map<int, double> posterior_map = {{1, 1.2}, {2, 0.45}, {6, 23.8}};

    image_data.AddMapOfPosteriorProbabilities(posterior_map);

    REQUIRE(0.45 == image_data.GetPosteriorProbabilityMap()[2]);

}

TEST_CASE("Get Class With Highest Probability From Image Data Correctly Test") {

    ImageData image_data;
    std::map<int, double> posterior_map = {{1, 0.43}, {2, 0.45}, {6, 0.87}};

    image_data.AddMapOfPosteriorProbabilities(posterior_map);

    REQUIRE(6 == image_data.GetClassWithHighestProbabilityFromPosteriors());
}

TEST_CASE("Get Specific Probability From 3D Probability Matrix") {

    TrainingData training_data;
    Model model;

    std::string file_1 = "../data/trainingimages";
    std::string file_2 = "../data/traininglabels";
    std::string test_file = "../catch_test_data/loading_test_file";

    training_data.ReadTrainingDataFromFileToVector(file_1);
    training_data.ReadTrainingLabelsFromFileToVector(file_2);

    model.CalculateProbabilities(training_data, test_file);
    double specific_probability = model.GetSpecificProbability(0, 0, 1);

    specific_probability = round(specific_probability * 1000.0) / 1000.0;

    REQUIRE(0.002 == specific_probability);
}