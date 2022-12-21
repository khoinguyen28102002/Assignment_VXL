/*
 * pedestrian.c
 *
 *  Created on: Dec 7, 2022
 *      Author: USER
 */

#include "global.h"
#include "pedestrian.h"

void pedestrian_run(){
		sendDATA();
		switch (status_pedestrian) {
			case PEDES_0:
				status_pedestrian = PEDES_1;
				status_auto = YELLOW1_RED2;
				time_yellow = _time_yellow;
				time_red = _time_red;
				break;
			case PEDES_1:
				turnOnYellowLed1();
				turnOnRedLed2();
				turnOnPesRedLed();
				timeOfPhase1 = time_yellow;
				timeOfPhase2 = time_yellow;
				sendDATA();
				time_yellow--;
				if(time_yellow <= 0){
					time_yellow = _time_yellow;
					time_red = _time_red;
					time_green = _time_green;
					status_auto = RED1_GREEN2;
					status_pedestrian = PEDES_2;
				}
				break;
			case PEDES_2:
				turnOnRedLed1();
				turnOnGreenLed2();
				turnOnPesGreenLed();
				timeOfPhase1 = time_red;
				timeOfPhase2 = time_green;
				sendDATA();
				time_green--;
				time_red--;
				if(time_green == 0){
					turnOffPesLed();
					time_green = _time_green;
					status_auto = RED1_YELLOW2;
					setTimer4(250);
					status_pedestrian = PEDES_3;
				}
				break;
			case PEDES_3:
				turnOnRedLed1();
				turnOnYellowLed2();
				timeOfPhase1 = time_red;
				timeOfPhase2 = time_yellow;
				sendDATA();
				time_red--;
				time_yellow--;
				if(time_yellow <= 0 || time_red <= 0){
					turnOffPesLed();
					time_red = _time_red;
					time_yellow = _time_yellow;
					time_green = _time_green;
					status_auto = GREEN1_RED2;
					timeOfPhase1 = time_green;
					timeOfPhase2 = time_red;
					status = AUTOMATIC_MODE;
				}
			default:
				break;
		}
}
