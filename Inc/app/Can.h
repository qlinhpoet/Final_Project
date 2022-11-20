
#ifndef CAN_H
#define CAN_H
#include "stm32f407vg.h"

Std_StatusReturnType CAN_AddTxMessage(CAN_HandleTypeDef *hcan, CAN_TxHeaderTypeDef *pHeader, uint8_t aData[], uint32_t *pTxMailbox);
Std_StatusReturnType CAN_GetRxMessage(CAN_HandleTypeDef *hcan, uint32_t RxFifo, CAN_RxHeaderTypeDef *pHeader, uint8_t aData[]);
Std_StatusReturnType CAN_Init(CAN_HandleTypeDef *hcan);
Std_StatusReturnType CAN_Start(CAN_HandleTypeDef *hcan);
Std_StatusReturnType CAN_ConfigFilter(CAN_HandleTypeDef *hcan, CAN_FilterTypeDef *sFilterConfig);

#endif /*CAN_H*/
