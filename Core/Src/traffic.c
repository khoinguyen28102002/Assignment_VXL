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
int time_red = 8;
int time_yellow = 5;
int time_green = 3;
//initialize countdown value for each traffic light
int count1= 0;
int count2 = 0;
int time_pes = 5;
int count_ped_buzzer = 0;
void init_traffic_light(){
	turnOffAllLed();
	status1 = RED1;
	status2 = GREEN2;
	count1 = time_red;
	count2 = time_green;
	counter = 0;
}
