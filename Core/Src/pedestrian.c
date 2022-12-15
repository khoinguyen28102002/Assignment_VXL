/*
 * pedestrian.c
 *
 *  Created on: Dec 7, 2022
 *      Author: USER
 */

#include "global.h"
#include "pedestrian.h"

void pedestrian_run(){
	if(status == PEDES_MODE){
//		uint32_t index;
		switch (status1) {
			case YELLOW1:
				if(count1 == 0){
					status1 = RED1;
					status2 = GREEN2;
					turnOnPesGreenLed();
					count1 = time_red;
				}
				else{
					turnOnYellowLed1();
					turnOnPesRedLed();
				}
				if(status2 != RED2){
					turnOnGreenLed2();
				}
				break;
			case RED1:
				if(count1 == time_yellow){
					if(timer3_flag == 1){
						BlinkyPesGreenLed();
						setTimer3(500);
					}
					turnOnYellowLed2();
				}
				if(count1 == 0){
					turnOnPesRedLed();
					status1 = GREEN1;
					status2 = RED2;
					count1 = time_green;
					count2 = time_red;
					status = AUTOMATIC_MODE;
				}
				else{
					turnOnRedLed1();
					turnOnGreenLed2();
				}
			default:
				break;
		}
		count1--;
	}
}
