#include "stm32f407_can_driver.h"
uint32_t CAN_Driver_TSR()
{
	/*read transmit status register*/
	uint32_t RetVal = CAN1->TSR;
//	CAN1->MSR &= ~(1<<11);
//	CAN1->MSR &= ~(1<<10);
//	CAN1->MSR |= (1<<8);


	return RetVal;

}
uint8_t CAN_SetUpID(uint16_t ID)
{
	uint8_t RetVal = 1;
	/*write id on register */
	CAN1->sTxMailBox[0].TIR = (ID << 21U);

	return RetVal;
}

uint8_t CAN_SetUpLD(uint8_t Length_Data)
{
	uint8_t RetVal = 1;
     /* Set up the DLC */
    CAN1->sTxMailBox[0].TDTR = Length_Data;

	return RetVal;
}

uint8_t CAN_WriteData(uint8_t cData[])
{
	uint8_t RetVal = 1;
	CAN1->sTxMailBox[0].TDHR =
                ((uint32_t)cData[7] << 0U ) |
                ((uint32_t)cData[6] << 8U ) |
                ((uint32_t)cData[5] << 16U) |
                ((uint32_t)cData[4] << 24U);
    CAN1->sTxMailBox[0].TDLR =
                ((uint32_t)cData[3] << 0U ) |
                ((uint32_t)cData[2] << 8U ) |
                ((uint32_t)cData[1] << 16U) |
                ((uint32_t)cData[0] << 24U);

    return RetVal;
}

uint8_t CAN_IPVSetTransmission()
{
	uint8_t RetVal = 1;
	/* Request transmission */
    CAN1->sTxMailBox[0].TIR |= 1U;

	return RetVal;
}

uint8_t CAN_StatusMailBox()
{
	uint8_t RetVal = 1;
    /* Check that the Rx FIFO 0 is not empty */
    if ((CAN1->RF0R & (1<<5)) == 0U)
    {
		RetVal = 0;
    }
	return RetVal;
}

uint16_t CAN_GetID()
{
	uint16_t RetVal = 0;
    /* get ID*/
    RetVal = ((CAN_RI0R_STID & CAN1->sFIFOMailBox[0].RIR) >> 21U);

	return RetVal;
}

uint8_t CAN_GetDataLength()
{
	uint8_t RetVal = 1;
    /* get ID*/
    RetVal = ((CAN_RDT0R_DLC & CAN1->sFIFOMailBox[0].RDTR) >> 0);

	return RetVal;
}

uint8_t CAN_ReadData(uint8_t cData[])
{
	uint8_t RetVal = 1;
    /* Get the data */
    cData[0] = (uint8_t)((CAN_RDL0R_DATA0 & CAN1->sFIFOMailBox[0].RDLR) >> 0U );
    cData[1] = (uint8_t)((CAN_RDL0R_DATA1 & CAN1->sFIFOMailBox[0].RDLR) >> 8U );
    cData[2] = (uint8_t)((CAN_RDL0R_DATA2 & CAN1->sFIFOMailBox[0].RDLR) >> 16U);
    cData[3] = (uint8_t)((CAN_RDL0R_DATA3 & CAN1->sFIFOMailBox[0].RDLR) >> 24U);
    cData[4] = (uint8_t)((CAN_RDH0R_DATA4 & CAN1->sFIFOMailBox[0].RDHR) >> 0U );
    cData[5] = (uint8_t)((CAN_RDH0R_DATA5 & CAN1->sFIFOMailBox[0].RDHR) >> 8U );
    cData[6] = (uint8_t)((CAN_RDH0R_DATA6 & CAN1->sFIFOMailBox[0].RDHR) >> 16U);
    cData[7] = (uint8_t)((CAN_RDH0R_DATA7 & CAN1->sFIFOMailBox[0].RDHR) >> 24U);

    return RetVal;
}

uint8_t CAN_Release()
{
	uint8_t RetVal = 1;
	/*set bit release FIFO0 output mailbox*/
	CAN1->RF0R |= (1<<5);

	return RetVal;
}

uint8_t CAN_ExitSleepMode()
{
	uint8_t RetVal = 1;
	/* Exit from sleep mode */
  	CAN1->MCR &= ~((uint16_t)(1<<1));

	return RetVal;
}

uint8_t CAN_RXTimeTrigger(uint8_t Mode)
{
	uint8_t RetVal = 1;
	if(Mode == 1)
	{
		CAN1->MCR |= (1<<7);
	}
	else if(Mode == 0)
	{
		CAN1->MCR &= ~(1<<7);
	}

	return RetVal;
}

uint8_t CAN_AutoRetransmit()
{
	uint8_t RetVal = 1;
	/* Set the automatic retransmission */
	CAN1->MCR |= (1<<4);

	return RetVal;
}

uint8_t CAN_LockFIFOMode()
{
	uint8_t RetVal = 1;
	/* Receive FIFO locked against overrun */
	CAN1->MCR |= (1<<3);

	return RetVal;
}

uint8_t CAN_SetBitTime(CAN_HandleTypeDef *hcan)
{
	uint8_t RetVal = 1;
	/* Receive FIFO locked against overrun */
	CAN1->BTR = (uint32_t)hcan->Init.Mode           |
                                    hcan->Init.SyncJumpWidth  |
                                    hcan->Init.TimeSeg1       |
                                    hcan->Init.TimeSeg2       |
                                    (hcan->Init.Prescaler - 1U);

	return RetVal;
}

uint8_t CAN_SetMCRINRQ()
{
	uint8_t RetVal = 1;
    /* Request leave initialisation */
    CAN1->MCR &= ~(1U);
	return RetVal;

}

uint8_t CAN_InitModeFilter(uint8_t Mode)
{
	uint8_t RetVal = 1;
	if(Mode == 1)
	{
	    /* Initialisation mode for the filter */
    	CAN1->FMR |= 1U;
	}
	else if(Mode ==0)
	{
		/* Leave the initialisation mode for the filter */
        CAN1->FMR &= ~1U;
	}

	return RetVal;

}

uint8_t CAN_DeInitFilter(uint32_t bank)
{
	uint8_t RetVal = 1;
	CAN1->FA1R &= ~(bank);

	return RetVal;

}
uint8_t CAN_FilterScale(uint32_t bank,CAN_FilterTypeDef *sFilterConfig)
{
	uint8_t RetVal = 1;
	/* 32-bit scale for the filter */
    CAN1->FS1R &= ~(bank);

    /* 32-bit identifier or First 32-bit identifier */
    CAN1->sFilterRegister[sFilterConfig->FilterBank].FR1 =
    ((0x0000FFFFU & (uint32_t)sFilterConfig->FilterIdHigh) << 16U) |
    (0x0000FFFFU & (uint32_t)sFilterConfig->FilterIdLow);

    /* 32-bit mask or Second 32-bit identifier */
    CAN1->sFilterRegister[sFilterConfig->FilterBank].FR2 =
    ((0x0000FFFFU & (uint32_t)sFilterConfig->FilterMaskIdHigh) << 16U) |
    (0x0000FFFFU & (uint32_t)sFilterConfig->FilterMaskIdLow);

	return RetVal;
}

uint8_t CAN_FilterMode(uint32_t bank)
{
	uint8_t RetVal = 1;
    /* Id/Mask mode for the filter*/
	CAN1->FM1R &= ~(bank);

	return RetVal;
}

uint8_t CAN_FilterFIFOAs(uint32_t bank)
{
	uint8_t RetVal = 1;
    /* FIFO 0 assignation for the filter */
    CAN1->FFA1R &= ~(bank);

	return RetVal;
}

uint8_t CAN_InitFilter(uint32_t bank)
{
	uint8_t RetVal = 1;
    /* FIFO 0 assignation for the filter */
    CAN1->FA1R |= bank;

	return RetVal;
}

