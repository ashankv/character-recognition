//
// Created by Ashank Verma on 3/11/18.
//

#ifndef NAIVEBAYES_TRAINING_DATA_H
#define NAIVEBAYES_TRAINING_DATA_H

#include <iostream>
#include <fstream>
#include <vector>
#include "image_data.h"

const int NUMBER_OF_PIXELS = 784;

/** A class to hold information for training data.
 *
 */
class TrainingData {

private:
    /** A vector of Image Data objects that will be created from training data file. */
    std::vector<ImageData> image_data_vector_;

    /** A vector of image labels that will be created from training label file.*/
    std::vector<int> image_labels_;

public:
    void readTrainingDataFromFileToVector(std::string& file_name);
    void readTrainingLabelsFromFileToVector(std::string& file_name);

    std::vector<ImageData>& getTrainingImageDataVector();
    std::vector<int>& getTrainingImageLabelVector();

};


#endif //NAIVEBAYES_TRAINING_DATA_H
