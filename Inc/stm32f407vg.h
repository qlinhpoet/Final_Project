/*
 * stm32f407vg_driver.h
 *
 *  Created on: Oct 18, 2021
 *      Author: Linh
 *      modify : Nov ,20 : add GPIO_JobResultType     Huy
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>
#define __IO volatile
#include <driver/stm32f407_rcc_driver.h>
#include <driver/stm32f407_gpio_driver.h>
#include <driver/stm32f407_usart_driver.h>
#include "../../Final_Project/Inc/driver/stm32f407_can_driver.h"

#define FLS_INTERNAL_SECTORS_CONFIGURED STD_ON

/** @addtogroup Exported_macro
  * @{
  */
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

/*
*	Config struct for EXTI
*/
typedef struct
{
	__IO uint32_t IMR;
	__IO uint32_t EMR;
	__IO uint32_t RTSR;
	__IO uint32_t FTSR;
	__IO uint32_t SWIER;
	__IO uint32_t PR;
}EXTI_RegDef_t;



/*
*	Some generic marcos
*/
#define ENABLE			1
#define DISABLE			0
#define SET				1
#define RESET			0
#define GPIO_PIN_SET 	1
#define GPIO_PIN_RESET 	0
#define STD_OFF      	0x00
#define STD_ON      	0x01
#define FALSE 			0
#define TRUE 			1



typedef enum
{
	Reset = 0,
	Set = 1
}Flag_Status;


typedef enum
{
	false = 0,
	true
}bool;

typedef enum
{
  HAL_UNLOCKED = 0x00U,
  HAL_LOCKED   = 0x01U
} HAL_LockTypeDef;

typedef bool boolean;

/*
 * ARM Cortex Mx Processor NVIC ISERx register Addresses
 */

#define NVIC_ISER0			((__IO uint32_t*)0xE000E100)
#define NVIC_ISER1			((__IO uint32_t*)0xE000E104)
#define NVIC_ISER2			((__IO uint32_t*)0xE000E108)
#define NVIC_ISER3			((__IO uint32_t*)0xE000E10C)
#define NVIC_ISER4			((__IO uint32_t*)0xE000E110)



/*
 * ARM Cortex Mx Processor NVIC ICERx register Addresses
 */
#define NVIC_ICER0 			((__IO uint32_t*)0xE000E180)
#define NVIC_ICER1 			((__IO uint32_t*)0xE000E184)
#define NVIC_ICER2 			((__IO uint32_t*)0xE000E188)
#define NVIC_ICER3 			((__IO uint32_t*)0xE000E18C)
#define NVIC_ICER4 			((__IO uint32_t*)0xE000E190)


/*
 * ARM Cortex Mx Processor Interrupt Priority Register Address Calculation
 */
#define NVIC_IPR_BASE_ADDR 	((__IO uint32_t*)0xE000E400)

/*
 * ARM Cortex Mx Processor number of priority bits implemented in Priority Register
 */
#define NO_PR_BITS_IMPLEMENTED  4

/*
*   base address of FLASH and SRAM memory
*/
#define FLASH_BASEADDRESS   0x08000000U
#define SRAM1_BASEADDRESS   0x20000000U
#define SRAM2_BASEADDRESS   0x2001C000U
#define ROM_BASEADDRESS     0x1FFF0000U                     /*System Memory*/
#define SRAM_BASEADDRESS    SRAM1_BASEADDRESS

/*
*   AHBx and APBx Bus Peripheeral base addresses
*/
#define PERIPH_BASE         0X40000000u
#define APB1PERIPH_BASE     0X40000000U
#define APB2PERIPH_BASE     0X40010000U
#define AHP1PERIPH_BASE     0X40020000U
#define AHP2PERIPH_BASE     0X50000000U


/*
*  BASE_ADDRESS of peripherals which are hanging on AHB1 bus
*/
#define GPIOA_BASEADDRESS   (AHP1PERIPH_BASE + 0X0000U)
#define GPIOB_BASEADDRESS   (AHP1PERIPH_BASE + 0X0400U)
#define GPIOC_BASEADDRESS   (AHP1PERIPH_BASE + 0X0800U)
#define GPIOD_BASEADDRESS   (AHP1PERIPH_BASE + 0X0C00U)
#define GPIOE_BASEADDRESS   (AHP1PERIPH_BASE + 0X1000U)
#define GPIOF_BASEADDRESS   (AHP1PERIPH_BASE + 0X1400U)
#define GPIOG_BASEADDRESS   (AHP1PERIPH_BASE + 0X1800U)
#define GPIOH_BASEADDRESS   (AHP1PERIPH_BASE + 0X1C00U)
#define GPIOI_BASEADDRESS   (AHP1PERIPH_BASE + 0X2000U)
#define GPIOJ_BASEADDRESS   (AHP1PERIPH_BASE + 0X2400U)
#define GPIOK_BASEADDRESS   (AHP1PERIPH_BASE + 0X2800U)
#define CRC_BASEADDRESS     (AHP1PERIPH_BASE + 0x3000U)
#define RCC_BASEADDRESS     (AHP1PERIPH_BASE + 0X3800U)
#define Flash_Interface_ADDR    (AHP1PERIPH_BASE + 0x3C00U)
#define BKPSRAM_BASEADDRESS (AHP1PERIPH_BASE + 0x4000U)
#define DMA1_BASEADDRESS    (AHP1PERIPH_BASE + 0x6000U)
#define DMA2_BASEADDRESS    (AHP1PERIPH_BASE + 0x6400U)

#define FLASH_R_BASE          (AHP1PERIPH_BASE + 0x3C00UL)



/*
*  BASE_ADDRESS of peripherals which are hanging on AHB2 bus
*/




/*
*  BASE_ADDRESS of peripherals which are hanging on APB2 bus
*/
#define EXTI_BASEADDRESS		(APB2PERIPH_BASE + 0X3C00)



/*
*  BASE_ADDRESS of peripherals which are hanging on APB2 bus
*/
#define TIM2_BASEADDRESS		(APB2PERIPH_BASE)
#define TIM3_BASEADDRESS		(APB2PERIPH_BASE + 0X0400)
#define TIM4_BASEADDRESS		(APB2PERIPH_BASE + 0X0800)
#define TIM5_BASEADDRESS		(APB2PERIPH_BASE + 0X0C00)
#define TIM6_BASEADDRESS		(APB2PERIPH_BASE + 0X1000)
#define TIM7_BASEADDRESS		(APB2PERIPH_BASE + 0X1400)
#define TIM12_BASEADDRESS		(APB2PERIPH_BASE + 0X1800)
#define TIM13_BASEADDRESS		(APB2PERIPH_BASE + 0X1C00)
#define TIM14_BASEADDRESS		(APB2PERIPH_BASE + 0X2000)
#define RTCnBKP_BASEADDRESS		(APB2PERIPH_BASE + 0X2800)
#define WWDG_BASEADDRESS		(APB2PERIPH_BASE + 0X2C00)
#define IWDG_BASEADDRESS		(APB2PERIPH_BASE + 0X3000)
#define I2S2ext_BASEADDRESS		(APB2PERIPH_BASE + 0X3400)
#define SPI2I2S2_BASEADDRESS		(APB2PERIPH_BASE + 0X3800)
#define SPI3I2S3_BASEADDRESS		(APB2PERIPH_BASE + 0X3C00)
#define I2S3ext_BASEADDRESS		(APB2PERIPH_BASE + 0X4000)
#define USART2_BASEADDRESS		(APB2PERIPH_BASE + 0X4400)
#define USART3_BASEADDRESS		(APB2PERIPH_BASE + 0X4800)
#define UART4_BASEADDRESS		(APB2PERIPH_BASE + 0X4C00)
#define I2C1_BASEADDRESS		(APB2PERIPH_BASE + 0X5400)
#define I2C2_BASEADDRESS		(APB2PERIPH_BASE + 0X5800)
#define I2C3_BASEADDRESS		(APB2PERIPH_BASE + 0X5C00)
#define CAN1_BASEADDRESS		(APB1PERIPH_BASE + 0X6400)
#define CAN2_BASEADDRESS		(APB2PERIPH_BASE + 0X6800)
#define PWR_BASEADDRESS			(APB2PERIPH_BASE + 0X7000)
#define DAC_BASEADDRESS			(APB2PERIPH_BASE + 0X7400)
#define UART7_BASEADDRESS		(APB2PERIPH_BASE + 0X7800)
#define UART8_BASEADDRESS		(APB2PERIPH_BASE + 0X7C00)


#define UART5_BASEADDRESS            (APB1PERIPH_BASE + 0x5000UL)





/*
*   PERIPHERAL definition
*/
#define GPIOA       ((GPIO_RegDef_t*)GPIOA_BASEADDRESS)
#define GPIOB       ((GPIO_RegDef_t*)GPIOB_BASEADDRESS)
#define GPIOC       ((GPIO_RegDef_t*)GPIOC_BASEADDRESS)
#define GPIOD       ((GPIO_RegDef_t*)GPIOD_BASEADDRESS)
#define GPIOE       ((GPIO_RegDef_t*)GPIOE_BASEADDRESS)
#define GPIOF       ((GPIO_RegDef_t*)GPIOF_BASEADDRESS)
#define GPIOG       ((GPIO_RegDef_t*)GPIOG_BASEADDRESS)
#define GPIOH       ((GPIO_RegDef_t*)GPIOH_BASEADDRESS)
#define GPIOI       ((GPIO_RegDef_t*)GPIOI_BASEADDRESS)
#define GPIOJ       ((GPIO_RegDef_t*)GPIOJ_BASEADDRESS)
#define GPIOK       ((GPIO_RegDef_t*)GPIOK_BASEADDRESS)

#define RCC         ((RCC_RegDef_t *)(RCC_BASEADDRESS))

#define EXTI				((EXTI_RegDef_t *)(EXTI_BASEADDRESS))

#define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)

#define UART5               ((USART_RegDef_t *) UART5_BASEADDRESS)

#define CAN1                ((CAN_TypeDef *) CAN1_BASEADDRESS)
/*
*   Clock enable marcro for GPIOx peripheral
*/
#define GPIOA_PCLK_EN()     ((((RCC_RegDef_t*)RCC_BASEADDRESS)->AHB1ENR) |= 1<<0)
#define GPIOB_PCLK_EN()     ((((RCC_RegDef_t*)RCC_BASEADDRESS)->AHB1ENR) |= 1<<1)
#define GPIOC_PCLK_EN()     ((((RCC_RegDef_t*)RCC_BASEADDRESS)->AHB1ENR) |= 1<<2)
#define GPIOD_PCLK_EN()     ((((RCC_RegDef_t*)RCC_BASEADDRESS)->AHB1ENR) |= 1<<3)
#define GPIOE_PCLK_EN()     ((((RCC_RegDef_t*)RCC_BASEADDRESS)->AHB1ENR) |= 1<<4)
#define GPIOF_PCLK_EN()     ((((RCC_RegDef_t*)RCC_BASEADDRESS)->AHB1ENR) |= 1<<5)
#define GPIOG_PCLK_EN()     ((((RCC_RegDef_t*)RCC_BASEADDRESS)->AHB1ENR) |= 1<<6)
#define GPIOH_PCLK_EN()     ((((RCC_RegDef_t*)RCC_BASEADDRESS)->AHB1ENR) |= 1<<7)
#define GPIOI_PCLK_EN()     ((((RCC_RegDef_t*)RCC_BASEADDRESS)->AHB1ENR) |= 1<<8)

/*
*   Clock disable marcro for GPIOx peripheral
*/
#define GPIOA_PCLK_DIS()     (RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DIS()     (RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DIS()     (RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DIS()     (RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DIS()     (RCC->AHB1ENR &= ~(1<<4))
#define GPIOF_PCLK_DIS()     (RCC->AHB1ENR &= ~(1<<5))
#define GPIOG_PCLK_DIS()     (RCC->AHB1ENR &= ~(1<<6))
#define GPIOH_PCLK_DIS()     (RCC->AHB1ENR &= ~(1<<7))
#define GPIOI_PCLK_DIS()     (RCC->AHB1ENR &= ~(1<<8))

/*
 *  Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOF_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0)
#define GPIOG_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); }while(0)
#define GPIOH_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0)
#define GPIOI_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8)); }while(0)


/**
* @brief    : GPIO job return status
*/
typedef enum
{
    GPIO_JOB_OK = 0,               /**< @brief The job has been finished succesfully */
    GPIO_JOB_FAILED,               /**< @brief The job has not been finished succesfully */
	GPIO_JOB_PENDING,              /**< @brief The job has not yet been finished */
	GPIO_JOB_CANCELED,             /**< @brief The job has been canceled */
	GPIO_BLOCK_INCONSISTENT,       /**< @brief The requested block is inconsistent, it may contain corrupted data */
	GPIO_BLOCK_INVALID             /**< @brief The requested block has been marked as invalid, the requested operation can not be performed */
}GPIO_JobResultType;

/*						FLASH					*/

/**
* @brief    : : FLASH job return status
*/

typedef enum
{
    FLS_JOB_OK = 0,               /**< @brief The job has been finished succesfully */
    FLS_JOB_FAILED,               /**< @brief The job has not been finished succesfully */
    FLS_JOB_PENDING,              /**< @brief The job has not yet been finished */
    FLS_JOB_CANCELED,             /**< @brief The job has been canceled */
    FLS_BLOCK_INCONSISTENT,       /**< @brief The requested block is inconsistent, it may contain corrupted data */
    FLS_BLOCK_INVALID             /**< @brief The requested block has been marked as invalid, the requested operation can not be performed */
}FLS_JobResultType;


typedef enum
{

    Fls_Sector_0 = 0,
    Fls_Sector_1,
    Fls_Sector_2,
    Fls_Sector_3,
    Fls_Sector_4,
    Fls_Sector_5,
    Fls_Sector_6,
    Fls_Sector_7,
    Fls_Sector_8,
    Fls_Sector_9,
    Fls_Sector_10,
    Fls_Sector_11

} Fls_Sector;

typedef enum
{
    E_OK         = 0U,           /**<@brief status return OK*/
    E_NOT_OK     = 1U            /**<@brief status return NOT_OK*/
} Std_StatusReturnType;

#endif  /*INC_STM32F407XX_H_*/
