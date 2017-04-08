cmake_minimum_required(VERSION 3.6)
project(MergeSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        MergeSortCmp.cpp
        merge.h
        )

add_executable(MergeSortCmp ${SOURCE_FILES})