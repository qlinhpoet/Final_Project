#ifndef CAN_IPW_H
#define CAN_IPW_H
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "stm32f407vg.h"
/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @brief
 * transmit a message
 * @param Addr: struct Can handle :*hcan
 				struct Can Tx header : *pHeader
 				array to contrain Data :aData[]
 				buffer to contain data mailbox : *pTxMailbox
 * @return
 * return status of function
 */
Std_StatusReturnType STM32F4_CANTransmit(CAN_HandleTypeDef *hcan, CAN_TxHeaderTypeDef *pHeader, uint8_t aData[], uint32_t *pTxMailbox);
/*!
 * @brief
 * reciver a message
 * @param Addr: struct Can handle :*hcan
 				struct Can Rx header : *pHeader
 				array to contrain Data :aData[]
 				buffer to contain data fifo : RxFifo
 * @return
 * return status of function
 */
Std_StatusReturnType STM32F4_CANRecive(CAN_HandleTypeDef *hcan, uint32_t RxFifo, CAN_RxHeaderTypeDef *pHeader, uint8_t aData[]);
/*!
 * @brief
 * innit can
 * @param Addr: struct Can handle :*hcan
 * @return
 * return status of function
 */
Std_StatusReturnType STM32F4_CANInit(CAN_HandleTypeDef *hcan);

/*!
 * @brief
 * start can
 * @param Addr: struct Can handle :*hcan
 * @return
 * return status of function
 */
Std_StatusReturnType STM32F4_CANStart(CAN_HandleTypeDef *hcan);
/*!
 * @brief
 * config filter
 * @param Addr: struct Can handle :*hcan
 				struct Filter config : *sFilterConfig
 * @return
 * return status of function
 */
Std_StatusReturnType STM32F4_CANConfigFilter(CAN_HandleTypeDef *hcan, CAN_FilterTypeDef *sFilterConfig);
/*!
 * @brief
 * set baudrate
 * @param Addr: baud rate :BaudRate
 * @return
 * return status of function
 */
Std_StatusReturnType STM32F4_CANSetBaudrate(uint32_t BaudRate);

#endif /*CAN_IPW_H*/
