/*
 * stm32f407_gpio_middleware.h
 *
 *  Created on: Nov 20, 2022
 *      Author: Phan Quang Huy
 */

#ifndef MIDDLEWARE_STM32F407_GPIO_MIDDLEWARE_H_
#define MIDDLEWARE_STM32F407_GPIO_MIDDLEWARE_H_

#include "stm32f407vg.h"
#include "driver/stm32f407_gpio_driver.h"

/**
* @brief          IP wrapper sector xxx function.
* @details        Route the xxx job to appropriate low level IP function.
* @implements
*/
int8_t GPIO_IPW_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);
int8_t GPIO_IPW_Init(GPIO_Handle_t *pGPIOHandle);
int8_t GPIO_IPW__DeInit(GPIO_RegDef_t *pGPIOx);
uint8_t GPIO_IPW_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_IPW_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
int8_t GPIO_IPW_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
int8_t GPIO_IPW_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
int8_t GPIO_IPW_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

#endif /* MIDDLEWARE_STM32F407_GPIO_MIDDLEWARE_H_ */
