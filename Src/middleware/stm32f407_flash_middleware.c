/*
 * stm32f407_flash_middleware.c
 *
 *  Created on: Nov 8, 2022
 *      Author: Linh
 */
#include "stm32f407vg.h"
//#include "stm32f407_flash_middleware.h"
#include <driver/stm32f407_flash_driver.h>

/**
* @brief          IP wrapper sector write function.
* @details        Route the write job to appropriate low level IP function.
* @implements     Fls_IPW_SectorWrite_Activity
*/
FLS_JobResultType Fls_IPW_Read(const uint32_t u32StartAddr,
                                      const uint32_t u32Length,
                                      const uint8_t *pJobDataSrcPtr
                                     )
{
	FLS_JobResultType eLldRetVal = FLS_JOB_FAILED;

    /* Decide the IP used: internal flash or external QSPI */
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
	eLldRetVal = Flash_Read_Driver(u32StartAddr, pJobDataSrcPtr, u32Length);
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */

    return eLldRetVal;
}



/**
* @brief          IP wrapper sector write function.
* @details        Route the write job to appropriate low level IP function.
* @implements     Fls_IPW_SectorWrite_Activity
*/
FLS_JobResultType Fls_IPW_SectorWrite(const uint32_t u32StartAddr,
                                      const uint32_t u32Length,
                                      const uint8_t *pJobDataSrcPtr,
                                      const boolean bAsynch
                                     )
{
	FLS_JobResultType eLldRetVal = FLS_JOB_OK;

    /* Decide the IP used: internal flash or external QSPI */
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
        FLASH_Write_Word(u32StartAddr, u32Length, pJobDataSrcPtr);
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */

    return eLldRetVal;
}



/**
* @brief          IP wrapper sector erase function.
* @details        Route the erase job to appropriate low level IP function.
* @implements     Fls_IPW_SectorErase_Activity
*/
FLS_JobResultType Fls_IPW_SectorErase(const Fls_Sector  Sector,
                                      boolean bAsynch
                                     )
{
    FLS_JobResultType eLldRetVal = FLS_JOB_OK;
    bAsynch = FALSE;

    /* Decide the IP used: internal flash or external QSPI */
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
    if (FALSE == bAsynch)
    {
        eLldRetVal = Flash_Sync_Erase(Sector, 100);
    }
	else
	{
		eLldRetVal = Flash_ASync_Erase(Sector, 100);
	}
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */

    return eLldRetVal;
}
