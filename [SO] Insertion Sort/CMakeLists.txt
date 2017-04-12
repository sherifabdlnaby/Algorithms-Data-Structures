cmake_minimum_required(VERSION 3.6)
project(InsertionSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES InsertionSort.cpp Insert.h)
add_executable(InsertionSort ${SOURCE_FILES} Insert.h)
add_executable(InsertionSortFile InsertionSortFile.cpp Insert.h)