#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the pins on the I2C chip used for LCD connections:
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
  
int pin = A0;   //input number A5 is now the input pin
int sensor = 0;   //saves the data that come from the thermometer
int temperature = 0;    //saves the temperature

void setup()
{
lcd.begin(16,2);    //declares 16 columns in 2 rows
}

void loop()
{
  
  sensor = analogRead(pin);  //reads the data of the thermometer 
  temperature = map(sensor, 0, 410, -50, 150);    //changes the data from the thermometer to degrees
  lcd.setCursor(0,0);   //sets the cursor to the column 0 in the row 1
  lcd.print("Messwert:");   //prints something on the LCD
  lcd.setCursor(10,0);    //sets the cursor to the column 10 in the row 1
  lcd.print(temperature);     //prints the degrees
  lcd.setCursor(12,0);
  lcd.print(char(223));
  lcd.setCursor(13,0);
  lcd.print("C");

  //let the text scroll to the left
  for(int i = 0; i<13; i++){
    lcd.scrollDisplayLeft();
    delay(150);
    }
  //let the text scroll to the right
  for(int i = 0; i<29; i++){
    lcd.scrollDisplayRight();
    delay(150);
    }
  //back to the left
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(150);
    }
  delay(1000);
}

