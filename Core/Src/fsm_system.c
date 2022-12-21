/*
 * fsm_system.c
 *
 *  Created on: Dec 7, 2022
 *      Author: USER
 */


#include "global.h"
#include "fsm_system.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"
#include "fsm_tuning.h"
#include "pedestrian.h"
#include "reading_button.h"
#include "main.h"

void RunSystem(){
	switch (status) {
		case INIT:
			init_traffic_light();
			status = AUTOMATIC_MODE;
			status_auto = GREEN1_RED2;
			setTimer2(100);
			break;
		case AUTOMATIC_MODE:
			if(timer2_flag == 1){
				fsm_automatic_run();
				setTimer2(1000);
			}
			if(Button1IsPressed()){
				preStatus = status_auto;
				turnOffAllLed();
				status = MANUAL_MODE;
				status_manual = MANUAL_0;
				setTimer3(100);
			}
			if(Button4IsPressed()){
				preStatus = status_auto;
				turnOffAllLed();
				status = PEDES_MODE;
				setTimer2(100);
			}
			break;
		case MANUAL_MODE:
			fsm_manual_run();
			if(Button1IsPressed()){
				status = TUNING_MODE;
				setTimer3(100);
				turnOffAllLed();
			}
			break;
		case TUNING_MODE:
			fsm_tuning_run();
			if(Button1IsPressed()){
				status = AUTOMATIC_MODE;
				turnOffAllLed();
			}
			break;
		case PEDES_MODE:
			if(timer2_flag){
				pedestrian_run();
				setTimer2(1000);
			}
			break;
		default:
			break;
	}
}
