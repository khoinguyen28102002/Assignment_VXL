/*
 * UART.c
 *
 *  Created on: Dec 15, 2022
 *      Author: Admin
 */

#include "UART.h"
#include "main.h"
#include "global.h"
#include "stdio.h"
void sendDATA(){
	switch (status_auto) {
		case RED1_GREEN2:
			HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!RED1: %d  	GREEN2: %d#\r\n", timeOfPhase1, timeOfPhase2), 1000);
			break;
		case RED1_YELLOW2:
			HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!RED1: %d  	YELLOW2:%d#\r\n", timeOfPhase1, timeOfPhase2), 1000);
			break;
		case GREEN1_RED2:
			HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!RED2: %d  	GREEN1:%d#\r\n", timeOfPhase1, timeOfPhase2), 1000);
			break;
		case YELLOW1_RED2:
			HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!RED2: %d  	YELLOW1:%d#\r\n", timeOfPhase1, timeOfPhase2), 1000);
			break;
		default:
			break;
	}
}
void sendDATA_Manual(){
	if(status == MANUAL_MODE){
		if(status_manual == MANUAL_1){
			HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!P1:GREEN		P2:RED#\r\n"), 1000);
		}
		else if(status_manual == MANUAL_2){
			HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!P1:YELLOW		P2:RED#\r\n"), 1000);
		}
		else if(status_manual == MANUAL_3){
			HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!P1:RED		P2:GREEN#\r\n"), 1000);
		}
		else if(status_manual == MANUAL_4){
			HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!P1:RED		P2:YELLOW#\r\n"), 1000);
		}
	}
}
void sendVALUE_SETTING(){
	if(status == TUNING_MODE){
		if(status_tuning == TUNING_RED_MODE){
			HAL_UART_Transmit(&huart2, (void *)buffer_TX, sprintf (buffer_TX,"!TIME RED: %d#\r\n", _time_red+counter), 1000);
		}
		else if(status_tuning == TUNING_YELLOW_MODE){
			HAL_UART_Transmit(&huart2, (void *)buffer_TX, sprintf (buffer_TX,"!TIME YELLOW: %d#\r\n", _time_yellow+counter), 1000);
		}
		else if(status_tuning == TUNING_GREEN_MODE){
			HAL_UART_Transmit(&huart2, (void *)buffer_TX, sprintf (buffer_TX,"!TIME GREEN: %d#\r\n", _time_green+counter), 1000);
		}
	}
}
