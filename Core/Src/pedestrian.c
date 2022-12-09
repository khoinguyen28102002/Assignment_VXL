/*
 * pedestrian.c
 *
 *  Created on: Dec 7, 2022
 *      Author: USER
 */

#include "global.h"
#include "pedestrian.h"
#include "scheduler.h"

void pedestrian_run(){
	if(status == PEDES_MODE){
		turnOnPesGreenLed();
		count_red1--;
		uint32_t index;
		if(count_red1 == 5){
			index = SCH_Add_Task(BlinkyPesGreenLed, 0, 1000);
		}
		if(count_red1 == 0){
			turnOnPesRedLed();
			SCH_Remove_Task(index);
		}
	}
}
