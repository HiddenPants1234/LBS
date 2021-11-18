//
// Created by valentin.adlgasser on 11.12.2018.
//

#ifndef SUBKLASSEN_CLEANING_STAFF_HPP
#define SUBKLASSEN_CLEANING_STAFF_HPP
#include "Person.hpp"
#include <string>

class Cleaning_Staff : private Person {
private:
    short working_hours;
    short floors;
public:
    Cleaning_Staff(short working_hours, short floors);

    short getWorking_hours() const;

    void setWorking_hours(short working_hours);

    short getFloors() const;

    void setFloors(short floors);

    float hours_per_floor() const;

    virtual ~Cleaning_Staff();
};


#endif //SUBKLASSEN_CLEANING_STAFF_HPP
