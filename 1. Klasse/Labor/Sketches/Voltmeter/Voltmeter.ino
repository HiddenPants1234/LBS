/* Voltmeter.ino
   This sketch measures the Volt of a battery and prints it on the Serial Monitor
   @author <Valentin Adlgasser>
   @date <13-06-2018>
   @version <1.0> 
   */
   
#define Pin A0

float sensorValue;
float volt1;
float volt;


void setup() {
  pinMode(Pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(Pin);    //Gets the value of the PIN but in 10 Bits
  //This part changes the Bit value to Volt
  volt1 = sensorValue*5;    
  volt = volt1/1024;
  
  //Print the result
  Serial.print("The battery has: ");
  Serial.print(volt);
  Serial.println(" Volt");
  
  delay(1000);

}
