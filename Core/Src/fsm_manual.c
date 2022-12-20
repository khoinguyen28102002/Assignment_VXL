/*
 * fsm_manual.c
 *
 *  Created on: Dec 14, 2022
 *      Author: USER
 */


#include "fsm_manual.h"
#include "global.h"
#include "traffic.h"

void fsm_manual_run(){
	if(timer3_flag){
		sendDATA_Manual();
		setTimer3(1000);
	}
	switch (status_manual) {
		case MANUAL_0:
			if(preStatus == GREEN1_RED2){
				status_manual = MANUAL_1;
			}
			else if(preStatus == YELLOW1_RED2){
				status_manual = MANUAL_2;
			}
			else if(preStatus == RED1_GREEN2){
				status_manual = MANUAL_3;
			}
			else if(preStatus == RED1_YELLOW2){
				status_manual = MANUAL_4;
			}
			break;
		case MANUAL_1:
			turnOnGreenLed1();
			turnOnRedLed2();
			if(Button2IsPressed()){
				status_manual = MANUAL_2;
			}
			break;
		case MANUAL_2:
			turnOnYellowLed1();
			turnOnRedLed2();
			if(Button2IsPressed()){
				status_manual = MANUAL_3;
			}
			break;
		case MANUAL_3:
			turnOnRedLed1();
			turnOnGreenLed2();
			if(Button2IsPressed()){
				status_manual = MANUAL_4;
			}
			break;
		case MANUAL_4:
			turnOnRedLed1();
			turnOnYellowLed2();
			if(Button2IsPressed()){
				status_manual = MANUAL_1;
			}
			break;
		default:
			break;
	}
	if(Button3IsPressed()){
		status = AUTOMATIC_MODE;
		status_manual = MANUAL_0;
		status_auto = preStatus;
		turnOffAllLed();
		setTimer2(100);
	}
}
