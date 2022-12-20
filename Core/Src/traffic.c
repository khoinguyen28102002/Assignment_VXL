/*
 * display_led.c
 *
 *  Created on: 2 thg 11, 2022
 *      Author: USER
 */

#include "traffic.h"
#include "global.h"
#include "main.h"

// initialize random time value for each traffic light
int _time_red = 20;
int _time_yellow = 5;
int _time_green = 15;

//initialize countdown value for each traffic light
int time_pes = 5;
int count_ped_buzzer = 0;
void init_traffic_light(){
	turnOffAllLed();
	time_red = _time_red;
	time_yellow = _time_yellow;
	time_green = _time_green;
	counter = 0;
}
