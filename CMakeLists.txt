cmake_minimum_required(VERSION 3.0)
project(svm)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(inference)
add_subdirectory(train)
add_subdirectory(data)