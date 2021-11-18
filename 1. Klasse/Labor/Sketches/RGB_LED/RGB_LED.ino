/* RGB_Led.ino
   In this sketch you can choose what you want to do with a RGB-Led.
   There is a menu where you can choose what task should be done.
   @author <Valentin Adlgasser>
   @date <13-06-2018>
   @version <1.0> 
   */
   
#define blue 5
#define green 6
#define red 10
#define buttonY 3
#define buttonP 11

boolean yellow = HIGH;    //This two booleans save what button has been pressed
boolean pink = HIGH;    
boolean startMessage = LOW;   //Boolean that saves if the "menu" has already been printed
boolean task3Message = LOW;   //Boolean that save if the Message for task 3 has been printed

int task = 0;   //Saves what task should be done

String RGBtext;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(buttonY, INPUT_PULLUP);
  pinMode(buttonP, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  //Prints a "menu" from where you can choose which task should be done
  if(startMessage == LOW){
  Serial.println("Which task should be done?");
  Serial.println("Press 1 to let the LED change its color every second");
  Serial.println("Press 2 to change the color of the LED by pressing a button");
  Serial.println("Press 3 to change the color of the LED by writing the RGB values into the Serial Monitor");
  startMessage = HIGH;
  }

  if(Serial.available()){
    task = Serial.parseInt();
    Serial.println(task);
    }
  if(task == 1){
    Task1();
    }
  if(task == 2){
    Task2();
    }
  if(task == 3){
    Task3();
    }
  
}

//changes the color every second
void Task1(){
  RGB(255,0,0);
  delay(1000);
  RGB(0,255,0);
  delay(1000);
  RGB(0,0,255);
  delay(1000);
  }

//reads a button and then changes the color
void Task2(){
  yellow = digitalRead(buttonY);
  pink = digitalRead(buttonP);
  //if the button for the yellow light is pressed it changes the LED to yellow
  if(yellow == LOW && pink == HIGH){
    RGB(255,20,147);
    }
  //if the button for the pink light is pressed it changes the LED to pink
  if(pink == LOW && yellow == HIGH){
    RGB(252,0,210);
    }
  }

//lets the user change the color through the serial monitor
void Task3(){
  if(task3Message == LOW){
    Serial.println("Task 3 is still in the making and does not work right now");
    Serial.println("Please insert the values in this format:");
    Serial.println("R,G,B");
    task3Message = HIGH;
  }
  //This part should take a string from the serial monitor, cut it and print the parts, but it doesn't work right now
  if(Serial.available()){
    RGBtext = Serial.readString();
    }
  String delimiter[] = ",";
  String *ptr;

  ptr = strtok(RGBtext, delimiter);

  while(ptr != NULL){
    printf(ptr);
    ptr = strtok(NULL, delimiter);
    }
  }

//a little function so I don't have to typ in digitalWrite all the time
void RGB(int r,int g,int b){
  digitalWrite(red, r);
  digitalWrite(green, g);
  digitalWrite(blue, b);
  } 
