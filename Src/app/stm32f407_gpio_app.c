/*
 * stm32f407_gpio_app.c
 *
 *  Created on: Nov 20, 2022
 *      Author: Phan Quang Huy
 */

#include "app/stm32f407_gpio_app.h"

/**
 * @brief 		GPIO peripheral Clock control
 *
 * @details  	enable or disable GPIO peripheral
 *
 * @param[in]	GPIOx base address
 * @param[in]	ENABLE or DISABLE
 *
 * @return           eLldRetVal
 * @retval           FLS_JOB_OK                    Command has been accepted.
 * @retval           FLS_JOB_FAILED                Command has not been accepted.
 *
 * @pre
 *
 */
 int8_t GPIO_AL_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
 {
	GPIO_JobResultType eLldRetVal = GPIO_JOB_FAILED;

	eLldRetVal = GPIO_IPW_PeriClockControl(pGPIOx,EnorDi);

	return eLldRetVal;

}

 /**
  * @brief 		GPIO Init
  *
  * @details  	1 . configure the mode of gpio pin
  * 			2. configure the speed
  * 			3. configure the pupd settings
  * 			4. configure the optype
  * 			5. configure the alt functionality
  *
  *
  * @param[in]	GPIOx handle ( GPIOx base address + GPIO_PinConfig )
  *
  * @return           eLldRetVal
  * @retval           FLS_JOB_OK                    Command has been accepted.
  * @retval           FLS_JOB_FAILED                Command has not been accepted.
  *
  * @pre
  *
  */
int8_t GPIO_AL_Init(GPIO_RegDef_t *pGPIOx, GPIO_PinConfig_t *GPIO_PinConfig)
{
	GPIO_JobResultType eLldRetVal = GPIO_JOB_FAILED;

	eLldRetVal = GPIO_IPW_Init(pGPIOx, GPIO_PinConfig);

	return eLldRetVal;

}

/**
 * @brief 		GPIO DeInit
 *
 * @details  	DeInit GPIO port
 *
 * @param[in]	GPIOx base address
 *
 * @return           eLldRetVal
 * @retval           FLS_JOB_OK                    Command has been accepted.
 * @retval           FLS_JOB_FAILED                Command has not been accepted.
 *
 * @pre
 *
 */
int8_t GPIO_AL__DeInit(GPIO_RegDef_t *pGPIOx)
{
	GPIO_JobResultType eLldRetVal = GPIO_JOB_FAILED;

	eLldRetVal = GPIO_IPW__DeInit(pGPIOx);

	return eLldRetVal;

}


uint8_t GPIO_AL_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	GPIO_JobResultType eLldRetVal = GPIO_JOB_FAILED;

	eLldRetVal = GPIO_IPW_ReadFromInputPin(pGPIOx,PinNumber); /*not correct*/

	return eLldRetVal;

}


uint16_t GPIO_AL_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	GPIO_JobResultType eLldRetVal = GPIO_JOB_FAILED;

	eLldRetVal = GPIO_IPW_ReadFromInputPort(pGPIOx); /*not correct*/

	return eLldRetVal;

}

/**
 * @brief 		GPIO Write to output pin
 *
 * @details  	Write value to specific GPIOx pin
 *
 * @param[in]	GPIOx base address
 * @param[in]	Pinnumber
 * @param[in]	Value
 *
 * @return           eLldRetVal
 * @retval           FLS_JOB_OK                    Command has been accepted.
 * @retval           FLS_JOB_FAILED                Command has not been accepted.
 *
 * @pre			 Pinnumber must range from 0 - 15, Value mustbe 1 or 0
 *
 */
int8_t GPIO_AL_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	GPIO_JobResultType eLldRetVal = GPIO_JOB_FAILED;

	eLldRetVal = GPIO_IPW_WriteToOutputPin(pGPIOx,PinNumber,Value);

	return eLldRetVal;

}

/**
 * @brief 		GPIO Write to output port
 *
 * @details  	Write value to specific GPIO port
 *
 * @param[in]	GPIOx base address
 * @param[in]	Value
 *
 * @return           eLldRetVal
 * @retval           FLS_JOB_OK                    Command has been accepted.
 * @retval           FLS_JOB_FAILED                Command has not been accepted.
 *
 * @pre			 Value mustbe 1 or 0
 *
 */
int8_t GPIO_AL_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	GPIO_JobResultType eLldRetVal = GPIO_JOB_OK;

	eLldRetVal = GPIO_IPW_WriteToOutputPort(pGPIOx,Value);

	return eLldRetVal;

}

/**
 * @brief 		GPIO toggle output pin
 *
 * @details  	Toggle specific GPIOx pin
 *
 * @param[in]	GPIOx base address
 * @param[in]	Pinnumber
 *
 * @return           eLldRetVal
 * @retval           FLS_JOB_OK                    Command has been accepted.
 * @retval           FLS_JOB_FAILED                Command has not been accepted.
 *
 * @pre			 Pinnumber value must range from 0 - 15
 *
 */
int8_t GPIO_AL_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	GPIO_JobResultType eLldRetVal = GPIO_JOB_FAILED;

	eLldRetVal = GPIO_IPW_ToggleOutputPin(pGPIOx,PinNumber);

	return eLldRetVal;

}


