//
// Created by valentin.adlgasser on 11.12.2018.
//

#include "Student.hpp"

short Student::getYear() const {
    return year;
}

void Student::setYear(short year) {
    Student::year = year;
}

void Student::printStudenInfo() const {
    std::cout << "NAME: " << name << "\n";
    std::cout << "BIRTHYEAR: " << birthyear << "\n";
    std::cout << "CLASSYEAR: " << year << "\n";
}

Student::Student(short year) : year(year) {}

Student::~Student() {
    std::cout << "Student gerekt" << "\n";
}

void Student::print() const{
    Person::print();
    std::cout << "Method in the Student-Class\n";
}
