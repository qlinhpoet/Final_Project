#include <middleware/stm32f407_can_middleware.h>
#include "driver/stm32f407_can_driver.h"
/*function transmit data*/
Std_StatusReturnType STM32F4_CANTransmit(CAN_HandleTypeDef *hcan, CAN_TxHeaderTypeDef *pHeader, uint8_t aData[], uint32_t *pTxMailbox)
{
	uint32_t transmitmailbox;
	/*read CAN transmit status register*/
	uint32_t tsr = CAN_Driver_TSR();


	/* Check that all the Tx mailboxes are not full */
	/* Select an empty transmit mailbox */
    transmitmailbox = 0U;/*sellect mailbox 0*/
    /* Check transmit mailbox value */
    if (transmitmailbox > 2U)//if mailbox >2
    {
    return E_NOT_OK;
    }
    /* Store the Tx mailbox */
    *pTxMailbox = (uint32_t)1 << transmitmailbox;
    /* Set up the Id */
    if(CAN_SetUpID(pHeader->StdId) != 1)
	{
		return E_NOT_OK;
	}
	/* Set up the DLC */
	if(CAN_SetUpLD((uint8_t)pHeader->DLC) != 1)
	{
		return E_NOT_OK;
	}
	/* Set up the data field */
	if(CAN_WriteData(aData) != 1)
	{
		return E_NOT_OK;
	}
      /* Request transmission */
    if(CAN_IPVSetTransmission() != 1)
	{
		return E_NOT_OK;
	}
      /* Return function status */
      return E_OK;
}


/*function recive data*/
Std_StatusReturnType STM32F4_CANRecive(CAN_HandleTypeDef *hcan, uint32_t RxFifo, CAN_RxHeaderTypeDef *pHeader, uint8_t aData[])
{
	HAL_CAN_StateTypeDef state = hcan->State;

	if ((state == HAL_CAN_STATE_READY) ||(state == HAL_CAN_STATE_LISTENING))
   {
  	/* Check the Rx FIFO */
    	if (RxFifo == 0) /* Rx element is assigned to Rx FIFO 0 */
    	{
    	  /* Check that the Rx FIFO 0 is not empty */
     	if(CAN_StatusMailBox() == 100U)
     	{
       	 return E_NOT_OK;
      	}
    	}
    	/* Get the header */
    	pHeader->IDE = 0U;
    	if (pHeader->IDE == 0U)
    	{
     	pHeader->StdId = CAN_GetID();
    	}
    	pHeader->DLC = CAN_GetDataLength();

		/* Get the data */
		if(CAN_ReadData(aData) != 1)
		{
			return E_NOT_OK;
		}
		/* Release the FIFO */
    	if (RxFifo == 0) /* Rx element is assigned to Rx FIFO 0 */
    	{
     	 /* Release RX FIFO 0 */
		if(CAN_Release() != 1)
		{
			return E_NOT_OK;
		}
    	}
	}
    else
    {
    	return E_NOT_OK;
	}

	return E_OK;

}


Std_StatusReturnType STM32F4_CANInit(CAN_HandleTypeDef *hcan)
{
	if(CAN_ExitSleepMode() != 1)
	{
		return E_NOT_OK;
	}
	if (CAN_SetMCRINRQ(1U) != 1)
	{
		return E_NOT_OK;
	}

	/* Set the time triggered communication mode */
  	if (hcan->Init.TimeTriggeredMode == 1U)
  	{
	    if(CAN_RXTimeTrigger(1U) != 1)
	    {
	    	return E_NOT_OK;
		}
  	}
 	else
 	{
		if(CAN_RXTimeTrigger(0U) != 1)
	    {
	    	return E_NOT_OK;
		}
  	}
  	/* Set the automatic retransmission */
   if (CAN_AutoRetransmit() != 1)
   {
   		return E_NOT_OK;
   }
     /* Set the receive FIFO locked mode */
   if (CAN_LockFIFOMode() != 1)
   {
  		return E_NOT_OK;
   }
//   /* Set the bit timing register */
//    if (CAN_SetBitTime(hcan) != 1)
//    {
//  		return E_NOT_OK;
//    }

    /* Initialize the CAN state */
     hcan->State = HAL_CAN_STATE_READY;

    /* Return function status */
    return E_OK;
}

Std_StatusReturnType STM32F4_CANStart(CAN_HandleTypeDef *hcan)
{
	Std_StatusReturnType RetVal = E_OK;
		if (CAN_SetMCRINRQ(0U)!= 1)
    	{
  			RetVal = E_NOT_OK;
    	}

   		 return RetVal;

}

Std_StatusReturnType STM32F4_CANConfigFilter(CAN_HandleTypeDef *hcan, CAN_FilterTypeDef *sFilterConfig)
{
	uint32_t filternbrbitpos;

  	    //HAL_CAN_StateTypeDef state = hcan->State;
		/* Initialisation mode for the filter */
		if(CAN_InitModeFilter(1U) != 1)
		{
			return E_NOT_OK;
		}
    	filternbrbitpos = (uint32_t)1 << (sFilterConfig->FilterBank & 0x1FU);
        /* Filter Deactivation */
		if(CAN_DeInitFilter(filternbrbitpos) != 1)
		{
			return E_NOT_OK;
		}

		 /* Filter Scale */
  		if (CAN_FilterScale(filternbrbitpos, sFilterConfig) != 1)
  		{
    			return E_NOT_OK;
		}
		 /* Filter Mode */
    	if (CAN_FilterMode(filternbrbitpos) != 1)
    	{
			return E_NOT_OK;
		}
		/* Filter FIFO assignment */
    	if (CAN_FilterFIFOAs(filternbrbitpos) != 1)
    	{
			return E_NOT_OK;
   		}
  	  /* Filter activation */
   		 if (CAN_InitFilter(filternbrbitpos) != 1)
   		{
			return E_NOT_OK;
  		}

    	/* Leave the initialisation mode for the filter */
    	if(CAN_InitModeFilter(0U) != 1)
		{
			return E_NOT_OK;
		}
   		/* Return function status */
   		 return E_OK;
}

Std_StatusReturnType STM32F4_CANSetBaudrate(uint32_t BaudRate)
{
	uint32_t System_Clock = 16000000U;
	uint8_t BRP  = 0U;
	uint8_t TSB1 = 0U;
	uint8_t TSB2 = 0U;
	uint16_t BitTime = 0U;
	uint8_t Temp = 0U;
	uint8_t ToTal = 0U;

	BitTime = System_Clock/BaudRate;
	for(Temp = 4; Temp < 120; Temp++)
	{
		if((BitTime % Temp == 0U) && ((BitTime / Temp)< 23))
		{
			BRP = BitTime /Temp;
			ToTal = Temp;
			Temp = 120;
		}
	}
	if((ToTal % 2) == 0)
	{
		TSB2 = (ToTal - 2)/2;
		TSB1 = TSB2 + 1;
	}
	else
	{
		TSB2 = (ToTal -1)/2;
		TSB1 = TSB2;
	}
	if(CAN_SetBitTime1(TSB1-1) != 1)
	{
		return E_NOT_OK;
	}
	if(CAN_SetBitTime2(TSB2-1) != 1)
	{
		return E_NOT_OK;
	}
	if(CAN_setBitBRP(BRP -1) != 1)
	{
		return E_NOT_OK;
	}

	return E_OK;
}


