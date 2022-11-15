/*
 * stm32f407_flash_driver.c
 *
 *  Created on: Nov 6, 2022
 *      Author: Linh
 */


#include <driver/stm32f407_flash_driver.h>

FLS_JobResultType Flash_Read_Driver(volatile uint32_t u32StartAddr,
					uint32_t *pDestAddressPtr,
					uint32_t u322Length
					)
{
	FLS_JobResultType Fls_JobResult = FLS_JOB_OK;
	for(int i=0; i < u322Length; i++)
	{
		*(uint32_t *)(pDestAddressPtr + i) = *(uint32_t*)(u32StartAddr +i*4);

	}
	return Fls_JobResult;
}

FLS_JobResultType FLASH_Write_Word(	volatile uint32_t u32StartAddr,
						const uint32_t u32Length,
						uint32_t *BufferWrite)
{
	/* Check that no Flash memory operation is ongoing by checking the BSY bit in the FLASH_CR register */
	while((FLASH->SR & FLASH_SR_BSY) == FLASH_SR_BSY);
	/* Check unlock sequences */
	if ((FLASH->CR & FLASH_CR_LOCK) == FLASH_CR_LOCK )
	{
		Linh_FLASH_Unlock();
	}

/* If the previous operation is completed, proceed to program the new data */
	CLEAR_BIT(FLASH->CR, FLASH_CR_PSIZE);
	FLASH->CR |= FLASH_PSIZE_WORD;
	FLASH->CR |= FLASH_CR_PG;

	uint32_t u32WriteAddr = u32StartAddr;
	for(int i=0; i < u32Length; i++)
	{
		u32WriteAddr += i;
		*(__IO uint32_t*)(u32StartAddr +i*4) = *(uint32_t *)(BufferWrite + i);

	}
	
	while((FLASH->SR & FLASH_SR_BSY) == FLASH_SR_BSY);
	return FLS_JOB_OK;
}

FLS_JobResultType Flash_ASync_Erase(volatile uint8_t sector, uint32_t u32TimeOut)
{

}

FLS_JobResultType Flash_Sync_Erase(volatile uint8_t sector, uint32_t u32TimeOut)
{
	FLS_JobResultType eRetVal = FLS_JOB_OK;
	/* Check that no Flash memory operation is ongoing by checking the BSY bit in the FLASH_CR register */
	while(((FLASH->SR & FLASH_SR_BSY) == FLASH_SR_BSY) && (u32TimeOut > 0U))
	{
		/*  Wating for Bsy bit */
		u32TimeOut --;
		if (u32TimeOut == 0)
		{
			//return FLASH_ERRORS_TIMEOUT;
			return FLS_JOB_FAILED;
		}
	}
	/* Check unlock sequences */
	if ((FLASH->CR & FLASH_CR_LOCK) == FLASH_CR_LOCK )
	{
		Linh_FLASH_Unlock();
	}
	/*
	 * 1. Check that no Flash memory operation is ongoing by checking the BSY bit in the
	FLASH_SR register
		2. Set the SER bit and select the sector out of the 12 sectors (for STM32F405xx/07xx and
	STM32F415xx/17xx) and out of 24 (for STM32F42xxx and STM32F43xxx) in the main
	memory block you wish to erase (SNB) in the FLASH_CR register
		3. Set the STRT bit in the FLASH_CR register
		4. Wait for the BSY bit to be cleared
	 */
	//clear psize
	FLASH->CR &= ~(3 << 8);
	//erase 32 bit
	FLASH->CR |= FLASH_PSIZE_WORD;
	//clear SNB
	FLASH->CR &= ~(0x1F << 3);
	//set SER
	FLASH->CR |= 1 << 1;
	//clear sector
	FLASH->CR |= sector << 3;
	FLASH->CR |= 1 << 16;
	while((FLASH->SR & FLASH_SR_BSY) == FLASH_SR_BSY);
	CLEAR_BIT(FLASH->CR, (FLASH_CR_SER | FLASH_CR_SNB));

	return FLS_JOB_OK;
}


void Linh_FLASH_Unlock(void)
{
 //HAL_StatusTypeDef status = HAL_OK;

 if(READ_BIT(FLASH->CR, FLASH_CR_LOCK) != RESET)
 {
   /* Authorize the FLASH Registers access */
   WRITE_REG(FLASH->KEYR, FLASH_KEY1);
   WRITE_REG(FLASH->KEYR, FLASH_KEY2);

   /* Verify Flash is unlocked */
   if(READ_BIT(FLASH->CR, FLASH_CR_LOCK) != RESET)
   {
     //status = HAL_ERROR;
   }
 }

 //return status;
}
