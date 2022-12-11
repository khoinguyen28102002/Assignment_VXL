/*
 * fsm_system.c
 *
 *  Created on: Dec 7, 2022
 *      Author: USER
 */


#include "global.h"
#include "fsm_system.h"
#include "reading_button.h"
#include "main.h"

void RunSystem(){
	switch (status) {
		case INIT:
			init_traffic_light();
			status = AUTOMATIC_MODE;
			break;
		case AUTOMATIC_MODE:
			if(Button1IsPressed()){ // If button1 is pressed, turn to MODIFY RED MODE status
				status = MANUAL_MODE;
				turnOffAllLed();
			}
			if(Button4IsPressed()){
				status = PEDES_MODE;
				turnOffAllLed1();
			}
			break;
		case MANUAL_MODE:
			if(Button1IsPressed()){ // If button1 is pressed, turn to MODIFY RED MODE status
				status = TUNING_MODE;
				turnOffAllLed();
			}
			break;
		case TUNING_MODE:
			if(Button1IsPressed()){ // If button1 is pressed, turn to MODIFY RED MODE status
				status = AUTOMATIC_MODE;
				turnOffAllLed();
			}
			break;
		case PEDES_MODE:
			count1 = time_red;
			status1 = YELLOW1;
			break;
		default:
			break;
	}
}
