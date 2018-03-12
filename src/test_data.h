//
// Created by Ashank Verma on 3/12/18.
//

#ifndef NAIVEBAYES_TEST_DATA_H
#define NAIVEBAYES_TEST_DATA_H


#include "image_data.h"

class TestData {

    std::vector<ImageData> image_data_vector_;
    std::vector<int> image_labels_;

public:
    void readTestDataFromFileToVector(std::string& file_name);
    void readTestLabelsFromFileToVector(std::string& file_name);
    std::vector<ImageData>& getTestImageDataVector();
    std::vector<int>& getTestImageLabelVector();


};


#endif //NAIVEBAYES_TEST_DATA_H
