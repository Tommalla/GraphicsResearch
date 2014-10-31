cmake_minimum_required(VERSION 2.8.9)

project(GraphicsResearch)

set (CMAKE_CXX_FLAGS "-Wall -std=c++11 -ggdb -pg")

set (EXECUTABLE_OUTPUT_PATH "${GraphicsResearch_BINARY_DIR}/bin")

add_subdirectory(src)

