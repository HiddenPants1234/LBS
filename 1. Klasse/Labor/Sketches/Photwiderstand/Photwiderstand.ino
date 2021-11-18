#define Pin A0
#define blue 9
#define green 10
#define red 11

float sensorValue;

void setup() {
  pinMode(Pin, INPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(Pin);    //Saves the value of the PIN
  //190 = Light
  //18 = Dark
 RGBLed();

}

//Only used if theres an RGB-Led used
void RGBLed(){
  //This Part changes the color of the LED depending on the brightness
  if(sensorValue < 95){
    RGB(252,20,147);
    }
  if(sensorValue > 95){
    RGB(139,0,139);
    }

  //This Part changes what's printed on the Serial Monitor depending on the brightness
  if(sensorValue < 60){
    Serial.println("Dark");
    }
  if(sensorValue > 130){
    Serial.println("Bright");
    }
  if(sensorValue > 60 == sensorValue < 130){
    Serial.println("Dawn");
    }

   delay(1000);
}

//Only used if theres one normal LED
void LED(){
  //If it's dark turn the light on
  if(sensorValue < 60){
    analogWrite(blue, HIGH);
  }
  //If it's not dark turn the light off
  else{
    analogWrite(blue, LOW);
  }
}

//Function so I don't have to write digitalWrite all the time
void RGB(int r, int g, int b){
  digitalWrite(red, r);
  digitalWrite(green, g);
  digitalWrite(blue, b);
}
