/*
 * stm32f407vg_gpio_driver.h
 *
 *  Created on: Oct 20, 2022
 *      Author: Phan Quang Huy
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "stm32f407vg.h"


/*
 * peripheral register definition structure for GPIO
 */
typedef struct
{
	__IO uint32_t MODER;                    /*!< GPIO port mode register,Address offset: 0x00      */
	__IO uint32_t OTYPER;                   /*!< GPIO port output type register, Address offset: 0x04      */
	__IO uint32_t OSPEEDR;				    /*!< GPIO port output speed register, Address offset: 0x08      */
	__IO uint32_t PUPDR;					/*!< GPIO port pull up / pull down register, Address offset: 0x0C      */
	__IO uint32_t IDR;						/*!< GPIO port input data register, Address offset: 0x10      */
	__IO uint32_t ODR;						/*!< GPIO port output data register, Address offset: 0x14      */
	__IO uint32_t BSRR;						/*!< GPIO port bit set / reset data register, Address offset: 0x18      */
	__IO uint32_t LCKR;						/*!< GPIO port congiguration lock register, Address offset: 0x1C      */
	__IO uint32_t AFR[2];				    /*!< AFR[0] : GPIO alternate function low register, AF[1] : GPIO alternate function high register    		Address offset: 0x20-0x24 */
}GPIO_RegDef_t;


/*
 * This is a Configuration structure for a GPIO pin
 */
typedef struct
{
	uint8_t GPIO_PinNumber;			/*!< possible values from @GPIO_PIN_NUMBERS >*/
	uint8_t GPIO_PinMode;			/*!< possible values from @GPIO_PIN_MODES >*/
	uint8_t GPIO_PinSpeed;			/*!< possible values from @GPIO_PIN_SPEED >*/
	uint8_t GPIO_PinPuPdControl;	/*!< possible values from @GPIO_PIN_PUPD_CONTROL >*/
	uint8_t GPIO_PinOPType;			/*!< possible values from @GPIO_PIN_OP_TYPE >*/
	uint8_t GPIO_PinAltFunMode;		/*!< possible values from @GPIO_PIN_ALT_FUNTION >*/
}GPIO_PinConfig_t;

/*
 * This is a Handle structure for a GPIO pin
 */

typedef struct
{
	GPIO_RegDef_t *pGPIOx;       		/*!< This holds the base address of the GPIO port to which the pin belongs >*/
	GPIO_PinConfig_t GPIO_PinConfig;    /*!< This holds GPIO pin configuration settings >*/

}GPIO_Handle_t;


/*
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0  				0
#define GPIO_PIN_NO_1  				1
#define GPIO_PIN_NO_2  				2
#define GPIO_PIN_NO_3  				3
#define GPIO_PIN_NO_4  				4
#define GPIO_PIN_NO_5  				5
#define GPIO_PIN_NO_6  				6
#define GPIO_PIN_NO_7  				7
#define GPIO_PIN_NO_8  				8
#define GPIO_PIN_NO_9  				9
#define GPIO_PIN_NO_10  			10
#define GPIO_PIN_NO_11 				11
#define GPIO_PIN_NO_12  			12
#define GPIO_PIN_NO_13 				13
#define GPIO_PIN_NO_14 				14
#define GPIO_PIN_NO_15 				15


/*
 * @GPIO_PIN_MODES
 * GPIO pin possible modes
 */
#define GPIO_MODE_IN 		0
#define GPIO_MODE_OUT 		1
#define GPIO_MODE_ALTFN 	2
#define GPIO_MODE_ANALOG 	3
#define GPIO_MODE_IT_FT     4     /*FT : falling edge */
#define GPIO_MODE_IT_RT     5	  /*RT : raising edge */
#define GPIO_MODE_IT_RFT    6

/*
 * @GPIO_PIN_OP_TYPE
 * GPIO pin possible output types
 */
#define GPIO_OP_TYPE_PP   0     /*push pull*/
#define GPIO_OP_TYPE_OD   1		/*open drain*/

/*
 * @GPIO_PIN_SPEED
 * GPIO pin possible output speeds
 */
#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_FAST			2
#define GPOI_SPEED_HIGH			3

/*
 * @GPIO_PIN_PUPD_CONTROL
 * GPIO pin pull up AND pull down configuration macros
 */
#define GPIO_NO_PUPD   		0
#define GPIO_PIN_PU			1
#define GPIO_PIN_PD			2


/******************************************************************************************
 *								APIs supported by this driver
 *		 For more information about the APIs check the function definitions
 ******************************************************************************************/


/*
 * Peripheral Clock setup
 */
uint8_t GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);  /*para1 : base address , para2: enable or disable*/

/*
 * Init and De-init
 */
uint8_t GPIO_Init(GPIO_Handle_t *pGPIOHandle);
uint8_t GPIO_DeInit(GPIO_RegDef_t *pGPIOx);


/*
 * Data read and write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
uint8_t GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
uint8_t GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
uint8_t GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


/*
 * IRQ Configuration and ISR handling
 */
uint8_t GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
uint8_t GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
uint8_t GPIO_IRQHandling(uint8_t PinNumber);




#endif	/*	INC_STM32F407XX_GPIO_DRIVER_H_	*/



