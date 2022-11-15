#include <stdio.h>
#include "stm32f407vg.h"
#include "app/stm32f407_flash_app.h"

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
uint32_t BufferWrite[3] = {0x1,0x2,0x3};
uint32_t *BufferRead;
int main()
{
	GPIO_Lib_Config();
	s = Fls_Read((uint32_t)SECTOR_3, &BufferRead, 3);
	Fls_Erase(Fls_Sector_3, 1);
	Fls_Write((uint32_t)0x0800C000, BufferWrite, 3, FALSE);
	s = Fls_Read((uint32_t)SECTOR_3, &BufferRead, 3);
	while(1)
	{
		GPIO_TogglePin(GPIOD, GPIO_PIN_13);
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
	GPIO_PeriClockControl(GPIOD, ENABLE);

	GPIO_PinConfig_t GPIO_InitStrcture;
	GPIO_InitStrcture.GPIO_PinMode = GPIO_MODE_OUT;
	GPIO_InitStrcture.GPIO_PinNumber = GPIO_PIN_13;
	GPIO_InitStrcture.GPIO_Speed = GPIO_SPEED_MEDIUM;
	GPIO_InitStrcture.GPIO_PuPdControl = GPIO_PullUp;

	GPIO_Init(GPIOD, &GPIO_InitStrcture);
}
