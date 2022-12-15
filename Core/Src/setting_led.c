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
	HAL_GPIO_WritePin(PORTA, TL1_A_Pin, 1);
	HAL_GPIO_WritePin(PORTB, TL1_B_Pin, 0);
}
void turnOnYellowLed1(){
	HAL_GPIO_WritePin(PORTA, TL1_A_Pin, 1);
	HAL_GPIO_WritePin(PORTB, TL1_B_Pin, 1);
}
void turnOnGreenLed1(){
	HAL_GPIO_WritePin(PORTA, TL1_A_Pin, 0);
	HAL_GPIO_WritePin(PORTB, TL1_B_Pin, 1);
}
void turnOffAllLed1(){
	HAL_GPIO_WritePin(PORTA, TL1_A_Pin, 0);
	HAL_GPIO_WritePin(PORTB, TL1_B_Pin, 0);
}
void turnOnRedLed2(){
	HAL_GPIO_WritePin(PORTB, TL2_A_Pin, 1);
	HAL_GPIO_WritePin(PORTB, TL2_B_Pin, 0);
}
void turnOnYellowLed2(){
	HAL_GPIO_WritePin(PORTB, TL2_A_Pin, 1);
	HAL_GPIO_WritePin(PORTB, TL2_B_Pin, 1);
}
void turnOnGreenLed2(){
	HAL_GPIO_WritePin(PORTB, TL2_A_Pin, 0);
	HAL_GPIO_WritePin(PORTB, TL2_B_Pin, 1);
}
void turnOffAllLed2(){
	HAL_GPIO_WritePin(PORTB, TL2_A_Pin, 0);
	HAL_GPIO_WritePin(PORTB, TL2_B_Pin, 0);
}
void turnOnPesRedLed(){
	HAL_GPIO_WritePin(PORTB, PL_A_Pin, 1);
	HAL_GPIO_WritePin(PORTB, PL_B_Pin, 0);
}
void turnOnPesGreenLed(){
	HAL_GPIO_WritePin(PORTB, PL_A_Pin, 0);
	HAL_GPIO_WritePin(PORTB, PL_B_Pin, 1);
}
void turnOffAllPesLed(){
	HAL_GPIO_WritePin(PORTB, PL_A_Pin, 0);
	HAL_GPIO_WritePin(PORTB, PL_B_Pin, 0);
}
void turnOffAllLed(){
	turnOffAllLed1();
	turnOffAllLed2();
	turnOffAllPesLed();
}
void BlinkyPesGreenLed(){
	HAL_GPIO_WritePin(PORTB, PL_A_Pin, 0);
	HAL_GPIO_TogglePin(PORTB, PL_B_Pin);
}
void BlinkyAllRedLed(){
	HAL_GPIO_TogglePin(PORTA, TL1_A_Pin);
	HAL_GPIO_WritePin(PORTB, TL1_B_Pin, 0);
	HAL_GPIO_TogglePin(PORTB, TL2_A_Pin);
	HAL_GPIO_WritePin(PORTB, TL2_B_Pin, 0);
}
void BlinkyAllYellowLed(){
	HAL_GPIO_TogglePin(PORTA, TL1_A_Pin);
	HAL_GPIO_TogglePin(PORTB, TL1_B_Pin);
	HAL_GPIO_TogglePin(PORTB, TL2_A_Pin);
	HAL_GPIO_TogglePin(PORTB, TL2_B_Pin);
}
void BlinkyAllGreenLed(){
	HAL_GPIO_WritePin(PORTA, TL1_A_Pin, 0);
	HAL_GPIO_TogglePin(PORTB, TL1_B_Pin);
	HAL_GPIO_WritePin(PORTB, TL2_A_Pin, 0);
	HAL_GPIO_TogglePin(PORTB, TL2_B_Pin);
}
