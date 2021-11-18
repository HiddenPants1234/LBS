//
// Created by valentin.adlgasser on 11.12.2018.
//

#ifndef SUBKLASSEN_PERSON_HPP
#define SUBKLASSEN_PERSON_HPP

#import <iostream>
#import <string>


class Person {
private:
    char gender;

    int age() const;

protected:
    std::string name;

public:
    char getGender() const;

    Person();

    void setGender(char gender);

    const std::string &getName() const;

    void setName(const std::string &name);

    virtual ~Person();

    short getBirthyear() const;

    void setBirthyear(short birthyear);

    short birthyear;

    void print() const;

    Person(char gender, const std::string &name);

};


#endif //SUBKLASSEN_PERSON_HPP
