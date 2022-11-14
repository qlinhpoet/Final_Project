/*
 * stm32f407vg_gpio_driver.c
 *
 *  Created on: Oct 18, 2022
 *      Author: Linh
 */

 #include <driver/stm32f407_gpio_driver.h>

 /*
*	GPIO control
*/

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}else if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_EN();
		}
	}

	if(EnorDi == DISABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DIS();
		}else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DIS();
		}else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DIS();
		}else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DIS();
		}else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DIS();
		}else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_DIS();
		}else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_DIS();
		}else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DIS();
		}else if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_DIS();
		}
	}
}



void GPIO_Init(GPIO_RegDef_t *pGPIOx, GPIO_PinConfig_t *GPIO_PinConfig)
{
	uint32_t temp;
	//enable GPIOx clock
	GPIO_PeriClockControl(pGPIOx, ENABLE);

	//1 . configure the mode of gpio pin
	if(GPIO_PinConfig->GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		/*the none interrupt mode*/
		temp = ((uint32_t)GPIO_PinConfig->GPIO_PinMode) << (2 * GPIO_PinConfig->GPIO_PinNumber);
		pGPIOx->MODER &= ~((uint32_t)0x3 << (2 * (uint32_t)GPIO_PinConfig->GPIO_PinNumber));	//clear 2 bit
		pGPIOx->MODER |= temp;		//gan gia tri 2 bit chon che do
	}else
	{
		/*with interrupt mode- chua viet duoc :))*/
	}

	//2. configure the speed
	temp = ((uint32_t)GPIO_PinConfig->GPIO_Speed)<<(2 * GPIO_PinConfig->GPIO_PinNumber);
	pGPIOx->OSPEED &= ~((uint32_t)0x3 << 2 * (uint32_t)GPIO_PinConfig->GPIO_PinNumber);			//clear 2 bit
	pGPIOx->OSPEED |= temp;

	//3. configure the pupd settings
	temp = (GPIO_PinConfig->GPIO_PuPdControl) << (2 * GPIO_PinConfig->GPIO_PinNumber);
	pGPIOx->PUPDR &= ~((uint32_t)0x3 << (2 * (uint32_t)GPIO_PinConfig->GPIO_PinNumber));		//clear 2 bit
	pGPIOx->PUPDR |= temp;

	//4. configure the otyper
	temp = (GPIO_PinConfig->GPIOOTyper) << (GPIO_PinConfig->GPIO_PinNumber);
	pGPIOx->OTYPER &= ~((uint32_t)0x1 << (uint32_t)(GPIO_PinConfig->GPIO_PinNumber));			//clear 1 bit
	pGPIOx->OTYPER |= temp;

	//5. configure the alt functionality
	if(GPIO_PinConfig->GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		//configure the alt function registers.
		uint8_t temp1, temp2;
		/*	pin0-7:AFR[0]	;	pin8-15:AFR[1]	*/
		temp1 = GPIO_PinConfig->GPIO_PinNumber / 8;
		temp2 = GPIO_PinConfig->GPIO_PinNumber  % 8;
		pGPIOx->AFR[temp1] &= ~(0xF << ( 4 * temp2 ) ); 										//clear 4 bit
		pGPIOx->AFR[temp1] |= (GPIO_PinConfig->GPIO_PinAltFunMode << ( 4 * temp2 ) );
	}
}



void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, GPIO_PIN_NUMBER PinNumber)
{

	pGPIOx->ODR  ^= ( 1 << PinNumber);
	/*
	if(pGPIOx->ODR & (1<<PinNumber))
	{
		pGPIOx->ODR &= ~(1<<PinNumber);
	}else
	{
		pGPIOx->ODR |= 1<<PinNumber;
	}
	*/
}



uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t ReadValue;
	ReadValue = (uint8_t)(0x01 & ((pGPIOx->IDR) >> PinNumber));
	return ReadValue;
}




uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	return (uint16_t)(pGPIOx->IDR);
}



void GPIO_WriteOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t u16Value)
{
	pGPIOx->ODR = u16Value;
}



void GPIO_WriteOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t EnorDi)
{
	if(EnorDi == DISABLE)
	{
		pGPIOx->ODR &= ~(1<<PinNumber);
	}else if(EnorDi == ENABLE)
	{
		pGPIOx->ODR |= 1<<PinNumber;
	}
}

/*
 * IRQ Configuration and ISR handling
 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(IRQNumber<=31)
		{
			*NVIC_ICER0 |= 1<<IRQNumber;
		}else if(IRQNumber >=32 && IRQNumber<=63)			//32 to 63
		{
			*NVIC_ICER1 |= 1 << (IRQNumber - 32);
		}else if(IRQNumber >=64 && IRQNumber<=95)			//64 to 95
		{
			*NVIC_ICER2 |= 1 << (IRQNumber - 64);
		}else if(IRQNumber >=96 && IRQNumber<=127)			//96 to 127
		{
			*NVIC_ICER3 |= 1 << (IRQNumber - 96);
		}
	}

	if(EnorDi == DISABLE)
	{
		if(IRQNumber <= 31)
		{
			*NVIC_ICER0 &= ~(1 << IRQNumber);
		}else if(IRQNumber >= 32 && IRQNumber <= 63)			//32 to 63
		{
			*NVIC_ICER1 &= ~(1 << (IRQNumber - 32));
		}else if(IRQNumber >=64 && IRQNumber<=95)			//64 to 95
		{
			*NVIC_ICER2 &= ~(1 << (IRQNumber - 64));
		}else if(IRQNumber >=96 && IRQNumber<=127)			//96 to 127
		{
			*NVIC_ICER3 &= ~(1 << (IRQNumber - 96));
		}
	}
}

/*
*	config priority for IRQ
1 thanh ghi ipr[] gom 4 fileds, dung de dat muc uu tien cho ngat tuong ung
	Co 16 muc priority cho IRQ, duoc gan gia tri bang 4 bit trong field cua cac thanh ghi IPR[]
	vdk stm32f4 gan cac ngat vao cac vi tri tu 0-n cua arm
*/

void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{
	/*1. find out the ipr register of IRQNumber*/
	uint8_t iprx = IRQNumber/4;
	/*2. tim ra field(8 bit) quy dinh priority cua loai IRQ*/
	uint8_t iprx_section = IRQNumber%4;
	/*Dua priority ve 0 truoc, vi neu chuyen tu muc IRQPriority= 1 sang 2 thi IRQPriority|0x02 = 0x03*/
	/*con tro kieu uint32 nen chi can + iprx de ra duoc dia chi thanh ghi*/
	*(NVIC_IPR_BASE_ADDR + iprx) = (*(NVIC_IPR_BASE_ADDR + iprx)&(0xff << iprx_section*8)) | (IRQPriority << (iprx_section*8 + 4));
}


void GPIO_IRQHandling(uint8_t PinNumber)
{
	/*	clear pending
		This bit is cleared by writing a ‘1’ into the bit.
	*/
	//clear the exti pr register corresponding to the pin number
	if(EXTI->PR & ( 1 << PinNumber))
	{
		//clear
		EXTI->PR |= ( 1 << PinNumber);
	}
}
