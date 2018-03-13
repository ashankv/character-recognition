//
// Created by Ashank Verma on 3/12/18.
//

#ifndef NAIVEBAYES_TEST_DATA_H
#define NAIVEBAYES_TEST_DATA_H


#include "image_data.h"

const int NUMBER_OF_CLASSES = 10;
const double ROUND_SCALER = 10000.0;
const int PERCENT_SCALER = 100;
const int COL_SIZE = 10;

class TestData {

    std::vector<ImageData> image_data_vector_;
    std::vector<int> image_labels_;
    std::map<int, int> image_label_frequencies_;
    std::vector<int> classified_labels_;
    std::map<int,std::vector<int>> confusion_map_;

public:
    void readTestDataFromFileToVector(std::string& file_name);
    void readTestLabelsFromFileToVector(std::string& file_name);

    std::vector<ImageData>& getTestImageDataVector();
    std::vector<int>& getTestImageLabelVector();
    std::vector<int>& getClassifiedLabels();

    void populateClassifiedLabels();
    void printConfusionMatrix();
    void populateConfusionMap();
    void populateImageLabelFrequencies();

};


#endif //NAIVEBAYES_TEST_DATA_H
