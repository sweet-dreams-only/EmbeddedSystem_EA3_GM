/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2011 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Components/Rte_NxtrLibs.h
 *     Workspace:  C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue Mar 21 14:08:38 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_NXTRLIBS_H
# define _RTE_NXTRLIBS_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"


/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

# define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
# include "MemMap.h"

extern VAR(UInt32, RTE_VAR_INIT) Rte_Irv_NxtrLibs_Time_mS_u32;

# define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
# include "MemMap.h"


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

#  define Rte_IrvRead_DtrmnElapsedTime_mS_u16_Time_mS_u32() \
  Rte_Irv_NxtrLibs_Time_mS_u32

#  define Rte_IrvRead_DtrmnElapsedTime_mS_u32_Time_mS_u32() \
  Rte_Irv_NxtrLibs_Time_mS_u32

#  define Rte_IrvRead_GetSystemTime_mS_u32_Time_mS_u32() \
  Rte_Irv_NxtrLibs_Time_mS_u32

#  define Rte_IrvRead_SystemTime_Per1_Time_mS_u32() \
  Rte_Irv_NxtrLibs_Time_mS_u32

#  define Rte_IrvWrite_SystemTime_Per1_Time_mS_u32(data) \
  (Rte_Irv_NxtrLibs_Time_mS_u32 = (data))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_NXTRLIBS_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_NXTRLIBS_APPL_CODE) DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) ElapsedTime);

FUNC(void, RTE_NXTRLIBS_APPL_CODE) DtrmnElapsedTime_mS_u32(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) ElapsedTime);

FUNC(void, RTE_NXTRLIBS_APPL_CODE) DtrmnElapsedTime_uS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) ElapsedTime);

FUNC(void, RTE_NXTRLIBS_APPL_CODE) DtrmnElapsedTime_uS_u32(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) ElapsedTime);

FUNC(void, RTE_NXTRLIBS_APPL_CODE) GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) CurrentTime);

FUNC(void, RTE_NXTRLIBS_APPL_CODE) GetSystemTime_uS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) CurrentTime);

FUNC(void, RTE_NXTRLIBS_APPL_CODE) SystemTime_Per1(void);

# define RTE_STOP_SEC_NXTRLIBS_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1490107833
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_NxtrLibs.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_NXTRLIBS_H */
