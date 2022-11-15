/*
 * stm32f407_flash_middleware.h
 *
 *  Created on: Nov 9, 2022
 *      Author: Linh
 */


#include "stm32f407vg.h"
#include "driver/stm32f407_flash_driver.h"


/**
* @brief          IP wrapper sector write function.
* @details        Route the write job to appropriate low level IP function.
* @implements     Fls_IPW_SectorWrite_Activity
*/
FLS_JobResultType Fls_IPW_SectorWrite(const uint32_t u32StartAddr,
                                      const uint32_t u32Length,
                                      const uint8_t *pJobDataSrcPtr,
                                      const boolean bAsynch
                                     );

/**
* @brief          IP wrapper sector erase function.
* @details        Route the erase job to appropriate low level IP function.
* @implements     Fls_IPW_SectorErase_Activity
*/
FLS_JobResultType Fls_IPW_SectorErase(const Fls_Sector  Sector,
                                      boolean bAsynch
                                     );

FLS_JobResultType Fls_IPW_Read(const uint32_t u32StartAddr,
                                      const uint32_t u32Length,
                                      const uint8_t *pJobDataSrcPtr
                                     );
