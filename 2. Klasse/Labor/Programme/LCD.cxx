#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include </home/pi/DS18B20/src/DS18B20.cpp> //Library for the 1-wire temperature sensor

#define I2C_ADDR   0x27 //Address for the I2C adapter
#define LCD_CHR  1 //mode to send data
#define LCD_CMD  0 //mode to send commands
#define LINE1  0x80 //address of the first line on the lcd
#define LINE2  0xC0 //address of the second line on the lcd
#define LCD_BACKLIGHT   0x08  //turn the backlight on
#define ENABLE  0b00000100 //enable bit
#define temperature 7 //1-wire sensor pin

void lcd_init(void);
void lcd_byte(int bits, int mode);
void lcd_toggle_enable(int bits);

void lcdLoc(int line); //move cursor
void ClrLcd(void); //clear LCD
void typeln(const char *s);
int fd;  //saves the wiringPiI2CSetup

int main(void)
{
  if (wiringPiSetup () == -1) exit (1);
  
  pinMode(temperature, INPUT);

  fd = wiringPiI2CSetup(I2C_ADDR);

  lcd_init(); //set the LCD up

  while (1)
  {
	float tempr = digitalRead(temperature);
	char buffer[20]; //buffer to safe the temperature in a char
	sprintf(buffer, "%4.2f",  tempr); //change a float to a char
	
	ClrLcd();
	lcdLoc(LINE1);
    typeln(buffer);

	delay(2000);
    ClrLcd();
    lcdLoc(LINE1);
    typeln("HELLO");
    lcdLoc(LINE2);
    typeln("WORLD");
    
    delay(2000);
    ClrLcd();
    lcdLoc(LINE1);
    typeln("IT'S");
    lcdLoc(LINE2);
    typeln("ME");
	delay(2000);
  }

  return 0;
}

//clear the lcd and go back to the first character
void ClrLcd(void)
{
  lcd_byte(0x01, LCD_CMD);
  lcd_byte(0x02, LCD_CMD);
}

//go to specific line on the lcd
void lcdLoc(int line)
{
  lcd_byte(line, LCD_CMD);
}

//write the char to the current location on the lcd
void typeChar(char val)
{
  lcd_byte(val, LCD_CHR);
}

//allows the char to be any size, even if the lcd can't print it anymore
void typeln(const char *s)
{
  while ( *s ) lcd_byte(*(s++), LCD_CHR);
}

//send byte to data pins
//bits = the data
//mode = 1 for data, 0 for command
void lcd_byte(int bits, int mode)
{
  int bits_high;
  int bits_low;
  //uses the two half byte writes to LCD
  bits_high = mode | (bits & 0xF0) | LCD_BACKLIGHT ;
  bits_low = mode | ((bits << 4) & 0xF0) | LCD_BACKLIGHT ;

  //High bits
  wiringPiI2CReadReg8(fd, bits_high);
  lcd_toggle_enable(bits_high);

  //Low bits
  wiringPiI2CReadReg8(fd, bits_low);
  lcd_toggle_enable(bits_low);
}

//enable the pins on the lcd
void lcd_toggle_enable(int bits)
{
  delayMicroseconds(500);
  wiringPiI2CReadReg8(fd, (bits | ENABLE));
  delayMicroseconds(500);
  wiringPiI2CReadReg8(fd, (bits & ~ENABLE));
  delayMicroseconds(500);
}

//initialise the lcd
void lcd_init()
{
  //these two lines are to initialise the lcd
  lcd_byte(0x33, LCD_CMD);
  lcd_byte(0x32, LCD_CMD);

  lcd_byte(0x06, LCD_CMD); //this decides in which direction the cursor moves
  lcd_byte(0x0C, LCD_CMD); //this sets the display to static, if the hexa would be 0x0F the display would blink
  lcd_byte(0x28, LCD_CMD); //decides the data length, the number of lines and the font size
  lcd_byte(0x01, LCD_CMD); //this clears the display
  delayMicroseconds(500);
}
