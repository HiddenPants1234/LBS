//
// Created by valentin.adlgasser on 12.12.2018.
//

#ifndef VEHICLE_CAR_HPP
#define VEHICLE_CAR_HPP

#include "Vehicle.hpp"
#include "Motor.hpp"
#include <iostream>
#include <string>

class Car : public Vehicle, public Motor{
private:
    int doors;
    std::string type;
public:
    Car(int wheels, int horsepower, const int buildyear, const int cylinders, std::string allignment, int enginesize, int doors, std::string type);

    int getDoors() const;

    void setDoors(int doors);

    const std::string &getType() const;

    void setType(const std::string &type);

    void showall() const;
};


#endif //VEHICLE_CAR_HPP
