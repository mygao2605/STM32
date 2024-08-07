/*
 * stm32_gpio.c
 *
 *  Created on: Aug 7, 2024
 *      Author: TuNa
 */

#include "stm32_gpio.h"



void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t status){
	if (status == ENABLE){
		if(pGPIOx== GPIOA){
			GPIOA_PCCK_EN();
		}else if(pGPIOx== GPIOB){
			GPIOB_PCCK_EN();
		}else if(pGPIOx== GPIOC){
			GPIOC_PCCK_EN();
		}else if(pGPIOx== GPIOD){
			GPIOD_PCCK_EN();
		}else if(pGPIOx== GPIOE){
			GPIOE_PCCK_EN();
		}
	}else{
		//
	}
}

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<= GPIO_MODE_ANALOG){

	}else{

	}
}

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t status);
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
