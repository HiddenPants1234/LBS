//
// Created by valentin.adlgasser on 30.11.2018.
//

#include "Doppelbruch.hpp"
#include <iostream>

int Doppelbruch::getZaehler1() const {
    return zaehler1;
}

void Doppelbruch::setZaehler1(int zaehler1) {
    Doppelbruch::zaehler1 = zaehler1;
}

int Doppelbruch::getNenner1() const {
    return nenner1;
}

void Doppelbruch::setNenner1(int nenner1) {
    Doppelbruch::nenner1 = nenner1;
}

int Doppelbruch::getZaehler2() const {
    return zaehler2;
}

void Doppelbruch::setZaehler2(int zaehler2) {
    Doppelbruch::zaehler2 = zaehler2;
}

int Doppelbruch::getNenner2() const {
    return nenner2;
}

void Doppelbruch::setNenner2(int nenner2) {
    Doppelbruch::nenner2 = nenner2;
}

int Doppelbruch::add(Doppelbruch bruch2) const {
    int z = (nenner * bruch2.zaehler) + (bruch2.nenner * zaehler);
    int n = nenner * bruch2.nenner;
    int teiler = Bruch::kuerzen(z,n);
    z /= teiler;
    n /= teiler;
    if(n == 1){
        std::cout << "Ergebnis Addition: " << z << "\n";
    }
    else {
        std::cout << "Ergebnis Addition: " << z << "/" << n << "\n";
    }
}
