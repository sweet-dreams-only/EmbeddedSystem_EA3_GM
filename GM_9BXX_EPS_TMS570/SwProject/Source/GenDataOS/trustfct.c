/* file: trustfct.c, automatically generated by genTMS570SafeCtxAS.exe, Version: 5.07 */
/* configuration read from: C:\Users\cz8l9t\AppData\Local\Temp\~cfg4_314_EPS.ecuc.arxml.oil */
/* generation at  : Wed May 18 15:08:50 2016 */
/* Unlimited license CBD1010124 for Nxtr Automotive */
/* Implementation: TMS570LS3x */
/* Version of general code: 5.23c */

#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif
#define osdVrmGenMajRelNum 5
#define osdVrmGenMinRelNum 7
#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif

#if defined USE_QUOTE_INCLUDES
 #include "Os.h"
#else
 #include <Os.h>
#endif

#pragma SET_DATA_SECTION(".osconst")

#pragma SET_CODE_SECTION(".oscode")

osqROM0 osqROM1 const osqROM2 TrustedFunctionType osqROM3 oskTrustedFctTab[osdNumberOfTrustedFunctions]=
{
   TRUSTED_NtWrapS_NvMProxy_Init,
   TRUSTED_TWrapS_Appdesc_BLTransition,
   TRUSTED_NtWrapS_PwmCdd_Init,
   TRUSTED_NtWrapS_Adc2_Init1,
   TRUSTED_NtWrapS_Wdg_TMS570LS3x_Init,
   TRUSTED_NtWrapS_WdgM_Init,
   TRUSTED_NtWrapS_Adc_Init,
   TRUSTED_TWrapS_XcpWriteAp0,
   TRUSTED_NtWrapS_ProcessF0FF,
   TRUSTED_NtWrapS_StaMd_Init1,
   TRUSTED_TWrapS_FeeIf_Init,
   TRUSTED_TWrapS_Fee_MainFunction,
   TRUSTED_TWrapS_Fee_Read,
   TRUSTED_TWrapS_Fee_Write,
   TRUSTED_TWrapS_Fee_EraseImmediateBlock,
   TRUSTED_TWrapS_Fee_InvalidateBlock,
   TRUSTED_TWrapS_Fee_Cancel,
   TRUSTED_TWrapS_Fee_GetStatus,
   TRUSTED_TWrapS_Fee_GetJobResult,
   TRUSTED_TWrapS_uDiagVIM_RednRpdShtdn,
   TRUSTED_TWrapS_uDiagECC_RednRpdShtdn,
   TRUSTED_TWrapS_Dma_InvalidateSlowADCGroup,
   TRUSTED_TWrapS_TI_Fee_SuspendResumeErase,
   TRUSTED_NtWrapS_StaMd_Init0,
};

#ifndef OS_SUPPRESS_CALLEESTUB
#endif /* OS_SUPPRESS_CALLEESTUB */
osqROM0 osqROM1 const osqROM2 NonTrustedFunctionType osqROM3 oskNonTrustedFctTab[osdNumberOfNonTrustedFunctions]=
{
   NONTRUSTED_NtWrapS_AssistLmtFunc_Scom_ManualTrqCmd,
   NONTRUSTED_NtWrapS_SCom_EOLNomMtrParam_Set,
   NONTRUSTED_NtWrapS_TrqCmdScl_SCom_Set,
   NONTRUSTED_NtWrapS_Polarity_SCom_SetPolarity,
   NONTRUSTED_NtWrapS_XcpWriteAp10,
   NONTRUSTED_NtWrapS_TrqCanc_Scom_SetCogTrqCal,
   NONTRUSTED_NtWrapS_DigColPs_SCom_CustSetTrim,
   NONTRUSTED_NtWrapS_DigColPs_SCom_CustClearTrim,
   NONTRUSTED_NtWrapS_DigColPs_SCom_NxtSetTrim,
   NONTRUSTED_NtWrapS_DigColPs_SCom_NxtClearTrim,
   NONTRUSTED_NtWrapS_GenPosTraj_SCom_SetInputParam,
   NONTRUSTED_NtWrapS_TSMit_SCom_GainReset,
   NONTRUSTED_NtWrapS_VehDyn_SCom_ForceCenter,
   NONTRUSTED_NtWrapS_CmMtrCurr3Phs_SCom_CalGain,
   NONTRUSTED_NtWrapS_CmMtrCurr3Phs_SCom_CalGainPhs3,
   NONTRUSTED_NtWrapS_CmMtrCurr3Phs_SCom_CalOffset3Phs,
   NONTRUSTED_NtWrapS_CmMtrCurr3Phs_SCom_SetMtrCurrCals3Phs,
   NONTRUSTED_NtWrapS_MtrPos3SinCos_Scom_WriteEOLMtrCals,
   NONTRUSTED_NtWrapS_AnaHwTrq_SCom_WriteT1T2OffsetTrim,
   NONTRUSTED_NtWrapS_HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim,
   NONTRUSTED_NtWrapS_MotPosnCmp_Scom_MotPosnCmpBackEmfWr,
   NONTRUSTED_NtWrapS_AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim,
   NONTRUSTED_NtWrapS_AnaHwTrq_SCom_ClrT1T2OffsetTrim,
   NONTRUSTED_NtWrapS_AnaHwTrq_SCom_SetAnaHwTrqScaleTrim,
   NONTRUSTED_NtWrapS_AnaHwTrq_SCom_SetT1T2OffsetTrim,
   NONTRUSTED_NtWrapS_HwTrqArbn_SCom_SetHwTrqArbOffsetTrim,
   NONTRUSTED_NtWrapS_HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim,
   NONTRUSTED_NtWrapS_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl,
   NONTRUSTED_NtWrapS_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl,
   NONTRUSTED_NtWrapS_TrqOvlSta_SCom_SetGmLoaIgnCntr,
   NONTRUSTED_NtWrapS_XcpWriteAp8,
   NONTRUSTED_NtWrapS_XcpWriteAp9,
};

osqROM0 osqROM1 const osqROM2 ApplicationType osqROM3 oskNTFToAppl[osdNumberOfNonTrustedFunctions]=
{
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_10,
   Ap_8,
   Ap_9,
};

#pragma SET_DATA_SECTION()

#pragma SET_CODE_SECTION()


/* END OF C:\_synergy\9BXX_CZ8L9T\GM_9BXX_EPS_TMS570\Tools\AsrProject.\..\..\SwProject\Source\GenData\\..\GenDataOs\trustfct.c */

