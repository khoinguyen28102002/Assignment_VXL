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
	}
	switch (status_manual) {
		case MANUAL_0:
			if(status1 == RED1 && status2 == GREEN2){
				status_manual = MANUAL_2;
			}
			else if(status1 == RED1 && status2 == YELLOW2){
				status_manual = MANUAL_1;
			}
			else if(status1 == RED2 && status2 == GREEN1){
				status_manual = MANUAL_4;
			}
			else if(status1 == RED2 && status2 == YELLOW1){
				status_manual = MANUAL_3;
			}
		case MANUAL_1:
			turnOnRedLed1();
			turnOnYellowLed2();
			turnOnPesGreenLed();
			if(Button2IsPressed()){
				status_manual = MANUAL_2;
				turnOffAllLed();
			}
			break;
		case MANUAL_2:
			turnOnRedLed1();
			turnOnGreenLed2();
			turnOnPesGreenLed();
			if(Button2IsPressed()){
				status_manual = MANUAL_3;
				turnOffAllLed();
			}
			break;
		case MANUAL_3:
			turnOnRedLed2();
			turnOnYellowLed1();
			turnOnPesRedLed();
			if(Button2IsPressed()){
				status_manual = MANUAL_4;
				turnOffAllLed();
			}
			break;
		case MANUAL_4:
			turnOnRedLed2();
			turnOnGreenLed1();
			turnOnPesRedLed();
			if(Button2IsPressed()){
				status_manual = MANUAL_1;
				turnOffAllLed();
			}
			break;
		default:
			break;
	}
	if(Button3IsPressed()){
		status = AUTOMATIC_MODE;
		turnOffAllLed();
		setTimer2(100);
	}
}
