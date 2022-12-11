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
int time_red = 0;
int time_yellow = 0;
int time_green = 0;

//initialize countdown value for each traffic light
int count1= 0;
int count2 = 0;
int time_pes = 5;
void init_traffic_light(){
	turnOffAllLed();
	status1 = RED1;
	status2 = GREEN2;
	count1 = time_red;
	count2 = time_green;
	counter = 0;
}
