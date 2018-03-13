//
// Created by Ashank Verma on 3/11/18.
//

#include <iostream>
#include <fstream>
#include "training_data.h"

/** Reads image data from file and saves in vector.
 *
 * @param file_name the file name to be read from.
 */
void TrainingData::ReadTrainingDataFromFileToVector(std::string &file_name) {

    std::ifstream file;

    file.open(file_name, std::ifstream::in);

    if(!file) {
        return;
    }

    char current_char;
    int counter = 0;
    ImageData *image_data = new ImageData();

    while (file.get(current_char)) {

        if (current_char != '\n') {
            if (current_char == '#' || current_char == '+') {
                image_data->AddToFeatureVector(true);
            } else {
                image_data->AddToFeatureVector(false);
            }

            counter++;

            if (counter >= NUMBER_OF_PIXELS) {
                image_data_vector_.push_back(*image_data);
                image_data = new ImageData();
                counter = 0;
            }
        }
    }

    file.close();
}

/** Reads image label data from file.
 *
 * @param file_name the file name to be read from.
 */
void TrainingData::ReadTrainingLabelsFromFileToVector(std::string &file_name) {

    std::ifstream file(file_name);

    if(!file) {
        return;
    }

    int current_int;

    while (!file.eof()) {
        if (file.peek() != ' '){
            file >> current_int;
            image_labels_.push_back(current_int);
        }
    }
}

/** Retrieves the image data vector.
 *
 * @return the image data vector to retrieve.
 */
std::vector<ImageData>& TrainingData::GetTrainingImageDataVector() {
    return image_data_vector_;
}

/** Retrieves the image label vector.
 *
 * @return the image label vector to retrieve.
 */
std::vector<int>& TrainingData::GetTrainingImageLabelVector() {
    return image_labels_;
}




