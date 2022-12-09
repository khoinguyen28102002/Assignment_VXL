/*
 * fsm_system.c
 *
 *  Created on: Dec 7, 2022
 *      Author: USER
 */


#include "global.h"
#include "fsm_system.h"
#include "reading_button.h"
#include "main.h"

void RunSystem(){
	switch (status) {
		case INIT:
			init_traffic_light();
			status = AUTOMATIC_MODE;
			break;
		case AUTOMATIC_MODE:
			if(Button1IsPressed()){ // If button1 is pressed, turn to MODIFY RED MODE status
				status = MANUAL_MODE;
				turnOffAllLed();
			}
			break;
		case MANUAL_MODE:
			if(Button1IsPressed()){ // If button1 is pressed, turn to MODIFY RED MODE status
				status = TUNING_MODE;
				turnOffAllLed();
			}
			break;
		case TUNING_MODE:
			if(Button1IsPressed()){ // If button1 is pressed, turn to MODIFY RED MODE status
				status = AUTOMATIC_MODE;
				turnOffAllLed();
			}
			break;
		case PEDES_MODE:
			count_red1 = time_red;
			count_yellow1 = time_yellow;
			int count_pes_buzzer = 0;
//			if(!(count_pes_buzzer%1000) && (count_pes_buzzer < time_red*1000)){
//				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, count_pes_buzzer/1000);
//			}else{
//				count_pes_buzzer++;
//			}
			break;
		default:
			break;
	}
}
