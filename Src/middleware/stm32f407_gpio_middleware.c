/*
 * stm32f407_gpio_middleware.c
 *
 *  Created on: Nov 20, 2022
 *      Author: Phan Quang Huy
 */


#include "stm32f407vg.h"
#include "middleware/stm32f407_gpio_middleware.h"


/**
* @brief          IP wrapper sector Periperal clock control function.
* @details        Route the control job to appropriate low level IP function.
* @implements
*/
int8_t GPIO_IPW_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	GPIO_JobResultType eLldRetVal = GPIO_JOB_OK;

	GPIO_PeriClockControl(pGPIOx,EnorDi);

	return eLldRetVal;
}

/**
* @brief          IP wrapper sector Init function.
* @details        Route the Init job to appropriate low level IP function.
* @implements
*/
int8_t GPIO_IPW_Init(GPIO_RegDef_t *pGPIOx, GPIO_PinConfig_t GPIO_PinConfig)
{
	GPIO_JobResultType eLldRetVal = GPIO_JOB_OK;

	GPIO_Init(pGPIOx, &GPIO_PinConfig);

	return eLldRetVal;
}

/**
* @brief          IP wrapper sector DeInit function.
* @details        Route the DeInit job to appropriate low level IP function.
* @implements
*/
int8_t GPIO_IPW__DeInit(GPIO_RegDef_t *pGPIOx)
{
	GPIO_JobResultType eLldRetVal = GPIO_JOB_OK;

	//eLldRetVal = GPIO_DeInit(pGPIOx);

	return eLldRetVal;
}

/**
* @brief          IP wrapper sector read function.
* @details        Route the read job to appropriate low level IP function.
* @implements
*/
uint8_t GPIO_IPW_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	GPIO_JobResultType eLldRetVal = GPIO_JOB_OK;

	eLldRetVal = GPIO_ReadFromInputPin(pGPIOx,PinNumber); /*not correct*/

	return eLldRetVal;
}

/**
* @brief          IP wrapper sector Read function.
* @details        Route the Read job to appropriate low level IP function.
* @implements
*/
uint16_t GPIO_IPW_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	GPIO_JobResultType eLldRetVal = GPIO_JOB_OK;

	eLldRetVal = GPIO_ReadFromInputPort(pGPIOx); /*not correct*/

	return eLldRetVal;
}

/**
* @brief          IP wrapper sector write function.
* @details        Route the write job to appropriate low level IP function.
* @implements
*/
int8_t GPIO_IPW_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	GPIO_JobResultType eLldRetVal = GPIO_JOB_OK;

	GPIO_WriteOutputPin(pGPIOx,PinNumber,Value);

	return eLldRetVal;
}

/**
* @brief          IP wrapper sector write function.
* @details        Route the write job to appropriate low level IP function.
* @implements
*/
int8_t GPIO_IPW_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	GPIO_JobResultType eLldRetVal = GPIO_JOB_OK;

	GPIO_WriteOutputPort(pGPIOx,Value);

	return eLldRetVal;
}

/**
* @brief          IP wrapper sector Toggle function.
* @details        Route the Toggle job to appropriate low level IP function.
* @implements
*/
int8_t GPIO_IPW_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	GPIO_JobResultType eLldRetVal = GPIO_JOB_OK;

	GPIO_TogglePin(pGPIOx,PinNumber);

	return eLldRetVal;
}
