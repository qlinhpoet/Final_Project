#include <app/stm32f407_can_app.h>
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

CAN_HandleTypeDef hcan1;
void Systick_Delay_ms(uint32_t u32Delay);
static void GPIO_Lib_Config();
static void MX_CAN1_Init(void);
static void CAN_SetInterrupt(void);
uint32_t DataNode1;
uint32_t DataNode2;
CAN_TxHeaderTypeDef   TxHeader;
CAN_RxHeaderTypeDef RxHeader;
uint8_t TxData[8] = {0x1,0x7,0x9,0X20,0X00};
uint8_t RxData[8];

uint32_t TxMailbox;
uint32_t RxFifo;

/* uart*/
uint8_t UartTx[9]= "";
uint32_t v = 47;
uint32_t s = 33;
uint32_t p = 102;
uint32_t Total = 30;
void TachSo(uint32_t v, uint32_t s, uint32_t p, uint8_t *Tx);
uint32_t huart5;
uint32_t BufferWrite[3] = {0x1,0x2,0x3};
uint32_t *BufferRead;
int main()
{
	  SET_BIT(RCC->APB1ENR, (1<<25));
	  /* Delay after an RCC peripheral clock enabling */
	  Systick_Delay_ms(200);
      SET_BIT(RCC->APB1ENR, (1<<28));
      Systick_Delay_ms(200);
	  MX_CAN1_Init();
	  CAN_SetInterrupt();
	  CAN_BaudRate(200000);
	  CAN_Start(&hcan1);

	  UART5_Config();
	  GPIO_Lib_Config();

	//Fls_Read((uint32_t)SECTOR_3, &Total, 3);
	Fls_Erase(Fls_Sector_3, 1);
	Fls_Write((uint32_t)SECTOR_3, &Total, 1, FALSE);
	Fls_Read((uint32_t)SECTOR_3, &Total, 3);
	while(1)
	{
		TachSo(v,Total,p,&UartTx);
		//UART_Transmit1(&huart5, &Tx, 9, 100);
//		GPIO_TogglePin(GPIOD, GPIO_PIN_13);
		Systick_Delay_ms(2000);
	}
}
void CAN_SetInterrupt(void)
{
	CAN1->IER |= (1<<1);
	NVIC->ISER[0] = (uint32_t)(1UL << (((uint32_t)20) & 0x1FUL));
}
void CAN1_RX0_IRQHandler(void)
{
	GPIO_TogglePin(GPIOD, GPIO_PIN_13);
	CAN_GetRxMessage(&hcan1,0U,&RxHeader, RxData);
	if(RxHeader.StdId == 0x179)
	{
		DataNode1 = RxData[0];
		p=DataNode1;
	}
	if(RxHeader.StdId == 0x200)
	{
		DataNode2 = RxData[0];
		v=DataNode2;
	}
	//Systick_Delay_ms(200);

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

	  CAN_FilterTypeDef canfilterconfig;
	  canfilterconfig.FilterActivation = 1U;
	  canfilterconfig.FilterBank = 10;  // which filter bank to use from the assigned ones
	  canfilterconfig.FilterFIFOAssignment = 0U;
	  canfilterconfig.FilterIdHigh = (0x200<<5);
	  canfilterconfig.FilterIdLow = 0;
	  canfilterconfig.FilterMaskIdHigh = 0;
	  canfilterconfig.FilterMaskIdLow = 0x0000;
	  canfilterconfig.FilterMode = 0U;
	  canfilterconfig.FilterScale = 1U;
	  canfilterconfig.SlaveStartFilterBank = 0;  // doesn't matter in single can controllers

	  CAN_ConfigFilter(&hcan1, &canfilterconfig);

	  CAN_FilterTypeDef canfilterconfig1;
	  canfilterconfig1.FilterActivation = 1U;
	  canfilterconfig1.FilterBank = 11;  // which filter bank to use from the assigned ones
	  canfilterconfig1.FilterFIFOAssignment = 0U;
	  canfilterconfig1.FilterIdHigh = (0x179<<5);
	  canfilterconfig1.FilterIdLow = 0;
	  canfilterconfig1.FilterMaskIdHigh = 0;
	  canfilterconfig1.FilterMaskIdLow = 0x0000;
	  canfilterconfig1.FilterMode = 0U;
	  canfilterconfig1.FilterScale = 1U;
	  canfilterconfig1.SlaveStartFilterBank = 0;  // doesn't matter in single can controllers

	  CAN_ConfigFilter(&hcan1, &canfilterconfig1);
}
void GPIO_Lib_Config()
{
	GPIO_PeriClockControl(GPIOB, ENABLE);

	GPIO_PinConfig_t GPIO_InitStrcture;

	GPIO_InitStrcture.GPIO_PinNumber = GPIO_PIN_8|GPIO_PIN_9;
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
	GPIO_PeriClockControl(GPIOD, ENABLE);

	GPIO_PinConfig_t GPIO_InitStrcture3;
	GPIO_InitStrcture3.GPIO_PinMode = GPIO_MODE_OUT;
	GPIO_InitStrcture3.GPIO_PinNumber = GPIO_PIN_13;
	GPIO_InitStrcture3.GPIO_Speed = GPIO_SPEED_MEDIUM;
	GPIO_InitStrcture3.GPIO_PuPdControl = GPIO_PullUp;

	GPIO_Init(GPIOD, &GPIO_InitStrcture3);
}

void TachSo(uint32_t v, uint32_t s, uint32_t p, uint8_t *UartTx)
{
	for(int i=8; i>=6; i--)
	{
		*(UartTx+i) = p % 10;
		p = (p - *(UartTx+i)) / 10;
		*(UartTx+i) += 48;
	}
	*(UartTx+5) = ';';
	for(int i=4; i>=3; i--)
	{
		*(UartTx+i) = s % 10;
		s = (s - *(UartTx+i)) / 10;
		*(UartTx+i) += 48;
	}
	*(UartTx+2) = ';';
	for(int i=1; i>=0; i--)
	{
		*(UartTx+i) = v % 10;
		v = (v - *(UartTx+i)) / 10;
		*(UartTx+i) += 48;
	}
}
