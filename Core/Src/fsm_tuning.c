/*
 * fsm_tuning.c
 *
 *  Created on: Dec 14, 2022
 *      Author: USER
 */


#include "global.h"
#include "traffic.h"
#include "fsm_tuning.h"

void fsm_tuning_run(){
	switch (status_tuning) {
		case TUNING_RED_MODE:
			turnOnRedLed1();
			turnOnRedLed2();
			if(Button2IsPressed()){
				counter++;
				sendVALUE_SETTING();
			}
			if(Button4IsPressed()){
				counter--;
				sendVALUE_SETTING();
			}
			if(Button1IsPressed()){
				status = TUNING_YELLOW_MODE;
				counter = 0;
				setTimer3(100);
				turnOffAllLed();
			}
			if(Button3IsPressed()){
				_time_red += counter;
				_time_yellow += (int) counter/3;
				_time_green += counter - ((int) counter/3);
				counter = 0;
				status = AUTOMATIC_MODE;
			}
			break;
		case TUNING_YELLOW_MODE:
			turnOnYellowLed1();
			turnOnYellowLed2();
			if(Button2IsPressed()){
				counter++;
				sendVALUE_SETTING();
			}
			if(Button4IsPressed()){
				counter--;
				sendVALUE_SETTING();
			}
			if(Button1IsPressed()){
				status = TUNING_GREEN_MODE;
				counter = 0;
				setTimer3(100);
				turnOffAllLed();
			}
			if(Button3IsPressed()){
				_time_yellow += counter;
				_time_red += counter*3;
				_time_green = _time_red - _time_yellow;
				counter = 0;
				status = AUTOMATIC_MODE;
			}
			break;
		case TUNING_GREEN_MODE:
			turnOnGreenLed1();
			turnOnGreenLed2();
			if(Button2IsPressed()){
				counter++;
				sendVALUE_SETTING();
			}
			if(Button4IsPressed()){
				counter--;
				sendVALUE_SETTING();
			}
			if(Button1IsPressed()){
				status = TUNING_RED_MODE;
				counter = 0;
				setTimer3(100);
				turnOffAllLed();
			}
			if(Button3IsPressed()){
				_time_green += counter;
				_time_yellow += (int) counter/2;
				_time_red = _time_green + _time_yellow;
				counter = 0;
				status = AUTOMATIC_MODE;
			}
			break;
		default:
			break;
	}
}
