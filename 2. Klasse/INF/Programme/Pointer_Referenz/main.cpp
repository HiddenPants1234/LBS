#include <iostream>

void test(int *a){
    *a = 5;
}

int pointer() {
   int myVar = 0;
   int myVar2 = 20;
   int* ptr = &myVar;
   int* ptr2 = &myVar2;
   int x[10] = {0,1,2,3};

   *ptr = 10;
   std::cout << myVar << "\n";
   (*ptr)++;
   std::cout << *ptr << "\n";

   ptr = &myVar;
   std::cout << ptr << "\n";

   ptr = ptr2;
   ptr = x;

   std::cout << *ptr << " \n";
   (*ptr)++;
   std::cout << *ptr << "\n";

   int b = 0;
   test(&b);
   std::cout << b << "\n";
}

void testr(int& a){
    a=50;
}

int referenz(){
    int myVar = 0;
    int myVar2 = 10;
    int& ref2 = myVar2;
    int& ref = myVar;
    ref++;
    std::cout << &ref << "\n";
    std::cout << myVar << "\n";

    ref = ref2;
    std::cout << &ref << "\n";
    std::cout << ref << "\n";

    testr(myVar);
    std::cout << myVar << "\n";
}

int main(){
    //pointer();
    referenz();

}