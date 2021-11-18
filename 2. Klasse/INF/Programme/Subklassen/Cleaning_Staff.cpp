//
// Created by valentin.adlgasser on 11.12.2018.
//

#include "Cleaning_Staff.hpp"

short Cleaning_Staff::getWorking_hours() const {
    return working_hours;
}

void Cleaning_Staff::setWorking_hours(short working_hours) {
    Cleaning_Staff::working_hours = working_hours;
}

short Cleaning_Staff::getFloors() const {
    return floors;
}

void Cleaning_Staff::setFloors(short floors) {
    Cleaning_Staff::floors = floors;
}

float Cleaning_Staff::hours_per_floor() const {
    float floorhour = working_hours / floors;
    std::cout << "Hours worked per floor: " << floorhour << "\n";
}

Cleaning_Staff::Cleaning_Staff(short working_hours, short floors) : working_hours(working_hours), floors(floors) {}

Cleaning_Staff::~Cleaning_Staff() {
    std::cout << "Cleaning Staff gerekt" << "\n";
}

