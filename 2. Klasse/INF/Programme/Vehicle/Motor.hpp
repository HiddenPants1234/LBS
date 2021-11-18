//
// Created by valentin.adlgasser on 12.12.2018.
//

#ifndef VEHICLE_MOTOR_HPP
#define VEHICLE_MOTOR_HPP

#include <string>

class Motor {
private:
    const int cylinders;
    std::string allignment;
    int enginesize;
public:
    const int getCylinders() const;

    const std::string &getAllignment() const;

    void setAllignment(const std::string &allignment);

    int getEnginesize() const;

    void setEnginesize(int enginesize);

    //again no standard constructor
    Motor(const int cylinders, const std::string &allignment, int enginesize);

    void showall() const;

};


#endif //VEHICLE_MOTOR_HPP
