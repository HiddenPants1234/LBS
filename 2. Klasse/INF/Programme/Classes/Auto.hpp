//
// Created by valentin.adlgasser on 27.11.2018.
//

#ifndef CLASSES_AUTO_HPP
#define CLASSES_AUTO_HPP


class Auto {
private:
    int construction_year;
    int horsepower;
    int max_speed;
    int doors;
    int price;
public:
    void printAuto() const;

    int getConstruction_year() const;

    Auto(int construction_year, int horsepower, int max_speed, int doors, int price);

    void setConstruction_year(int construction_year);

    int getHorsepower() const;

    void setHorsepower(int horsepower);

    int getMax_speed() const;

    void setMax_speed(int max_speed);

    int getDoors() const;

    virtual ~Auto();

    void setDoors(int doors);

    int getPrice() const;

    void setPrice(int price);

};


#endif //CLASSES_AUTO_HPP
