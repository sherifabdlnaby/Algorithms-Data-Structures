cmake_minimum_required(VERSION 3.6)
project(Mergesort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES1 MergeSort.cpp mergesort.h)
set(SOURCE_FILES2 MergeCommented.cpp mergesort.h)
add_executable(Mergesort ${SOURCE_FILES1})
add_executable(MergeCommented ${SOURCE_FILES2})