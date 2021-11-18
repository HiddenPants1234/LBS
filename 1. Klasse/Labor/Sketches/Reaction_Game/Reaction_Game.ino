/* Reaction_Game.ino
   In this sektch I programmed a reactiongame, in which a LED turns on and the player has to press a button as quickly after as he can.
    Playing process:
    1. Press the right button
    2. Green LED turns on
    3. Red LED turns on
    4. Press the left button
    5. Game starts all over 
   @author <Valentin Adlgasser>
   @date <24-05-2018>
   @version <1.0> 
   */


#define ledStart 2   //Start LED
#define switchStart 3    //Start Button
#define ledGame 13   //Game LED
#define switchGame 11    //Game Button

int buttonState = 0;    //Tracks the state of the button
int lastButtonState = 0;    //Used to detect if a button was pressed

boolean gameOn = false;   //Keeps track if a game is going on
boolean startButtonState = HIGH;   //State of the startbutton
boolean playerDone = false;   //Keeps track if the player has pushed a button
boolean startMsg = false;   //Keeps track if the start message has already been written

int randomTime = 0;
int startTime = 0;    //When did the game start
int endTime = 0;    //When did the player press the button
int finalTime = 0;    //Time between start end end of the game

void setup() {
  pinMode(switchStart, INPUT_PULLUP);
  pinMode(switchGame, INPUT_PULLUP);
  pinMode(ledStart, OUTPUT);
  pinMode(ledGame, OUTPUT);
  Serial.begin(9600);
  }

void loop() {
  //Print the star Message and set that the start message has been displayed
  if (startMsg == false){
    Serial.println(" ");
    Serial.println("Press the button on the right side to start the game");
    startMsg = true;
  }
 
   startButtonState = digitalRead(switchStart);   //Waits for the start button to be pressed
   
   //Start the game if the start button is pressed and there is no active game going on
   if(startButtonState == LOW && gameOn == false){
      RandomNumber();
      }
}

//RandomNumber generates a random delay before the Game LED starts to come on
void RandomNumber(){
  Serial.println(" ");
  Serial.println("GET READY");
  digitalWrite(ledStart, HIGH); // Turn the green LED on to indicate a game is about to start
  randomTime = random(0.5,5);   //Generates a random time between 0.5 and 5 seconds
  randomTime = randomTime * 1000;
  delay(randomTime);
  StartGame();  
  }

//Listen for the buttons to be pressed
void StartGame(){
  gameOn = true;
  startTime = millis();
  digitalWrite(ledGame, HIGH);
  
  //Listen for the game button to be pressed and set the game as done
  while(playerDone == false){
    buttonState = digitalRead(switchGame);
    if(buttonState == LOW && playerDone == false){
      endTime = millis();
      playerDone = true;
      }
    }
    EndGame();  
  }

//Ends the game and resets all functions to its original value
void EndGame(){
  digitalWrite(ledGame, LOW);
  finalTime = endTime - startTime;
  Serial.println("Your time was:");
  Serial.print(finalTime);   //prints the final time of the player
  Serial.println(" Milliseconds");
  delay(2000);
  digitalWrite(ledStart, LOW);
  digitalWrite(ledGame, LOW);

  //reset all variables to restart the game
  buttonState = 0;   
  lastButtonState = 0;   
  gameOn = false;   
  startButtonState = HIGH;   
  playerDone = false;   
  startMsg = false;   
  randomTime = 0;
  startTime = 0;    
  endTime = 0;  
  finalTime = 0;

  return;
  }


  
