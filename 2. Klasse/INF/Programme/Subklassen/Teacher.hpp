//
// Created by valentin.adlgasser on 11.12.2018.
//

#ifndef SUBKLASSEN_TEACHER_HPP
#define SUBKLASSEN_TEACHER_HPP

#include "Person.hpp"


class Teacher : protected Person {
private:
    int monthlySalary;
public:
    virtual ~Teacher();

    int getMonthlySalary() const;

    Teacher(int monthlySalary);

    void setMonthlySalary(int monthlySalary);

    int  yearlySalary() const;


};


#endif //SUBKLASSEN_TEACHER_HPP
