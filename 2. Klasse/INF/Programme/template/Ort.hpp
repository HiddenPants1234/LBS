#include <iostream>

template <typename T>

class Ort {
private:
    T xKoordinate;
    T yKoordinate;
    std:: string name;
public:
    Ort(std::string name) {
        this->name = name;
    };
    T getX() const {
        return xKoordinate;
    };
    T getY() const {
        return yKoordinate;
    };
    std::string getName() const;
    void aendern(T x, T y) {
        this->xKoordinate = x;
        this->yKoordinate = y;
    };
    ~Ort(){};
};

template <typename T>
std::string Ort<T>::getName() const {
    return name;
}