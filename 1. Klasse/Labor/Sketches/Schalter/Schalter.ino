
void setup() {
  pinMode(6,INPUT);
  Serial.begin(9600);

}

void loop() {
  Serial.println(digitalRead(6));
  delay(100);
    
   

}
