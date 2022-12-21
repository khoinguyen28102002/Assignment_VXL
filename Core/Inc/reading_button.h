/*
 * button.h
 *
 *  Created on: 5 thg 12, 2022
 *      Author: USER
 */

#ifndef INC_READING_BUTTON_H_
#define INC_READING_BUTTON_H_

#define PORTA	GPIOA
#define PORTB	GPIOB
#define NORMAL_STATE 					SET
#define PRESSED_STATE 					RESET
#define NUM_OF_BUTTON 					4
#define DURATION_FOR_AUTO_INCREASING 	300

int buttonBuffer[NUM_OF_BUTTON];
int counterForButtonPress3s[NUM_OF_BUTTON];
int flagForButtonPress3s[NUM_OF_BUTTON];
int button_flag[NUM_OF_BUTTON] ;


int isButtonPress(int index);
int Button1IsPressed();
int Button2IsPressed();
int Button3IsPressed();
int Button4IsPressed();
void ReadingButton();

#endif /* INC_READING_BUTTON_H_ */
