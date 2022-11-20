#ifndef STM32F407_CAN_DRIVER_H_
#define STM32F407_CAN_DRIVER_H_
#include "stm32f407vg.h"

/*******************  Bit definition for CAN_RDT0R register  ******************/
#define CAN_RDT0R_DLC_Pos      (0U)                                            
#define CAN_RDT0R_DLC_Msk      (0xFUL << CAN_RDT0R_DLC_Pos)                     /*!< 0x0000000F */
#define CAN_RDT0R_DLC          CAN_RDT0R_DLC_Msk                               /*!<Data Length Code */
#define CAN_RDT0R_FMI_Pos      (8U)                                            
#define CAN_RDT0R_FMI_Msk      (0xFFUL << CAN_RDT0R_FMI_Pos)                    /*!< 0x0000FF00 */
#define CAN_RDT0R_FMI          CAN_RDT0R_FMI_Msk                               /*!<Filter Match Index */
#define CAN_RDT0R_TIME_Pos     (16U)                                           
#define CAN_RDT0R_TIME_Msk     (0xFFFFUL << CAN_RDT0R_TIME_Pos)                 /*!< 0xFFFF0000 */
#define CAN_RDT0R_TIME         CAN_RDT0R_TIME_Msk                              /*!<Message Time Stamp */
/*******************  Bit definition for CAN_RI0R register  *******************/
#define CAN_RI0R_RTR_Pos       (1U)                                            
#define CAN_RI0R_RTR_Msk       (0x1UL << CAN_RI0R_RTR_Pos)                      /*!< 0x00000002 */
#define CAN_RI0R_RTR           CAN_RI0R_RTR_Msk                                /*!<Remote Transmission Request */
#define CAN_RI0R_IDE_Pos       (2U)                                            
#define CAN_RI0R_IDE_Msk       (0x1UL << CAN_RI0R_IDE_Pos)                      /*!< 0x00000004 */
#define CAN_RI0R_IDE           CAN_RI0R_IDE_Msk                                /*!<Identifier Extension */
#define CAN_RI0R_EXID_Pos      (3U)                                            
#define CAN_RI0R_EXID_Msk      (0x3FFFFUL << CAN_RI0R_EXID_Pos)                 /*!< 0x001FFFF8 */
#define CAN_RI0R_EXID          CAN_RI0R_EXID_Msk                               /*!<Extended Identifier */
#define CAN_RI0R_STID_Pos      (21U)                                           
#define CAN_RI0R_STID_Msk      (0x7FFUL << CAN_RI0R_STID_Pos)                   /*!< 0xFFE00000 */
#define CAN_RI0R_STID          CAN_RI0R_STID_Msk                               /*!<Standard Identifier or Extended Identifier */
//#include<stdbool.h>
/*******************  Bit definition for CAN_RDL0R register  ******************/
#define CAN_RDL0R_DATA0_Pos    (0U)                                            
#define CAN_RDL0R_DATA0_Msk    (0xFFUL << CAN_RDL0R_DATA0_Pos)                  /*!< 0x000000FF */
#define CAN_RDL0R_DATA0        CAN_RDL0R_DATA0_Msk                             /*!<Data byte 0 */
#define CAN_RDL0R_DATA1_Pos    (8U)                                            
#define CAN_RDL0R_DATA1_Msk    (0xFFUL << CAN_RDL0R_DATA1_Pos)                  /*!< 0x0000FF00 */
#define CAN_RDL0R_DATA1        CAN_RDL0R_DATA1_Msk                             /*!<Data byte 1 */
#define CAN_RDL0R_DATA2_Pos    (16U)                                           
#define CAN_RDL0R_DATA2_Msk    (0xFFUL << CAN_RDL0R_DATA2_Pos)                  /*!< 0x00FF0000 */
#define CAN_RDL0R_DATA2        CAN_RDL0R_DATA2_Msk                             /*!<Data byte 2 */
#define CAN_RDL0R_DATA3_Pos    (24U)                                           
#define CAN_RDL0R_DATA3_Msk    (0xFFUL << CAN_RDL0R_DATA3_Pos)                  /*!< 0xFF000000 */
#define CAN_RDL0R_DATA3        CAN_RDL0R_DATA3_Msk                             /*!<Data byte 3 */

/*******************  Bit definition for CAN_RDH0R register  ******************/
#define CAN_RDH0R_DATA4_Pos    (0U)                                            
#define CAN_RDH0R_DATA4_Msk    (0xFFUL << CAN_RDH0R_DATA4_Pos)                  /*!< 0x000000FF */
#define CAN_RDH0R_DATA4        CAN_RDH0R_DATA4_Msk                             /*!<Data byte 4 */
#define CAN_RDH0R_DATA5_Pos    (8U)                                            
#define CAN_RDH0R_DATA5_Msk    (0xFFUL << CAN_RDH0R_DATA5_Pos)                  /*!< 0x0000FF00 */
#define CAN_RDH0R_DATA5        CAN_RDH0R_DATA5_Msk                             /*!<Data byte 5 */
#define CAN_RDH0R_DATA6_Pos    (16U)                                           
#define CAN_RDH0R_DATA6_Msk    (0xFFUL << CAN_RDH0R_DATA6_Pos)                  /*!< 0x00FF0000 */
#define CAN_RDH0R_DATA6        CAN_RDH0R_DATA6_Msk                             /*!<Data byte 6 */
#define CAN_RDH0R_DATA7_Pos    (24U)                                           
#define CAN_RDH0R_DATA7_Msk    (0xFFUL << CAN_RDH0R_DATA7_Pos)                  /*!< 0xFF000000 */
#define CAN_RDH0R_DATA7        CAN_RDH0R_DATA7_Msk                             /*!<Data byte 7 */

/**
  * @brief  CAN Tx message header structure definition
  */
typedef struct
{
  uint32_t StdId;    /*!< Specifies the standard identifier.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0x7FF. */

  uint32_t ExtId;    /*!< Specifies the extended identifier.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0x1FFFFFFF. */

  uint32_t IDE;      /*!< Specifies the type of identifier for the message that will be transmitted.
                          This parameter can be a value of @ref CAN_identifier_type */

  uint32_t RTR;      /*!< Specifies the type of frame for the message that will be transmitted.
                          This parameter can be a value of @ref CAN_remote_transmission_request */

  uint32_t DLC;      /*!< Specifies the length of the frame that will be transmitted.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 8. */

} CAN_TxHeaderTypeDef;

/*******************  Bit definition for CAN_RF0R register  *******************/
#define CAN_RF0R_FMP0_Pos      (0U)                                            
#define CAN_RF0R_FMP0_Msk      (0x3UL << CAN_RF0R_FMP0_Pos)                     /*!< 0x00000003 */
#define CAN_RF0R_FMP0          CAN_RF0R_FMP0_Msk                               /*!<FIFO 0 Message Pending */
#define CAN_RF0R_FULL0_Pos     (3U)                                            
#define CAN_RF0R_FULL0_Msk     (0x1UL << CAN_RF0R_FULL0_Pos)                    /*!< 0x00000008 */
#define CAN_RF0R_FULL0         CAN_RF0R_FULL0_Msk                              /*!<FIFO 0 Full */
#define CAN_RF0R_FOVR0_Pos     (4U)                                            
#define CAN_RF0R_FOVR0_Msk     (0x1UL << CAN_RF0R_FOVR0_Pos)                    /*!< 0x00000010 */
#define CAN_RF0R_FOVR0         CAN_RF0R_FOVR0_Msk                              /*!<FIFO 0 Overrun */
#define CAN_RF0R_RFOM0_Pos     (5U)                                            
#define CAN_RF0R_RFOM0_Msk     (0x1UL << CAN_RF0R_RFOM0_Pos)                    /*!< 0x00000020 */
#define CAN_RF0R_RFOM0         CAN_RF0R_RFOM0_Msk                              /*!<Release FIFO 0 Output Mailbox */
/**
  * @brief  CAN Rx message header structure definition
  */
typedef struct
{
  uint32_t StdId;    /*!< Specifies the standard identifier.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0x7FF. */

  uint32_t ExtId;    /*!< Specifies the extended identifier.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0x1FFFFFFF. */

  uint32_t IDE;      /*!< Specifies the type of identifier for the message that will be transmitted.
                          This parameter can be a value of @ref CAN_identifier_type */

  uint32_t RTR;      /*!< Specifies the type of frame for the message that will be transmitted.
                          This parameter can be a value of @ref CAN_remote_transmission_request */

  uint32_t DLC;      /*!< Specifies the length of the frame that will be transmitted.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 8. */

  uint32_t Timestamp; /*!< Specifies the timestamp counter value captured on start of frame reception.
                          @note: Time Triggered Communication Mode must be enabled.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0xFFFF. */

  uint32_t FilterMatchIndex; /*!< Specifies the index of matching acceptance filter element.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0xFF. */

} CAN_RxHeaderTypeDef;

typedef enum
{
  HAL_CAN_STATE_RESET             = 0x00U,  /*!< CAN not yet initialized or disabled */
  HAL_CAN_STATE_READY             = 0x01U,  /*!< CAN initialized and ready for use   */
  HAL_CAN_STATE_LISTENING         = 0x02U,  /*!< CAN receive process is ongoing      */
  HAL_CAN_STATE_SLEEP_PENDING     = 0x03U,  /*!< CAN sleep request is pending        */
  HAL_CAN_STATE_SLEEP_ACTIVE      = 0x04U,  /*!< CAN sleep mode is active            */
  HAL_CAN_STATE_ERROR             = 0x05U   /*!< CAN error state                     */

} HAL_CAN_StateTypeDef;

typedef enum
{
	Disable = 0,
	Enable = 1
}State;

typedef struct
{
  uint32_t Prescaler;                  /*!< Specifies the length of a time quantum.
                                            This parameter must be a number between Min_Data = 1 and Max_Data = 1024. */

  uint32_t Mode;                       /*!< Specifies the CAN operating mode.
                                            This parameter can be a value of @ref CAN_operating_mode */

  uint32_t SyncJumpWidth;              /*!< Specifies the maximum number of time quanta the CAN hardware
                                            is allowed to lengthen or shorten a bit to perform resynchronization.
                                            This parameter can be a value of @ref CAN_synchronisation_jump_width */

  uint32_t TimeSeg1;                   /*!< Specifies the number of time quanta in Bit Segment 1.
                                            This parameter can be a value of @ref CAN_time_quantum_in_bit_segment_1 */

  uint32_t TimeSeg2;                   /*!< Specifies the number of time quanta in Bit Segment 2.
                                            This parameter can be a value of @ref CAN_time_quantum_in_bit_segment_2 */

  State TimeTriggeredMode;   /*!< Enable or disable the time triggered communication mode.
                                            This parameter can be set to ENABLE or DISABLE. */

  State AutoBusOff;          /*!< Enable or disable the automatic bus-off management.
                                            This parameter can be set to ENABLE or DISABLE. */

  State AutoWakeUp;          /*!< Enable or disable the automatic wake-up mode.
                                            This parameter can be set to ENABLE or DISABLE. */

  State AutoRetransmission;  /*!< Enable or disable the non-automatic retransmission mode.
                                            This parameter can be set to ENABLE or DISABLE. */

  State ReceiveFifoLocked;   /*!< Enable or disable the Receive FIFO Locked mode.
                                            This parameter can be set to ENABLE or DISABLE. */

  State TransmitFifoPriority;/*!< Enable or disable the transmit FIFO priority.
                                            This parameter can be set to ENABLE or DISABLE. */

} CAN_InitTypeDef;
typedef struct
{
  __IO uint32_t TIR;  /*!< CAN TX mailbox identifier register */
  __IO uint32_t TDTR; /*!< CAN mailbox data length control and time stamp register */
  __IO uint32_t TDLR; /*!< CAN mailbox data low register */
  __IO uint32_t TDHR; /*!< CAN mailbox data high register */
} CAN_TxMailBox_TypeDef;

/**
  * @brief Controller Area Network FIFOMailBox
  */

typedef struct
{
  __IO uint32_t RIR;  /*!< CAN receive FIFO mailbox identifier register */
  __IO uint32_t RDTR; /*!< CAN receive FIFO mailbox data length control and time stamp register */
  __IO uint32_t RDLR; /*!< CAN receive FIFO mailbox data low register */
  __IO uint32_t RDHR; /*!< CAN receive FIFO mailbox data high register */
} CAN_FIFOMailBox_TypeDef;

typedef struct
{
  __IO uint32_t FR1; /*!< CAN Filter bank register 1 */
  __IO uint32_t FR2; /*!< CAN Filter bank register 1 */
} CAN_FilterRegister_TypeDef;

typedef struct
{
  __IO uint32_t              MCR;                 /*!< CAN master control register,         Address offset: 0x00          */
  __IO uint32_t              MSR;                 /*!< CAN master status register,          Address offset: 0x04          */
  __IO uint32_t              TSR;                 /*!< CAN transmit status register,        Address offset: 0x08          */
  __IO uint32_t              RF0R;                /*!< CAN receive FIFO 0 register,         Address offset: 0x0C          */
  __IO uint32_t              RF1R;                /*!< CAN receive FIFO 1 register,         Address offset: 0x10          */
  __IO uint32_t              IER;                 /*!< CAN interrupt enable register,       Address offset: 0x14          */
  __IO uint32_t              ESR;                 /*!< CAN error status register,           Address offset: 0x18          */
  __IO uint32_t              BTR;                 /*!< CAN bit timing register,             Address offset: 0x1C          */
  uint32_t                   RESERVED0[88];       /*!< Reserved, 0x020 - 0x17F                                            */
  CAN_TxMailBox_TypeDef      sTxMailBox[3];       /*!< CAN Tx MailBox,                      Address offset: 0x180 - 0x1AC */
  CAN_FIFOMailBox_TypeDef    sFIFOMailBox[2];     /*!< CAN FIFO MailBox,                    Address offset: 0x1B0 - 0x1CC */
  uint32_t                   RESERVED1[12];       /*!< Reserved, 0x1D0 - 0x1FF                                            */
  __IO uint32_t              FMR;                 /*!< CAN filter master register,          Address offset: 0x200         */
  __IO uint32_t              FM1R;                /*!< CAN filter mode register,            Address offset: 0x204         */
  uint32_t                   RESERVED2;           /*!< Reserved, 0x208                                                    */
  __IO uint32_t              FS1R;                /*!< CAN filter scale register,           Address offset: 0x20C         */
  uint32_t                   RESERVED3;           /*!< Reserved, 0x210                                                    */
  __IO uint32_t              FFA1R;               /*!< CAN filter FIFO assignment register, Address offset: 0x214         */
  uint32_t                   RESERVED4;           /*!< Reserved, 0x218                                                    */
  __IO uint32_t              FA1R;                /*!< CAN filter activation register,      Address offset: 0x21C         */
  uint32_t                   RESERVED5[8];        /*!< Reserved, 0x220-0x23F                                              */
  CAN_FilterRegister_TypeDef sFilterRegister[28]; /*!< CAN Filter Register,                 Address offset: 0x240-0x31C   */
} CAN_TypeDef;

typedef struct __CAN_HandleTypeDef
{
  CAN_InitTypeDef             Init;                      /*!< CAN required parameters */

  __IO HAL_CAN_StateTypeDef   State;                     /*!< CAN communication state */

  __IO uint32_t               ErrorCode;                 /*!< CAN Error code.
                                                              This parameter can be a value of @ref CAN_Error_Code */
} CAN_HandleTypeDef;

/**
  * @brief  CAN filter configuration structure definition
  */
typedef struct
{
  uint32_t FilterIdHigh;          /*!< Specifies the filter identification number (MSBs for a 32-bit
                                       configuration, first one for a 16-bit configuration).
                                       This parameter must be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF. */

  uint32_t FilterIdLow;           /*!< Specifies the filter identification number (LSBs for a 32-bit
                                       configuration, second one for a 16-bit configuration).
                                       This parameter must be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF. */

  uint32_t FilterMaskIdHigh;      /*!< Specifies the filter mask number or identification number,
                                       according to the mode (MSBs for a 32-bit configuration,
                                       first one for a 16-bit configuration).
                                       This parameter must be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF. */

  uint32_t FilterMaskIdLow;       /*!< Specifies the filter mask number or identification number,
                                       according to the mode (LSBs for a 32-bit configuration,
                                       second one for a 16-bit configuration).
                                       This parameter must be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF. */

  uint32_t FilterFIFOAssignment;  /*!< Specifies the FIFO (0 or 1U) which will be assigned to the filter.
                                       This parameter can be a value of @ref CAN_filter_FIFO */

  uint32_t FilterBank;            /*!< Specifies the filter bank which will be initialized.
                                       For single CAN instance(14 dedicated filter banks),
                                       this parameter must be a number between Min_Data = 0 and Max_Data = 13.
                                       For dual CAN instances(28 filter banks shared),
                                       this parameter must be a number between Min_Data = 0 and Max_Data = 27. */

  uint32_t FilterMode;            /*!< Specifies the filter mode to be initialized.
                                       This parameter can be a value of @ref CAN_filter_mode */

  uint32_t FilterScale;           /*!< Specifies the filter scale.
                                       This parameter can be a value of @ref CAN_filter_scale */

  uint32_t FilterActivation;      /*!< Enable or disable the filter.
                                       This parameter can be a value of @ref CAN_filter_activation */

  uint32_t SlaveStartFilterBank;  /*!< Select the start filter bank for the slave CAN instance.
                                       For single CAN instances, this parameter is meaningless.
                                       For dual CAN instances, all filter banks with lower index are assigned to master
                                       CAN instance, whereas all filter banks with greater index are assigned to slave
                                       CAN instance.
                                       This parameter must be a number between Min_Data = 0 and Max_Data = 27. */

} CAN_FilterTypeDef;

uint32_t CAN_Driver_TSR(void);
uint8_t CAN_SetUpID(uint16_t ID);
uint8_t CAN_SetUpLD(uint8_t Length_Data);
uint8_t CAN_WriteData(uint8_t cData[]);
uint8_t CAN_IPVSetTransmission( void);
uint8_t CAN_StatusMailBox( void);
uint16_t CAN_GetID(void);
uint8_t CAN_GetDataLength( void);
uint8_t CAN_ReadData(uint8_t cData[]);
uint8_t CAN_Release( void);
uint8_t CAN_ExitSleepMode( void);
uint8_t CAN_RXTimeTrigger(uint8_t Mode);
uint8_t CAN_AutoRetransmit( void);
uint8_t CAN_LockFIFOMode( void);
uint8_t CAN_SetBitTime(CAN_HandleTypeDef *hcan);
uint8_t CAN_SetMCRINRQ(void);
uint8_t CAN_InitModeFilter(uint8_t Moden);
uint8_t CAN_DeInitFilter(uint32_t bank);
uint8_t CAN_FilterScale(uint32_t bank,CAN_FilterTypeDef *sFilterConfig);
uint8_t CAN_FilterMode(uint32_t bank);
uint8_t CAN_FilterFIFOAs(uint32_t bank);
uint8_t CAN_InitFilter(uint32_t bank);

 #endif /*STM32F407_CAN_DRIVER_H_*/

