//
// Created by valentin.adlgasser on 27.11.2018.
//

#include <iostream>
#include "Auto.hpp"

int Auto::getConstruction_year() const {
    return construction_year;
}

void Auto::setConstruction_year(int construction_year) {
    Auto::construction_year = construction_year;
}

int Auto::getHorsepower() const {
    return horsepower;
}

void Auto::setHorsepower(int horsepower) {
    Auto::horsepower = horsepower;
}

int Auto::getMax_speed() const {
    return max_speed;
}

void Auto::setMax_speed(int max_speed) {
    Auto::max_speed = max_speed;
}

int Auto::getDoors() const {
    return doors;
}

void Auto::setDoors(int doors) {
    Auto::doors = doors;
}

int Auto::getPrice() const {
    return price;
}

void Auto::setPrice(int price) {
    Auto::price = price;
}

void Auto::printAuto() const {
    std::cout << "Construciton Year: " << construction_year << "\n";
    std::cout << "Horsepower: " << horsepower << "\n";
    std::cout << "Maximum Speed: " << max_speed << "\n";
    std::cout << "Doors: " << doors << "\n";
    std::cout << "Price: " << price << "\n";
}

Auto::Auto(int construction_year, int horsepower, int max_speed, int doors, int price) : construction_year(
        construction_year), horsepower(horsepower), max_speed(max_speed), doors(doors), price(price) {}

Auto::~Auto() {
    std::cout << "deleted\n";
}
