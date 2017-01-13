cmake_minimum_required(VERSION 2.8.0)
project(svm_perfomance_evaluation)

set(CMAKE_CXX_STANDARD 11)

set(HEADERS_FILES
    scoped_timer.h
    test.h
)

set(SOURCE_FILES
    svm_perfomance_evaluation-main.cpp
    scoped_timer.cpp
)

add_executable(svm_perfomance_evaluation
               ${SOURCE_FILES}
               ${HEADERS_FILES}
)
