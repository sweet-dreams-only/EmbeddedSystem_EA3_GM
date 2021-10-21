/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtrldVelRtn.c
 *     Workspace:  C:/Sankar/New_EA3_Database/Working/CtrldVelRtn/autosar
 *     SW-C Type:  CtrldVelRtn
 *  Generated at:  Tue Oct 20 17:14:54 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <CtrldVelRtn>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2015, 2016, 2017 Nxtr
 * Nxtr Confidential
 *
 * Module File Name	 : CtrldVelRtn.c
 * Module Description: Implementation of SF002B - Controlled Velocity Return FDD.
 * Project           : CBD
 * Author            : Sankardu Varadapureddi
 **********************************************************************************************************************
 * Version Control:
 * %version:          5 %
 * %derived_by:       nz2796 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                              SCR #
 * -------   -------  --------  ------------------------------------------------------------------------------  -------
 * 10/09/15  1        SV        Initial Version                                                                EA3#3527
 * 12/10/15  2        KK        SF-02B update after split up from CF019A                          EA3#5221 and EA3#5219
 * 07/27/16  3        JK        Anomaly fix EA3#9016 - Misusage of vehicle speed  look-up table                EA3#9108
 * 10/17/16  4        JK        Updated to FDD v1.2.0 - Anomaly fix EA3#10770                                 EA3#11060
 * 01/03/17	 5		  ML		Updated to fix Anomaly EA3#12991											  EA3#13370
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_CtrldVelRtn.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "filters.h"
#include "GlobalMacro.h"
#include "fixmath.h"
#include "interpolation.h"

/* PRQA S 4395 EOF 
* MISRA-C:2004 Rule 10.4: A composite expression of 'essentially floating' type (%1s) is being cast to a different type category, '%2s'. */
/* PRQA S 310 EOF
* MISRA-C:2004 Rule 11.4: Casting to different object pointer type. */
/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */

#define D_TRQGRADCALCNWGHTGFAC1_ULS_F32		1.1978F
#define D_TRQGRADCALCNWGHTGFAC2_ULS_F32		3.3286F
#define D_TRQGRADCALCNWGHTGFAC3_ULS_F32		4.3159F
#define D_TRQGRADCALCNWGHTGFAC4_ULS_F32		18.0384F
#define D_DRVRTQOBSVRAGTHD_HWRAD_F32 252.0F
#define D_DRVRTQOBSVRFINALTHD_HWNM_F32 10.0F
#define D_DRVRTQOBSVRTQTHD_HWNM_F32 100.0F
#define D_DRVRTQOBSVRVELTHD_HWRADPS_F32 420.0F

#define	D_MAX5_CNT_U08		5U
#define	D_MAX4_CNT_U08		4U

#define CTRLDVELRTN_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AUTOMATIC) CtrldVelRtn_PrevADrvTrqFilt_HwNm_M_f32;				/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) CtrldVelRtn_PrevBDrvTrqFilt_HwNm_M_f32;				/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) CtrldVelRtn_PrevCDrvTrqFilt_HwNm_M_f32;				/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) CtrldVelRtn_PrevDDrvTrqFilt_HwNm_M_f32;				/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) CtrldVelRtn_PrevEDrvTrqFilt_HwNm_M_f32;				/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) CtrldVelRtn_PrevFDrvTrqFilt_HwNm_M_f32;				/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) CtrldVelRtn_PrevRtnOffsetSlew_HwDeg_M_f32;			/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) CtrldVelRtn_PrevHwTrqScaSelector_Uls_M_f32;			/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) CtrldVelRtn_PrevITermB_HwNm_M_f32;					/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) CtrldVelRtn_PrevITermC_HwNm_M_f32;					/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) CtrldVelRtn_PrevITerm_HwNm_M_f32;					/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) CtrldVelRtn_PrevOutpMtrx_Uls_M_f32[5];				/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) CtrldVelRtn_PrevHwAuthySca_Uls_M_f32;				/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) CtrldVelRtn_DesVel_HwDegpS_M_f32;					/* PRQA S 3218 */

STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_HwPosComp_HwDeg_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_DrvTrqEst_HwNm_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_DrvTrqFilt_HwNm_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_TrqGrdtSca_Uls_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_TrqGrdt_HwNmpS_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_TbarTrqSca_Uls_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_PosSca_Uls_D_f32;				/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_VelErrorSca_Uls_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_HwTrqSca_Uls_D_f32;				/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_HwTrqScaSelector_Uls_D_f32;		/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_HwAuthySca_Uls_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_CtrlScaPreFilt_Uls_D_f32;		/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_DesVelScaPreFilt_Uls_D_f32;		/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_PTermCmd_HwNm_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_IntgtrLim_HwNm_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_ITermCmd_HwNm_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_DampgCmd_HwNm_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_RtnCmdPreLim_MtrNm_D_f32;		/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_ReturnCmd_MtrNm_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_CtrlSca_Uls_D_f32;				/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_DesVelSca_Uls_D_f32;			/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) CtrldVelRtn_DesVel_HwDegpS_D_f32;			/* PRQA S 3218 */
#define CTRLDVELRTN_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define CTRLDVELRTN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, CTRLDVELRTN_VAR) CtrldVelRtn_DesVelLPFSV_HwDegpS_M_Str;
STATIC VAR(LPF32KSV_Str, CTRLDVELRTN_VAR) CtrldVelRtn_DrvTrqLPFSV_HwNm_M_Str;
STATIC VAR(LPF32KSV_Str, CTRLDVELRTN_VAR) CtrldVelRtn_TbarTrqLPFSV_HwNm_M_Str;
STATIC VAR(LPF32KSV_Str, CTRLDVELRTN_VAR) CtrldVelRtn_DesVelScaLPFSV_Uls_M_Str;
STATIC VAR(LPF32KSV_Str, CTRLDVELRTN_VAR) CtrldVelRtn_CtrlScaLPFSV_Uls_M_Str;
#define CTRLDVELRTN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/* Function Prototypes */
STATIC FUNC(void, CTRLDVELRTN_APPL_CODE) InpCdng(VAR(float32,AUTOMATIC) ReturnOffset_HwDeg_T_f32,
		                                         VAR(float32,AUTOMATIC) HandwheelPosition_HwDeg_T_f32,
												 VAR(float32,AUTOMATIC) HandwheelVelocity_HwRadpS_T_f32,
												 P2VAR(float32, AUTOMATIC, CTRLDVELRTN_APPL_VAR) CompHwPos_HwDeg_T_f32,
												 P2VAR(float32, AUTOMATIC, CTRLDVELRTN_APPL_VAR) HwVel_HwDegpS_T_f32);
												 
STATIC FUNC(float32, CTRLDVELRTN_APPL_CODE) DrvrTqSelctr(VAR(float32,AUTOMATIC) MtrTrqCmd_MtrNm_T_f32,
														 VAR(float32,AUTOMATIC) TbarTrq_HwNm_T_f32,
									                     VAR(float32,AUTOMATIC) HwPos_HwDeg_T_f32,
									                     VAR(float32,AUTOMATIC) HwVel_HwRadpS_T_f32);
														 
STATIC FUNC(float32, CTRLDVELRTN_APPL_CODE) TqGrdtSca(VAR(float32,AUTOMATIC) DrvTrqFilt_HwNm_T_f32,
                                                      VAR(float32,AUTOMATIC) VehicleSpeed_Kph_T_f32);

STATIC FUNC(float32, CTRLDVELRTN_APPL_CODE) VelErrSca(VAR(float32,AUTOMATIC) HwPos_HwDeg_T_f32,
													  VAR(float32,AUTOMATIC) HwVel_HwDegpS_T_f32,
													  VAR(float32,AUTOMATIC) VehicleSpeed_Kph_T_f32);

STATIC FUNC(float32, CTRLDVELRTN_APPL_CODE) HwTrqSca(VAR(float32,AUTOMATIC) DrvTrqFilt_HwNm_T_f32,
													 VAR(float32,AUTOMATIC) HwVel_HwDegpS_T_f32,
													 VAR(float32,AUTOMATIC) VehicleSpeed_Kph_T_f32);													  
											 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Boolean: D_FALSE_CNT_LGC = FALSE
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_CTRLDVELRTN_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtrldVelRtn_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CTRLDVELRTN_APPL_CODE) CtrldVelRtn_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CtrldVelRtn_Init1
 *********************************************************************************************************************/
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_Rtn_DesVelLPFKn_Hz_f32, D_2MS_SEC_F32, &CtrldVelRtn_DesVelLPFSV_HwDegpS_M_Str);
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_Rtn_HwTrqLPFKn_Hz_f32, D_2MS_SEC_F32, &CtrldVelRtn_DrvTrqLPFSV_HwNm_M_Str);
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_Rtn_HwTrqLPFKn_Hz_f32, D_2MS_SEC_F32, &CtrldVelRtn_TbarTrqLPFSV_HwNm_M_Str);
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_Rtn_ScaLPFKn_Hz_f32, D_2MS_SEC_F32, &CtrldVelRtn_DesVelScaLPFSV_Uls_M_Str);
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_Rtn_ScaLPFKn_Hz_f32, D_2MS_SEC_F32, &CtrldVelRtn_CtrlScaLPFSV_Uls_M_Str);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtrldVelRtn_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_CtrldVelRtn_Per1_DefeatReturnSvc_Cnt_lgc(void)
 *   Boolean Rte_IRead_CtrldVelRtn_Per1_DiagStsHwPosDis_Cnt_lgc(void)
 *   Float Rte_IRead_CtrldVelRtn_Per1_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_CtrldVelRtn_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Float Rte_IRead_CtrldVelRtn_Per1_HandwheelVelocity_HwRadpS_f32(void)
 *   Float Rte_IRead_CtrldVelRtn_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_CtrldVelRtn_Per1_MRFMtrTrqCmdScl_MtrNm_f32(void)
 *   Float Rte_IRead_CtrldVelRtn_Per1_PAReturnSclFct_Uls_f32(void)
 *   Float Rte_IRead_CtrldVelRtn_Per1_ReturnDDFactor_Uls_f32(void)
 *   Float Rte_IRead_CtrldVelRtn_Per1_ReturnOffset_HwDeg_f32(void)
 *   Float Rte_IRead_CtrldVelRtn_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CtrldVelRtn_Per1_ReturnCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_CtrldVelRtn_Per1_ReturnCmd_MtrNm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_CTRLDVELRTN_APPL_CODE) CtrldVelRtn_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CtrldVelRtn_Per1
 *********************************************************************************************************************/

	/* inputs */
	VAR(boolean, AUTOMATIC) DefeatReturnSvc_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DiagStsHwPosDis_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) HandwheelAuthority_Uls_T_f32;
	VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) HandwheelVelocity_HwRadpS_T_f32;
	VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
	VAR(float32, AUTOMATIC) MRFMtrTrqCmdScl_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) PAReturnSclFct_Uls_T_f32;
	VAR(float32, AUTOMATIC) ReturnDDFactor_Uls_T_f32;
	VAR(float32, AUTOMATIC) ReturnOffset_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
	
	VAR(float32, AUTOMATIC) RtnCmd_MtrNm_T_f32;
	
	VAR(float32, AUTOMATIC) CompHwPos_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) HwVel_HwDegpS_T_f32;
	VAR(float32, AUTOMATIC) DrvTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) DrvTrqFilt_HwNm_T_f32;
	VAR(float32, AUTOMATIC) TbarTrqFilt_HwNm_T_f32;
	VAR(float32, AUTOMATIC) TrqGrdtSca_Uls_T_f32;
	VAR(uint16, AUTOMATIC) TbarTrqSca_Uls_T_u2p14;
	VAR(float32, AUTOMATIC) TbarTrqSca_Uls_T_f32;
	VAR(uint16, AUTOMATIC) PosSca_Uls_T_u2p14;
	VAR(float32, AUTOMATIC) PosSca_Uls_T_f32;       
	VAR(float32, AUTOMATIC) VelErrSca_Uls_T_f32;
	VAR(float32, AUTOMATIC) HwTrqSca_Uls_T_f32;
	VAR(uint16, AUTOMATIC) HwAuthySca_Uls_T_u2p14;
	VAR(float32, AUTOMATIC) HwAuthySca_Uls_T_f32;
	VAR(float32, AUTOMATIC) CtrlSca_Uls_T_f32;
	VAR(float32, AUTOMATIC) CtrlScaPreFilt_Uls_T_f32;
	VAR(uint16, AUTOMATIC) DesVelScaPreFilt_Uls_T_u2p14;
	VAR(float32, AUTOMATIC) DesVelScaPreFilt_Uls_T_f32;
	VAR(float32, AUTOMATIC) DesVelSca_Uls_T_f32;
	VAR(uint16, AUTOMATIC) VehicleSpeed_Kph_T_u9p7;
	VAR(uint16, AUTOMATIC) HwPosAbs_HwDeg_T_u12p4;
	VAR(uint16, AUTOMATIC) DesVelScaFacPreFilt_Uls_T_u10p6;
	VAR(float32, AUTOMATIC) DesVelScaFacPreFilt_Uls_T_f32;
	VAR(float32, AUTOMATIC) DesVelPreFilt_HwDegpS_T_f32;
	VAR(float32, AUTOMATIC) VelErr_HwDegpS_T_f32;
	VAR(uint16, AUTOMATIC) Kp_Uls_T_u4p12;
	VAR(float32, AUTOMATIC) Kp_Uls_T_f32;
	VAR(uint16, AUTOMATIC) Ki_Uls_T_u8p8;
	VAR(float32, AUTOMATIC) Ki_Uls_T_f32;
	VAR(float32, AUTOMATIC) PTerm_HwNm_T_f32;
	VAR(float32, AUTOMATIC) ITerm_HwNm_T_f32;
	VAR(float32, AUTOMATIC) PITerm_HwNm_T_f32;
	VAR(float32, AUTOMATIC) ITermA_HwNm_T_f32;
	VAR(float32, AUTOMATIC) ITermB_HwNm_T_f32;
	VAR(float32, AUTOMATIC) ITermC_HwNm_T_f32;
	VAR(float32, AUTOMATIC) IntLimUpper_HwNm_T_f32;
	VAR(uint16, AUTOMATIC) IntLimUpper_HwNm_T_u6p10;
	VAR(uint16, AUTOMATIC) DampgTermInter_HwNm_T_u6p10;
	VAR(float32, AUTOMATIC) DampgTermInter_HwNm_T_f32;
	VAR(float32, AUTOMATIC) DampgTerm_HwNm_T_f32;
	VAR(uint16, AUTOMATIC) RtnCmdLimUpper_MtrNm_T_u4p12;
	VAR(float32, AUTOMATIC) RtnCmdLimUpper_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) PreLimRtnCmd_MtrNm_T_f32;
	
	/* read inputs */
	DefeatReturnSvc_Cnt_T_lgc = Rte_IRead_CtrldVelRtn_Per1_DefeatReturnSvc_Cnt_lgc();
	DiagStsHwPosDis_Cnt_T_lgc = Rte_IRead_CtrldVelRtn_Per1_DiagStsHwPosDis_Cnt_lgc();
	HandwheelAuthority_Uls_T_f32 = Rte_IRead_CtrldVelRtn_Per1_HandwheelAuthority_Uls_f32();
	HandwheelPosition_HwDeg_T_f32 = Rte_IRead_CtrldVelRtn_Per1_HandwheelPosition_HwDeg_f32();
	HandwheelVelocity_HwRadpS_T_f32 = Rte_IRead_CtrldVelRtn_Per1_HandwheelVelocity_HwRadpS_f32();
	HwTorque_HwNm_T_f32 = Rte_IRead_CtrldVelRtn_Per1_HwTorque_HwNm_f32();
	MRFMtrTrqCmdScl_MtrNm_T_f32 = Rte_IRead_CtrldVelRtn_Per1_MRFMtrTrqCmdScl_MtrNm_f32();
	PAReturnSclFct_Uls_T_f32 = Rte_IRead_CtrldVelRtn_Per1_PAReturnSclFct_Uls_f32();
	ReturnDDFactor_Uls_T_f32 = Rte_IRead_CtrldVelRtn_Per1_ReturnDDFactor_Uls_f32();
	ReturnOffset_HwDeg_T_f32 = Rte_IRead_CtrldVelRtn_Per1_ReturnOffset_HwDeg_f32();
	VehicleSpeed_Kph_T_f32 = Rte_IRead_CtrldVelRtn_Per1_VehicleSpeed_Kph_f32();

	/* Input Conditioning */
	InpCdng(ReturnOffset_HwDeg_T_f32,
			HandwheelPosition_HwDeg_T_f32,
			HandwheelVelocity_HwRadpS_T_f32,
			&CompHwPos_HwDeg_T_f32,
			&HwVel_HwDegpS_T_f32);
	
	/* Driver Torque Selector */
	DrvTrq_HwNm_T_f32 = DrvrTqSelctr(MRFMtrTrqCmdScl_MtrNm_T_f32,
	                                 HwTorque_HwNm_T_f32,
									 CompHwPos_HwDeg_T_f32,
									 HandwheelVelocity_HwRadpS_T_f32);
									 
	/****** Start of 'Return Command' ******/
	
	VehicleSpeed_Kph_T_u9p7 = FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, u9p7_T);
	HwPosAbs_HwDeg_T_u12p4 = FPM_FloatToFixed_m(Abs_f32_m(CompHwPos_HwDeg_T_f32), u12p4_T);
	
	/*** Start of 'Scale' ***/
	DrvTrqFilt_HwNm_T_f32 = LPF_OpUpdate_f32_m(DrvTrq_HwNm_T_f32, &CtrldVelRtn_DrvTrqLPFSV_HwNm_M_Str);
	CtrldVelRtn_DrvTrqFilt_HwNm_D_f32 = DrvTrqFilt_HwNm_T_f32;
	
	TbarTrqFilt_HwNm_T_f32 = LPF_OpUpdate_f32_m(HwTorque_HwNm_T_f32, &CtrldVelRtn_TbarTrqLPFSV_HwNm_M_Str);

	/* Torque Gradient Scale */
	TrqGrdtSca_Uls_T_f32 = TqGrdtSca(DrvTrqFilt_HwNm_T_f32,VehicleSpeed_Kph_T_f32);
	CtrldVelRtn_TrqGrdtSca_Uls_D_f32 = TrqGrdtSca_Uls_T_f32;
	
	/* TBar Torque Scale */
	TbarTrqSca_Uls_T_u2p14 = BilinearXMYM_u16_u16XMu16YM_Cnt(VehicleSpeed_Kph_T_u9p7,
														   FPM_FloatToFixed_m(Abs_f32_m(TbarTrqFilt_HwNm_T_f32), u8p8_T),
														   t_Rtn_ScaFacVehSpdTbl_Kph_u9p7,
														   TableSize_m(t_Rtn_ScaFacVehSpdTbl_Kph_u9p7),
														   (P2CONST(uint16, AUTOMATIC, CTRLDVELRTN_CONST))t2_Rtn_TBarTrqScaX_HwNm_u8p8,
														   (P2CONST(uint16, AUTOMATIC, CTRLDVELRTN_CONST))t2_Rtn_TBarTrqScaY_Uls_u2p14,
														   TableSize_m(t2_Rtn_TBarTrqScaX_HwNm_u8p8[0]));
														   
	TbarTrqSca_Uls_T_f32 = FPM_FixedToFloat_m(TbarTrqSca_Uls_T_u2p14, u2p14_T);													   
	CtrldVelRtn_TbarTrqSca_Uls_D_f32 = TbarTrqSca_Uls_T_f32;
	
	/* Position Scale */
	PosSca_Uls_T_u2p14 = IntplVarXY_u16_u16Xu16Y_Cnt(t_Rtn_PosScaX_HwDeg_u12p4,
													 t_Rtn_PosScaY_Uls_u2p14,
													 TableSize_m(t_Rtn_PosScaX_HwDeg_u12p4),
													 HwPosAbs_HwDeg_T_u12p4);
	
	PosSca_Uls_T_f32 = FPM_FixedToFloat_m(PosSca_Uls_T_u2p14, u2p14_T);													   
	CtrldVelRtn_PosSca_Uls_D_f32 = PosSca_Uls_T_f32;
	
	/* Velocity Error Scale */
	VelErrSca_Uls_T_f32 = VelErrSca(CompHwPos_HwDeg_T_f32,
									HwVel_HwDegpS_T_f32,
									VehicleSpeed_Kph_T_f32);
	CtrldVelRtn_VelErrorSca_Uls_D_f32 = VelErrSca_Uls_T_f32;

	/* Hand wheel Torque Scale */
	HwTrqSca_Uls_T_f32 = HwTrqSca(DrvTrqFilt_HwNm_T_f32,
								  HwVel_HwDegpS_T_f32,
								  VehicleSpeed_Kph_T_f32);
	CtrldVelRtn_HwTrqSca_Uls_D_f32 = HwTrqSca_Uls_T_f32;
	
	/* Hand wheel Authority Scale */
	HwAuthySca_Uls_T_u2p14 = IntplVarXY_u16_u16Xu16Y_Cnt(t_Rtn_HwAuthyScaX_Uls_u2p14,
													     t_Rtn_HwAuthyScaY_Uls_u2p14,
													     TableSize_m(t_Rtn_HwAuthyScaX_Uls_u2p14),
													     FPM_FloatToFixed_m(HandwheelAuthority_Uls_T_f32, u2p14_T));
	
	HwAuthySca_Uls_T_f32 = FPM_FixedToFloat_m(HwAuthySca_Uls_T_u2p14, u2p14_T);	
	
	HwAuthySca_Uls_T_f32 = Limit_m(HwAuthySca_Uls_T_f32, 
								  (CtrldVelRtn_PrevHwAuthySca_Uls_M_f32 - (k_Rtn_HwAuthySlew_UlspS_f32 * D_2MS_SEC_F32)),
								  (CtrldVelRtn_PrevHwAuthySca_Uls_M_f32 + (k_Rtn_HwAuthySlew_UlspS_f32 * D_2MS_SEC_F32)));

	CtrldVelRtn_PrevHwAuthySca_Uls_M_f32 = HwAuthySca_Uls_T_f32;
	
	CtrldVelRtn_HwAuthySca_Uls_D_f32 = HwAuthySca_Uls_T_f32;
	
	/* Control scale */
	CtrlScaPreFilt_Uls_T_f32 = PosSca_Uls_T_f32 * 
							   HwTrqSca_Uls_T_f32 * 
							   TbarTrqSca_Uls_T_f32 *
							   TrqGrdtSca_Uls_T_f32 *
							   VelErrSca_Uls_T_f32 *
							   HwAuthySca_Uls_T_f32;
								
	CtrldVelRtn_CtrlScaPreFilt_Uls_D_f32 = CtrlScaPreFilt_Uls_T_f32;
	
	CtrlSca_Uls_T_f32 = LPF_OpUpdate_f32_m(CtrlScaPreFilt_Uls_T_f32, &CtrldVelRtn_CtrlScaLPFSV_Uls_M_Str);
	
	CtrldVelRtn_CtrlSca_Uls_D_f32 = CtrlSca_Uls_T_f32;
	
	/* Desired Velocity Scale */
	DesVelScaPreFilt_Uls_T_u2p14 = BilinearXMYM_u16_u16XMu16YM_Cnt(VehicleSpeed_Kph_T_u9p7,
															     FPM_FloatToFixed_m(Abs_f32_m(DrvTrqFilt_HwNm_T_f32), u8p8_T),
															     t_Rtn_ScaFacVehSpdTbl_Kph_u9p7,
															     TableSize_m(t_Rtn_ScaFacVehSpdTbl_Kph_u9p7),
															     (P2CONST(uint16, AUTOMATIC, CTRLDVELRTN_CONST))t2_Rtn_DesVelScaX_HwNm_u8p8,
															     (P2CONST(uint16, AUTOMATIC, CTRLDVELRTN_CONST))t2_Rtn_DesVelScaY_Uls_u2p14,
															     TableSize_m(t2_Rtn_DesVelScaX_HwNm_u8p8[0]));
														   
	DesVelScaPreFilt_Uls_T_f32 = FPM_FixedToFloat_m(DesVelScaPreFilt_Uls_T_u2p14, u2p14_T);													   
	CtrldVelRtn_DesVelScaPreFilt_Uls_D_f32 = DesVelScaPreFilt_Uls_T_f32;
	
	DesVelSca_Uls_T_f32 = LPF_OpUpdate_f32_m(DesVelScaPreFilt_Uls_T_f32, &CtrldVelRtn_DesVelScaLPFSV_Uls_M_Str);
	CtrldVelRtn_DesVelSca_Uls_D_f32 = DesVelSca_Uls_T_f32;
	/*** End of 'Scale' ***/
	
	/*** Start of 'Target Velocity' ***/
	DesVelScaFacPreFilt_Uls_T_u10p6 = BilinearXMYM_u16_u16XMu16YM_Cnt(VehicleSpeed_Kph_T_u9p7,
															        HwPosAbs_HwDeg_T_u12p4,
															        t_Rtn_VehSpdTbl_Kph_u9p7,
															        TableSize_m(t_Rtn_VehSpdTbl_Kph_u9p7),
															        (P2CONST(uint16, AUTOMATIC, CTRLDVELRTN_CONST))t2_Rtn_DesVelX_HwDeg_u12p4,
															        (P2CONST(uint16, AUTOMATIC, CTRLDVELRTN_CONST))t2_Rtn_DesVelY_HwDegpS_u10p6,
															        TableSize_m(t2_Rtn_DesVelX_HwDeg_u12p4[0]));
														   
	DesVelScaFacPreFilt_Uls_T_f32 = FPM_FixedToFloat_m(DesVelScaFacPreFilt_Uls_T_u10p6, u10p6_T);		
	
	DesVelPreFilt_HwDegpS_T_f32 = (-(float32)Sign_f32_m(CompHwPos_HwDeg_T_f32)) *
	                              DesVelScaFacPreFilt_Uls_T_f32 * 								  
	                              DesVelSca_Uls_T_f32;
	
	CtrldVelRtn_DesVel_HwDegpS_M_f32 = LPF_OpUpdate_f32_m(DesVelPreFilt_HwDegpS_T_f32, &CtrldVelRtn_DesVelLPFSV_HwDegpS_M_Str);		
	CtrldVelRtn_DesVel_HwDegpS_D_f32 = CtrldVelRtn_DesVel_HwDegpS_M_f32;
	/*** End of 'Target Velocity' ***/
	
	/*** Start of 'Control' ***/
	VelErr_HwDegpS_T_f32 = CtrldVelRtn_DesVel_HwDegpS_M_f32 - HwVel_HwDegpS_T_f32;
	
	/* Control Gain */
	Kp_Uls_T_u4p12 = IntplVarXY_u16_u16Xu16Y_Cnt(t_Rtn_VehSpdTbl_Kph_u9p7,
												 t_Rtn_Kp_Uls_u4p12,
												 TableSize_m(t_Rtn_VehSpdTbl_Kph_u9p7),
												 VehicleSpeed_Kph_T_u9p7);
	
	Kp_Uls_T_f32 = FPM_FixedToFloat_m(Kp_Uls_T_u4p12, u4p12_T);		
	
	Ki_Uls_T_u8p8 = IntplVarXY_u16_u16Xu16Y_Cnt(t_Rtn_VehSpdTbl_Kph_u9p7,
												t_Rtn_Ki_Uls_u8p8,
												TableSize_m(t_Rtn_VehSpdTbl_Kph_u9p7),
												VehicleSpeed_Kph_T_u9p7);
	
	Ki_Uls_T_f32 = FPM_FixedToFloat_m(Ki_Uls_T_u8p8, u8p8_T);
	
	/* Proportional Control */
	PTerm_HwNm_T_f32 = Kp_Uls_T_f32 * VelErr_HwDegpS_T_f32 * CtrlSca_Uls_T_f32;
	
	CtrldVelRtn_PTermCmd_HwNm_D_f32 = PTerm_HwNm_T_f32;
	
	/* Integral Control */
	IntLimUpper_HwNm_T_u6p10 = BilinearXYM_u16_u16Xu16YM_Cnt(VehicleSpeed_Kph_T_u9p7,
															 HwPosAbs_HwDeg_T_u12p4,
															 t_Rtn_ScaFacVehSpdTbl_Kph_u9p7,
															 TableSize_m(t_Rtn_ScaFacVehSpdTbl_Kph_u9p7),
															 (P2CONST(uint16, AUTOMATIC, CTRLDVELRTN_CONST))t_Rtn_PosScaX_HwDeg_u12p4,
															 (P2CONST(uint16, AUTOMATIC, CTRLDVELRTN_CONST))t2_Rtn_IntgtrLimTblY_HwNm_u6p10,
															 TableSize_m(t_Rtn_PosScaX_HwDeg_u12p4));
														   
	IntLimUpper_HwNm_T_f32 = FPM_FixedToFloat_m(IntLimUpper_HwNm_T_u6p10, u6p10_T) * CtrlSca_Uls_T_f32 ;
	
	CtrldVelRtn_IntgtrLim_HwNm_D_f32 = IntLimUpper_HwNm_T_f32;
	
	ITermA_HwNm_T_f32 = Ki_Uls_T_f32 * VelErr_HwDegpS_T_f32 * CtrlSca_Uls_T_f32;
	
	ITermB_HwNm_T_f32 = ITermA_HwNm_T_f32 + CtrldVelRtn_PrevITermC_HwNm_M_f32;
	                    
	ITermC_HwNm_T_f32 = (((ITermB_HwNm_T_f32 + CtrldVelRtn_PrevITermB_HwNm_M_f32) * 0.5F) * D_2MS_SEC_F32) + CtrldVelRtn_PrevITerm_HwNm_M_f32;
	
	ITerm_HwNm_T_f32 = Limit_m(ITermC_HwNm_T_f32, -IntLimUpper_HwNm_T_f32, IntLimUpper_HwNm_T_f32);
	
	CtrldVelRtn_PrevITermB_HwNm_M_f32 = ITermB_HwNm_T_f32;
	CtrldVelRtn_PrevITermC_HwNm_M_f32 = (ITerm_HwNm_T_f32 - ITermC_HwNm_T_f32) * k_Rtn_Kb_Uls_f32;
	CtrldVelRtn_PrevITerm_HwNm_M_f32 = ITerm_HwNm_T_f32;
	
	CtrldVelRtn_ITermCmd_HwNm_D_f32 = ITerm_HwNm_T_f32;
	
	PITerm_HwNm_T_f32 = PTerm_HwNm_T_f32 + ITerm_HwNm_T_f32;
	/*** End of 'Control' ***/
	
	/*** Start of 'Damping' ***/
	DampgTermInter_HwNm_T_u6p10 = BilinearXMYM_u16_u16XMu16YM_Cnt(VehicleSpeed_Kph_T_u9p7,
															    FPM_FloatToFixed_m(Abs_f32_m(HwVel_HwDegpS_T_f32), u10p6_T),
															    t_Rtn_VehSpdTbl_Kph_u9p7,
															    TableSize_m(t_Rtn_VehSpdTbl_Kph_u9p7),
															    (P2CONST(uint16, AUTOMATIC, CTRLDVELRTN_CONST))t2_Rtn_DampgTblX_HwDegpS_u10p6,
															    (P2CONST(uint16, AUTOMATIC, CTRLDVELRTN_CONST))t2_Rtn_DampgTblY_HwNm_u6p10,
															    TableSize_m(t2_Rtn_DampgTblX_HwDegpS_u10p6[0]));
														   
	DampgTermInter_HwNm_T_f32 = FPM_FixedToFloat_m(DampgTermInter_HwNm_T_u6p10, u6p10_T);		
	
	DampgTerm_HwNm_T_f32 = ((float32)Sign_f32_m(HwVel_HwDegpS_T_f32)) *
	                       DampgTermInter_HwNm_T_f32 *
	                       ((k_Rtn_DampgEnable_Cnt_Lgc == TRUE)? 1.0F : 0.0F) *
						   ((k_Rtn_DampgScaEnable_Cnt_Lgc == TRUE)? CtrlSca_Uls_T_f32 : 1.0F);
	
	CtrldVelRtn_DampgCmd_HwNm_D_f32 = DampgTerm_HwNm_T_f32;
	
	/*** End of 'Damping' ***/
	
	/*** Start of 'Limit' ***/
	
	RtnCmdLimUpper_MtrNm_T_u4p12 = IntplVarXY_u16_u16Xu16Y_Cnt(t_Rtn_VehSpdTbl_Kph_u9p7,
															   t_Rtn_OutpLimTblY_MtrNm_u4p12,
															   TableSize_m(t_Rtn_VehSpdTbl_Kph_u9p7),
															   VehicleSpeed_Kph_T_u9p7);
	
	RtnCmdLimUpper_MtrNm_T_f32 = FPM_FixedToFloat_m(RtnCmdLimUpper_MtrNm_T_u4p12, u4p12_T);	
	
	if((DefeatReturnSvc_Cnt_T_lgc == TRUE) || (DiagStsHwPosDis_Cnt_T_lgc == TRUE))
	{
		PreLimRtnCmd_MtrNm_T_f32 = 0.0F;
	}
	else
	{
		PreLimRtnCmd_MtrNm_T_f32 = ((PITerm_HwNm_T_f32 - DampgTerm_HwNm_T_f32) *
		                            k_Rtn_Polarity_Uls_f32 *
									ReturnDDFactor_Uls_T_f32 *
									PAReturnSclFct_Uls_T_f32) / k_Cmn_SysTrqRatio_HwNmpMtrNm_f32;
	}
	
	CtrldVelRtn_RtnCmdPreLim_MtrNm_D_f32 = PreLimRtnCmd_MtrNm_T_f32;
	
	RtnCmd_MtrNm_T_f32 = Limit_m(PreLimRtnCmd_MtrNm_T_f32, -RtnCmdLimUpper_MtrNm_T_f32, RtnCmdLimUpper_MtrNm_T_f32);
	
	CtrldVelRtn_ReturnCmd_MtrNm_D_f32 = RtnCmd_MtrNm_T_f32;
	/*** End of 'Limit' ***/
	
	Rte_IWrite_CtrldVelRtn_Per1_ReturnCmd_MtrNm_f32(RtnCmd_MtrNm_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_CTRLDVELRTN_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Name		    :	InpCdng
* Description	:	Implementation of "Input Conditioning" block
* Inputs		:	ReturnOffset_HwDeg_T_f32,HandwheelPosition_HwDeg_T_f32,HandwheelVelocity_HwRadpS_T_f32
* 				    *CompHwPos_HwDeg_T_f32,*HwVel_HwDegpS_T_f32
* Outputs		:	None
* Usage Notes   :   None
**********************************************************************************************************************/
STATIC FUNC(void, CTRLDVELRTN_APPL_CODE) InpCdng(VAR(float32,AUTOMATIC) ReturnOffset_HwDeg_T_f32,
		                                         VAR(float32,AUTOMATIC) HandwheelPosition_HwDeg_T_f32,
												 VAR(float32,AUTOMATIC) HandwheelVelocity_HwRadpS_T_f32,
												 P2VAR(float32, AUTOMATIC, CTRLDVELRTN_APPL_VAR) CompHwPos_HwDeg_T_f32,
												 P2VAR(float32, AUTOMATIC, CTRLDVELRTN_APPL_VAR) HwVel_HwDegpS_T_f32)
{
	VAR(float32,AUTOMATIC) ReturnOffsetLimd_HwDeg_T_f32;
	VAR(float32,AUTOMATIC) ReturnOffsetSlew_HwDeg_T_f32;
	
	ReturnOffsetLimd_HwDeg_T_f32 = Limit_m(ReturnOffset_HwDeg_T_f32, -k_Rtn_OffsRng_HwDeg_f32, k_Rtn_OffsRng_HwDeg_f32);
	
	ReturnOffsetSlew_HwDeg_T_f32 = Limit_m(ReturnOffsetLimd_HwDeg_T_f32, 
	                                      (CtrldVelRtn_PrevRtnOffsetSlew_HwDeg_M_f32 - (k_Rtn_OffsSlew_HwDegpS_f32 * D_2MS_SEC_F32)),
										  (CtrldVelRtn_PrevRtnOffsetSlew_HwDeg_M_f32 + (k_Rtn_OffsSlew_HwDegpS_f32 * D_2MS_SEC_F32)));
										  
	CtrldVelRtn_PrevRtnOffsetSlew_HwDeg_M_f32 = ReturnOffsetSlew_HwDeg_T_f32;
	
	*CompHwPos_HwDeg_T_f32 = HandwheelPosition_HwDeg_T_f32 - ReturnOffsetSlew_HwDeg_T_f32;
	
	CtrldVelRtn_HwPosComp_HwDeg_D_f32 = *CompHwPos_HwDeg_T_f32;
	
	*HwVel_HwDegpS_T_f32 = HandwheelVelocity_HwRadpS_T_f32/D_PIOVR180_ULS_F32;	                                       
}
/**********************************************************************************************************************
* Name		    :	DrvrTqSelctr
* Description	:	Implementation of "Driver Torque Selector" block
* Inputs		:	MtrTrqCmd_MtrNm_T_f32,TbarTrq_HwNm_T_f32,HwPos_HwDeg_T_f32,HwVel_HwDegpS_T_f32
* Outputs		:	DrvTrq_HwNm_T_f32
* Usage Notes   :   None
**********************************************************************************************************************/
STATIC FUNC(float32, CTRLDVELRTN_APPL_CODE) DrvrTqSelctr(VAR(float32,AUTOMATIC) MtrTrqCmd_MtrNm_T_f32,
														 VAR(float32,AUTOMATIC) TbarTrq_HwNm_T_f32,
									                     VAR(float32,AUTOMATIC) HwPos_HwDeg_T_f32,
									                     VAR(float32,AUTOMATIC) HwVel_HwRadpS_T_f32)
{
	VAR(float32,AUTOMATIC) DrvTrq_HwNm_T_f32;
	VAR(float32,AUTOMATIC) TrqMtrx_HwNm_T_f3[4];
	VAR(float32,AUTOMATIC) OutpMtrxA_Uls_T_f32[5];
	VAR(float32,AUTOMATIC) OutpMtrxB_Uls_T_f32[5];
	VAR(float32,AUTOMATIC) Sum_Uls_T_f32 = 0.0F;
	VAR(float32,AUTOMATIC) SumA_Uls_T_f32 = 0.0F;
	VAR(float32,AUTOMATIC) SumB_Uls_T_f32 = 0.0F;

	VAR(uint8,AUTOMATIC) RowIdx_Uls_T_u08;
	VAR(uint8,AUTOMATIC) ColIdx_Uls_T_u08;
 
	if(k_Rtn_DrvTrqEnable_Cnt_Lgc != FALSE)
	{
		TrqMtrx_HwNm_T_f3[0] = (MtrTrqCmd_MtrNm_T_f32 * k_Cmn_SysTrqRatio_HwNmpMtrNm_f32);
		TrqMtrx_HwNm_T_f3[1] = TbarTrq_HwNm_T_f32;
		TrqMtrx_HwNm_T_f3[2] = (HwPos_HwDeg_T_f32 * D_PIOVR180_ULS_F32);
		TrqMtrx_HwNm_T_f3[3] = HwVel_HwRadpS_T_f32;

		for (RowIdx_Uls_T_u08 = 0U; RowIdx_Uls_T_u08 < D_MAX5_CNT_U08; RowIdx_Uls_T_u08++)
		{
			SumA_Uls_T_f32 = SumA_Uls_T_f32 + ((t_Rtn_DrvTrqMtrxC_Uls_f32[RowIdx_Uls_T_u08]) *
											   (CtrldVelRtn_PrevOutpMtrx_Uls_M_f32[RowIdx_Uls_T_u08]));
		}
		
		for (RowIdx_Uls_T_u08 = 0U; RowIdx_Uls_T_u08 < D_MAX4_CNT_U08; RowIdx_Uls_T_u08++)
		{
			SumB_Uls_T_f32 = SumB_Uls_T_f32 + ((t_Rtn_DrvTrqMtrxD_Uls_f32[RowIdx_Uls_T_u08]) *
											   (TrqMtrx_HwNm_T_f3[RowIdx_Uls_T_u08]));
		}

		for (RowIdx_Uls_T_u08 = 0U; RowIdx_Uls_T_u08 < D_MAX5_CNT_U08; RowIdx_Uls_T_u08++)
		{
			for (ColIdx_Uls_T_u08 = 0U; ColIdx_Uls_T_u08 < D_MAX4_CNT_U08; ColIdx_Uls_T_u08++)
			{
				Sum_Uls_T_f32 = Sum_Uls_T_f32 + ((t2_Rtn_DrvTrqMtrxB_Uls_f32[RowIdx_Uls_T_u08][ColIdx_Uls_T_u08]) *
												 (TrqMtrx_HwNm_T_f3[ColIdx_Uls_T_u08]));
			}
			OutpMtrxA_Uls_T_f32[RowIdx_Uls_T_u08] = Sum_Uls_T_f32;

			Sum_Uls_T_f32 = 0.0F;
		}

		for (RowIdx_Uls_T_u08 = 0U; RowIdx_Uls_T_u08 < D_MAX5_CNT_U08; RowIdx_Uls_T_u08++)
		{
			for (ColIdx_Uls_T_u08 = 0U; ColIdx_Uls_T_u08 < D_MAX5_CNT_U08; ColIdx_Uls_T_u08++)
			{
				Sum_Uls_T_f32 = Sum_Uls_T_f32 + ((t2_Rtn_DrvTrqMtrxA_Uls_f32[RowIdx_Uls_T_u08][ColIdx_Uls_T_u08]) *
												 (CtrldVelRtn_PrevOutpMtrx_Uls_M_f32[ColIdx_Uls_T_u08]));
			}
			OutpMtrxB_Uls_T_f32[RowIdx_Uls_T_u08] = Sum_Uls_T_f32;
				
			Sum_Uls_T_f32 = 0.0F;
		}
		
		for (RowIdx_Uls_T_u08 = 0U; RowIdx_Uls_T_u08 < D_MAX5_CNT_U08; RowIdx_Uls_T_u08++)
		{
			CtrldVelRtn_PrevOutpMtrx_Uls_M_f32[RowIdx_Uls_T_u08] = OutpMtrxA_Uls_T_f32[RowIdx_Uls_T_u08] + OutpMtrxB_Uls_T_f32[RowIdx_Uls_T_u08];
		}

		CtrldVelRtn_PrevOutpMtrx_Uls_M_f32[0] = Limit_m(CtrldVelRtn_PrevOutpMtrx_Uls_M_f32[0],-D_DRVRTQOBSVRAGTHD_HWRAD_F32,D_DRVRTQOBSVRAGTHD_HWRAD_F32);
		CtrldVelRtn_PrevOutpMtrx_Uls_M_f32[1] = Limit_m(CtrldVelRtn_PrevOutpMtrx_Uls_M_f32[1],-D_DRVRTQOBSVRVELTHD_HWRADPS_F32,D_DRVRTQOBSVRVELTHD_HWRADPS_F32);
		CtrldVelRtn_PrevOutpMtrx_Uls_M_f32[2] = Limit_m(CtrldVelRtn_PrevOutpMtrx_Uls_M_f32[2],-D_DRVRTQOBSVRAGTHD_HWRAD_F32,D_DRVRTQOBSVRAGTHD_HWRAD_F32);
		CtrldVelRtn_PrevOutpMtrx_Uls_M_f32[3] = Limit_m(CtrldVelRtn_PrevOutpMtrx_Uls_M_f32[3],-D_DRVRTQOBSVRVELTHD_HWRADPS_F32,D_DRVRTQOBSVRVELTHD_HWRADPS_F32);
		CtrldVelRtn_PrevOutpMtrx_Uls_M_f32[4] = Limit_m(CtrldVelRtn_PrevOutpMtrx_Uls_M_f32[4],-D_DRVRTQOBSVRTQTHD_HWNM_F32,D_DRVRTQOBSVRTQTHD_HWNM_F32);

		DrvTrq_HwNm_T_f32 = SumA_Uls_T_f32 + SumB_Uls_T_f32;
		DrvTrq_HwNm_T_f32 = Limit_m(DrvTrq_HwNm_T_f32,-D_DRVRTQOBSVRFINALTHD_HWNM_F32,D_DRVRTQOBSVRFINALTHD_HWNM_F32);
		
		CtrldVelRtn_DrvTrqEst_HwNm_D_f32 = DrvTrq_HwNm_T_f32;		
	}
	else
	{
		DrvTrq_HwNm_T_f32 = TbarTrq_HwNm_T_f32;
	}
	
	return DrvTrq_HwNm_T_f32;

}
/**********************************************************************************************************************
* Name		    :	TqGrdtSca
* Description	:	Implementation of "Torque Gradient Scale" block
* Inputs		:	DrvTrqFilt_HwNm_T_f32,VehicleSpeed_Kph_T_f32
* Outputs		:	TrqGrdtSca_Uls_T_f32
* Usage Notes   :   None
**********************************************************************************************************************/
STATIC FUNC(float32, CTRLDVELRTN_APPL_CODE) TqGrdtSca(VAR(float32,AUTOMATIC) DrvTrqFilt_HwNm_T_f32,
                                                      VAR(float32,AUTOMATIC) VehicleSpeed_Kph_T_f32)
{
	VAR(float32,AUTOMATIC) TrqGrdt_HwNmpS_T_f32;
	VAR(uint16,AUTOMATIC) TrqGrdtSca_Uls_T_u2p14;
	VAR(float32,AUTOMATIC) TrqGrdtSca_Uls_T_f32;
	VAR(float32,AUTOMATIC) DrvTrqFiltInter_HwNm_T_f32;
	
	DrvTrqFiltInter_HwNm_T_f32 = (float32)(DrvTrqFilt_HwNm_T_f32 * D_TRQGRADCALCNWGHTGFAC4_ULS_F32);
	
	if(k_Rtn_TrqGrdtScaEnable_Cnt_lgc == TRUE)
	{		
		/* Torque Gradient */
		TrqGrdt_HwNmpS_T_f32 = (float32)(((float32)(DrvTrqFiltInter_HwNm_T_f32 - CtrldVelRtn_PrevFDrvTrqFilt_HwNm_M_f32) * D_TRQGRADCALCNWGHTGFAC1_ULS_F32) +
							             ((float32)(CtrldVelRtn_PrevADrvTrqFilt_HwNm_M_f32 - CtrldVelRtn_PrevEDrvTrqFilt_HwNm_M_f32) * D_TRQGRADCALCNWGHTGFAC2_ULS_F32) +
							             ((float32)(CtrldVelRtn_PrevBDrvTrqFilt_HwNm_M_f32 - CtrldVelRtn_PrevDDrvTrqFilt_HwNm_M_f32) * D_TRQGRADCALCNWGHTGFAC3_ULS_F32));
							   
		CtrldVelRtn_TrqGrdt_HwNmpS_D_f32 = TrqGrdt_HwNmpS_T_f32;
		
		CtrldVelRtn_PrevFDrvTrqFilt_HwNm_M_f32 = CtrldVelRtn_PrevEDrvTrqFilt_HwNm_M_f32;
		CtrldVelRtn_PrevEDrvTrqFilt_HwNm_M_f32 = CtrldVelRtn_PrevDDrvTrqFilt_HwNm_M_f32;
		CtrldVelRtn_PrevDDrvTrqFilt_HwNm_M_f32 = CtrldVelRtn_PrevCDrvTrqFilt_HwNm_M_f32;
		CtrldVelRtn_PrevCDrvTrqFilt_HwNm_M_f32 = CtrldVelRtn_PrevBDrvTrqFilt_HwNm_M_f32;		
		CtrldVelRtn_PrevBDrvTrqFilt_HwNm_M_f32 = CtrldVelRtn_PrevADrvTrqFilt_HwNm_M_f32;		
		CtrldVelRtn_PrevADrvTrqFilt_HwNm_M_f32 = DrvTrqFiltInter_HwNm_T_f32;




		
		TrqGrdtSca_Uls_T_u2p14 = BilinearXMYM_u16_u16XMu16YM_Cnt(FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, u9p7_T),
															   FPM_FloatToFixed_m(Abs_f32_m(TrqGrdt_HwNmpS_T_f32), u8p8_T),
															   t_Rtn_ScaFacVehSpdTbl_Kph_u9p7,
															   TableSize_m(t_Rtn_ScaFacVehSpdTbl_Kph_u9p7),
															   (P2CONST(uint16, AUTOMATIC, CTRLDVELRTN_CONST))t2_Rtn_TrqGrdtScaX_HwNmpS_u8p8,
															   (P2CONST(uint16, AUTOMATIC, CTRLDVELRTN_CONST))t2_Rtn_TrqGrdtScaY_Uls_u2p14,
															   TableSize_m(t2_Rtn_TrqGrdtScaX_HwNmpS_u8p8[0]));
		
		TrqGrdtSca_Uls_T_f32 = FPM_FixedToFloat_m(TrqGrdtSca_Uls_T_u2p14, u2p14_T);
	}
	else
	{
		TrqGrdtSca_Uls_T_f32 = 1.0F;
	}
	
	return TrqGrdtSca_Uls_T_f32;
}
/**********************************************************************************************************************
* Name		    :	VelErrSca
* Description	:	Implementation of "Velocity Error Scale" block
* Inputs		:	HwPos_HwDeg_T_f32,HwVel_HwDegpS_T_f32,VehicleSpeed_Kph_T_f32
* Outputs		:	VelErrSca_Uls_T_f32
* Usage Notes   :   None
**********************************************************************************************************************/
STATIC FUNC(float32, CTRLDVELRTN_APPL_CODE) VelErrSca(VAR(float32,AUTOMATIC) HwPos_HwDeg_T_f32,
													  VAR(float32,AUTOMATIC) HwVel_HwDegpS_T_f32,
													  VAR(float32,AUTOMATIC) VehicleSpeed_Kph_T_f32)
{
	VAR(uint16,AUTOMATIC) VelErrScaIntm_Uls_T_u2p14;
	VAR(float32,AUTOMATIC) VelErrScaIntm_Uls_T_f32;
	VAR(uint16,AUTOMATIC) VehSpdIntpl_Uls_T_u2p14;
	VAR(float32,AUTOMATIC) VehSpdIntpl_Uls_T_f32;
	VAR(float32,AUTOMATIC) VelErrSca_Uls_T_f32;
	
	if(k_Rtn_VelErrScaEnable_Cnt_lgc == TRUE)
	{
		VelErrScaIntm_Uls_T_u2p14 = BilinearXYM_u16_s16Xu16YM_Cnt(FPM_FloatToFixed_m(Abs_f32_m(HwPos_HwDeg_T_f32), u12p4_T),
																  FPM_FloatToFixed_m((Abs_f32_m(Abs_f32_m(HwVel_HwDegpS_T_f32) - CtrldVelRtn_DesVel_HwDegpS_M_f32)), s10p5_T),
																  t_Rtn_VelErrorScaZ_HwDeg_u12p4,
																  TableSize_m(t_Rtn_VelErrorScaZ_HwDeg_u12p4),
																  (P2CONST(sint16, AUTOMATIC, CTRLDVELRTN_CONST))t_Rtn_VelErrorScaX_HwDegpS_s10p5,
																  (P2CONST(uint16, AUTOMATIC, CTRLDVELRTN_CONST))t2_Rtn_VelErrorScaY_Uls_u2p14,
																  TableSize_m(t_Rtn_VelErrorScaX_HwDegpS_s10p5));
														
		VelErrScaIntm_Uls_T_f32 = FPM_FixedToFloat_m(VelErrScaIntm_Uls_T_u2p14, u2p14_T);													
	}
	else
	{
		VelErrScaIntm_Uls_T_f32 = 1.0F;
	}
	
	VehSpdIntpl_Uls_T_u2p14 = IntplVarXY_u16_u16Xu16Y_Cnt(t_Rtn_ScaFacVehSpdTbl_Kph_u9p7,
														  t_Rtn_VelErrVehSpdScaY_Uls_u2p14,
														  TableSize_m(t_Rtn_ScaFacVehSpdTbl_Kph_u9p7),
														  FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, u9p7_T));
	
	VehSpdIntpl_Uls_T_f32 = FPM_FixedToFloat_m(VehSpdIntpl_Uls_T_u2p14, u2p14_T);													   
	
	VelErrSca_Uls_T_f32 = (VelErrScaIntm_Uls_T_f32 * VehSpdIntpl_Uls_T_f32) + 
	                      (1.0F - VehSpdIntpl_Uls_T_f32);
	
	return VelErrSca_Uls_T_f32;
}
/**********************************************************************************************************************
* Name		    :	HwTrqSca
* Description	:	Implementation of "Handwheel Torque Scale" block
* Inputs		:	DrvTrqFilt_HwNm_T_f32,HwVel_HwDegpS_T_f32,VehicleSpeed_Kph_T_f32
* Outputs		:	HwTrqSca_Uls_T_f32
* Usage Notes   :   None
**********************************************************************************************************************/
STATIC FUNC(float32, CTRLDVELRTN_APPL_CODE) HwTrqSca(VAR(float32,AUTOMATIC) DrvTrqFilt_HwNm_T_f32,
													 VAR(float32,AUTOMATIC) HwVel_HwDegpS_T_f32,
													 VAR(float32,AUTOMATIC) VehicleSpeed_Kph_T_f32)
{
	VAR(float32,AUTOMATIC) HwTrqSca_Uls_T_f32;
	VAR(float32,AUTOMATIC) HwTrqScaInp_Uls_T_f32;
	VAR(float32,AUTOMATIC) HwTrqScaSelector_Uls_T_f32;
	VAR(uint16,AUTOMATIC) VehicleSpeed_Kph_T_u9p7;
	VAR(uint16,AUTOMATIC) DrvTrqFiltAbs_HwNm_T_u8p8;
	VAR(uint16,AUTOMATIC) HwTrqSca1_Uls_T_u2p14;
	VAR(float32,AUTOMATIC) HwTrqSca1_Uls_T_f32;
	VAR(uint16,AUTOMATIC) HwTrqSca2_Uls_T_u2p14;
	VAR(float32,AUTOMATIC) HwTrqSca2_Uls_T_f32;
	
	/* Select Hand wheel Torque Scale */
	if(((DrvTrqFilt_HwNm_T_f32 > k_Rtn_SelHwTrqScaTrqThr_HwNm_f32)&&
	    (HwVel_HwDegpS_T_f32 > k_Rtn_SelHwTrqScaVelThr_HwDegpS_f32))  ||
	   ((DrvTrqFilt_HwNm_T_f32 < -k_Rtn_SelHwTrqScaTrqThr_HwNm_f32)&&
	    (HwVel_HwDegpS_T_f32 < -k_Rtn_SelHwTrqScaVelThr_HwDegpS_f32))) 
	{
		HwTrqScaInp_Uls_T_f32 = 1.0F;
	}
	else
	{
		HwTrqScaInp_Uls_T_f32 = 0.0F;
	}
	
	HwTrqScaSelector_Uls_T_f32 = Limit_m(HwTrqScaInp_Uls_T_f32, 
								        (CtrldVelRtn_PrevHwTrqScaSelector_Uls_M_f32 + (k_Rtn_SelHwTrqScaSlewDec_UlspS_f32 * D_2MS_SEC_F32)),
								        (CtrldVelRtn_PrevHwTrqScaSelector_Uls_M_f32 + (k_Rtn_SelHwTrqScaSlewInc_UlspS_f32 * D_2MS_SEC_F32)));
	
	CtrldVelRtn_PrevHwTrqScaSelector_Uls_M_f32 = HwTrqScaSelector_Uls_T_f32;
	
	CtrldVelRtn_HwTrqScaSelector_Uls_D_f32 = HwTrqScaSelector_Uls_T_f32;
	
	/* Hand wheel Torque Scale Calculation */
	VehicleSpeed_Kph_T_u9p7 = FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, u9p7_T);
	DrvTrqFiltAbs_HwNm_T_u8p8 = FPM_FloatToFixed_m(Abs_f32_m(DrvTrqFilt_HwNm_T_f32), u8p8_T);
	
	HwTrqSca1_Uls_T_u2p14 = BilinearXMYM_u16_u16XMu16YM_Cnt(VehicleSpeed_Kph_T_u9p7,
														  DrvTrqFiltAbs_HwNm_T_u8p8,
														  t_Rtn_ScaFacVehSpdTbl_Kph_u9p7,
														  TableSize_m(t_Rtn_ScaFacVehSpdTbl_Kph_u9p7),
														  (P2CONST(uint16, AUTOMATIC, CTRLDVELRTN_CONST))t2_Rtn_HwTrqSca1X_HwNm_u8p8,
														  (P2CONST(uint16, AUTOMATIC, CTRLDVELRTN_CONST))t2_Rtn_HwTrqSca1Y_Uls_u2p14,
														  TableSize_m(t2_Rtn_HwTrqSca1X_HwNm_u8p8[0]));
												
	HwTrqSca1_Uls_T_f32 = FPM_FixedToFloat_m(HwTrqSca1_Uls_T_u2p14, u2p14_T);	
	
	HwTrqSca2_Uls_T_u2p14 = BilinearXMYM_u16_u16XMu16YM_Cnt(VehicleSpeed_Kph_T_u9p7,
														  DrvTrqFiltAbs_HwNm_T_u8p8,
														  t_Rtn_ScaFacVehSpdTbl_Kph_u9p7,
														  TableSize_m(t_Rtn_ScaFacVehSpdTbl_Kph_u9p7),
														  (P2CONST(uint16, AUTOMATIC, CTRLDVELRTN_CONST))t2_Rtn_HwTrqSca2X_HwNm_u8p8,
														  (P2CONST(uint16, AUTOMATIC, CTRLDVELRTN_CONST))t2_Rtn_HwTrqSca2Y_Uls_u2p14,
														  TableSize_m(t2_Rtn_HwTrqSca2X_HwNm_u8p8[0]));
											
	HwTrqSca2_Uls_T_f32 = FPM_FixedToFloat_m(HwTrqSca2_Uls_T_u2p14, u2p14_T);	
	
	HwTrqSca_Uls_T_f32 = (HwTrqSca1_Uls_T_f32 * HwTrqScaSelector_Uls_T_f32) + 
	                     ((1.0F - HwTrqScaSelector_Uls_T_f32) * HwTrqSca2_Uls_T_f32);
						 
	return HwTrqSca_Uls_T_f32;
}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
