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
 *          File:  Components/Rte_Ap_MotPosnCmp.h
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
#ifndef _RTE_AP_MOTPOSNCMP_H
# define _RTE_AP_MOTPOSNCMP_H

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


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AssiMechPolarity_Cnt_s08 (0)
#  define Rte_InitValue_MotPosnCumvAlgnd_Rev_f32 (0.0F)
#  define Rte_InitValue_MotPosnCumvAlgndCrf_Deg_f32 (0.0F)
#  define Rte_InitValue_MotPosnCumvAlgndMrf_Deg_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_2ms_10, RTE_VAR_NOINIT) Rte_Task_2ms_10;

#  define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

#  define Rte_IRead_MotPosnCmp_Per2_AssiMechPolarity_Cnt_s08() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_MotPosnCmp_MotPosnCmp_Per2.Rte_AssiMechPolarity_Cnt_s08.value)

#  define Rte_IRead_MotPosnCmp_Per2_MotPosnCumvAlgnd_Rev_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_MotPosnCmp_MotPosnCmp_Per2.Rte_MotPosnCumvAlgnd_Rev_f32.value)

#  define Rte_IWrite_MotPosnCmp_Per2_MotPosnCumvAlgndCrf_Deg_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_MotPosnCmp_MotPosnCmp_Per2.Rte_MotPosnCumvAlgndCrf_Deg_f32.value = (data) \
  )

#  define Rte_IWriteRef_MotPosnCmp_Per2_MotPosnCumvAlgndCrf_Deg_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_MotPosnCmp_MotPosnCmp_Per2.Rte_MotPosnCumvAlgndCrf_Deg_f32.value)

#  define Rte_IWrite_MotPosnCmp_Per2_MotPosnCumvAlgndMrf_Deg_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_MotPosnCmp_MotPosnCumvAlgndMrf_Deg_f32.value = (data) \
  )

#  define Rte_IWriteRef_MotPosnCmp_Per2_MotPosnCumvAlgndMrf_Deg_f32() \
  (&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_MotPosnCmp_MotPosnCumvAlgndMrf_Deg_f32.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# endif
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_MotPosnCmpMtrPosBackEmf_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)20, arg1))


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(UInt16, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Ap_MotPosnCmp_MotPosnCmpMtrPosBackEmf;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_MotPosnCmpMtrPosBackEmf() \
  (&Rte_Ap_MotPosnCmp_MotPosnCmpMtrPosBackEmf)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_MOTPOSNCMP_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_MOTPOSNCMP_APPL_CODE) MotPosnCmp_Per2(void);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AP_MOTPOSNCMP_APPL_CODE) MotPosnCmp_Scom_MotPosnCmpBackEmfRead(P2VAR(UInt16, AUTOMATIC, RTE_AP_MOTPOSNCMP_APPL_VAR) MotPosnBackEmfReadData);
# else
FUNC(void, RTE_AP_MOTPOSNCMP_APPL_CODE) MotPosnCmp_Scom_MotPosnCmpBackEmfRead(P2VAR(MotPosnBackEmfData, AUTOMATIC, RTE_AP_MOTPOSNCMP_APPL_VAR) MotPosnBackEmfReadData);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AP_MOTPOSNCMP_APPL_CODE) MotPosnCmp_Scom_MotPosnCmpBackEmfWr(P2CONST(UInt16, AUTOMATIC, RTE_AP_MOTPOSNCMP_APPL_DATA) MotPosnBackEmfWrData, P2VAR(UInt8, AUTOMATIC, RTE_AP_MOTPOSNCMP_APPL_VAR) MotPosnCmpBackEmfWrResp);
# else
FUNC(void, RTE_AP_MOTPOSNCMP_APPL_CODE) MotPosnCmp_Scom_MotPosnCmpBackEmfWr(P2CONST(MotPosnBackEmfData, AUTOMATIC, RTE_AP_MOTPOSNCMP_APPL_DATA) MotPosnBackEmfWrData, P2VAR(UInt8, AUTOMATIC, RTE_AP_MOTPOSNCMP_APPL_VAR) MotPosnCmpBackEmfWrResp);
# endif

# define RTE_STOP_SEC_AP_MOTPOSNCMP_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1490107833
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_MotPosnCmp.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_MOTPOSNCMP_H */
