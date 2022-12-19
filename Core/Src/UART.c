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
	if(status1 == RED1 && status2 == GREEN2){
		HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!RED1: %d  	GREEN2: %d#\r\n", count1, count2), 1000);
	}
	else if(status1 == RED1 && status2 == YELLOW2){
		HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!RED1: %d  	YELLOW2:%d#\r\n", count1, count2), 1000);
	}
	else if(status1 == RED2 && status2 == GREEN1){
		HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!GREEN1: %d  	RED2:%d#\r\n", count1, count2), 1000);
	}
	else if(status1 == RED2 && status2 == YELLOW1){
		HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!YELLOW1: %d  	RED2:%d#\r\n", count1, count2), 1000);
	}
}
void sendDATA_Manual(){
	if(status == MANUAL_MODE){
		if(status_manual == MANUAL_1){
			HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!P1:RED		P2:YELLOW#\r\n"), 1000);
		}
		else if(status_manual == MANUAL_2){
			HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!P1:RED		P2:GREEN#\r\n"), 1000);
		}
		else if(status_manual == MANUAL_3){
			HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!P1:YELLOW		P2:RED#\r\n"), 1000);
		}
		else if(status_manual == MANUAL_4){
			HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!P1:GREEN		P2:RED#\r\n"), 1000);
		}
	}
}
void sendVALUE_SETTING(){
	if(status == TUNING_MODE){
		if(status_tuning == TUNING_RED_MODE){
			HAL_UART_Transmit(&huart2, (void *)buffer_TX, sprintf (buffer_TX,"!TIME RED: %d#\r\n", time_red+counter), 1000);
		}
		else if(status_tuning == TUNING_YELLOW_MODE){
			HAL_UART_Transmit(&huart2, (void *)buffer_TX, sprintf (buffer_TX,"!TIME YELLOW: %d#\r\n", time_yellow+counter), 1000);
		}
		else if(status_tuning == TUNING_GREEN_MODE){
			HAL_UART_Transmit(&huart2, (void *)buffer_TX, sprintf (buffer_TX,"!TIME GREEN: %d#\r\n", time_green+counter), 1000);
		}
	}
}
