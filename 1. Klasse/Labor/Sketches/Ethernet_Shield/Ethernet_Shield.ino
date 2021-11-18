/* BlinkLed.ino
   In this program I read the value of a potentiometer and load it up to dweet.io
   @author <Valentin Adlgasser>
   @date <29-06-2018>
   @version <1.0> 
   */
   
#include <Ethernet.h>   //library for the ethernet shield
#include <SPI.h>    //also a library for the ethernet shield
#define potentio A0

int value = 0;
int connection;   //saves the state of the connection
unsigned char mac[] = { "HR911105Adlg" };   //saves a random mac-address
char server[] = {"dweet.io"};   //saves the servername
char buff[255];   //buffer for the URL
EthernetClient client;    //defines the variable client as EthernetClient

void setup() {

  Serial.begin(9600);
  Ethernet.begin(mac);    //starts the Ethernet connection
 
}

void loop() {
  delay(7000);
  client.stop();    //stops the connection
  value = analogRead(potentio);   //reads tha value of the potentiometer
  connection = (client.connect(server, 80));    //gets the connection-state
  sprintf(buff, "GET /dweet/for/krassmann?Zustand=%i HTTP/1.1", value);   //writes the value of the potentiometer to the string

  
 
    //if a connection is available print connected an write my data to dweet.io
    if(connection == 1){
      Serial.println("connected");
      client.println(buff);
      client.println();
      Serial.println(buff);    
      }
    else{
      Serial.println("connection lost");
      Serial.println(buff);
      }
    Serial.println(connection);   //print the state of the connection
    
}
