/*@Author Valentin Adlgasser
* @Date 03-12-2018
*/

#include <wiringPi.h>
#include <iostream>

#define pir 27	//define pin 27 as PIR
#define buzzer 29	//define pin 29 as buzzer


int bewegung = 0;	//int to save the state of the PIR


int main(void)
{
	wiringPiSetup () ;
	pinMode(pir, INPUT);
	pinMode(buzzer, OUTPUT);
	
	for(;;)
	{
		if(bewegung == HIGH)
			{
				digitalWrite(buzzer, HIGH);
				delay(1000);
				digitalWrite(buzzer, LOW);
			}
		else
		{
			digitalWrite(buzzer, LOW)
		}
		
		delay(5000);	//the PIR needs some time to reset

	}
	
	return 0;
}

