cmake_minimum_required(VERSION 2.8.9)

project(GraphicsResearch)

set (CMAKE_CXX_FLAGS "-Wall -std=c++11 -ggdb -pg")
set (EXECUTABLE_OUTPUT_PATH "${GraphicsResearch_BINARY_DIR}/bin")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(SFML_STATIC_VARIABLES TRUE)
find_package(SFML 2.1 COMPONENTS system window graphics audio REQUIRED)

include_directories(${SFML_INCLUDE_DIR})

add_subdirectory(src)

install(DIRECTORY resources DESTINATION "${GraphicsResearch_BINARY_DIR}")

