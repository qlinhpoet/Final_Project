#ifndef CAN_IPW_H
#define CAN_IPW_H
#include "stm32f407vg.h"
#include "driver/stm32f407_can_driver.h"
Std_StatusReturnType STM32F4_CANTransmit(CAN_HandleTypeDef *hcan, CAN_TxHeaderTypeDef *pHeader, uint8_t aData[], uint32_t *pTxMailbox);
Std_StatusReturnType STM32F4_CANRecive(CAN_HandleTypeDef *hcan, uint32_t RxFifo, CAN_RxHeaderTypeDef *pHeader, uint8_t aData[]);
Std_StatusReturnType STM32F4_CANInit(CAN_HandleTypeDef *hcan);
Std_StatusReturnType STM32F4_CANStart(CAN_HandleTypeDef *hcan);
Std_StatusReturnType STM32F4_CANConfigFilter(CAN_HandleTypeDef *hcan, CAN_FilterTypeDef *sFilterConfig);
Std_StatusReturnType STM32F4_CANSetBaudrate(uint32_t BaudRate);

#endif /*CAN_IPW_H*/
