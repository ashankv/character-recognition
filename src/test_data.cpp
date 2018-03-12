//
// Created by Ashank Verma on 3/12/18.
//
#include <fstream>
#include "test_data.h"
#include "training_data.h"

/** Reads test data from file and converts to a vector.
 *
 * @param file_name the file name to read from.
 */
void TestData::readTestDataFromFileToVector(std::string& file_name) {
    std::ifstream file;

    file.open(file_name, std::ifstream::in);

    if(!file) {
        return;
    }

    char current_char;
    int counter = 0;
    ImageData* image_data = new ImageData();

    while (file.get(current_char)) {

        //std::cout << current_char;

        if (current_char != '\n') {
            if (current_char == '#' || current_char == '+') {
                image_data->addToPixelVector(true);
                //std::cout << true << "|";
            } else {
                image_data->addToPixelVector(false);
                //std::cout << false << "|";
            }

            counter++;

            //std::cout << "Counter: " << counter << std::endl;

            if (counter >= NUMBER_OF_PIXELS) {
                image_data_vector_.push_back(*image_data);
                image_data = new ImageData();
                counter = 0;
            }
        }
    }

    file.close();
}

/** Reads the test labels from the file and converts to a vector.
 *
 * @param file_name the file name to read from.
 */
void TestData::readTestLabelsFromFileToVector(std::string& file_name) {

    std::ifstream file(file_name);

    if(!file) {
        return;
    }

    int current_int;
    while (!file.eof()) {

        if (file.peek() != ' '){
            file >> current_int;
            //std::cout << current_int << std::endl;
            image_labels_.push_back(current_int);
        }
    }
}

/** Retrieves the Image Data vector of test data.
 *
 * @return the Image Data vector of test data.
 */
std::vector<ImageData>& TestData::getTestImageDataVector() {
    return image_data_vector_;
}

/** Retrieves the test image labels from the data.
 *
 * @return the test image labels from the data.
 */
std::vector<int>& TestData::getTestImageLabelVector() {
    return image_labels_;
}
