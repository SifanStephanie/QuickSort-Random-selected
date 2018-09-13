cmake_minimum_required(VERSION 3.6)
project(random_selected)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(random_selected ${SOURCE_FILES})