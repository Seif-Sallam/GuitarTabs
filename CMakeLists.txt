cmake_minimum_required(VERSION 3.16)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>")

project(GuitarTabs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(guitar-tabs)
add_subdirectory(playground)