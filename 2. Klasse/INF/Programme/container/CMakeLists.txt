cmake_minimum_required(VERSION 3.10)
project(container)

set(CMAKE_CXX_STANDARD 11)

add_executable(container main.cpp VekQueue.cpp VekQueue.hpp)