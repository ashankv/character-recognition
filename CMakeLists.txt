cmake_minimum_required(VERSION 3.9)
project(NaiveBayes)

set(CMAKE_CXX_STANDARD 11)

add_executable(NaiveBayes src/classifying_engine.cpp src/image_data.cpp src/image_data.h src/model.cpp src/model.h src/classifying_engine.h src/training_data.cpp src/training_data.h)