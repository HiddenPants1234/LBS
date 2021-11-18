//
// Created by valentin.adlgasser on 11.12.2018.
//

#include "Teacher.hpp"

int Teacher::getMonthlySalary() const {
    return monthlySalary;
}

void Teacher::setMonthlySalary(int monthlySalary) {
    Teacher::monthlySalary = monthlySalary;
}

Teacher::Teacher(int monthlySalary) : monthlySalary(monthlySalary) {}

int Teacher::yearlySalary() const {
    int temp =  monthlySalary * 14;
    return temp;
}

Teacher::~Teacher() {
    std::cout << "Teacher gerekt" << "\n";
}
