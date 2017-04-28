cmake_minimum_required(VERSION 3.6)
project(AVL)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp AVL.cpp AVL.h)
add_executable(AVL ${SOURCE_FILES})