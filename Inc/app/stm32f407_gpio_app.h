/*
 * stm32f407_gpio_app.h
 *
 *  Created on: Nov 20, 2022
 *      Author: Phan Quang Huy
 */

#ifndef APP_STM32F407_GPIO_APP_H_
#define APP_STM32F407_GPIO_APP_H_

#include "stm32f407vg.h"
#include "middleware/stm32f407_gpio_middleware.h"


/**
* @brief          AL wrapper sector function.
* @details        Route the job to appropriate low level IP function.
* @implements
*/
int8_t GPIO_AL_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);
int8_t GPIO_AL_Init(GPIO_Handle_t *pGPIOHandle);
int8_t GPIO_AL__DeInit(GPIO_RegDef_t *pGPIOx);
uint8_t GPIO_AL_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_AL_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
int8_t GPIO_AL_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
int8_t GPIO_AL_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
int8_t GPIO_AL_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

#endif /* APP_STM32F407_GPIO_APP_H_ */
