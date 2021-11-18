/* This programm reads the data from a dht11, if a vibration-sensor recognizes a vibration
@author <Valentin Adlgasser>
@date <18.12.2018>
*/

#include <iostream>
#include <wiringPi.h>
#include <stdint.h>
#include <fstream>
#include <ctime>

#define vibration 29
#define temperature 28
#define MAXTIMINGS	85
#define DHTPIN		28

int dht11_dat[5] = { 0, 0, 0, 0, 0 };


int vibrationstate = 0;

//function to get the current date and time
void getTime(int &year, int &month, int &day, int &hours, int &mins, int &secs) 
{
	time_t tt;
	time(&tt);
	tm TM = *localtime(&tt);

	year = TM.tm_year;
	month = TM.tm_month;
	day = TM.tm_month;
	hours = TM.tm_hour;
	mins = TM.tm_min;
	secs = TM.tm_sec;
}

//function to read the data of the dht11
void read_dht11_dat()
{
	uint8_t laststate	= HIGH;
	uint8_t counter		= 0;
	uint8_t j		= 0, i;

	dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;

	/* pull pin down for 18 milliseconds */
	pinMode( DHTPIN, OUTPUT );
	digitalWrite( DHTPIN, LOW );
	delay( 18 );
	/* then pull it up for 40 microseconds */
	digitalWrite( DHTPIN, HIGH );
	delayMicroseconds( 40 );
	/* prepare to read the pin */
	pinMode( DHTPIN, INPUT );

	/* detect change and read data */
	for ( i = 0; i < MAXTIMINGS; i++ )
	{
		counter = 0;
		while ( digitalRead( DHTPIN ) == laststate )
		{
			counter++;
			delayMicroseconds( 1 );
			if ( counter == 255 )
			{
				break;
			}
		}
		laststate = digitalRead( DHTPIN );

		if ( counter == 255 )
			break;

		/* ignore first 3 transitions */
		if ( (i >= 4) && (i % 2 == 0) )
		{
			/* shove each bit into the storage bytes */
			dht11_dat[j / 8] <<= 1;
			if ( counter > 50 )
				dht11_dat[j / 8] |= 1;
			j++;
		}
	}

	/*
	 * check we read 40 bits (8bit x 5 ) + verify checksum in the last byte
	 * print it out if data is good
	 */
	if ( (j >= 40) && (dht11_dat[4] == ( (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF) ) )
	{	
		int year, month, day, hours, mins, secs;
		getTime(year, month, day, hours, mins, secs)
		std::ofstream outfile;
		outfile.open("Temperature.csv");
		outfile << year << "." << month << "." << day << ";" << hours << "." << mins << "." << secs ";" << dht11_dat[2] << ";" << dht_dat[0] << "\n";
	}
	else  {
		std::cout << "---------------------\n" << "Couldn't read Data. Please try again\n";
	}
}

//function to get the current state of the vibration-sensor
void getvibration(){
	vibrationstate = digitalRead(vibration);
	if(vibrationstate == HIGH){
		read_dht11_dat();
	}
	else{
	}
}

int main(void){
	wiringPiSetup();
	pinMode(vibration, INPUT);
	pinMode(temperature, INPUT);
	digitalWrite(vibrationstate, HIGH);
	
	for(;;){
		getvibration();		
	}	
	
	return 0;
}



