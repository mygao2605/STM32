/*
 * stm32_spi.h
 *
 *  Created on: Aug 8, 2024
 *      Author: TuNa
 */

#ifndef INC_STM32_SPI_H_
#define INC_STM32_SPI_H_
#include <stm32f10xx.h>


typedef struct{
	uint8_t SPI_DeviceMode; // Master or Slave
	uint8_t SPI_BusConfig;  //
	uint8_t SPI_SclkSpeed;  // Clock
	uint8_t SPI_DFF;        // Data 8 bit or 16 bit
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;

}SPI_Config_t;


// Mode
#define SPI_DEVICE_MODE_MASTER 1
#define SPI_DEVICE_MODE_SLAVE 0

//Bus Config
#define SPI_BUS_CONFIG_FD   		  1 //full duplex
#define SPI_BUS_CONFIG_HD 			  2 //half duplex
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY 3 //simple :only Read

//SCLK Clock Speed
#define SPI_SCLK_SPEED_DIV2			  0
#define SPI_SCLK_SPEED_DIV4			  1
#define SPI_SCLK_SPEED_DIV8			  2
#define SPI_SCLK_SPEED_DIV16		  3
#define SPI_SCLK_SPEED_DIV32		  4
#define SPI_SCLK_SPEED_DIV64		  5
#define SPI_SCLK_SPEED_DIV128		  6
#define SPI_SCLK_SPEED_DIV256		  7

//DFF : Data frame format
#define SPI_DFF_8bits				  0
#define SPI_DFF_16bits				  1

//CPOL
#define SPI_CPOL_LOW				  0
#define SPI_CPOL_HIGH				  1

//CPHA
#define SPI_CPHA_LOW				  0
#define SPI_CPHA_HIGH				  1

//SSM
#define SPI_SSM_DI					  0
#define SPI_SSM_EN					  1

typedef struct{
	SPI_RegDef_t *pSPIx;
	SPI_Config_t SPIConfig;
}SPI_Handle_t;


void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t status);
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

/*
 * Polling Mode
 */
void SPI_SendData(SPI_Handle_t *pSPIHandle,uint8_t *pTxBuffer, uint32_t size);
void SPI_ReceiveData(SPI_Handle_t *pSPIHandle,uint8_t *pRxBuffer, uint32_t size);

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



#endif /* INC_STM32_SPI_H_ */
