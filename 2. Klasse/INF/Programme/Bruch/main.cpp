/**Dieses Programm rechnet mit 2 Brüchen in einer Klasse
 * @file main.cpp
 * @author Valentin Adlgasser
 * @date 29.11.2018
 * \mainpage Index für das Programm 'Bruch'
 *
 * \section Programmbeschreibung
 *
 * Dieses Programm rechnet mit 2 Büchen oder mit einem Bruch und einem Integer
 *
 */

#include <iostream>
#include "Bruch.hpp"

int main() {
    auto bruch1 = Bruch(10,4);
    auto bruch2 = Bruch(10,4);
    int ganzzahl = 1;

    std::cout << Bruch::getCounter() <<"\n";
    bruch1.add(ganzzahl);
    bruch1.sub(bruch2);
    bruch1.mult(bruch2);
    bruch1.div(bruch2);

    return 0;
}