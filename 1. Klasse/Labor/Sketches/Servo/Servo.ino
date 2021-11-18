/* Temperature.ino
   In this sketch you can control a servo-motor either by the serial-monitor or with a potentio-meter
   @author <Valentin Adlgasser>
   @date <21-06-2018>
   @version <1.0> 
   */
   

#include <Servo.h>    //library to use the commands for the servo-motor

#define potentio A0

Servo servo;    //define the servo motor as servo

int servoV = 0;   //integer that saves the value of the servo-motor
int value = 0;    //integer that saves the value of the potentio-meter

void setup() {
  servo.attach(8);    //defines on what pin the servo-motor is plugged in
  Serial.begin(9600);
  servo.write(0);   //says that the servo-motor starts at 0 degrees
  //Serial.println("Please write how many degrees the motor should turn");    //Only used if you use the function serial()
}

void loop() {
  value = analogRead(potentio);
  servoV = map(value, 0, 1023, 0, 180);   //maps the values of the potentio-meter to the servo-motor
  servo.write(servoV);    //turns the servo-motor to the defined degrees
  serial();
}

//function to control the servo-motor by the serial-monitor
void serial(){
  if(Serial.available()){
    servoV = Serial.parseInt();   //gets the value of the serial-monitor
    servo.write(servoV);    //turns the servo-motor to the written degrees
    }
}
