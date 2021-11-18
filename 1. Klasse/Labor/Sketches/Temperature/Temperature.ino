/* Temperature.ino
   This sketch gets the temperature via an external thermometer and turns two LEDs on depending on the temperature
   @author <Valentin Adlgasser>
   @date <07-06-2018>
   @version <1.0> 
   */



#define ledR 2
#define ledG 7
  
  int pin = A5;   //input number A5 is now the input pin
  int sensor = 0;   //saves the data that come from the thermometer
  int temperature = 0;    //saves the temperature
  int interval = 1000;   //is the delay in which the thermometer scans the temperature


void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, LOW);
  sensor = analogRead(pin);  //reads the data of the thermometer 
  temperature = map(sensor, 0, 410, -50, 150);    //changes the data from the thermometer to degrees
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  //loop to turn on the red led if the degrees are over 30°C
  if(temperature > 30){
    digitalWrite(ledR, HIGH);
    }
  //loop to turn on the green led if the degrees are under 30°C
  else{
    digitalWrite(ledG, HIGH);
    }

  delay(interval);
}
