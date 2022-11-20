/*
 * stm32f407vg_usart_driver.c
 *
 *  Created on: Nov 10, 2022
 *      Author: Linh
 */

 #include <stm32f407_usart_driver.h>


 void USART_PeriClockControl(USART_RegDef_t *pUSARTx, uint8_t EnorDi)
 {

 }


void USART_Init();
void USART_DeInit();
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
