//
// Created by valentin.adlgasser on 12.12.2018.
//

#include <iostream>
#include "Motor.hpp"

const int Motor::getCylinders() const {
    return cylinders;
}

const std::string &Motor::getAllignment() const {
    return allignment;
}

void Motor::setAllignment(const std::string &allignment) {
    Motor::allignment = allignment;
}

int Motor::getEnginesize() const {
    return enginesize;
}

void Motor::setEnginesize(int enginesize) {
    Motor::enginesize = enginesize;
}

void Motor::showall() const{
    std::cout << "      -Cylinders: " << cylinders << "\n";
    std::cout << "      -Allignment: " << allignment << "\n";
    std::cout << "      -Enginesize: " << enginesize << "\n";
}

Motor::Motor(const int cylinders, const std::string &allignment, int enginesize) : cylinders(cylinders),
                                                                                   allignment(allignment),
                                                                                   enginesize(enginesize) {}
