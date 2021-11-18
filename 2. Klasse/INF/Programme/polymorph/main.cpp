#include <iostream>

class test1{
public:
   virtual void print() = 0;
};

class test2 : public test1{
public:
    void print(){
        //test1:print();
        std::cout << "test2\n";
    }
};

int main() {
    test1* t1 = new test1();
    test2* t2 = new test2();
    test1* t3 = new test2();

    t1->print();
    t2->print();
    t3->print();

    return 0;
}