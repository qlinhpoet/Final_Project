#include <stdio.h>
#include "stm32f407vg.h"
#include "can.h"
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

CAN_HandleTypeDef hcan1;
void Systick_Delay_ms(uint32_t u32Delay);
static void GPIO_Lib_Config();
static void MX_CAN1_Init(void);
static void CAN_SetInterrupt(void);

CAN_TxHeaderTypeDef   TxHeader;
uint8_t TxData[8] = {0x1,0x7,0x9,0X20,0X00};
uint8_t RxData[8];

uint32_t TxMailbox;
int main()
{
	uint32_t Tmpreg;
	  SET_BIT(RCC->APB1ENR, 1<<25);
	  /* Delay after an RCC peripheral clock enabling */
	  Tmpreg = READ_BIT(RCC->APB1ENR, 1<<25);
	  Systick_Delay_ms(200);
//      SET_BIT(RCC->APB1ENR, (1<<28));
//      Tmpreg = READ_BIT(RCC->APB1ENR, (1<<28));
//	  Systick_Delay_ms(200);
	  MX_CAN1_Init();
	  CAN_Start(&hcan1);

	  TxHeader.DLC = 3U;  // data length
	  TxHeader.IDE = 0U;
	  TxHeader.RTR = 0U;
	  TxHeader.StdId = 0x200;  // ID

	GPIO_Lib_Config();
	while(1)
	{
		GPIO_TogglePin(GPIOD, GPIO_PIN_13);
		CAN_AddTxMessage(&hcan1,&TxHeader,TxData,&TxMailbox);
		Systick_Delay_ms(2000);
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

void MX_CAN1_Init()
{
	  hcan1.Init.Prescaler = 16;
	  hcan1.Init.Mode = 0u;
	  hcan1.Init.SyncJumpWidth = 0U;
	  hcan1.Init.TimeSeg1 = 1U;
	  hcan1.Init.TimeSeg2 = 1U;
	  hcan1.Init.TimeTriggeredMode = DISABLE;
	  hcan1.Init.AutoBusOff = DISABLE;
	  hcan1.Init.AutoWakeUp = DISABLE;
	  hcan1.Init.AutoRetransmission = DISABLE;
	  hcan1.Init.ReceiveFifoLocked = DISABLE;
	  hcan1.Init.TransmitFifoPriority = DISABLE;
	  CAN_Init(&hcan1);
}
void GPIO_Lib_Config()
{
	GPIO_PeriClockControl(GPIOB, ENABLE);
	//GPIO_PeriClockControl(GPIOD, ENABLE);

	GPIO_PinConfig_t GPIO_InitStrcture;

	GPIO_InitStrcture.GPIO_PinNumber = GPIO_PIN_9;
    GPIO_InitStrcture.GPIO_PinMode = GPIO_MODE_ALTFN;
    GPIO_InitStrcture.GPIO_Speed = GPIO_SPEED_VeryHIGH;
    GPIO_InitStrcture.GPIO_PuPdControl = GPIO_NoPull;
    GPIO_InitStrcture.GPIO_PinAltFunMode = AF9;

	GPIO_Init(GPIOB, &GPIO_InitStrcture);
	GPIO_PinConfig_t GPIO_InitStrcture1;

	GPIO_InitStrcture1.GPIO_PinNumber = GPIO_PIN_8;
    GPIO_InitStrcture1.GPIO_PinMode = GPIO_MODE_ALTFN;
    GPIO_InitStrcture1.GPIO_Speed = GPIO_SPEED_VeryHIGH;
    GPIO_InitStrcture1.GPIO_PuPdControl = GPIO_NoPull;
    GPIO_InitStrcture1.GPIO_PinAltFunMode = AF9;

	GPIO_Init(GPIOB, &GPIO_InitStrcture1);

	GPIO_PinConfig_t GPIO_InitStrcture3;
	GPIO_InitStrcture3.GPIO_PinMode = GPIO_MODE_OUT;
	GPIO_InitStrcture3.GPIO_PinNumber = GPIO_PIN_13;
	GPIO_InitStrcture3.GPIO_Speed = GPIO_SPEED_MEDIUM;
	GPIO_InitStrcture3.GPIO_PuPdControl = GPIO_PullUp;

	GPIO_Init(GPIOD, &GPIO_InitStrcture3);

}
