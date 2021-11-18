#include <iostream>
#include <wiringPi.h>
#include <ctime>

#define red 27
#define green 28
#define blue 29
#define line 26

//function so I don't have to type in digital Write all the time
void RGB(int r, int g, int b)
{
	digitalWrite(red, r);
	digitalWrite(green, g);
	digitalWrite(blue, b);	
}

int main(void){
	wiringPiSetup () ;
	pinMode (red, OUTPUT);
	pinMode (green, OUTPUT);
	pinMode (blue, OUTPUT);
	pinMode (line, INPUT);
	
	//countdown to the start of the game
	std::cout << "3\n";
	delay(1000);
	std::cout << "2\n";
	delay(1000);
	std::cout << "1\n";
	delay(1000);
	std::cout << "GO!!!\n";
	
	int task = 0;
	time_t start, stop;
	time(&start);	//saves the current time
	
	for(;;){
		bool val = digitalRead (line);	//bool to check if the tracking-sensor is on a line or not
		
		if(val == HIGH) {
			RGB(0,255,0);
			//std::cout << "Tracker on line\n";			
		}
		else {
			RGB(0,0,255);
			//std::cout << "Tracker not on line \n";
			task++;		//if you get of the line count one up
		}
		//if you get of the line 20 times, stop the game
		if (task > 20){
			time(&stop);
			std::cout << "Time survived: " << difftime(stop, start) << " Seconds\n";	//prints the seconds you survived
			return 0;
		}
		delay(100);
		std::cout << task << "\n";
	}

	return 0;
}

