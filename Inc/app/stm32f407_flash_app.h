/*
 * stm32f407_flash_app.h
 *
 *  Created on: Nov 9, 2022
 *      Author: Linh
 */

#ifndef APP_STM32F407_FLASH_APP_H_
#define APP_STM32F407_FLASH_APP_H_
#include "stm32f407vg.h"
#include "middleware/stm32f407_flash_middleware.h"

typedef uint32_t Fls_LengthType;

FLS_JobResultType Fls_Read(uint32_t SourceAddress,
                uint32_t * TargetAddressPtr,
                uint32_t Length
                );

FLS_JobResultType Fls_Write(uint32_t TargetAddress,
                            const uint32_t * SourceAddressPtr,
                            Fls_LengthType Length,
                            const boolean bAsynch
                                       );

                                       
FLS_JobResultType Fls_Erase(Fls_Sector  Sector,
                         Fls_LengthType Length
                        );


#endif /* APP_STM32F407_FLASH_APP_H_ */
