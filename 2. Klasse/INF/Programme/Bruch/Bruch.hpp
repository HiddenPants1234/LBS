//
// Created by valentin.adlgasser on 28.11.2018.
//

#ifndef BRUCH_BRUCH_HPP
#define BRUCH_BRUCH_HPP
/**Headerfile für die Klasse Bruch
 * @file bruch.hpp
 * @author Valentin Adlgasser
 * @date 29.11.2018
 */

class Bruch {
private:
    int zaehler;
    int nenner;
    static int counter;
public:
    static int getCounter();

    int add(Bruch bruch2) const;

    int add(int ganzzahl) const;

    int sub(Bruch bruch2) const;

    int mult(Bruch bruch2) const;

    int div(Bruch bruch2) const;

    int getZaehler() const;

    virtual ~Bruch();

    Bruch(int zaehler, int nenner);

    void setZaehler(int zaehler);

    int getNenner() const;

    void setNenner(int nenner);

private:

    int kuerzen(int a, int b) const;


};


#endif //BRUCH_BRUCH_HPP
