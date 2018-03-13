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