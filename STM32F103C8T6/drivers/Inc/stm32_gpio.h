/*
 * stm32_gpio.h
 *
 *  Created on: Aug 7, 2024
 *      Author: TuNa
 */

#ifndef INC_STM32_GPIO_H_
#define INC_STM32_GPIO_H_
#include "stm32f10xx.h"

#define GPIO_Pin_No_0 0
#define GPIO_Pin_No_1 1
#define GPIO_Pin_No_2 2
#define GPIO_Pin_No_3 3
#define GPIO_Pin_No_4 4
#define GPIO_Pin_No_5 5
#define GPIO_Pin_No_6 6
#define GPIO_Pin_No_7 7
#define GPIO_Pin_No_8 8
#define GPIO_Pin_No_9 9
#define GPIO_Pin_No_10 10
#define GPIO_Pin_No_11 11
#define GPIO_Pin_No_12 12
#define GPIO_Pin_No_13 13
#define GPIO_Pin_No_14 14
#define GPIO_Pin_No_15 15

// Mode
#define GPIO_MODE_IN 0
#define GPIO_MODE_OUT 1
#define GPIO_MODE_ALTFN 2
#define GPIO_MODE_ANALOG 3


// TYPE
#define GPIO_OP_TYPE_PP 0
#define GPIO_OP_TYPE_OD 1

//SPEED
#define GPIO_SPEED_LOW 0
#define GPIO_SPEED_MEDIUM 1
#define GPIO_SPEED_FASR 2
#define GPIO_SPEED_HIGH 3

#define GPIO_NO_PUPD 0
#define GPIO_PIN_PU 1
#define GPIO_PIN_PO 2

#define GPIO_PIN_SET 1
#define GPIO_PIN_RESET 0

typedef struct{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOpType;
	uint8_t GPIO_PinAltFunMode;

}GPIO_PinConfig_t;
//
typedef struct{
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t status);
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);



#endif /* INC_STM32_GPIO_H_ */
