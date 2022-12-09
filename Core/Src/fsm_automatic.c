/*
 * traffic_auto.c
 *
 *  Created on: Dec 6, 2022
 *      Author: USER
 */

#include <fsm_automatic.h>
#include "global.h"

void fsm_automatic_run(){
	if(status == AUTOMATIC_MODE){
		// check the status of traffic lights in row
		switch (status1) {
			case RED1:
				turnOnRedLed1();
				// countdown and display on uart
				//	TODO
				break;
			case YELLOW1:
				turnOnYellowLed1();
				// countdown and display on uart
				// TODO
				break;
			case GREEN1:
				turnOnGreenLed1();
				// countdown and display on uart
				// TODO
			default:
				break;
		}
		// Check the status of traffic lights in column
		switch (status2) {
			case RED2:
				turnOnRedLed2();
				// countdown and display on uart
				// TODO
				break;
			case YELLOW2:
				turnOnYellowLed2();
				// countdown and display on uart
				// TODO
				break;
			case GREEN2:
				turnOnGreenLed2();
				// countdown and display on uart
				// TODO
				break;
			default:
				break;
		}

	}
}

