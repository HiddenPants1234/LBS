//
// Created by valentin.adlgasser on 20.12.2018.
//

#ifndef VEHICLE_SUB_EXCEPTION_HPP
#define VEHICLE_SUB_EXCEPTION_HPP


#include <bits/exception.h>
#include <iostream>

class Sub_Exception : public std::exception {
private:
    std::string Message;

public:
    Sub_Exception(const std::string& s):Message(s){}
    std::string& getMessage();
    virtual char const* what();
};


#endif //VEHICLE_SUB_EXCEPTION_HPP
