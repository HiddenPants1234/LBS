#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <ctime>

void testfunction(int a) {
    std::cout << a << ", " ;
}

int main() {
    std::vector<int> vector1;
    std::vector<int>::iterator returnvector;
    std::list<int> list1;
    std::list<int>::iterator returnlist;

    srand(time(NULL));

    for(int i = 0; i<50; i++) {
       vector1.push_back(rand()%100);
       list1.push_back(rand()%100);
    }

    std::cout << "For Each:\n";
    std::for_each(vector1.begin(), vector1.end(), testfunction);
    std::cout << "\n";
    std::for_each(list1.begin(), list1.end(), testfunction);

    std::cout << "\n\nFind:";
    returnvector = std::find(vector1.begin(), vector1.end(), 30);
    std::cout << "\n" << *returnvector << "\n";
    returnlist = std::find(list1.begin(), list1.end(), 30);
    std::cout << *returnlist << "\n";

    std::cout << "\nSort:\n";
    std::sort(vector1.begin(), vector1.end());
    std::for_each(vector1.begin(), vector1.end(), testfunction);


    return 0;
}