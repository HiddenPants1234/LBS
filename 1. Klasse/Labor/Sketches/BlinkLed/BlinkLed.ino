/* BlinkLed.ino
   Dieser Sketch lässt zwei LEDs die auf PIN 1 und 4 angesteckt sind, abwechselnd blinken.
   @author <Valentin Adlgasser>
   @date <16-05-2018>
   @version <1.0> 
   */

#define ledRed 1                   //definiert PIN 1 als ledRot
#define ledGreen 4                 //definiert PIN 4 als ledGruen

int dtime = 0;                   //Variable für die Verzögerung in Millisekunden
int newdtime = 0;
int printdtime = 0;
int i = 0;                        //Variable "i" ist der Zähler für die For-Schleife


void setup() {
  pinMode(ledRed, OUTPUT);         //Definiert, dass der PIN ledRot ein Ausgang ist
  pinMode(ledGreen, OUTPUT);
  Serial.begin(9600);
      Serial.println("Aktuelle Pausenzeit: ");
   Serial.println(dtime); 
   Serial.println("Bitte neue Pausenzeit eingeben: ");
}


    
    
void loop() {
     if (Serial.available()){
      int newdtime = Serial.parseFloat();
   Serial.println("Neue Pausenzeit: ");
   Serial.println(newdtime);
    for (i=0; i<2; i++){ 
  digitalWrite(ledRed,LOW);
  delay(newdtime);
  digitalWrite(ledRed, HIGH);
  delay(newdtime);                      
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, HIGH);
  delay(newdtime);
  digitalWrite(ledGreen,LOW);
  } 

     }
   
  /*digitalWrite(ledRed, HIGH);
  delay(dtime);                      //delay Verzögert den Befehl in Millisekunden
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, HIGH);
  delay(dtime);
  digitalWrite(ledGreen,LOW);
  */


}
