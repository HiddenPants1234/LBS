/* @file main.cpp
 * @author Valentin Adlgasser
 * @date 29.11.2018
 */

#include <iostream>
#include "Person.hpp"
#include "Student.hpp"
#include "Teacher.hpp"
#include "Cleaning_Staff.hpp"

int main() {
    std::cout << "-----Person-----\n";
    auto vali = Person('m',"Valentin Adlgasser");
    vali.birthyear = 2000;
    vali.print();

    std::cout << "-----Student-----\n";
    auto anton = Student(2);
    anton.setName("Anton Riedl");
    anton.setBirthyear(1996);
    anton.printStudenInfo();
    anton.print();

    std::cout << "-----Teacher-----\n";
    auto pichler = Teacher(2200);
    std::cout << "Yearly Salary: " << pichler.yearlySalary() << "€\n";

    std::cout << "-----Cleaning Staff-----\n";
    auto cleaningLady = Cleaning_Staff(9, 3);
    cleaningLady.hours_per_floor();

    std::cout << "-----Destruction-----\n";

    return 0;
}