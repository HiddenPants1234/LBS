#include <iostream>
#include <iomanip>

namespace one{
    void func(){
        std::cout << "Namespace one" << std::endl;
    }
}

namespace two{
    void func(){
        std::cout << "Namespace two" << std::endl;
    }

}

int main() {
    int number;
    double dnumber = 11.12;
    double dnumber2 = 0.01365;
    char test;

    std::cout << "Zahl eingeben" << "\n";

    std::cin >> number;
    std::cin.sync();
    std::cin >> test;
    std::cout << test << "\n";

    one::func();
    two::func();

    std::cout << "Number: " << number << " in Hex: "  << std::hex << number << std::endl;
    std::cout << "Number: " << std::dec << number << " in Oct: "  << std::oct << number << std::endl;
    std::cout << std::dec << std::showpos << number << "\n";
    std::cout << std::noshowpos << std::setprecision(3) << dnumber << "\n";
    std::cout << std::setprecision(2) << dnumber2 << "\n";

    std::cout.width(6);
    std::cout.fill('*');
    std::cout << std::left << dnumber << "\n";






    return 0;
}