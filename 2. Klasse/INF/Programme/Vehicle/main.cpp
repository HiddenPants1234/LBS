/* This program has two classes with only one subclass, this subclass has also a subclass and every class prints all their atributes with 'showall'.
 * @file main.cpp
 * @author Valentin Adlgasser
 * @date 12.12.2018
 */

#include <iostream>
#include "Vehicle.hpp"
#include "Car.hpp"
#include "Mitsubishi.hpp"
#include "Sub_Exception.hpp"

int main() {
    auto bmw = Car(5, 250, 2006, 6, "V", 2600, 5, "3er-Klasse");
    auto hovercraft = Vehicle(0, 400, 1980);
    auto evo7 = Mitsubishi(4, 280, 2002, 6, "V", 3200, 4, "Lancer Evolution 7", true, true);
    std::cout << "----------BMW----------\n";
    bmw.showall();
    std::cout << "----------Hovercraft----------\n";
    hovercraft.showall();
    std::cout << "----------Mitsubishi----------\n";
    evo7.showall();
    try {
        evo7.testException(2);
    }
    catch(Sub_Exception& e){
        std::cout << e.getMessage();
        std::cout << e.what();
    }


    return 0;
}