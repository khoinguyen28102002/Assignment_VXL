/*
 * traffic_auto.c
 *
 *  Created on: Dec 6, 2022
 *      Author: USER
 */

#include "fsm_automatic.h"
#include "global.h"

void fsm_automatic_run(){
	switch (status_auto) {
		case GREEN1_RED2:
			turnOnRedLed2();
			turnOnGreenLed1();
			timeOfPhase1 = time_green;
			timeOfPhase2 = time_red;
			sendDATA();
			time_green--;
			time_red--;
			if(time_green <= 0){
				status_auto = YELLOW1_RED2;
			}
			break;
		case YELLOW1_RED2:
			turnOnYellowLed1();
			turnOnRedLed2();
			timeOfPhase1 = time_yellow;
			timeOfPhase2 = time_red;
			sendDATA();
			time_yellow--;
			time_red--;
			if(time_yellow <= 0 || time_red <= 0){
				time_green = _time_green;
				time_red = _time_red;
				time_yellow = _time_yellow;
				status_auto = RED1_GREEN2;
			}
			break;
		case RED1_GREEN2:
			turnOnRedLed1();
			turnOnGreenLed2();
			timeOfPhase1 = time_red;
			timeOfPhase2 = time_green;
			sendDATA();
			time_red--;
			time_green--;
			if(time_green <= 0){
				status_auto = RED1_YELLOW2;
			}
			break;
		case RED1_YELLOW2:
			turnOnRedLed1();
			turnOnYellowLed2();
			timeOfPhase1 = time_red;
			timeOfPhase2 = time_yellow;
			sendDATA();
			time_red--;
			time_yellow--;
			if(time_yellow <= 0 || time_red <= 0){
				time_green = _time_green;
				time_red = _time_red;
				time_yellow = _time_yellow;
				status_auto = GREEN1_RED2;
			}
			break;
		default:
			break;
	}
}

