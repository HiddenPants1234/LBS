//
// Created by valentin.adlgasser on 11.12.2018.
//

#ifndef SUBKLASSEN_STUDENT_HPP
#define SUBKLASSEN_STUDENT_HPP

#include "Person.hpp"


class Student : public Person {
private:
    short year;
public:
    virtual ~Student();

    Student(short year);

    short getYear() const;

    void setYear(short year);

    void printStudenInfo() const;

    void print() const;

};


#endif //SUBKLASSEN_STUDENT_HPP
