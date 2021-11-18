//
// Created by valentin.adlgasser on 12.12.2018.
//

#include "Car.hpp"

int Car::getDoors() const {
    return doors;
}

void Car::setDoors(int doors) {
    Car::doors = doors;
}

const std::string &Car::getType() const {
    return type;
}

void Car::setType(const std::string &type) {
    Car::type = type;
}

//constructor that also uses the constructor of the Car-Class
Car::Car(int wheels, int horsepower, const int buildyear, const int cylinders, std::string allignment, int enginesize, int doors, std::string type) : Vehicle(wheels, horsepower, buildyear), Motor(cylinders, allignment, enginesize){
    this->doors = doors;
    this->type = type;
}

//this method overwrites the method from the Car-Class
void Car::showall() const{
    Vehicle::showall();
    std::cout << "Doors: " << doors << "\n";
    std::cout << "Type: " << type << "\n";
    Motor::showall();
}

