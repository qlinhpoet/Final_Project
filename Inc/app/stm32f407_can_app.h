#ifndef CAN_H
#define CAN_H
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "stm32f407vg.h"
/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @brief
 * Add a message to transmit 
 * @param Addr: CAN_HandleTypeDef *hcan      : struct Can handle
 				CAN_TxHeaderTypeDef *pHeader : struct Can transmit Header 
 				uint8_t aData[]              : array to contain data
 				uint32_t *pTxMailbox         : to contain mail box
 * @return : status of function
 */
Std_StatusReturnType CAN_AddTxMessage(CAN_HandleTypeDef *hcan, CAN_TxHeaderTypeDef *pHeader, uint8_t aData[], uint32_t *pTxMailbox);
/*!
 * @brief
 * Get a message 
 * @param Addr: CAN_HandleTypeDef *hcan      : struct Can handle
 				CAN_RxHeaderTypeDef *pHeader : struct Can reciver Header 
 				uint8_t aData[]              : array to contain data
 				uint32_t RxFifo              : to contain data fifo
 * @return : status of function
 */
Std_StatusReturnType CAN_GetRxMessage(CAN_HandleTypeDef *hcan, uint32_t RxFifo, CAN_RxHeaderTypeDef *pHeader, uint8_t aData[]);
/*!
 * @brief
 * init CAN protocol 
 * @param Addr: CAN_HandleTypeDef *hcan      : struct Can handle
 * @return : status of function
 */
Std_StatusReturnType CAN_Init(CAN_HandleTypeDef *hcan);
/*!
 * @brief
 * start CAN protocol 
 * @param Addr: CAN_HandleTypeDef *hcan      : struct Can handle
 * @return : status of function
 */
Std_StatusReturnType CAN_Start(CAN_HandleTypeDef *hcan);
/*!
 * @brief
 * conifig filter 
 * @param Addr: CAN_HandleTypeDef *hcan      : struct Can handle
 				CAN_FilterTypeDef *sFilterConfig : struct  Can filter
 * @return : status of function
 */
Std_StatusReturnType CAN_ConfigFilter(CAN_HandleTypeDef *hcan, CAN_FilterTypeDef *sFilterConfig);
/*!
 * @brief
 * set baudrate 
 * @param Addr: uint32_t BaudRate 
 * @return : status of function
 */
Std_StatusReturnType CAN_BaudRate(uint32_t BaudRate);

#endif /*CAN_H*/
