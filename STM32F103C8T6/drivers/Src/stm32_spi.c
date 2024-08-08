/*
 * stm32_spi.c
 *
 *  Created on: Aug 8, 2024
 *      Author: TuNa
 */
#include <stm32_spi.h>
#include <stm32f10xx.h>


void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t status){
	if(status==ENABLE){
		if(pSPIx==SPI2){
			SPI2_PCCK_EN();
		}else if(pSPIx==SPI3){
			SPI3_PCCK_EN();
		}
	}else{
		//TODO
	}
};

void SPI_Init(SPI_Handle_t *pSPIHandle){
	SPI_PeriClockControl(pSPIHandle->pSPIx, ENABLE);
	uint32_t tempreg = 0;

	tempreg |= pSPIHandle->SPIConfig.SPI_DeviceMode << SPI_CR1_MSTR;

	if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD){
		tempreg &= ~(1<<SPI_CR1_BIDIMODE);
	}else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD){
		tempreg |= (1<<SPI_CR1_BIDIMODE);
	}else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY){
		tempreg &= ~(1<<SPI_CR1_BIDIMODE);
		tempreg |=  (1<<SPI_CR1_RXONLY);
	}




};
void SPI_DeInit(SPI_RegDef_t *pSPIx){

};

/*
 * Polling Mode
 */
void SPI_SendData(SPI_Handle_t *pSPIHandle,uint8_t *pTxBuffer, uint32_t size){

};
void SPI_ReceiveData(SPI_Handle_t *pSPIHandle,uint8_t *pRxBuffer, uint32_t size){

};

/*
 * Interrupt Mode
 */

uint8_t SPI_SendDataIT(SPI_Handle_t *pSPIHandle,uint8_t *pTxBuffer, uint32_t size);
uint8_t SPI_ReceiveDataIT(SPI_Handle_t *pSPIHandle,uint8_t *pRxBuffer, uint32_t size);
/*
 * DMA Mode
 */

uint8_t SPI_SendDataDMA(SPI_Handle_t *pSPIHandle,uint8_t *pTxBuffer, uint32_t size);
uint8_t SPI_ReceiveDataDMA(SPI_Handle_t *pSPIHandle,uint8_t *pRxBuffer, uint32_t size);

void SPI_TRQInterruptConfig();
void SPI_TRQPriorityConfig();
void SPI_TRQHandling();
