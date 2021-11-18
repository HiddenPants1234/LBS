//
// Created by valentin.adlgasser on 12.12.2018.
//

#include "Mitsubishi.hpp"

bool Mitsubishi::isTuned() const {
    return tuned;
}

void Mitsubishi::setTuned(bool tuned) {
    Mitsubishi::tuned = tuned;
}

bool Mitsubishi::isLimitedslipdifferential() const {
    return limitedslipdifferential;
}

void Mitsubishi::setLimitedslipdifferential(bool limitedslipdifferential) {
    Mitsubishi::limitedslipdifferential = limitedslipdifferential;
}

//constructor with the constructor of the Car-Class
Mitsubishi::Mitsubishi(int wheels, int horsepower, const int buildyear, const int cylinders, std::string allignment, int enginesize, int doors, std::string type, bool tuned, bool limitedslipdiff) : Car(wheels, horsepower, buildyear, cylinders, allignment, enginesize, doors, type){
    this->tuned = tuned;
    this->limitedslipdifferential = limitedslipdiff;
}

void Mitsubishi::showall() const{
    Car::showall();
    std::cout << "      -Tuned: " << tuned << "\n";
    std::cout << "      -Limited Slip Differential: " << limitedslipdifferential << "\n";
}

void Mitsubishi::testException(int a) {
    if(a == 2){
        throw Sub_Exception("Custom exception called\n");
    }
}