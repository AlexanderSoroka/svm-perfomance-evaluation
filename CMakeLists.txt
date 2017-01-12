# cmake_minimum_required(VERSION <specify CMake version here>)
project(svm_perfomance_evaluation)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES svm_perfomance_evaluation-main.cpp scoped_timer.h scoped_timer.cpp)
add_executable(svm_perfomance_evaluation ${SOURCE_FILES})