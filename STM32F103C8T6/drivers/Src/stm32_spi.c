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

	tempreg |=pSPIHandle->SPIConfig.SPI_SclkSpeed << SPI_CR1_BR;
	tempreg |=pSPIHandle->SPIConfig.SPI_SclkSpeed << SPI_CR1_DFF;
	tempreg |=pSPIHandle->SPIConfig.SPI_SclkSpeed << SPI_CR1_CPOL;
	tempreg |=pSPIHandle->SPIConfig.SPI_SclkSpeed << SPI_CR1_CPHA;
	tempreg |=pSPIHandle->SPIConfig.SPI_SclkSpeed << SPI_CR1_SSM;

	pSPIHandle->pSPIx->CR1= tempreg;

};
void SPI_DeInit(SPI_RegDef_t *pSPIx){

};

uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName){
	if(pSPIx->SR&FlagName){
		return FLAG_SET;
	}
	return FLAG_RESET;
};



/*
 * Polling Mode
 */
void SPI_SendData(SPI_RegDef_t *pSPIx ,uint8_t *pTxBuffer, uint32_t len){
	while(len>0){
		while(SPI_GetFlagStatus(pSPIx,SPI_TXE_FLAG)== FLAG_RESET);
		if(pSPIx->CR1 & (1<<SPI_CR1_DFF))
		{
			pSPIx->DR = *((uint16_t*)pTxBuffer);
			len--;
			len--;
			(uint16_t*)pTxBuffer++;
		}else{
			pSPIx->DR = *pTxBuffer;
			len--;
			pTxBuffer++;
		}
	}

};
void SPI_ReceiveData(SPI_RegDef_t *pSPIx,uint8_t *pRxBuffer, uint32_t len){
	while(len>0){
			while(SPI_GetFlagStatus(pSPIx,SPI_RXNE_FLAG)== FLAG_RESET);
			if(pSPIx->CR1 & (1<<SPI_CR1_DFF))
			{
				*((uint16_t*)pRxBuffer)=pSPIx->DR;
				len--;
				len--;
				(uint16_t*)pRxBuffer++;
			}else{
				*pRxBuffer=pSPIx->DR ;
				len--;
				pRxBuffer++;
			}
		}
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
