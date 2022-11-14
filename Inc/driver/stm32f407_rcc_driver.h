/*
 * stm32f407vg_rcc_driver.h
 *
 *  Created on: Oct 18, 2022
 *      Author: Linh
 */

#ifndef INC_STM32F407XX_RCC_DRIVER_H_
#define INC_STM32F407XX_RCC_DRIVER_H_

#include "stm32f407vg.h"

/*
*   rcc register definition structure
*/
typedef struct
{
    __IO uint32_t CR;
    __IO uint32_t PLLCFGR;
    __IO uint32_t CFGR;
    __IO uint32_t CIR;
    __IO uint32_t AHB1RSTR;
    __IO uint32_t AHB2RSTR;
    __IO uint32_t AHBB3RSTR;
    __IO uint32_t RESERVED1;
    __IO uint32_t APB1RSTR;
    __IO uint32_t APB2RSTR;
    __IO uint32_t RESERVED2;
    __IO uint32_t RESERVED3;
    __IO uint32_t AHB1ENR;
    __IO uint32_t AHB2ENR;
    __IO uint32_t AHB3ENR;
    __IO uint32_t RESERVED4;
    __IO uint32_t APB1ENR;
    __IO uint32_t APB2ENR;
    __IO uint32_t RESERVED5;
    __IO uint32_t RESERVED6;
    __IO uint32_t AHB1LPENR;
    __IO uint32_t AHB2LPENR;
    __IO uint32_t AHB3LPENR;
    __IO uint32_t RESERVED7;
    __IO uint32_t APB1LPENR;
    __IO uint32_t APB2LPENR;
    __IO uint32_t RESERVED8;
    __IO uint32_t RESERVED9;
    __IO uint32_t BDCR;
    __IO uint32_t CSR;
    __IO uint32_t RESERVED10;
    __IO uint32_t RESERVED11;
    __IO uint32_t SSCGR;
    __IO uint32_t PLLI2SCFGR;
    __IO uint32_t PLLSAICFGR;
    __IO uint32_t DCKCFGR;
}RCC_RegDef_t;


void RCC_APB2PeriphResetCmd(uint32_t RCC_APB2Periph, uint8_t EnorDi);
void RCC_APB1PeriphResetCmd(uint32_t RCC_APB1Periph, uint8_t EnorDi);
void RCC_BackupResetCmd(uint8_t EnorDi);
void RCC_ClockSecuritySystemCmd(uint8_t EnorDi);
void RCC_MCOConfig();
uint8_t RCC_GetFlagStatus();
void RCC_ClearFlag(void);
uint8_t RCC_GetITStatus();
void RCC_ClearITPendingBit();

#endif /*INC_STM32F407XX_RCC_DRIVER_H_*/
