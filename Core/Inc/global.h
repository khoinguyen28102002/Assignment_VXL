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
#include "software_timer.h"
#include "UART.h"
#define INIT				255
#define AUTOMATIC_MODE 		254
#define TUNING_MODE 		253
#define MANUAL_MODE 		252
#define PEDES_MODE			251

#define	RED1				6
#define	GREEN1				7
#define YELLOW1				8
#define RED2				9
#define GREEN2				10
#define YELLOW2				11

#define MANUAL_1			12
#define MANUAL_2			13
#define MANUAL_3			14
#define MANUAL_4			18
#define MANUAL_0			19
#define TUNING_RED_MODE		15
#define TUNING_YELLOW_MODE	16
#define TUNING_GREEN_MODE	17

#define	PEDES_1				27
#define	PEDES_2				28
#define	PEDES_3				29
#define	PEDES_4				30

int status; // status of all system
int preStatus;
int count;  // count is used for scan led in MODIFY MODE
int counter;// counter is used for scan led in NORMAL MODE
char buffer_TX[50];
#endif /* INC_GLOBAL_H_ */
