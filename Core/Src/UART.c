/*
 * UART.c
 *
 *  Created on: Dec 15, 2022
 *      Author: Admin
 */

#include "UART.h"
void sendDATA(){
	if(timer4_flag){
			if(!count1)
			{
				HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!7SEG:%d:LIGHT1#\r\n", count1/100), 1000);
			}
			else
			{
				HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!7SEG:DELAY:LIGHT1#\r\n"), 1000);
			}

			if(!count2)
			{
				HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!7SEG:%d:LIGHT2#\r\n", count2/100), 1000);
			}
			else
			{
				HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!7SEG:DELAY:LIGHT2#\r\n"), 1000);
			}
			setTimer2(1000);  // 1s send data;
		}
}

void sendVALUE_SETTING(){
	HAL_UART_Transmit(&huart2, (void *)buffer_TX, sprintf (buffer_TX,"!RED:%d:YELLOW:%d:GREEN:%d#\r\n", time_red_1/1000, time_yellow_1/1000, time_green_1/1000), 1000);
}
