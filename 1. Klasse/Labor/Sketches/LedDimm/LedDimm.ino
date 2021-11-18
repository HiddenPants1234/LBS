/* Reaction_Game.ino
   In this program are 4 sketches, each does a different task and what the sketch does is written above each
   @author <Valentin Adlgasser>
   @date <24-05-2018>
   @version <1.0> 
   */

#define ledRed 3
#define ledGreen 5



//These variables have to be integers, if they're not the "for" loops don't work
int bRed = 0;   //integer that saves the brightness of the red LED

void setup() {
//Only used for the second task
  /*Serial.begin(9600);
  Serial.println("Please enter the brightness of the LED in percent");*/
}

void loop() {  
  
  /*//task 1
  //Change the brightness between 20%, 50% and 75%
  analogWrite(ledRed, (20*2.55));
  delay(300);
  analogWrite(ledRed, (50*2.55));
  delay(300);
  analogWrite(ledRed, (75*2.55));
  delay(300);*/
  
  //task 2
  //Change brightness on the serial monitor
  /*//Loop to change the brightness 
  if(Serial.available()){
  Serial.print(Serial.available());
  bRed = Serial.parseInt();
  bRed = bRed * 2.55;   //The user enters the brightness in percent, so I have to multiply his value by 2.55 to get a 8Bit-value
  //Serial.println(bRed);   //Prints the bit value to the monitor(Just for testing)
  analogWrite(ledRed, bRed);
  }*/

  //task 3
  //Change the brightness from 0% to 100% and back
/*//Loop to let the LED shine brighter and brighter
  for(bRed=0; bRed<=255; bRed++){
    analogWrite(ledRed, bRed);
    delay(10);
    }
  //Lopp to let the LED shine darker and darker
  for(bRed=255; bRed>=0; bRed--){
    analogWrite(ledRed, bRed);
    delay(10);
    }*/

  //task 4
  //Change the brighntess of the red LED from 0% to 100% while the green LED does the exact opposite
  //Loop to let the red LED shine brighter and brighter and the green LED does the opposite
  for(float i = 1; i<=255; i *= 1.1){
    analogWrite(ledRed, i);
    analogWrite(ledGreen, 255/i);
    delay(10);
    }
  //Loop to let the red LED shine darker and darker and the green LED does the opposite
  for(float i =255; i>=1; i/=1.1){
    analogWrite(ledRed, i);
    analogWrite(ledGreen, 255/i);
    delay(10);
    }
  
}

