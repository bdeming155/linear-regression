cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)

include_directories(include/eigen-3.4.0)

add_executable(lin_reg src/main.cpp)
