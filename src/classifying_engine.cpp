#include <iostream>
#include "image_data.h"
#include "training_data.h"


int main() {

    TrainingData training_data;
    std::string file_name = "../data/trainingimages";
    std::string file_name_2 = "../data/traininglabels";

    training_data.readImageDataVectorFromFile(file_name);
    training_data.readImageLabelFromFile(file_name_2);

    std::vector<ImageData> image_data_vector = training_data.getImageDataVector();
    std::vector<int> image_data_labels = training_data.getImageLabelVector();

    std::cout << image_data_vector.size() << std::endl;
    std::cout << image_data_labels.size() << std::endl;

    return 0;
}