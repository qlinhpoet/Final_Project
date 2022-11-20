#include <stdio.h>
#include "stm32f407vg.h"

uint32_t *pSyst_CSR = (uint32_t*)0xE000E010;
uint32_t *pSYST_RVR = (uint32_t*)0xE000E014;
uint32_t *pSYST_CVR = (uint32_t*)0xE000E018;
typedef struct
{
	volatile uint32_t CSR;
	volatile uint32_t RVR;
	volatile uint32_t CVR;
	volatile uint32_t CALIB;
}SYSTICK_RegDef_t;
#define SysTick_BaseAddr	0xE000E010
#define Systick		((SYSTICK_RegDef_t*)SysTick_BaseAddr)
void Systick_Delay_ms(uint32_t u32Delay);

void GPIO_Lib_Config();
uint32_t s;
uint32_t BufferWrite[3] = {0x100,0x200,0x300};
int main()
{
	GPIO_Lib_Config();
	s = Flash_Read((uint32_t)0x0800C000);
	Fls_Erase(Fls_Sector_3, 1);
	Fls_Write((uint32_t)0x0800C000, BufferWrite, 3, FALSE);
	s = Flash_Read((uint32_t)0x0800C000);
	while(1)
	{
		GPIO_AL_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
		Systick_Delay_ms(1000);
	}
}

void Systick_Delay_ms(uint32_t u32Delay)
{
	while(u32Delay)
	{
		/*Cortex System timer clock max 168/8 MHz*/
		Systick->RVR = 21000-1;
		Systick->CVR = 0;

		/*no exception*/
		/*clear counter flag*/
		/*enable counter*/
		/*processor clock - 72M*/
		Systick->CSR = 0x05;

		while(((Systick->CSR) & (1<<16)) == 0)
		{

		}
		--u32Delay;
	}
}

void GPIO_Lib_Config()
{
	GPIO_Handle_t GPIO_InitStrcture;



	GPIO_InitStrcture.pGPIOx = GPIOD;

	GPIO_InitStrcture.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIO_InitStrcture.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GPIO_InitStrcture.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_MEDIUM;
	GPIO_InitStrcture.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_AL_PeriClockControl(GPIOD, ENABLE);
	GPIO_AL_Init(&GPIO_InitStrcture);
}
