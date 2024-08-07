#ifdef STM32F10xxx_H_
#define STM32F10xxx_H_

// Step 1 : Configure the flash
#define FLASH_BASEADDR  
#define ROM_BASEADDR 
#define SRAM_BASEADDR 0x20000000U 

// Step 2: Configure the Periogeral base
#define PERIPH_BASEADDR 0x40000000U
#define APB1PERIPH_BASEADDR PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR 0x40010000U
#define AHBPERIPH_BASEADDR 0x40018000U

// Step 3: Configure the GPIO base
#define GPIOA_BASEADDR (APB2PERIPH_BASEADDR + 0x0800) // 0x4001 0800
#define GPIOB_BASEADDR (APB2PERIPH_BASEADDR + 0x0C00) // 0x4001 0C00
#define GPIOC_BASEADDR (APB2PERIPH_BASEADDR + 0x1000) // 0x4001 1000
#define GPIOD_BASEADDR (APB2PERIPH_BASEADDR + 0x1400) // 0x4001 1400
#define GPIOE_BASEADDR (APB2PERIPH_BASEADDR + 0x1800) // 0x4001 1800
#define GPIOF_BASEADDR (APB2PERIPH_BASEADDR + 0x1C00) // 0x4001 1C00
#define GPIOG_BASEADDR (APB2PERIPH_BASEADDR + 0x2000) // 0x4001 2000

// Step 4: Configure the RCC,EXTI and SYSCFG base
#define RCC_BASEADDR (AHBPERIPH_BASEADDR + 0x3000)    //RCC
#define EXTI_BASEADDR (APB2PERIPH_BASEADDR + 0x0400)  // EXTI
// #define EXTI_BASEADDR (APB2PERIPH_BASEADDR + 0x0400)  // SYSCFG

// Step 5: Configure the USART SPI I2C CAN base
#define UART2_BASEADDR (APB1PERIPH_BASEADDR + 0x4400) // UART 2
#define UART3_BASEADDR (APB1PERIPH_BASEADDR + 0x4800) // UART 3
#define UART4_BASEADDR (APB1PERIPH_BASEADDR + 0x4C00) // UART 4
#define UART5_BASEADDR (APB1PERIPH_BASEADDR + 0x5000) // UART 5

#define SPI2_BASEADDR (APB1PERIPH_BASEADDR + 0x3C00)  // SPI 2
#define SPI3_BASEADDR (APB1PERIPH_BASEADDR + 0x3800)  // SPI 3

#define I2C1_BASEADDR (APB1PERIPH_BASEADDR + 0x5800)  // I2C 1
#define I2C2_BASEADDR (APB1PERIPH_BASEADDR + 0x5400)  // I2C 2

#define bxCAN1_BASEADDR (APB1PERIPH_BASEADDR + 0x6400) // bxCAN 1
#define bxCAN2_BASEADDR (APB1PERIPH_BASEADDR + 0x6800) // bxCAN 2

// Step 6: GPIO_RegDef struct
typedef struct 
{
    /* data */
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BSR;
    volatile uint32_t LCKR;

}GPIO_RegDef_t;

// Step 7 GPIO
#define GPIOA ((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOF ((GPIO_RegDef_t *)GPIOF_BASEADDR)
#define GPIOG ((GPIO_RegDef_t *)GPIOG_BASEADDR)

// Step 8: RCC_RegDef struct
typedef struct 
{
    /* data */
    volatile uint32_t CR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t AHBENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t APB1ENR;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;

}RCC_RegDef_t;

#define RCC ((RCC_RegDef_t *)RCC_BASEADDR)

typedef struct 
{
    /* data */
    volatile uint32_t IMR;
    volatile uint32_t EMR;
    volatile uint32_t RTSR;
    volatile uint32_t FTSR;
    volatile uint32_t SWIER;
    volatile uint32_t PR;

}EXTI_RegDef_t;

#define EXTI ((EXTI_RegDef_t *)EXTI_BASEADDR)


typedef struct 
{
    /* data */
    volatile uint32_t CR;
    volatile uint32_t DR;
    volatile uint32_t BRR;
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t CR3;
    volatile uint32_t GTPR;

}UART_RegDef_t;


#define UART2 ((UART_RegDef_t *)UART2_BASEADDR) 
#define UART3 ((UART_RegDef_t *)UART3_BASEADDR) 
#define UART4 ((UART_RegDef_t *)UART4_BASEADDR)
#define UART5 ((UART_RegDef_t *)UART5_BASEADDR) 

typedef struct 
{
    /* data */
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t OAR1;
    volatile uint32_t OAR2;
    volatile uint32_t DR;
    volatile uint32_t SR1;
    volatile uint32_t SR2;
    volatile uint32_t CCR;
    volatile uint32_t TRISE;

}I2C_RegDef_t;

#define I2C1 ((I2C_RegDef_t *)I2C1_BASEADDR) 
#define I2C2 ((I2C_RegDef_t *)I2C2_BASEADDR)

typedef struct 
{
    /* data */
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t CRCPR;
    volatile uint32_t RXCRCR;
    volatile uint32_t TXCRCR;
    volatile uint32_t I2SCFGR;
    volatile uint32_t BDCR;
    volatile uint32_t I2SPR;

}SPI_RegDef_t;

#define SPI2 ((SPI_RegDef_t *)SPI2_BASEADDR) 
#define SPI3 ((I2C_RegDef_t *)SPI3_BASEADDR)

typedef struct 
{
    /* data */
    volatile uint32_t MCR;
    volatile uint32_t MSR;
    volatile uint32_t TSR;
    volatile uint32_t RF0R;
    volatile uint32_t RF1R;
    volatile uint32_t IER;
    volatile uint32_t ESR;
    volatile uint32_t TI0R;
    volatile uint32_t TDT0R;
    volatile uint32_t TDL0R;//
    volatile uint32_t TDH0R;
    volatile uint32_t TI1R;
    volatile uint32_t TDT1R;
    volatile uint32_t TDL1R;
    volatile uint32_t TDH1R;
    volatile uint32_t TI2R;
    volatile uint32_t TDT2R;
    volatile uint32_t TDL2R;
    volatile uint32_t TDH2R;
    volatile uint32_t RI0R;
    volatile uint32_t RDT0R;
    volatile uint32_t RDL0R;
    volatile uint32_t RDH0R;
    volatile uint32_t RI1R;
    volatile uint32_t RDT1R;
    volatile uint32_t RDL1R;
    volatile uint32_t RDH1R;
    volatile uint32_t FMR;
    volatile uint32_t FM1R;
    volatile uint32_t FS1R;
    volatile uint32_t FFA1R;
    volatile uint32_t FA1R;
    volatile uint32_t F0R1;
    volatile uint32_t F0R2;
    volatile uint32_t F1R1;
    volatile uint32_t F1R2;
    volatile uint32_t F27R1;
    volatile uint32_t F27R2;

}bxCAN_RegDef_t;


#endif // STM32F10xxx_H_
