/* Ultrasonic.ino
   In this sketch I used an ultrasonic-senosr to get meassure distances. Also a speaker is used make sounds like in a car
   and LEDs light up depending on the distance
   @author <Valentin Adlgasser>
   @date <20-06-2018>
   @version <1.0> 
   */

//These Pins are for the ultrasonci-sensor
#define echo 6
#define trigger 7

#define speaker 5
#define ledR 12
#define ledY 11
#define ledG 10

float timer = 0;    //Saves the data that comes back from the ultrasonic-senosr
float distance = 0;   //Saves the distance between an object an the sensor
float peep = 0;   //saves the delay for the speaker



void setup() {
  Serial.begin(9600);
  pinMode(echo, INPUT);   //Has to be an input beacause it gets data
  pinMode(trigger, OUTPUT);   //Hast to be an output because it sends ultrasonic-waves
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(speaker, OUTPUT);   //Has to be an output because a speaker has to output sounds
}

void loop() {
  digitalWrite(trigger, LOW);   //Turn the ultrasonic-sender off to get no background noises
  delay(5);
  digitalWrite(trigger, HIGH);    //Turn the ultrasonic-sender on an send waves for 10 milliseconds
  delay(10);
  digitalWrite(trigger, LOW);

  timer = pulseIn(echo, HIGH);    //gets the data of the sensor
  distance = (timer/2) * 0.0342;    //a little calculation to change the data from the sensor to centimeters

  //Sometimes the sensor gets wrong values, but with this loop I stoped it
  if(distance > 1000){
    distance = 0;
    }
    
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  Speaker();
  led();


}

//Function to let the speaker sound
void Speaker(){
  
  peep = map(distance, 0, 49, 1, 500);    //Map-function to change the distance into a millisecond value

  //If the distance is bigger than 49cm, turn the speaker off
  if(distance > 49){
    digitalWrite(speaker, LOW);
    }
  //Loop to turn the Speaker on an off everytime
  if(distance <= 49 && distance > 2){
     digitalWrite(speaker, HIGH);
     delay(50);
     digitalWrite(speaker,LOW);
     delay(peep);
    }
  //If the distance is under 2cm turn the speaker on fulltime
  if(distance <= 2){
    digitalWrite(speaker, HIGH);
    }
}

//Function to turn the LEDs on an off
void led(){
    if(distance >= 100){
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, HIGH);
    }
  if(distance < 100 && distance >= 50){
    digitalWrite(ledG, LOW);
    digitalWrite(ledR, LOW);
    digitalWrite(ledY, HIGH);
    }
  if(distance < 50){
    digitalWrite(ledY, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledR, HIGH);
    } 
}
