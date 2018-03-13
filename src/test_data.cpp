//
// Created by Ashank Verma on 3/12/18.
//
#include <fstream>
#include <array>
#include <iomanip>
#include <cmath>
#include <sstream>
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
    ImageData *image_data = new ImageData();

    while (file.get(current_char)) {

        if (current_char != '\n') {
            if (current_char == '#' || current_char == '+') {
                image_data->addToPixelVector(true);
            } else {
                image_data->addToPixelVector(false);
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

/** Populates the vector of classified labels of each ImageData object.
 *
 */
void TestData::populateClassifiedLabels() {
    for (auto& image : image_data_vector_) {
        classified_labels_.push_back(image.getClassWithHighestProbabilityFromPosteriors());
    }
}

/** Populate confusion map, or frequency of each class given a class.
 *
 */
void TestData::populateConfusionMap() {

    for (int i = 0; i < NUMBER_OF_CLASSES; i++) {

        std::vector<int> class_confusion_frequency(NUMBER_OF_CLASSES, 0);

        for (int j = 0; j < classified_labels_.size(); j++) {

            int actual_label = classified_labels_[j];
            int expected_label = image_labels_[j];

            if (expected_label == i) {
                class_confusion_frequency[actual_label] += 1;
            }
        }
        confusion_map_[i] = class_confusion_frequency;
    }
}

/** Prints the 10x10 confusion matrix given the classified labels and the actual labels.
 *
 */
void TestData::printConfusionMatrix() {

    populateImageLabelFrequencies();
    populateConfusionMap();

    std::cout << "CONFUSION MATRIX: Actual vs. Expected Percentages" << std::endl;

    for (int i = 0; i < NUMBER_OF_CLASSES; i++) {
        std::vector<int> confusion_vector = confusion_map_[i];

        for(int j = 0; j < confusion_vector.size(); j++) {

            double confusion_element = (double) confusion_vector[j] / (double) image_label_frequencies_[i];
            confusion_element = (round(confusion_element * ROUND_SCALER) / ROUND_SCALER) * PERCENT_SCALER;

            std::ostringstream string_stream;
            string_stream << confusion_element << "%";
            std::string percentage = string_stream.str();

            std::cout << std::setw(COL_SIZE) << std::left << percentage;
        }

        std::cout << std::endl;
    }

}

/** Prints each classified label next to their corresponding test label.
 *
 */
void TestData::printClassifiedLabels() {

    std::cout << "Classified Labels vs. Actual Labels" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < classified_labels_.size(); i++) {
        std::cout << classified_labels_[i] << "   |   " << image_labels_[i] << std::endl;
    }

    std::cout << std::endl;

}

/** Populates the frequency of each image label that appears in the test data.
 *
 */
void TestData::populateImageLabelFrequencies() {

    for (int i = 0; i < image_labels_.size(); i++) {
        image_label_frequencies_[image_labels_.at(i)] += 1;
    }
}

/** Retrieves the classified labels.
 *
 * @return the classified labels.
 */
std::vector<int>& TestData::getClassifiedLabels() {
    return classified_labels_;
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



