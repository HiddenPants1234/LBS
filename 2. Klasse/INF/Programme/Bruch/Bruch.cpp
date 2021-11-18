/**Klasse um mit Brüchen zu Rechnen
 * @file bruch.cpp
 * @author Valentin Adlgasser
 * @date 29.11.2018
 */

#include "Bruch.hpp"
#include <iostream>

int Bruch::counter = 0;

int Bruch::getZaehler() const {
    return zaehler;
}

void Bruch::setZaehler(int zaehler) {
    Bruch::zaehler = zaehler;
}

int Bruch::getNenner() const {
    return nenner;
}

void Bruch::setNenner(int nenner) {
    Bruch::nenner = nenner;
}
/**
 * Constructor\n
 * Der Counter für das Aufrufen des Constructors wird um 1 erhöht
 */
Bruch::Bruch(int zaehler, int nenner) : zaehler(zaehler), nenner(nenner) {
    counter++;
}
/**
 * Destructor\n
 * Der Counter für das Aufrufen des Constructors wird um 1 verringert
 */
Bruch::~Bruch() {
    counter--;
}
/**
 * Methode um den Counter auszugeben
 * @return Gibt den Wert des Counters zurück
 */
int Bruch::getCounter() {
    return counter;
}
/**Addition
 *
 * @param bruch2 ist ein Bruch
 * @return Ergebnis der Addition
 */
int Bruch::add(Bruch bruch2) const {
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
/**Addition mit Ganzzahl
 *
 * @param ganzzahl ist ein Integer
 * @return Ergebnis der Addition
 */
int Bruch::add(int ganzzahl) const{
    int z = zaehler;
    int n = nenner;
    z += (nenner * ganzzahl);
    int teiler = Bruch::kuerzen(z,n);
    z /= teiler;
    n /= teiler;
    if(nenner == 1){
        std::cout << "Ergebnis Addition: " << z << "\n";
    }
    else {
        std::cout << "Ergebnis Addition: " << z << "/" << n << "\n";
    }
}
/**Subtraktion
 *
 * @param bruch2 ist ein Bruch
 * @return Ergebnis der Subtraktion
 */
int Bruch::sub(Bruch bruch2) const {
    int z = (nenner * bruch2.zaehler) - (bruch2.nenner * zaehler);
    int n = nenner * bruch2.nenner;
    int teiler = Bruch::kuerzen(z,n);
    z /= teiler;
    n /= teiler;
    if(z == 0){
        std::cout << "Ergebnis Subtraktion: 0\n";
    }
    else if( n == 1){
        std::cout << "Ergebnis Subtraktion: " << z << "\n";
    }
    else{
        std::cout << "Ergebnis Subtraktion: " << z << "/" << n << "\n";
    }
}
/**Multiplikation
 *
 * @param bruch2 ist ein Bruch
 * @return Ergebnis der Multiplikation
 */
int Bruch::mult(Bruch bruch2) const{
    int z = zaehler * bruch2.zaehler;
    int n = nenner * bruch2.nenner;
    int teiler = Bruch::kuerzen(z,n);
    z /= teiler;
    n /= teiler;
    if(z == 0){
        std::cout << "Ergebnis Multiplikation: 0\n";
    }
    else if( n == 1){
        std::cout << "Ergebnis Multiplikation: " << z << "\n";
    }
    else{
        std::cout << "Ergebnis Multiplikation: " << z << "/" << n << "\n";
    }
}
/**Division
 *
 * @param bruch2 ist ein Bruch
 * @return Ergebnis der Division
 */
int Bruch::div(Bruch bruch2) const{
    int z = zaehler * bruch2.nenner;
    int n = nenner * bruch2.zaehler;
    int teiler = Bruch::kuerzen(z,n);
    z /= teiler;
    n /= teiler;
    if(z == 0){
        std::cout << "Ergebnis Division: 0\n";
    }
    else if( n == 1){
        std::cout << "Ergebnis Division: " << z << "\n";
    }
    else{
        std::cout << "Ergebnis Division: " << z << "/" << n << "\n";
    }
}

//Funktion um die Brüche zu kürzen
int Bruch::kuerzen(int a, int b) const{
    if (a == 0)
        return b;

    while (b != 0) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

    return a;
}

