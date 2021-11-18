//
// Created by valentin.adlgasser on 20.12.2018.
//

#include "Sub_Exception.hpp"
#include <iostream>

std::string& Sub_Exception::getMessage() {
    {return Message;}
}
char const* Sub_Exception::what() {
    std::exception::what();
    return("Custom message");
}
