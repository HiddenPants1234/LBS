cmake_minimum_required(VERSION 3.10)
project(Vehicle)

set(CMAKE_CXX_STANDARD 11)

add_executable(Vehicle main.cpp Vehicle.cpp Vehicle.hpp Car.cpp Car.hpp Mitsubishi.cpp Mitsubishi.hpp Motor.cpp Motor.hpp Sub_Exception.cpp Sub_Exception.hpp)