#include <iostream>
#include "Ort.hpp"

int main() {
    Ort<int> test("Cool");
    test.aendern(33, 45);
    std::cout << "Name: " << test.getName() << "\nX: " << test.getX() << "\nY: " << test.getY() << "\n";
    return 0;
}