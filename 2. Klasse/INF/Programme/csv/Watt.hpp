#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

template <typename T>

class Watt {
private:
    T watts;
    T volt;
    T ampere;
public:
    Watt() {
        openCSV();
    }

    void openCSV() {
        std::ifstream csvread;  //stream to save the input from the csv file
        std::ofstream csvoutput;    //stream to save the output to the csv file
        csvread.open("C:\\Users\\valentin.adlgasser\\Downloads\\values.csv", std::ios::in); //This opens the csv and puts everything into the stream
        csvoutput.open("C:\\Users\\valentin.adlgasser\\Downloads\\output.csv");
        std::string s = ""; //string to save each line of the input
        while(std::getline(csvread, s)) {
            size_t pos = 0; //saves the position of the ";"

            while((pos = s.find(';')) != std::string::npos) {
                std::string value = s.substr(0, pos);   //string that saves the value before the ";"
                std::string value2 = s.substr(pos+1, s.npos);   //string that saves the value after the ";"
                s = s.substr(pos+1);

                replace(value, value2);

                std::cout << "Watt: " << watts << "\n";
                csvoutput << watts << ";"; //this writes to a csv
                csvoutput << volt << ";";
                csvoutput << ampere << "\n";
            }
        }
    }

    void replace (std::string v, std::string a) {
        v = std::regex_replace(v, std::regex("\\,"), ".");  //replace the "," in the string with a "." so it can be casted to a float
        a = std::regex_replace(a, std::regex("\\,"), ".");
        calcWatt(std::stof(v),std::stof(a));
    }

    void calcWatt(float v, float a) {
        this->volt = v;
        this->ampere = a;
        watts = volt * ampere;
    }

};