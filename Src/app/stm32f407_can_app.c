/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "stm32f407_can_middleware.h"
#include "stm32f407_can_app.h"
/*******************************************************************************
 * Codes
 ******************************************************************************/
 /* add a message to transmit*/
Std_StatusReturnType CAN_AddTxMessage(CAN_HandleTypeDef *hcan, CAN_TxHeaderTypeDef *pHeader, uint8_t aData[], uint32_t *pTxMailbox)
{
    Std_StatusReturnType RetVal = E_OK;
	if(STM32F4_CANTransmit(hcan,pHeader,aData,pTxMailbox) != E_OK)
    {
    	RetVal = E_NOT_OK;
    }

	return RetVal;
}
/* get a message*/
Std_StatusReturnType CAN_GetRxMessage(CAN_HandleTypeDef *hcan, uint32_t RxFifo, CAN_RxHeaderTypeDef *pHeader, uint8_t aData[])
{
	Std_StatusReturnType RetVal = E_OK;
	if(STM32F4_CANRecive(hcan,RxFifo,pHeader,aData) != E_OK)
    {
    	RetVal = E_NOT_OK;
    }

	return RetVal;
}
/* init can*/
Std_StatusReturnType CAN_Init(CAN_HandleTypeDef *hcan)
{
	Std_StatusReturnType RetVal = E_OK;
	if(STM32F4_CANInit(hcan) != E_OK)
    {
    	RetVal = E_NOT_OK;
    }

	return RetVal;
}
/* start can*/
Std_StatusReturnType CAN_Start(CAN_HandleTypeDef *hcan)
{
	Std_StatusReturnType RetVal = E_OK;
	if(STM32F4_CANStart(hcan) != E_OK)
    {
    	RetVal = E_NOT_OK;
    }

	return RetVal;
}
/* config filter*/
Std_StatusReturnType CAN_ConfigFilter(CAN_HandleTypeDef *hcan, CAN_FilterTypeDef *sFilterConfig)
{
	Std_StatusReturnType RetVal = E_OK;
	if(STM32F4_CANConfigFilter(hcan,sFilterConfig) != E_OK)
    {
    	RetVal = E_NOT_OK;
    }

	return RetVal;
}
/* config baud rate*/
Std_StatusReturnType CAN_BaudRate(uint32_t BaudRate)
{
	Std_StatusReturnType RetVal = E_OK;
	if(STM32F4_CANSetBaudrate(BaudRate) != E_OK)
    {
    	RetVal = E_NOT_OK;
    }

	return RetVal;
}
/* END OF CODE*/
