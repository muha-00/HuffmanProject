cmake_minimum_required(VERSION 3.29)
project(HuffmanProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(HuffmanProject main.cpp
        HuffmanTree.cpp
        HuffmanTree.h)
