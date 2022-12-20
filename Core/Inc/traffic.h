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
// time set for led

int _time_red;
int _time_yellow;
int _time_green;
// counter array for each led in row
int timeOfPhase1;
// counter array for each led in column
int	timeOfPhase2;
// counter for pedestrian buzzer
int count_ped_buzzer;
void init_traffic_light();
#endif /* INC_TRAFFIC_H_ */
