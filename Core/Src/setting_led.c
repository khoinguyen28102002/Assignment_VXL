/*
 * setting_led.c
 *
 *  Created on: Dec 5, 2022
 *      Author: USER
 */



#include "main.h"
#include "setting_led.h"
void testLed(){
	HAL_GPIO_TogglePin(PORTA, LED_Pin);
}
void turnOnRedLed1(){
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, 1);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, 0);
}
void turnOnYellowLed1(){
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, 1);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, 1);
}
void turnOnGreenLed1(){
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, 0);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, 1);
}


void turnOnRedLed2(){
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, 1);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, 0);
}
void turnOnYellowLed2(){
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, 1);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, 1);
}
void turnOnGreenLed2(){
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, 0);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, 1);
}


void turnOnPesRedLed(){
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, 1);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, 0);
}
void turnOnPesGreenLed(){
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, 0);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, 1);
}
void turnOffPesLed(){
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, 0);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, 0);
}

void turnOffAllLed(){
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, 0);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin,0);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, 0);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin,0);
}
