/*Serieller_Monitor.ino
 *Dieser Code lässt eine LED blinken.  
 *Die Pausen- und die Leuchtzeit kann vom User selbst eingegeben werden.
 *@author <Valentin Adlgasser>
 *@date <16-05-2018>
 *@version <1.0> 
 */
 
char mystr[10] = "Hello"; //String data

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
}

void loop() {
  Serial.write(mystr,5); //Write the serial data
  delay(1000);
}
