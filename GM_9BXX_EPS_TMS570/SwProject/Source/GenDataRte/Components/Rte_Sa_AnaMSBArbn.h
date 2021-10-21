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
 *          File:  Components/Rte_Sa_AnaMSBArbn.h
 *     Workspace:  C:/_synergy/9BXX_CZ8L9T/GM_9BXX_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Thu Aug 27 16:36:11 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_ANAMSBARBN_H
# define _RTE_SA_ANAMSBARBN_H

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

#  define Rte_InitValue_AlignedCumMtrPosMRF_Deg_f32 (0.0F)
#  define Rte_InitValue_AssistAssyPolarity_Cnt_s08 (0)
#  define Rte_InitValue_CumMtrPosCRF_Deg_f32 (0.0F)
#  define Rte_InitValue_CumMtrPosMRF_Deg_f32 (0.0F)
#  define Rte_InitValue_MotorVelMRF_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_MtrPosCorrlnSts_Cnt_u16 (0U)
#  define Rte_InitValue_SysCCumMtrPosCRF_Deg_f32 (0.0F)
#  define Rte_InitValue_SysCCumMtrPosMRF_Deg_f32 (0.0F)
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

#  define Rte_IRead_AnaMSBArbn_Per2_AssistAssyPolarity_Cnt_s08() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBArbn_AnaMSBArbn_Per2.Rte_AssistAssyPolarity_Cnt_s08.value)

#  define Rte_IRead_AnaMSBArbn_Per2_MotorVelMRF_MtrRadpS_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBArbn_AnaMSBArbn_Per2.Rte_MotorVelMRF_MtrRadpS_f32.value)

#  define Rte_IRead_AnaMSBArbn_Per2_MtrPosCorrlnSts_Cnt_u16() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_AnaMSBCorrln_MtrPosCorrInSts_Cnt_u16.value)

#  define Rte_IWrite_AnaMSBArbn_Per2_AlignedCumMtrPosMRF_Deg_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBArbn_AnaMSBArbn_Per2.Rte_AlignedCumMtrPosMRF_Deg_f32.value = (data) \
  )

#  define Rte_IWriteRef_AnaMSBArbn_Per2_AlignedCumMtrPosMRF_Deg_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBArbn_AnaMSBArbn_Per2.Rte_AlignedCumMtrPosMRF_Deg_f32.value)

#  define Rte_IWrite_AnaMSBArbn_Per2_CumMtrPosCRF_Deg_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBArbn_AnaMSBArbn_Per2.Rte_CumMtrPosCRF_Deg_f32.value = (data) \
  )

#  define Rte_IWriteRef_AnaMSBArbn_Per2_CumMtrPosCRF_Deg_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBArbn_AnaMSBArbn_Per2.Rte_CumMtrPosCRF_Deg_f32.value)

#  define Rte_IWrite_AnaMSBArbn_Per2_CumMtrPosMRF_Deg_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBArbn_AnaMSBArbn_Per2.Rte_CumMtrPosMRF_Deg_f32.value = (data) \
  )

#  define Rte_IWriteRef_AnaMSBArbn_Per2_CumMtrPosMRF_Deg_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBArbn_AnaMSBArbn_Per2.Rte_CumMtrPosMRF_Deg_f32.value)

#  define Rte_IWrite_AnaMSBArbn_Per2_SysCCumMtrPosCRF_Deg_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBArbn_AnaMSBArbn_Per2.Rte_SysCCumMtrPosCRF_Deg_f32.value = (data) \
  )

#  define Rte_IWriteRef_AnaMSBArbn_Per2_SysCCumMtrPosCRF_Deg_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBArbn_AnaMSBArbn_Per2.Rte_SysCCumMtrPosCRF_Deg_f32.value)

#  define Rte_IWrite_AnaMSBArbn_Per2_SysCCumMtrPosMRF_Deg_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBArbn_AnaMSBArbn_Per2.Rte_SysCCumMtrPosMRF_Deg_f32.value = (data) \
  )

#  define Rte_IWriteRef_AnaMSBArbn_Per2_SysCCumMtrPosMRF_Deg_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBArbn_AnaMSBArbn_Per2.Rte_SysCCumMtrPosMRF_Deg_f32.value)


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

#  define Rte_Call_EOLMtr2Cals_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)16, arg1))
#  define Rte_Call_EOLMtr3Cals_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)17, arg1))
#  define Rte_Call_EOLMtrCals_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)15, arg1))


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(MtrPosCal_DataType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Sa_AnaMSBArbn_AnaMSBArbn_MtrPos1EOLData;
extern VAR(MtrPos2Cal_DataType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Sa_AnaMSBArbn_AnaMSBArbn_MtrPos2EOLData;
extern VAR(MtrPos3Cal_DataType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Sa_AnaMSBArbn_AnaMSBArbn_MtrPos3EOLData;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_AnaMSBArbn_MtrPos1EOLData() \
  (&Rte_Sa_AnaMSBArbn_AnaMSBArbn_MtrPos1EOLData)

#  define Rte_Pim_AnaMSBArbn_MtrPos2EOLData() \
  (&Rte_Sa_AnaMSBArbn_AnaMSBArbn_MtrPos2EOLData)

#  define Rte_Pim_AnaMSBArbn_MtrPos3EOLData() \
  (&Rte_Sa_AnaMSBArbn_AnaMSBArbn_MtrPos3EOLData)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_ANAMSBARBN_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_ANAMSBARBN_APPL_CODE) AnaMSBArbn_Init1(void);

FUNC(void, RTE_SA_ANAMSBARBN_APPL_CODE) AnaMSBArbn_Per2(void);

FUNC(void, RTE_SA_ANAMSBARBN_APPL_CODE) AnaMSBArbn_SCom_ReadEOLMtr3Cals(P2VAR(MtrPos3Cal_DataType, AUTOMATIC, RTE_SA_ANAMSBARBN_APPL_VAR) Mtr3CalDataPtr);

FUNC(void, RTE_SA_ANAMSBARBN_APPL_CODE) AnaMSBArbn_SCom_ReadEOLMtrCals(P2VAR(MtrPosCal_DataType, AUTOMATIC, RTE_SA_ANAMSBARBN_APPL_VAR) MtrCalDataPtr, P2VAR(MtrPos2Cal_DataType, AUTOMATIC, RTE_SA_ANAMSBARBN_APPL_VAR) Mtr2CalDataPtr);

FUNC(void, RTE_SA_ANAMSBARBN_APPL_CODE) AnaMSBArbn_SCom_SetEOLMtr3Cals(P2CONST(MtrPos3Cal_DataType, AUTOMATIC, RTE_SA_ANAMSBARBN_APPL_DATA) Mtr3CalDataPtr);

FUNC(void, RTE_SA_ANAMSBARBN_APPL_CODE) AnaMSBArbn_SCom_SetEOLMtrCals(P2CONST(MtrPosCal_DataType, AUTOMATIC, RTE_SA_ANAMSBARBN_APPL_DATA) MtrCalDataPtr, P2CONST(MtrPos2Cal_DataType, AUTOMATIC, RTE_SA_ANAMSBARBN_APPL_DATA) Mtr2CalDataPtr);

# define RTE_STOP_SEC_SA_ANAMSBARBN_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1440701359
#    error "The magic number of the generated file <C:/_synergy/9BXX_CZ8L9T/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Sa_AnaMSBArbn.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1440701359
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_ANAMSBARBN_H */
