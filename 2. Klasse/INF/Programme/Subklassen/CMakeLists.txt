cmake_minimum_required(VERSION 3.10)
project(Subklassen)

set(CMAKE_CXX_STANDARD 11)

add_executable(Subklassen main.cpp Person.cpp Person.hpp Student.cpp Student.hpp Teacher.cpp Teacher.hpp Cleaning_Staff.cpp Cleaning_Staff.hpp)