/*
 * fsm_tuning.c
 *
 *  Created on: Dec 14, 2022
 *      Author: USER
 */


#include "global.h"
#include "traffic.h"
#include "fsm_tuning.h"

void fsm_tuning_run(){
	switch (status_tuning) {
		case TUNING_RED_MODE:
			if(Button2IsPressed()){
				//increase time for red light (both sides)
				counter++;
			}
			// display on art


			if(timer3_flag){
				BlinkyAllRedLed();
				setTimer3(500);
			}
			if(Button1IsPressed()){
				status = TUNING_YELLOW_MODE;// if button1 is pressed, turn to TUNING YELLOW MODE
				counter = 0;
				setTimer3(500); // timer for blinky yellow led
				turnOffAllLed();
			}
			if(Button3IsPressed()){
				// if button3 is pressed, turn to NORMAL MODE
				time_red += counter;
				counter = 0;
				status = AUTOMATIC_MODE;
			}
			break;
		case TUNING_YELLOW_MODE:
			if(Button2IsPressed()){
				//increase time for red light (both sides)
				counter++;
			}
			// display on uart


			if(timer3_flag){
				BlinkyAllYellowLed();
				setTimer3(500);
			}
			if(Button1IsPressed()){
				status = TUNING_GREEN_MODE;// if button1 is pressed, turn to TUNING YELLOW MODE
				counter = 0;
				setTimer3(500); // timer for blinky yellow led
				turnOffAllLed();
			}
			if(Button3IsPressed()){
				// if button3 is pressed, turn to NORMAL MODE
				time_yellow += counter;
				counter = 0;
				status = AUTOMATIC_MODE;
			}
			break;
		case TUNING_GREEN_MODE:
			if(Button2IsPressed()){
				//increase time for red light (both sides)
				counter++;
			}
			// display on uart


			if(timer3_flag){
				BlinkyAllGreenLed();
				setTimer3(500);
			}
			if(Button1IsPressed()){
				status = TUNING_RED_MODE;// if button1 is pressed, turn to TUNING YELLOW MODE
				counter = 0;
				setTimer3(500); // timer for blinky yellow led
				turnOffAllLed();
			}
			if(Button3IsPressed()){
				// if button3 is pressed, turn to NORMAL MODE
				time_green += counter;
				counter = 0;
				status = AUTOMATIC_MODE;
			}
			break;
		default:
			break;
	}
}
