/*
 * stm32_uart.c
 *
 *  Created on: Aug 8, 2024
 *      Author: TuNa
 */

#include <stm32_uart.h>
#include <stm32f10xx.h>


void UART_PeriClockControl(UART_RegDef_t *pUARTx, uint8_t status){
	if(status==ENABLE){
		if(pUARTx==UART2){
			UART2_PCCK_EN();
		}else if(pUARTx==UART3){
			UART3_PCCK_EN();
		}else if(pUARTx==UART4){
			UART4_PCCK_EN();
		}else if(pUARTx==UART5){
			UART5_PCCK_EN();
		}
	}else{
		//TODO
	}
};
