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
 *          File:  Components/Rte_Sa_DigColPs.h
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
#ifndef _RTE_SA_DIGCOLPS_H
# define _RTE_SA_DIGCOLPS_H

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

#  define Rte_InitValue_I2CHwAbsPos_HwDeg_f32 (0.0F)
#  define Rte_InitValue_I2CHwAbsPosValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_MecState_Cnt_enum (0U)
#  define Rte_InitValue_TrimComp_Cnt_lgc (FALSE)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_4ms_10, RTE_VAR_NOINIT) Rte_Task_4ms_10;

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

#  define Rte_IRead_DigColPs_Per2_MecState_Cnt_enum() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Sa_DigColPs_DigColPs_Per2.Rte_MecState_Cnt_enum.value)

#  define Rte_IWrite_DigColPs_Per2_I2CHwAbsPosValid_Cnt_lgc(data) \
  ( \
    Rte_Task_4ms_10.Rte_TB.Rte_I_DigColPs_I2CHwAbsPosValid_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_DigColPs_Per2_I2CHwAbsPosValid_Cnt_lgc() \
  (&Rte_Task_4ms_10.Rte_TB.Rte_I_DigColPs_I2CHwAbsPosValid_Cnt_lgc.value)

#  define Rte_IWrite_DigColPs_Per2_I2CHwAbsPos_HwDeg_f32(data) \
  ( \
    Rte_Task_4ms_10.Rte_TB.Rte_I_DigColPs_I2CHwAbsPos_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_DigColPs_Per2_I2CHwAbsPos_HwDeg_f32() \
  (&Rte_Task_4ms_10.Rte_TB.Rte_I_DigColPs_I2CHwAbsPos_HwDeg_f32.value)

#  define Rte_IWrite_DigColPs_Per2_TrimComp_Cnt_lgc(data) \
  ( \
    Rte_Task_4ms_10.Rte_RB.Rte_Sa_DigColPs_DigColPs_Per2.Rte_TrimComp_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_DigColPs_Per2_TrimComp_Cnt_lgc() \
  (&Rte_Task_4ms_10.Rte_RB.Rte_Sa_DigColPs_DigColPs_Per2.Rte_TrimComp_Cnt_lgc.value)


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

#  define Rte_Call_EOLDigColPosCals_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)6, arg1))
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_GetNTCActive(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) NTCActive_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCActive NxtrDiagMgr10_GetNTCActive
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr10_SetNTCStatus
#  define RTE_START_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NXTRLIBS_APPL_CODE) DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) ElapsedTime);
#  define RTE_STOP_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(arg1, arg2) (DtrmnElapsedTime_mS_u16(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NXTRLIBS_APPL_CODE) GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) CurrentTime);
#  define RTE_STOP_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_GetSystemTime_mS_u32(arg1) (GetSystemTime_mS_u32(arg1), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(DigColPsEOLType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_DigColPs_DigColPsEOL;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_DigColPsEOL() \
  (&Rte_DigColPs_DigColPsEOL)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_DIGCOLPS_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_Init1(void);

FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_Per1(void);

FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_Per2(void);

FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_Per3(void);

FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_SCom_CustClrTrim(void);

FUNC(Std_ReturnType, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_SCom_CustSetTrim(void);

FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_SCom_NxtClrTrim(void);

FUNC(Std_ReturnType, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_SCom_NxtSetTrim(void);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) PhaNvmRead_GetData(P2VAR(Boolean, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) ColCustDataReadCmpl_Cnt_lgc, P2VAR(Boolean, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) SpurCustDataReadCmpl_Cnt_lgc, P2VAR(UInt32, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) ColCustData_Uls_u32, P2VAR(UInt32, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) SpurCustData_Uls_u32);
# else
FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) PhaNvmRead_GetData(P2VAR(CustReadCmplType, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) ColCustDataReadCmpl_Cnt_lgc, P2VAR(CustReadCmplType, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) SpurCustDataReadCmpl_Cnt_lgc, P2VAR(CustDataType, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) ColCustData_Uls_u32, P2VAR(CustDataType, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) SpurCustData_Uls_u32);
# endif

# define RTE_STOP_SEC_SA_DIGCOLPS_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DigColPs_SCom_ConditionsNotCorrect (34U)

#  define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1490107833
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Sa_DigColPs.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_DIGCOLPS_H */
