
#include "app/stm32f407_flash_app.h"

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
static FLS_JobResultType Fls_eJobResult;
/**
 * @brief            Reads from flash memory.
 * @details          Starts a read job asynchronously.
 *
 * @param[in]        SourceAddress        Source address in flash memory.
 * @param[in]        Length               Number of bytes to read.
 * @param[out]       TargetAddressPtr     Pointer to target data buffer.
 *
 * @return           Fls_eJobResult
 * @retval           FLS_JOB_OK                 Read command has been accepted.
 * @retval           FLS_JOB_FAILED             Read command has not been accepted.
 *
 * @api
 *
 * @pre            The module has to be initialized and not busy.
 * @post           @p Fls_Read changes module status and some internal variables
 *
 * @implements       Fls_Read_Activity
 *
 */
FLS_JobResultType Fls_Read(uint32_t SourceAddress,
                uint32_t * TargetAddressPtr,
                uint32_t Length
                )
{
	Fls_eJobResult = (FLS_JobResultType)FLS_JOB_FAILED;

    Fls_eJobResult = Fls_IPW_Read(SourceAddress, Length, TargetAddressPtr);

    return Fls_eJobResult;
}

/**
 * @brief        Write up to one physical flash sector
 *
 * @details      Call low level flash driver service to write given number of bytes
 *               at given sector offset
 *
 * @param[in]    TargetAddress Source address in flash memory to write data from
 * @param[in]    Length Number of bytes to read
 *
 * @return       FLS_JobResultType
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
	Fls_eJobResult = (FLS_JobResultType)FLS_JOB_FAILED;

	Fls_eJobResult = Fls_IPW_SectorWrite(TargetAddress, Length, SourceAddressPtr, bAsynch);
    
    return Fls_eJobResult;
}

/**
 * @brief            Erase one or more complete flash sectors.
 * @details          Starts an erase job asynchronously. The actual job is performed
 *                   by the @p Fls_MainFunction.
 *
 * @param[in]        Sector               Sector in flash memory.
 * @param[in]        Length               Number of bytes to erase.
 *
 * @return           Fls_eJobResult
 * @retval           FLS_JOB_OK                    Erase command has been accepted.
 * @retval           FLS_JOB_FAILED                Erase command has not been accepted.
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
	Fls_eJobResult = (FLS_JobResultType)FLS_JOB_FAILED;

	Fls_eJobResult = Fls_IPW_SectorErase(Sector, FALSE);

    return Fls_eJobResult;
}
