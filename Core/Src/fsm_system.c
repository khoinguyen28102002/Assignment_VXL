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
			setTimer2(500);
			break;
		case AUTOMATIC_MODE:
			if(timer2_flag){
				fsm_automatic_run();
				setTimer2(1000);
			}
			if(Button1IsPressed()){
				status = MANUAL_MODE;
				turnOffAllLed();
			}
			if(PesButtonIsPressed()){
				count1 = time_red;
				status1 = YELLOW1;
				status = PEDES_MODE;
				setTimer2(500);
				setTimer3(time_yellow*1000);
				turnOffAllLed1();
			}
			break;
		case MANUAL_MODE:
			fsm_manual_run();
			if(Button1IsPressed()){
				status = TUNING_MODE;
//				setTimer2(1000);
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
