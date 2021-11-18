/*Serieller_Monitor.ino
 *Dieser Code lässt eine LED blinken.  
 *Die Pausen- und die Leuchtzeit kann vom User selbst eingegeben werden.
 *@author <Valentin Adlgasser>
 *@date <16-05-2018>
 *@version <1.0> 
 */

#define g1 13                           

int timer = 0;

void setup() {
pinMode(g1,OUTPUT);
Serial.begin(115200);
Serial.println("Bitte geben sie ihr Delay ein");
}

void loop() {
  if(Serial.available()>0){                     
    timer = Serial.parseInt();
  }
  
  digitalWrite(g1, HIGH);
  delay(timer);
  digitalWrite(g1, LOW);
  delay(timer);

 
} 
