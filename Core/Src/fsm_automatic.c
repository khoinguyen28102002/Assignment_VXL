/*
 * traffic_auto.c
 *
 *  Created on: Dec 6, 2022
 *      Author: USER
 */

#include "fsm_automatic.h"
#include "global.h"

void fsm_automatic_run(){
	sendDATA();
	switch (status1) {
		case RED1:
			turnOnRedLed1();
			turnOnPesGreenLed();
			if(count1 <= 0){
				count1 = time_green;
				status1 = GREEN1;
				turnOffAllLed1();
			}
			sendDATA();
			break;
		case YELLOW1:
			turnOnYellowLed1();
			turnOffAllPesLed();
			if(count1 <= 0){
				count1 = time_red;
				status1 = RED1;
				turnOffAllLed1();
			}
			sendDATA();
			break;
		case GREEN1:
			turnOnGreenLed1();
			turnOnPesRedLed();
			if(count1 <= 0){
				count1 = time_yellow;
				status1 = YELLOW1;
				turnOffAllLed1();
			}
			sendDATA();
		default:
			break;
	}
	switch (status2) {
		case RED2:
			turnOnGreenLed2();
			if(count2 <= 0){
				count2 = time_green;
				status2 = GREEN2;
				turnOffAllLed2();
			}
			break;
		case YELLOW2:
			turnOnYellowLed2();
			if(count2 <= 0){
				count2 = time_red;
				status2 = RED2;
				turnOffAllLed2();
			}
			break;
		case GREEN2:
			turnOnGreenLed2();
			if(count2 <= 0){
				count2 = time_yellow;
				status2 = YELLOW2;
				turnOffAllLed2();
			}
			break;
		default:
			break;
	}
	count1--;
	count2--;
}

