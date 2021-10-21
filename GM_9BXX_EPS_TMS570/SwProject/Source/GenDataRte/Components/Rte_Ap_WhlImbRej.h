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
 *          File:  Components/Rte_Ap_WhlImbRej.h
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
#ifndef _RTE_AP_WHLIMBREJ_H
# define _RTE_AP_WHLIMBREJ_H

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

#  define Rte_InitValue_DiagStsWIRDisable_Cnt_lgc (FALSE)
#  define Rte_InitValue_HwTrq_HwNm_f32 (0.0F)
#  define Rte_InitValue_QualWhlFreqL_Hz_f32 (0.0F)
#  define Rte_InitValue_QualWhlFreqR_Hz_f32 (0.0F)
#  define Rte_InitValue_VehSpd_Kph_f32 (0.0F)
#  define Rte_InitValue_VehSpdValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_WIRCmdAmpBlnd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_WIRMfgEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_WhlFreqQualified_Cnt_lgc (TRUE)
#  define Rte_InitValue_WhlImbRejCmd_MtrNm_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd_SystemState_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



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

#  define Rte_IRead_WhlImbRej_Per1_DiagStsWIRDisable_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_DiagStsWIRDisable_Cnt_lgc.value)

#  define Rte_IRead_WhlImbRej_Per1_HwTrq_HwNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_HwTrq_HwNm_f32.value)

#  define Rte_IRead_WhlImbRej_Per1_QualWhlFreqL_Hz_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_QualWhlFreqL_Hz_f32.value)

#  define Rte_IRead_WhlImbRej_Per1_QualWhlFreqR_Hz_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_QualWhlFreqR_Hz_f32.value)

#  define Rte_IRead_WhlImbRej_Per1_VehSpdValid_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_VehSpdValid_Cnt_lgc.value)

#  define Rte_IRead_WhlImbRej_Per1_VehSpd_Kph_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_VehSpd_Kph_f32.value)

#  define Rte_IRead_WhlImbRej_Per1_WIRMfgEnable_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_WIRMfgEnable_Cnt_lgc.value)

#  define Rte_IRead_WhlImbRej_Per1_WhlFreqQualified_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_WhlFreqQualified_Cnt_lgc.value)

#  define Rte_IWrite_WhlImbRej_Per1_WIRCmdAmpBlnd_MtrNm_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_WIRCmdAmpBlnd_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_WhlImbRej_Per1_WIRCmdAmpBlnd_MtrNm_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_WIRCmdAmpBlnd_MtrNm_f32.value)

#  define Rte_IWrite_WhlImbRej_Per1_WhlImbRejCmd_MtrNm_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_WhlImbRejCmd_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_WhlImbRej_Per1_WhlImbRejCmd_MtrNm_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_WhlImbRejCmd_MtrNm_f32.value)

#  define Rte_IWrite_WhlImbRej_Per3_WhlImbRejCmd_MtrNm_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per3.Rte_WhlImbRejCmd_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_WhlImbRej_Per3_WhlImbRejCmd_MtrNm_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per3.Rte_WhlImbRejCmd_MtrNm_f32.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
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
FUNC(void, RTE_NXTRLIBS_APPL_CODE) DtrmnElapsedTime_mS_u32(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) ElapsedTime);
#  define RTE_STOP_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(arg1, arg2) (DtrmnElapsedTime_mS_u32(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NXTRLIBS_APPL_CODE) GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) CurrentTime);
#  define RTE_STOP_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_GetSystemTime_mS_u32(arg1) (GetSystemTime_mS_u32(arg1), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_WHLIMBREJ_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WhlImbRej_Init1(void);

FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WhlImbRej_Per1(void);

FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WhlImbRej_Per2(void);

FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WhlImbRej_Per3(void);

FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WhlImbRej_SCom_GetWIRInfo(P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRCmpActRng1Ptr_Cnt_u32, P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRCmpActRng2Ptr_Cnt_u32, P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRCmpActRng3Ptr_Cnt_u32, P2VAR(UInt16, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) AlgFltStatusPtr_Cnt_b16, P2VAR(Float, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRMaxCompPtr_Pct_f32);

# define RTE_STOP_SEC_AP_WHLIMBREJ_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1490107833
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_WhlImbRej.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_WHLIMBREJ_H */
