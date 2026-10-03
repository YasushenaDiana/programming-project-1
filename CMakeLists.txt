cmake_minimum_required(VERSION 4.0)
project(BoardCells)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(BoardCells
        Cell.h
        RandomCell.h
        RandomCell.cpp)