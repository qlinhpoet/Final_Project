/*
 * stm32f407vg_usart_driver.c
 *
 *  Created on: Nov 10, 2022
 *      Author: Linh
 */
#include <driver/stm32f407_usart_driver.h>
#include <driver/stm32f407_gpio_driver.h>

void USART_Init(USART_RegDef_t *pUSARTx)
{
    /*enable clock UART5, GPIOC, GPIOD*/
    RCC->APB1ENR |= 1<<20;
    RCC->AHB1ENR |= 1<<2;
    RCC->AHB1ENR |= 1<<3;
    pUSARTx->BRR;
    /**UART5 GPIO Configuration
		  	    PC12     ------> UART5_TX
		  	    PD2     ------> UART5_RX
		  	    */
    GPIO_PinConfig_t GPIO_InitStruct;
	GPIO_InitStruct.GPIO_PinNumber = GPIO_PIN_12;
	GPIO_InitStruct.GPIO_PinMode = GPIO_MODE_ALTFN;
	GPIO_InitStruct.GPIO_PuPdControl = GPIO_PullUp;
	GPIO_InitStruct.GPIO_Speed = GPIO_SPEED_VeryHIGH;
	GPIO_InitStruct.GPIO_PinAltFunMode = ((uint8_t)0x08);
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_PinNumber = GPIO_PIN_2;
	GPIO_InitStruct.GPIO_PinMode = GPIO_MODE_ALTFN;
	GPIO_InitStruct.GPIO_PuPdControl = GPIO_PullUp;
	GPIO_InitStruct.GPIO_Speed = GPIO_SPEED_VeryHIGH;
	GPIO_InitStruct.GPIO_PinAltFunMode = ((uint8_t)0x08);
	GPIO_Init(GPIOD, &GPIO_InitStruct);

	/*disabel*/
	UART5->CR1 &= ~(1 << 13);

	/* Set the UART Communication parameters */
	/*/UART BRR = mantissa + overflow + fraction
            	= (UART DIVMANT << 4) + (UART DIVFRAQ & 0xF0) + (UART DIVFRAQ & 0x0FU) */
	UART5->BRR = 0x683;
	UART5->CR1 = 0x0c;
	/* Enable the peripheral */
	UART5->CR1 |= 1UL << 13;

}
void USART_DeInit();

void UART_Transmit(USART_RegDef_t *pUSARTx, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    uint8_t TxXferSize = Size;
    uint8_t TxXferCount = Size;

    while (TxXferCount > 0U)
    {
      while (((UART5->SR & (1 << 7)) == (1 << 7) ? SET : RESET) == RESET);
      TxXferCount--;
      UART5->DR = (*pData++ & (uint8_t)0xFF);
    }
}

void USART_SentData(USART_RegDef_t *pUSARTx, uint8_t Data)
{
    /* Transmit Data*/
    pUSARTx->DR = Data & (uint8_t)0xff;
    /*wait*/
    while((pUSARTx->SR) | (1<<7) == 0);
}

uint8_t USART_ReceiveData(USART_RegDef_t *pUSARTx, uint8_t Data)
{
    return (uint8_t)pUSARTx->DR;
}

/*
*   Interrupt config
*/

void USART_ITConfig(USART_RegDef_t *pUSARTx, uint16_t USART_IT, State EnorDi)
{

    /* The CTS Interrupt is not available for UART4 and UART5 */
    if(USART_IT == USART_CTS_Flag)
    {
        if( pUSARTx == UART4_BASEADDRESS || pUSARTx == UART5_BASEADDRESS)
        {
            while(1);
            /**/
        }
    }


}
void USART_GetITStatus()
{

}


/*
*   Clear Pending bit
*/
void USART_ClearPendingBit()
{

}


/*
*   Get USART Flag
*/
Flag_Status USART_GetFlagStatus(USART_RegDef_t* pUSARTx, uint16_t USART_FLAG)
{
    Flag_Status BitStatus = 0;

    /* The CTS flag is not available for UART4 and UART5 */
    if(USART_FLAG == USART_CTS_Flag)
    {
        if( pUSARTx == UART4_BASEADDRESS || pUSARTx == UART5_BASEADDRESS)
        {
            while(1);
            /**/
        }
    }

    if( (pUSARTx->SR & USART_FLAG) == 0 )
    {
        BitStatus == RESET;
    }else
    {
        BitStatus == SET;
    }
    return BitStatus;
}

/*
*   Clear USART Flag
*/
void USART_ClearFlag(USART_RegDef_t* pUSARTx, uint16_t USART_FLAG)
{
    /* The CTS flag is not available for UART4 and UART5 */
    if(USART_FLAG == USART_CTS_Flag)
    {
        if( pUSARTx == UART4_BASEADDRESS || pUSARTx == UART5_BASEADDRESS)
        {
            while(1);
            /**/
        }
    }
    /*all bit of usart->sr are set by hardware*/
    pUSARTx->SR = (uint16_t)~(USART_FLAG);
}
