/* -----------------------------------------------------------------------------
  Filename:    tp_par.c
  Description: Toolversion: 08.31.00.01.01.01.23.01.00.00
                
                Serial Number: CBD1010123
                Customer Info: Nxtr
                               Package: GMLAN 3.0 Multi Channel 
                               Micro: TI TMS570 LS2125
                               Compiler: Texas Instruments 4.9.0
                
                
                Generator Fwk   : GENy 
                Generator Module: Tp_Iso15765
                
                Configuration   : C:\Synergy\GM_C1XX_EPS_TMS570-zz4r1x1\GM_C1XX_EPS_TMS570\Tools\AsrProject\GENy\RT_2.0_Mod.gny
                
                ECU: 
                        TargetSystem: Hw_Tms470/570Cpu (Dcan)
                        Compiler:     TexasInstruments
                        Derivates:    TMS570PSFC66
                
                Channel "Channel0":
                        Databasefile: C:\Synergy\GM_C1XX_EPS_TMS570-zz4r1x1\GM_C1XX_EPS_TMS570\Tools\AsrProject\GENy\GlobalA_HS.dbc
                        Bussystem:    CAN
                        Manufacturer: General Motors
                        Node:         EPS_HS
                Channel "Channel1":
                        Databasefile: C:\Synergy\GM_C1XX_EPS_TMS570-zz4r1x1\GM_C1XX_EPS_TMS570\Tools\AsrProject\GENy\GlobalA_CE.dbc
                        Bussystem:    CAN
                        Manufacturer: General Motors
                        Node:         EPS_CE

  Generated by , 2014-07-23  09:36:49
 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2008 by Vctr Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vctr Informatik 
  GmbH.
  
  Vctr Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vctr Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

#include "can_inc.h"
#include "tpmc.h"
#include "v_inc.h"
V_MEMROM0 V_MEMROM1 CanTransmitHandle V_MEMROM2 kTpTxHandle_Field[kTpTxChannelCount] = {
	  CanTxUSDT_Resp_From_EHPS_EPS_HS
	, CanTxUSDT_Resp_From_EPS_EPS_JR_CE
};


V_MEMROM0 V_MEMROM1 TxDataPtr V_MEMROM2 kTpTxData_Field[kTpTxChannelCount] = {
	  USDT_Resp_From_EHPS_EPS_HS._c
	, USDT_Resp_From_EPS_EPS_JR_CE._c
};


vuint8 DummyCopyToCan(TpCopyToCanInfoStructPtr infoStruct)
{
	__ApplTpTxCopyToCAN_mem(infoStruct);
	return 0;
}


V_MEMROM0 V_MEMROM1 ApplTpIndicationFct V_MEMROM2 TpRxIndication[kTpRxChannelCount] = {
	  DescPhysReqInd
	, GgdaPhysReqInd
};

V_MEMROM0 V_MEMROM1 ApplTpRxErrorIndicationFct V_MEMROM2 TpRxErrorIndication[kTpRxChannelCount] = {
	  DescRxErrorIndication
	, GgdaRxErrorIndication
};

V_MEMROM0 V_MEMROM1 ApplTpConfirmationFct V_MEMROM2 TpTxConfirmation[kTpTxChannelCount] = {
	  DescConfirmation
	, GgdaConfirmation
};

V_MEMROM0 V_MEMROM1 ApplTpGetRxBufferFct V_MEMROM2 TpGetRxBuffer[kTpRxChannelCount] = {
	  DescGetBuffer
	, GgdaPhysGetBuffer
};

V_MEMROM0 V_MEMROM1 ApplTpTxErrorIndicationFct V_MEMROM2 TpTxErrorIndication[kTpTxChannelCount] = {
	  DescTxErrorIndication
	, GgdaTxErrorIndication
};

V_MEMROM0 V_MEMROM1 ApplTpCopyToCanFct V_MEMROM2 TpTxCopyToCan[kTpTxChannelCount] = {
	  DescCopyToCAN
	, DummyCopyToCan
};

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 TpRxHandleToChannel[] = 
{
  0xFFu /* ID: 0x000007cb, Handle: 0, T1_HostToTarget */, 
  0xFFu /* ID: 0x00000500, Handle: 1, Wheel_Pulses_HS */, 
  0xFFu /* ID: 0x000004c1, Handle: 2, PPEI_Engine_General_Status_4 */, 
  0xFFu /* ID: 0x000003f1, Handle: 3, PPEI_Platform_Eng_Cntrl_Requests */, 
  0xFFu /* ID: 0x000003e9, Handle: 4, PPEI_Vehicle_Speed_and_Distance */, 
  0xFFu /* ID: 0x0000034a, Handle: 5, NonDriven_Wheel_Grnd_Velocity_HS */, 
  0xFFu /* ID: 0x00000348, Handle: 6, Driven_Wheel_Grnd_Velocity_HS */, 
  0xFFu /* ID: 0x00000232, Handle: 7, Driving_Mode_Control_HS */, 
  0xFFu /* ID: 0x00000214, Handle: 8, Brake_Pedal_Driver_Status_HS */, 
  0xFFu /* ID: 0x000001f5, Handle: 9, PPEI_Trans_General_Status_2 */, 
  0xFFu /* ID: 0x000001f1, Handle: 10, PPEI_Platform_General_Status */, 
  0xFFu /* ID: 0x000001e9, Handle: 11, PPEI_Chassis_General_Status_1 */, 
  0xFFu /* ID: 0x00000180, Handle: 12, LKA_Steering_Torque_Cmd_HS */, 
  0xFFu /* ID: 0x0000017d, Handle: 13, Antilock_Brake_and_TC_Status_HS */, 
  0xFFu /* ID: 0x000000d3, Handle: 14, PPEI_Hybrid_General_Status_3_HS */, 
  0xFFu /* ID: 0x000000c9, Handle: 15, PPEI_Engine_General_Status_1 */, 
  0xFFu /* ID: 0x000000c1, Handle: 16, PPEI_Driven_Whl_Rotational_Stat */, 
  0xFFu /* ID: 0x0000034a, Handle: 17, NonDriven_Wheel_Grnd_Velocity_CE */, 
  0xFFu /* ID: 0x00000348, Handle: 18, Driven_Wheel_Grnd_Velocity_CE */, 
  0xFFu /* ID: 0x00000337, Handle: 19, Park_Assist_Parallel_CE */, 
  0xFFu /* ID: 0x00000182, Handle: 20, Vehicle_Dynamics_ESC_Hyb_CE */, 
  0xFFu /* ID: 0x00000180, Handle: 21, Steering_Torque_Command_CE */, 
  0xFFu /* ID: 0x00000708, Handle: 22, Xcp_Master_Msg */, 
  0 /* ID: 0x00000242, Handle: 23, USDT_Req_to_EHPS_EPS_HS */, 
  0xFFu /* ID: 0x00000101, Handle: 24, USDT_Req_to_All_HS_ECUs */, 
  1 /* ID: 0x00000242, Handle: 25, USDT_Req_to_EPS_EPS_JR_CE */, 
  0xFFu /* ID: 0x00000101, Handle: 26, USDT_Req_to_All_CE_ECUs */
};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 TpTxHandleToChannel[] = 
{
  0xFFu /* ID: 0x00000778, Handle: 0, DTC_Triggered_778 */, 
  0xFFu /* ID: 0x00000706, Handle: 1, Xcp_Slave_Msg */, 
  0 /* ID: 0x00000642, Handle: 2, USDT_Resp_From_EHPS_EPS_HS */, 
  0xFFu /* ID: 0x00000542, Handle: 3, UUDT_Resp_From_EHPS_EPS_HS */, 
  0xFFu /* ID: 0x000001e5, Handle: 4, PPEI_Steering_Wheel_Angle */, 
  0xFFu /* ID: 0x00000184, Handle: 5, LKA_Steering_Trq_Overlay_Stat_HS */, 
  0xFFu /* ID: 0x00000148, Handle: 6, Power_Steering_Information_HS */, 
  1 /* ID: 0x00000642, Handle: 7, USDT_Resp_From_EPS_EPS_JR_CE */, 
  0xFFu /* ID: 0x00000542, Handle: 8, UUDT_Resp_From_EPS_EPS_JR_CE */, 
  0xFFu /* ID: 0x00000335, Handle: 9, Electric_Power_Steering_CE */, 
  0xFFu /* ID: 0x000001e5, Handle: 10, PPEI_Steering_Wheel_Angle_CE */, 
  0xFFu /* ID: 0x000001ca, Handle: 11, Steering_Torque_Overlay_Stat_CE */
};

/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 155536786
      #error "The magic number of the generated file <C:\Synergy\GM_C1XX_EPS_TMS570-zz4r1x1\GM_C1XX_EPS_TMS570\SwProject\Source\_GenData\tp_par.c> is different. Please check time and date of generated files!"
  #endif
#else
  #error "The magic number is not defined in the generated file <C:\Synergy\GM_C1XX_EPS_TMS570-zz4r1x1\GM_C1XX_EPS_TMS570\SwProject\Source\_GenData\tp_par.c> "

#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

