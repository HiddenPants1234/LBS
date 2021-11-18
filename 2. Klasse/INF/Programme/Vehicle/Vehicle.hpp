//
// Created by valentin.adlgasser on 12.12.2018.
//

#ifndef VEHICLE_VEHICLE_HPP
#define VEHICLE_VEHICLE_HPP

#include <iostream>

class Vehicle {
private:
    int wheels;
    int horsepower;
    const int buildyear;
public:
    //constructor because we can't use a standard constructor
    Vehicle(int wheels, int horsepower, const int buildyear);

    int getWheels() const;

    void setWheels(int wheels);

    int getHorsepower() const;

    void setHorsepower(int horsepower);

    const int getBuildyear() const;

    //method to print the specs of the vehicle
    void showall() const;

};


#endif //VEHICLE_VEHICLE_HPP
