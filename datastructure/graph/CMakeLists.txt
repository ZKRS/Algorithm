cmake_minimum_required(VERSION 3.9)
project(graph)

set(CMAKE_CXX_STANDARD 11)

add_executable(graph main.cpp DenseGraph.h SparseGraph.h Edge.h ReadGraph.h ReadGraph.h ConnectedComponents.h)