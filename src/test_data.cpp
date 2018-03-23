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
void TestData::ReadTestDataFromFileToVector(std::string &file_name) {
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

/** Reads the test labels from the file and converts to a vector.
 *
 * @param file_name the file name to read from.
 */
void TestData::ReadTestLabelsFromFileToVector(std::string &file_name) {

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

/** Populates the vector of classified labels of each ImageData object.
 *
 */
void TestData::PopulateClassifiedLabels() {
    for (auto& image : image_data_vector_) {
        classified_labels_.push_back(image.GetClassWithHighestProbabilityFromPosteriors());
    }
}

/** Populate confusion map, or frequency of each class given a class.
 *
 */
void TestData::PopulateConfusionMap() {

    // Iterate through each class.
    for (int i = 0; i < NUMBER_OF_CLASSES; i++) {

        // Creates a vector of class size, initialized with value of 0.
        std::vector<int> class_confusion_frequency(NUMBER_OF_CLASSES, 0);

        // Iterate through number of test data
        for (int j = 0; j < classified_labels_.size(); j++) {

            // Get actual/expected labels on the jth value
            int actual_label = classified_labels_[j];
            int expected_label = image_labels_[j];

            // For every value that equals to the current i value, increase the frequency based on actual/expected
            if (expected_label == i) {
                class_confusion_frequency[actual_label] += 1;
            }
        }

        // Add the vector to the confusion map.
        confusion_map_[i] = class_confusion_frequency;
    }
}

/** Prints the 10x10 confusion matrix given the classified labels and the actual labels.
 *
 */
void TestData::PrintConfusionMatrix() {

    PopulateImageLabelFrequencies();
    PopulateConfusionMap();

    std::cout << "CONFUSION MATRIX: Actual vs. Expected Percentages" << std::endl;

    for (int i = 0; i < NUMBER_OF_CLASSES; i++) {
        std::vector<int> confusion_vector = confusion_map_[i];

        for(int j = 0; j < confusion_vector.size(); j++) {

            // Rounds each element.
            double confusion_element = (double) confusion_vector[j] / (double) image_label_frequencies_[i];
            confusion_element = (round(confusion_element * ROUND_SCALER) / ROUND_SCALER) * PERCENT_SCALER;

            std::ostringstream string_stream;
            string_stream << confusion_element << "%";
            std::string percentage = string_stream.str();

            std::cout << std::setw(COL_SIZE) << std::left << percentage;
        }

        std::cout << std::endl;
        std::cout << std::endl;
    }

}

/** Prints each classified label next to their corresponding test label.
 *
 */
void TestData::PrintClassifiedLabels() {

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
void TestData::PopulateImageLabelFrequencies() {

    for (int i = 0; i < image_labels_.size(); i++) {
        image_label_frequencies_[image_labels_.at(i)] += 1;
    }
}

/** Retrieves the classified labels.
 *
 * @return the classified labels.
 */
std::vector<int>& TestData::GetClassifiedLabels() {
    return classified_labels_;
}

/** Retrieves the Image Data vector of test data.
 *
 * @return the Image Data vector of test data.
 */
std::vector<ImageData>& TestData::GetTestImageDataVector() {
    return image_data_vector_;
}

/** Retrieves the test image labels from the data.
 *
 * @return the test image labels from the data.
 */
std::vector<int>& TestData::GetTestImageLabelVector() {
    return image_labels_;
}

/** Prints Test Images that have the highest probability of classification for each class.
 *
 */
void TestData::PrintHighestProbabilityImageForEachClass() {

    for (int i = 0; i < NUMBER_OF_CLASSES; i++) {

        std::cout << "Class: " << i << std::endl;

        double max_probability = BIG_NEGATIVE;
        ImageData most_accurate_image;

        for (auto image_data : image_data_vector_) {

            std::map<int, double> posterior_probabilities = image_data.GetPosteriorProbabilityMap();

            if (posterior_probabilities[i] > max_probability) {
                max_probability = posterior_probabilities[i];
                most_accurate_image = image_data;
            }
        }

        std::cout << "Highest Value: " << max_probability << std::endl;
        most_accurate_image.PrintImage();
        std::cout << std::endl;
        std::cout << "----------------" << std::endl;

    }

}

/** Prints Test Images that have the lowest probability of classification for each class.
 *
 */
void TestData::PrintLowestProbabilityImageForEachClass() {

    std::cout << std::endl;

    for (int i = 0; i < NUMBER_OF_CLASSES; i++) {

        std::cout << "Class: " << i << std::endl;

        double max_probability = 0.0;
        ImageData most_accurate_image;

        for (auto image_data : image_data_vector_) {

            std::map<int, double> posterior_probabilities = image_data.GetPosteriorProbabilityMap();

            if (posterior_probabilities[i] < max_probability) {
                max_probability = posterior_probabilities[i];
                most_accurate_image = image_data;
            }
        }

        std::cout << "Lowest Value: " << max_probability << std::endl;
        most_accurate_image.PrintImage();
        std::cout << std::endl;
        std::cout << "----------------" << std::endl;

    }

}



