/*
 * global.h
 *
 *  Created on: Dec 5, 2022
 *      Author: USER
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "setting_led.h"
#include "reading_button.h"
#include "traffic.h"
#include "stdint.h"

#define INIT				1
#define AUTOMATIC_MODE 		2
#define TUNING_MODE 		3
#define MANUAL_MODE 		4
#define PEDES_MODE			5

#define RED1				6
#define GREEN1				7
#define YELLOW1				8
#define RED2				9
#define GREEN2				10
#define YELLOW2				11

#define MANUAL_RED_MODE		12
#define MANUAL_YELLOW_MODE	13
#define MANUAL_GREEN_MODE	14

#define TUNING_RED_MODE		15
#define TUNING_YELLOW_MODE	16
#define TUNING_GREEN_MODE	17

int status; // status of all system
int count;  // count is used for scan led in MODIFY MODE
int counter;// counter is used for scan led in NORMAL MODE

#endif /* INC_GLOBAL_H_ */
