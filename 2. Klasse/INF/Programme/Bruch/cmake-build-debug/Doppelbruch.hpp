//
// Created by valentin.adlgasser on 30.11.2018.
//

#ifndef BRUCH_DOPPELBRUCH_HPP
#define BRUCH_DOPPELBRUCH_HPP


class Doppelbruch {
private:
    int zaehler1;
    int nenner1;
    int zaehler2;
public:
    int getZaehler1() const;

    void setZaehler1(int zaehler1);

    int getNenner1() const;

    void setNenner1(int nenner1);

    int getZaehler2() const;

    void setZaehler2(int zaehler2);

    int getNenner2() const;

    void setNenner2(int nenner2);

private:
    int nenner2;
};


#endif //BRUCH_DOPPELBRUCH_HPP
