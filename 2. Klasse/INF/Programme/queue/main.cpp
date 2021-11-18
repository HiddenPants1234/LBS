#include <iostream>
#include <queue>

//Funktion um den gesamten Inhalt der Queue auszugeben
void showq(std::queue<int32_t> gq) {
    std::queue<int32_t> g = gq;
    while (!g.empty()) {
        std::cout << '\t' << g.front();
        g.pop();
    }
    std::cout << '\n';
}

int main() {
    std::queue<int32_t> gq1; //Integer Queue wird erstellt
    //Daten werden in die Queue eingefügt
    gq1.push(10);
    gq1.push(20);
    gq1.emplace(40); //Hat dieselbe Funktion wie "push"

    std::cout << "Der Inhalt der Queue1: ";
    showq(gq1);

    std::cout << "\ngq1.size(): " << gq1.size(); //Gibt die größe der Queue aus
    std::cout << "\ngq1.front(): " << gq1.front(); //Gibt das erste Element der Queue aus
    std::cout << "\ngq1.back(): " << gq1.back(); //Gibt das letzte Element der Queue aus

    std::cout << "\ngq1.pop(): ";
    gq1.pop(); //Erstes Element der Queue wird gelöscht
    showq(gq1);

    std::queue<int32_t> gq2;
    swap(gq1, gq2); //Gesamter Inhalt der ersten Queue wird in die zweite verschoben
    std::cout << "\nDer Inhalt der Queue2: ";
    showq(gq2);

    return 0;
}