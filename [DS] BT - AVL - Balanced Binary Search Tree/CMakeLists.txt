cmake_minimum_required(VERSION 3.6)
project(BST)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp AVL.cpp AVL.h)
add_executable(BST ${SOURCE_FILES})