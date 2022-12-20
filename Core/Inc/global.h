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

#define	RED1_GREEN2			6
#define	RED1_YELLOW2		7
#define GREEN1_RED2			8
#define YELLOW1_RED2		9

#define MANUAL_1			12
#define MANUAL_2			13
#define MANUAL_3			14
#define MANUAL_4			18
#define MANUAL_0			19

#define TUNING_RED_MODE		15
#define TUNING_YELLOW_MODE	16
#define TUNING_GREEN_MODE	17

#define	PEDES_0				27
#define	PEDES_1				28
#define	PEDES_2				29
#define	PEDES_3				30

int status; // status of all system
int preStatus;
int status_auto;
int status_manual;
int status_tuning;
int status_pedestrian;
int counter;
#endif /* INC_GLOBAL_H_ */
