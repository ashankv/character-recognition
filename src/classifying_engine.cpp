#include <iostream>
#include "image_data.h"
#include "training_data.h"
#include "model.h"


int main() {

    TrainingData training_data;
    std::string file_name = "../data/trainingimages";
    std::string file_name_2 = "../data/traininglabels";

    training_data.readTrainingDataFromFileToVector(file_name);
    training_data.readTrainingLabelsFromFileToVector(file_name_2);

    std::vector<ImageData> image_data_vector = training_data.getTrainingImageDataVector();
    std::vector<int> image_data_labels = training_data.getTrainingImageLabelVector();

    Model model;
    model.calculateProbabilities(training_data);

    std::cout << model.getSpecificProbability(0, 3, 0);
    //std::cout << image_data_vector.size() << std::endl;
    //std::cout << image_data_labels.size() << std::endl;

    return 0;
}