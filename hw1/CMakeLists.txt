cmake_minimum_required(VERSION 3.19)
project(hw1)

set(CMAKE_CXX_STANDARD 14)

add_executable(hw1 main.cpp container.h shape.h rectangle.h triangle.h circle.h rectangle.cpp container.cpp triangle.cpp shape.cpp circle.cpp)