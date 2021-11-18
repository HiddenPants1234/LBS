//
// Created by valentin.adlgasser on 11.12.2018.
//

#include "Person.hpp"
#import <iostream>

char Person::getGender() const {
    return gender;
}

void Person::setGender(char gender) {
    Person::gender = gender;
}

const std::string &Person::getName() const {
    return name;
}

void Person::setName(const std::string &name) {
    Person::name = name;
}

short Person::getBirthyear() const {
    return birthyear;
}

void Person::setBirthyear(short birthyear) {
    Person::birthyear = birthyear;
}

void Person::print() const{
    std::cout << "NAME: " << name << "\n";
    std::cout << "GENDER: " << gender << "\n";
    std::cout << "AGE: " << Person::age() << "\n";
}

int Person::age() const{
    int personage = 2018 - birthyear;
    return personage;
}

Person::Person(char gender, const std::string &name) : gender(gender), name(name) {}

Person::~Person() {
    std::cout << "Person gerekt" << "\n";
}

Person::Person() {}
