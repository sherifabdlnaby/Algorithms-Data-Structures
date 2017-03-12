cmake_minimum_required(VERSION 3.6)
project(Bubble_Sort)

set(CMAKE_CXX_STANDARD 11)

add_executable(Bubble_Sort  BubbleSort.cpp BubbleSortLibrary.h)
add_executable(BubbleSortFile BubbleSortFile.cpp BubbleSortLibrary.h)