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
int count_red1 = 0;
int count_yellow1 = 0;
int count_green1= 0;
int count_red2 = 0;
int count_yellow2 = 0;
int count_green2 = 0;
int time_pes = 5;
void init_traffic_light(){
	turnOffAllLed();
	status1 = RED1;
	status2 = GREEN2;
	count_red1 = count_red2 = time_red;
	count_yellow1 = count_yellow2 = time_yellow;
	count_green1 = count_green2 = time_green;
	counter = 0;
}
