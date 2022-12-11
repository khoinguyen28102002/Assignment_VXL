/*
 * display_led.h
 *
 *  Created on: 2 thg 11, 2022
 *      Author: USER
 */

#ifndef INC_TRAFFIC_H_
#define INC_TRAFFIC_H_

// time buffer for each led
int time_red;
int time_yellow;
int time_green;
int time_ped;
// counter array for each led in row
int count1;
// counter array for each led in column
int count2;

int status1; // status of traffic light in row
int status2; // status of traffic light in column
void init_traffic_light();
#endif /* INC_TRAFFIC_H_ */
