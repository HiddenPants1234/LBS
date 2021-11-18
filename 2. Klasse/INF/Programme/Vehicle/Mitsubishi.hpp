//
// Created by valentin.adlgasser on 12.12.2018.
//

#ifndef VEHICLE_MITSUBISHI_HPP
#define VEHICLE_MITSUBISHI_HPP

#include "Car.hpp"
#include "Sub_Exception.hpp"


class Mitsubishi : public Car{
private:
    bool tuned;
    bool limitedslipdifferential;

public:
    bool isTuned() const;

    void setTuned(bool tuned);

    bool isLimitedslipdifferential() const;

    void setLimitedslipdifferential(bool limitedslipdifferential);

    Mitsubishi(int wheels, int horsepower, const int buildyear, const int cylinders, std::string allignment, int enginesize, int doors, std::string type, bool tuned, bool limitedslipdiff);

    void showall() const;

    void testException(int a);

};


#endif //VEHICLE_MITSUBISHI_HPP
