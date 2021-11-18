/*This Programm enters some Values to a class and prints them
@author <Valentin Adlgasser>
@date <27.11.2018>*/

#include <iostream>
#include "Auto.hpp"

int main() {
    Auto bmw = Auto(123, 2, 213, 1234, 154);
    std::cout << "--BMW 1--\n";
    bmw.printAuto();
    bmw.setConstruction_year(1999);
    bmw.setDoors(3);
    bmw.setHorsepower(555);
    bmw.setMax_speed(215);
    bmw.setPrice(123456);
    std::cout << "--BMW 2--\n";
    bmw.printAuto();
    auto mini = bmw;
    std::cout << "--Mini 1--\n";
    mini.printAuto();
    mini.setConstruction_year(2012);
    std::cout << "--Mini 2--\n";
    mini.printAuto();

    auto* vw = new Auto(2016,123,210,5,12345);
    Auto* skoda = vw;
    std::cout << "--VW--\n";
    vw->printAuto();
    std::cout << "--Skoda--\n";
    skoda->printAuto();
    std::cout << "\n";
    skoda = nullptr;
    delete(vw);

    return 0;
}