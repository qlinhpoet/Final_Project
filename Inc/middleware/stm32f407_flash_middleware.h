/*
 * stm32f407_flash_middleware.h
 *
 *  Created on: Nov 9, 2022
 *      Author: Linh
 */


#include "stm32f407vg.h"
#include "stm32f407_flash_driver.h"


/**
* @brief          IP wrapper sector write function.
* @details        Route the write job to appropriate low level IP function.
* @implements     Fls_IPW_SectorWrite_Activity
*/
Fls_LLDReturnType Fls_IPW_SectorWrite(const Fls_AddressType u32SectorOffset,
                                      const Fls_AddressType u32Length,
                                      const uint8 *pJobDataSrcPtr,
                                      const boolean bAsynch
                                     )
{
    Fls_LLDReturnType eLldRetVal = FLASH_E_FAILED;
    Fls_HwChType eHwCh;

    /* Get channel type(INTERNAL, QSPI,...) to determine the HW IP used(internal or external flash). */
    eHwCh = (*(Fls_pConfigPtr->paHwCh))[Fls_u32JobSectorIt];

    /* Decide the IP used: internal flash or external QSPI */
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
    if (FLS_CH_INTERN == eHwCh)
    {
        eLldRetVal = Fls_IPW_SectorWriteFtfcJobs(u32SectorOffset, u32Length, pJobDataSrcPtr, bAsynch);
    }
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */


#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
    if (FLS_CH_QSPI == eHwCh)
    {
        eLldRetVal = Fls_IPW_SectorWriteQspiJobs(u32SectorOffset, u32Length, pJobDataSrcPtr, bAsynch);
    }
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */

    return eLldRetVal;
}

/**
* @brief          IP wrapper sector erase function.
* @details        Route the erase job to appropriate low level IP function.
* @implements     Fls_IPW_SectorErase_Activity
*/
FLS_JobResultType Fls_IPW_SectorErase(const Fls_Sector  Sector,
                                      boolean bAsynch
                                     );
