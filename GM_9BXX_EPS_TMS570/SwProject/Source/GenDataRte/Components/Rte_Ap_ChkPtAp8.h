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
 *          File:  Components/Rte_Ap_ChkPtAp8.h
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
#ifndef _RTE_AP_CHKPTAP8_H
# define _RTE_AP_CHKPTAP8_H

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


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_WDGM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_WDGM_APPL_CODE) WdgM_CheckpointReached(WdgM_SupervisedEntityIdType parg0, WdgM_CheckpointIdType parg1);
#  define RTE_STOP_SEC_WDGM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_ChkPtAp8_100msEnd_CP_CheckpointReached() (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)2, (WdgM_CheckpointIdType)1))
#  define Rte_Call_ChkPtAp8_100msStart_CP_CheckpointReached() (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)2, (WdgM_CheckpointIdType)0))
#  define Rte_Call_ChkPtAp8_2msEnd_CP_CheckpointReached() (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)8, (WdgM_CheckpointIdType)1))
#  define Rte_Call_ChkPtAp8_2msStart_CP_CheckpointReached() (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)8, (WdgM_CheckpointIdType)0))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_CHKPTAP8_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CHKPTAP8_APPL_CODE) ChkPtAp8_100msEnd_Per(void);

FUNC(void, RTE_AP_CHKPTAP8_APPL_CODE) ChkPtAp8_100msStart_Per(void);

FUNC(void, RTE_AP_CHKPTAP8_APPL_CODE) ChkPtAp8_2msEnd_Per(void);

FUNC(void, RTE_AP_CHKPTAP8_APPL_CODE) ChkPtAp8_2msStart_Per(void);

# define RTE_STOP_SEC_AP_CHKPTAP8_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_WdgM_CheckpointReached_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1490107833
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_ChkPtAp8.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_CHKPTAP8_H */
