/*
 * setting_led.h
 *
 *  Created on: Dec 5, 2022
 *      Author: USER
 */

#ifndef INC_SETTING_LED_H_
#define INC_SETTING_LED_H_

#define PORTA	GPIOA
#define PORTB	GPIOB

void testLed();


void turnOnRedLed1();
void turnOnYellowLed1();
void turnOnGreenLed1();


void turnOnRedLed2();
void turnOnYellowLed2();
void turnOnGreenLed2();


void turnOnPesRedLed();
void turnOnPesGreenLed();
void turnOffPesLed();

void turnOffAllLed();

#endif /* INC_SETTING_LED_H_ */
