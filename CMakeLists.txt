cmake_minimum_required(VERSION 2.8.0)
project(svm_perfomance_evaluation)

set(CMAKE_CXX_STANDARD 11)

set(HEADERS_FILES
    datasets/climate_model_crashes.h
    datasets/generic/line_base.h
    scoped_timer.h
    test.h
)

set(SOURCE_FILES
    datasets/climate_model_crashes.inl
    svm_perfomance_evaluation-main.cpp
    scoped_timer.cpp
)

add_executable(svm_perfomance_evaluation
               ${SOURCE_FILES}
               ${HEADERS_FILES}
)
