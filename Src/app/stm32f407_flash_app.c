
#include "app/stm32f407_flash_app.h"

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief        Write up to one physical flash sector
 *
 * @details      Call low level flash driver service to write given number of bytes
 *               at given sector offset
 *
 * @param[in]    SectorOffset Flash sector offset to write data from
 * @param[in]    Length Number of bytes to read
 *
 * @return       Fls_LLDReturnType
 * @retval       FLASH_E_OK write operation succeeded
 * @retval       FLASH_E_FAILED write operation failed due to a hardware error
 *
 * @pre          The module must be initialized, the Fls_u32JobSectorIt internal job
 *               variable must contain valid index of logical sector to write,
 *               SectorOffset and Length must be in physical sector boundary and page
 *               aligned, Fls_pJobDataSrcPtr internal job variable must point to data
 *               write buffer
 *
 */
FLS_JobResultType Fls_Write(uint32_t TargetAddress,
                            const uint32_t * SourceAddressPtr,
                            Fls_LengthType Length,
                            const boolean bAsynch
                                       )
{
    FLS_JobResultType RetVal = (FLS_JobResultType)FLS_JOB_OK;

    RetVal = Fls_IPW_SectorWrite(TargetAddress, Length, SourceAddressPtr, bAsynch);

#if ( (FLS_ERASE_VERIFICATION_ENABLED == STD_ON) || (FLS_WRITE_VERIFICATION_ENABLED == STD_ON) )
    /* A verification has been failed, convert to FLASH_E_FAILED */
    else if (FLASH_E_BLOCK_INCONSISTENT == RetVal)
    {
        RetVal = FLASH_E_FAILED;
    }
    else
    {
        ; /* empty else at the end of an else-if structure */
    }
#endif /* (FLS_ERASE_VERIFICATION_ENABLED == STD_ON) || (FLS_WRITE_VERIFICATION_ENABLED == STD_ON) */
    return RetVal;
}

/**
 * @brief            Erase one or more complete flash sectors.
 * @details          Starts an erase job asynchronously. The actual job is performed
 *                   by the @p Fls_MainFunction.
 *
 * @param[in]        TargetAddress        Target address in flash memory.
 * @param[in]        Length               Number of bytes to erase.
 *
 * @return           Std_ReturnType
 * @retval           E_OK                    Erase command has been accepted.
 * @retval           E_NOT_OK                Erase command has not been accepted.
 *
 * @api
 *
 * @pre              The module has to be initialized and not busy.
 * @post             @p Fls_Erase changes module status and some internal variables
 *                   (@p Fls_u32JobSectorIt, @p Fls_u32JobSectorEnd, @p Fls_Job,
 *                   @p Fls_eJobResult).
 *
 * @implements       Fls_Erase_Activity
 *
 */
FLS_JobResultType Fls_Erase(Fls_Sector  Sector, 
                         Fls_LengthType Length
                        )
{
    FLS_JobResultType RetVal = (FLS_JobResultType)FLS_JOB_OK;

    RetVal = Fls_IPW_SectorErase(Sector, FALSE);

    return RetVal;
}
