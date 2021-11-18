
#include <iostream>
#include <wiringPi.h>
#include <lirc/lirc_client.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define red 27
#define green 28
#define blue 29

//function to change the RGB-lighting
void RGB(int r, int g, int b) {
	digitalWrite(red, r);
	digitalWrite(green, g);
	digitalWrite(blue, b);	
}

int main(void) {
	struct lirc_config *config; //struct for the lirc-config

        int buttonTimer = millis(); //timer, because the remote-buttons need a cooldown-phase
        char *code;
        char *c;

        if (wiringPiSetup () == -1)
            exit (1) ;

        pinMode (red, OUTPUT);
        pinMode (green, OUTPUT);
        pinMode (blue, OUTPUT);
 
        //Initiate lirc, if theres a failure: exit
        if(lirc_init("lirc",1)==-1)
                exit(EXIT_FAILURE);
 
        //read the default config for the remote
        if(lirc_readconfig(NULL,&config,NULL)==0)
        {
                //while the lirc-socket is open do some stuff
                while(lirc_nextcode(&code)==0)
                {
                        //If code = NULL, that means that nothing was returned from the lirc-socket, if nothing returns it skips the lines
                        if(code==NULL) continue;{
                                //Make sure there is a 400ms gap before detecting button presses.
                                if (millis() - buttonTimer  > 400){
                                        //Check to see if the string "KEY_1" appears in the code and change the led accordingly
                                        if(strstr (code,"KEY_1")){
                                                RGB(0,0,255);
                                                buttonTimer = millis();
                                        }
                                        else if(strstr (code,"KEY_2")){
                                                RGB(0,255,0);
                                                buttonTimer = millis();
                                        }
                                        else if(strstr (code,"KEY_3")){
                                                RGB(255,0,0);
                                                buttonTimer = millis();
                                        }
                                }
                        }
                        //Need to free up code before the next loop
                        free(code);
                }
                //Frees the data structures associated with config.
                lirc_freeconfig(config);
        }
        //lirc_deinit() closes the connection to lircd and does some internal clean-up stuff.
        lirc_deinit();
        exit(EXIT_SUCCESS);

	return 0;
}

