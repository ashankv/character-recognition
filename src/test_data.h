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

private:

    /** A vector of ImageData objects that will be created from test data file. */
    std::vector<ImageData> image_data_vector_;

    /** A vector of image labels that will be created from test labels file. */
    std::vector<int> image_labels_;

    /** A map of a class number to class frequency. */
    std::map<int, int> image_label_frequencies_;

    /** A vector of classified labels that are retrieved using our model. */
    std::vector<int> classified_labels_;

    /** A map that maps each class to a vector of 0-10 frequencies. */
    std::map<int,std::vector<int>> confusion_map_;

public:

    void readTestDataFromFileToVector(std::string& file_name);
    void readTestLabelsFromFileToVector(std::string& file_name);

    std::vector<ImageData>& getTestImageDataVector();
    std::vector<int>& getTestImageLabelVector();
    std::vector<int>& getClassifiedLabels();

    void populateClassifiedLabels();
    void populateConfusionMap();
    void populateImageLabelFrequencies();

    void printConfusionMatrix();
    void printClassifiedLabels();

};


#endif //NAIVEBAYES_TEST_DATA_H
