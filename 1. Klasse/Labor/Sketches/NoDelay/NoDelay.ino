/* NoDelay.ino
   In this program are 4 sketches, each does a different task, all of them run parallel and no delay is used
   @author <Valentin Adlgasser>
   @date <06-06-2018>
   @version <1.0> 
   */

#define task1 3
#define task2 5
#define task3 6
#define ledR 9
#define ledG 10




//Global Variables
//These variables have to be integers, if they're not the "for" loops don't work
int bRed = 0;   //integer that saves the brightness of the LEDs
int globalintervall = 1000;    //defines the global intervall
int globaltime = millis();    //defines the global clock
int globaltimeold = 0;    //defines the old global time
int globalFlag = 0;   //defines witch task was already done

void setup() {
//Only used for the second task
  Serial.begin(9600);
  Serial.println("Please enter the brightness of the LED in percent");
}

void loop() {
  if(globaltime - globaltimeold >= 1000 && globalFlag = 0){
    number1();
    globaltimeold = globaltime;
    globaltime = millis();
    globalFlag = 1;
    }  
  else if(globaltime - globaltimeold >= 1000 && globalFlag = 1){
    number2();
    globaltimeold = globaltime;
    globaltime = millis();
    globalFlag = 2;
    }
  else if(globaltime - globaltimeold >= 1000 && globalFlag = 2){
    number3();
    globaltimeold = globaltime;
    globaltime = millis();
    globalFlag = 3;
    } 
  else if(globaltime - globaltimeold >= 1000 && globalFlag = 3){
    number4();
    globaltimeold = globaltime;
    globaltime = millis();
    globalFlag = 0;
    } 
}

//Change the brightness between 20%, 50% and 75%
void number1() {

  //Variables for function number 1
  
  //stores the last time the time of task 1 was updated
  unsigned long previousMillis1 = 0;    //stores the previous time
  const int interval1 = 1000;   //stores the interval
  int task1State = 20;    //stores witch task was already done
  unsigned long currentMillis1 = millis();    //defines the clock for this function

    if(currentMillis1 - previousMillis1 >= interval1 && task1State == 20){
      previousMillis1 = currentMillis1;
      analogWrite(task1, (20*2.55));
      task1State = 50;
      currentMillis1 = millis();
      }
    else if(currentMillis1 - previousMillis1 >= interval1 && task1State == 50){
      previousMillis1 = currentMillis1;
      analogWrite(task1, (50*2.55));
      currentMillis1 = millis();
      }
    else if(currentMillis1 - previousMillis1 >= interval1 && task1State == 75){
      previousMillis1 = currentMillis1;
      analogWrite(task1, (75*2.55));
      task1State = 20;
      currentMillis1 = millis();
      }
}
  
//Change brightness on the serial monitor
void number2() {
  
  //Loop to change the brightness 
  if(Serial.available()){
      Serial.print(Serial.available());
      bRed = Serial.parseInt();
      bRed = bRed * 2.55;   //The user enters the brightness in percent, so I have to multiply his value by 2.55 to get a 8Bit-value
      //Serial.println(bRed);   //Prints the bit value to the monitor(Just for testing)
      analogWrite(task2, bRed);
      }
  }

//Change the brightness from 0% to 100% and back
void number3(unsigned long thisMillis) {

  //variables for function number 3

  #define UP 0
  #define DOWN 1
  const int minPWM = 0;
  const int maxPWM = 1;
  byte fadeDirection = UP;
  int fadeValue = 0;
  int fadeIncrement = 5;
  unsigned long previousFadeMillis;
  int fadeInterval = 50;

  if (thisMillis - previousFadeMillis >= fadeInterval) {
    // yup, it's time!
    if (fadeDirection == UP) {
      fadeValue = fadeValue + fadeIncrement;  
      if (fadeValue >= maxPWM) {
        // At max, limit and change direction
        fadeValue = maxPWM;
        fadeDirection = DOWN;
      }
    } else {
      //if we aren't going up, we're going down
      fadeValue = fadeValue - fadeIncrement;
      if (fadeValue <= minPWM) {
        // At min, limit and change direction
        fadeValue = minPWM;
        fadeDirection = UP;
      }
    }
    // Only need to update when it changes
    analogWrite(task3, fadeValue);  
 
    // reset millis for the next iteration (fade timer only)
    previousFadeMillis = thisMillis;
  }
}

/*//Change the brighntess of the red LED from 0% to 100% while the green LED does the exact opposite
void number4() {
    //Loop to let the red LED shine brighter and brighter and the green LED does the opposite
    for(float i = 1; i<=255; i *= 1.1){
      analogWrite(ledR, i);
      analogWrite(ledG, 255/i);
      delay(10);
      }
    //Loop to let the red LED shine darker and darker and the green LED does the opposite
    for(float i =255; i>=1; i/=1.1){
      analogWrite(ledR, i);
      analogWrite(ledG, 255/i);
      delay(10);
      }
  }*/

