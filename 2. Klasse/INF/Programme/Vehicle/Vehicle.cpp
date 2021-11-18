//
// Created by valentin.adlgasser on 12.12.2018.
//

#include "Vehicle.hpp"
#include <iostream>

int Vehicle::getWheels() const {
    return wheels;
}

void Vehicle::setWheels(int wheels) {
    Vehicle::wheels = wheels;
}

int Vehicle::getHorsepower() const {
    return horsepower;
}

void Vehicle::setHorsepower(int horsepower) {
    Vehicle::horsepower = horsepower;
}

const int Vehicle::getBuildyear() const {
    return buildyear;
}

void Vehicle::showall() const{
    std::cout << "Wheels: " << wheels << "\n";
    std::cout << "Horsepower: " << horsepower << "\n";
    std::cout << "Buildyear: " << buildyear << "\n";

}

Vehicle::Vehicle(int wheels, int horsepower, const int buildyear) : wheels(wheels), horsepower(horsepower),
                                                                    buildyear(buildyear) {}
