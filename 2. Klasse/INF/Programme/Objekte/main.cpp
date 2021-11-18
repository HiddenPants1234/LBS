#include <iostream>
int position = 0;
char stack[11];

void push(){
    if(position < 9) {
        std::cout << "Write a char that you want to add\n";
        std::cin >> stack[position];
        std::cout << "\nStack: ";
        std::cin.sync();
        std::cin.clear();
        position++;

        for(int i = 0; i < position; i++){
            std::cout << stack[i] << " | ";
        }
    }
    else if(position == 9){
        std::cout << "Stack is full, delete something to add a new item";
    }
    std::cout << "\n";

}

void pull(){
    if(position > 0){
        std::cout << "First item deleted\n\n" << "Stack: ";
        stack[position] = NULL;
        position--;

        for(int i = 0; i < position; i++){
            std::cout << stack[i] <<  " | \n";
        }
    }
    else if(position == 0){
        std::cout << "Stack is empty, add something to delete an item\n";
    }

}


int main() {
    char cases;
    int end = 0;

    while(end == 0) {
        std::cout << "Write 'p' to add something to the stack\n" << "Write 'd' to delete something from the stack\n" << "Write 'e' to end the programm\n";
        std::cin >> cases;

        switch (cases) {
            case 'p':
            case 'P':
                push();
                break;

            case 'd':
            case 'D':
                pull();
                break;

            case 'e':
            case 'E':
                return 0;

            default:
                std::cout << "Please enter a working input";
        }
    }

}