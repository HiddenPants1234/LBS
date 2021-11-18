/* Artikelliste.cpp
 * In diesem Program werden Artikel eingelesen und als Liste wieder ausgegeben
 * @author <Valentin Adlgasser>
 * @date <21.11.2018
 * @version <1.0>
 */

#include <iostream>
#include <string>
#include <cstring>

short i;    //Für die Anzahl der Artikel
short Counter;  //Zum Speichern welcher Artikel gerade benutzt wird

int main() {
    std::cout << "Wieviele Artikel wollen Sie eingeben?\n";
    std::cin >> i;  //Speichert die Anzahl der Artikel
    std::cin.sync();

    //Struct um alle Daten der Artikel zu speichern
    struct Artikel{
        int artikelnummer;
        char artikelname[100];  //Muss ein Char sein, weil es Probleme mit dem String in einem Struct gab
        int stueckzahl;
        double stueckpreis;
        double warenwert;
    } Artikel[Counter];


    for(Counter = 1; Counter < i+1; Counter++){
        std::string t1;     //temp Variable um den Artikelnamen zu speichern
        std::cout << "Artikelnummer " << Counter << " eingeben: ";
        std::cin >> Artikel[Counter].artikelnummer;
        //Diese Schleifen werden benutzt um zu validieren, dass der Input wirklich eine Zahl ist
        while(std::cin.fail()){
            std::cin.clear();
            std::cin.sync();
            std::cout << "Echte Artikelnummer eingeben: ";
            std::cin >> Artikel[Counter].artikelnummer;
        }
        std::cin.sync();
        std::cin.clear();
        std::cout << "Artikelname " << Counter << " eingeben: ";
        std::cin >> t1;
        std::cin.sync();
        std::cout << "Stueckzahl " << Counter << " eingeben: ";
        std::cin >>  Artikel[Counter].stueckzahl;
        while(std::cin.fail()){
            std::cin.clear();
            std::cin.sync();
            std::cout << "Echte Stueckzahl eingeben: ";
            std::cin >> Artikel[Counter].stueckzahl;
        }
        std::cin.sync();
        std::cout << "Stueckpreis " << Counter << " eingeben: ";
        std::cin >> Artikel[Counter].stueckpreis;
        while(std::cin.fail()){
            std::cin.clear();
            std::cin.sync();
            std::cout << "Echten Stueckpreis eingeben: ";
            std::cin >> Artikel[Counter].stueckpreis;
        }
        std::cin.sync();
        Artikel[Counter].warenwert = Artikel[Counter].stueckzahl * Artikel[Counter].stueckpreis;        //Berechnen des Gesamtwertes

        std::strcpy(Artikel[Counter].artikelname, t1.c_str());      //temp Variable in das Char Array des Structs speichern

    }

    std::cout << "Artikelnummer\t" << "Artikelname\t" << "Stueckzahl\t" << "Stueckpreis\t" << "Warenwert" << "\n";
    double summe = 0;

    for(Counter = 1; Counter < i+1; Counter++){
        std::cout << Artikel[Counter].artikelnummer << "\t\t\t\t" << Artikel[Counter].artikelname << "\t\t" << Artikel[Counter].stueckzahl << "\t\t\t" << Artikel[Counter].stueckpreis << "\t\t" << Artikel[Counter].warenwert << "\n";
        summe += Artikel[Counter].warenwert;
    }
    std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "SUMME: " << summe;


    return 0;
}