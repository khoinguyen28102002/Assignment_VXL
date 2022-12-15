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
	switch (status_manual) {
		case MANUAL_1:
			turnOnRedLed1();
			turnOnYellowLed2();
			turnOffAllPesLed();
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
				status_manual = MANUAL_3;
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
	}
}
