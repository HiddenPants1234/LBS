/*
    In this sketch you can choose what you want to do with a RGB-Led.
    There is a menu where you can choose what task should be done.
    @author <Valentin Adlgasser>
    @date <27-11-2018>
*/
#include <wiringPi.h>
#include <iostream>

#define red 27
#define green 28
#define blue 29

//function so I don't have to type in digital Write all the time
void RGB(int r, int g, int b)
{
	digitalWrite(red, r);
	digitalWrite(green, g);
	digitalWrite(blue, b);	
}

//task to let the change the color from yellow to green to blue
void task1(){
	RGB(255, 255, 0);
    delay(1000);
    RGB(0, 255, 0);
    delay(1000);
    RGB(0, 0, 255);
    delay(1000);
}

//task to let the user change the color manually
void task2(){
	int r;
	int g;
	int b;
	std::cout << "Enter the RGB values\n";
	std::cin >> r;
	std::cin.sync();
	std::cin >> g;
	std::cin.sync();
	std::cin >> b;
	std::cin.sync();
	RGB(r,g,b);
}

int main(void)
{
	wiringPiSetup () ;
	pinMode (red, OUTPUT);
	pinMode (green, OUTPUT);
	pinMode (blue, OUTPUT);
	
	for(;;)
	{	int task;
		std::cout << "What task do you wanna do?\n" << "'1' for task 1, '2' for task 2 and '3' to end the program\n";
		std::cin >> task;
		//switch to let the user decide which task he wants to do
		switch(task){
				case 1:
					task1();
					break;
				case 2: 
					task2();
					break;
				case 3:
					return 0;
				default:
					std::cout << "Please enter a working task\n";			
		}
		
	}
	return 0;
}
