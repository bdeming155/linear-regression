cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

FetchContent_Declare(Eigen
        GIT_REPOSITORY https://gitlab.com/libeigen/eigen
        GIT_TAG 3.4)

FetchContent_MakeAvailable(Eigen)

add_executable(lin_reg src/main.cpp)

target_link_libraries(lin_reg
        PUBLIC
        Eigen3::Eigen)