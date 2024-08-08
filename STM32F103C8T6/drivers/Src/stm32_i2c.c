/*
 * stm32_i2c.c
 *
 *  Created on: Aug 8, 2024
 *      Author: TuNa
 */

#include <stm32_i2c.h>
#include <stm32f10xx.h>

void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t status){
	if(status==ENABLE){
		if(pI2Cx==I2C1){
			I2C1_PCCK_EN();
		}else if(pI2Cx==I2C2){
			I2C2_PCCK_EN();
		}
	}else{
		//TODO
	}
};
