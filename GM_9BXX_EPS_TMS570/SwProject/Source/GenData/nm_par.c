/* -----------------------------------------------------------------------------
  Filename:    nm_par.c
  Description: Toolversion: 08.31.00.01.01.01.23.01.00.00
                
                Serial Number: CBD1010123
                Customer Info: Nxtr
                               Package: GMLAN 3.0 Multi Channel 
                               Micro: TI TMS570 LS2125
                               Compiler: Texas Instruments 4.9.0
                
                
                Generator Fwk   : GENy 
                Generator Module: Nm_Gmlan_Gm
                
                Configuration   : C:\CMSynergy_Projects\Chrysler_C1xx\Chrysler_LWR_EPS_TMS570\Tools\AsrProject\GENy\RT_2.0_Mod.gny
                
                ECU: 
                        TargetSystem: Hw_Tms470/570Cpu (Dcan)
                        Compiler:     TexasInstruments
                        Derivates:    TMS570PSFC66
                
                Channel "Channel0":
                        Databasefile: C:\Synergy\GM_K2XX_EPS_TMS570-zz4r1x\GM_K2XX_EPS_TMS570\Tools\AsrProject\GENy\GlobalA_HS.dbc
                        Bussystem:    CAN
                        Manufacturer: General Motors
                        Node:         EPS_HS
                Channel "Channel1":
                        Databasefile: GlobalA_CE.dbc
                        Bussystem:    CAN
                        Manufacturer: General Motors
                        Node:         EPS_CE

  Generated by , 2013-07-16  15:26:14
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

#include "v_inc.h"
#include "gmnmdef.h"
#include "nm_par.h"
V_MEMROM0 V_MEMROM1 CanTransmitHandle V_MEMROM2 NmTxHandle_VNMF_Field[kNmNumberOfChannels * kNmNumberOfIdentities] = 
{
  kCanTxHandleNotUsed, 
  kCanTxHandleNotUsed
};

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 NmSourceId_Field[kNmNumberOfChannels * kNmNumberOfIdentities] = 
{
  49, 
  49
};

V_MEMROM0 V_MEMROM1 CanTransmitHandle V_MEMROM2 NmTxHandle_HLVW_Field[kNmNumberOfChannels] = 
{
  kCanTxHandleNotUsed, 
  kCanTxHandleNotUsed
};

/* VN configuration */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 NmVnTypeTable[kNmNumberOfVirtualNets] = 
{
  kVnLocal | kVnInitActive /* VN_SLHSSharedDiagnostic, Id: 0, Ch: Channel0 */, 
  kVnLocal /* VN_AllNodes, Id: 1, Ch: Channel0 */, 
  kVnLocal | kVnInitActive /* VN_SLHS_VNReq, Id: 2, Ch: Channel0 */, 
  kVnLocal | kVnInitActive /* VN_SLHSSharedDiagnostic, Id: 0, Ch: Channel1 */, 
  kVnLocal /* VN_AllNodes, Id: 1, Ch: Channel1 */, 
  kVnLocal | kVnInitActive /* VN_SLHS_VNReq, Id: 2, Ch: Channel1 */
};

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 NmVnStartIndex[kNmNumberOfChannels+1] = 
{
  0, 
  3, 
  6
};

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 NmVnRelevantMask[kNmNumberOfVnBytes] = 
{
  0x00u, 
  0x00u
};

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 NmVnByteMask[kNmNumberOfVirtualNets] = 
{
  0x80u /* VN_SLHSSharedDiagnostic, Id: 0, Ch: Channel0 */, 
  0x40u /* VN_AllNodes, Id: 1, Ch: Channel0 */, 
  0x20u /* VN_SLHS_VNReq, Id: 2, Ch: Channel0 */, 
  0x80u /* VN_SLHSSharedDiagnostic, Id: 0, Ch: Channel1 */, 
  0x40u /* VN_AllNodes, Id: 1, Ch: Channel1 */, 
  0x20u /* VN_SLHS_VNReq, Id: 2, Ch: Channel1 */
};

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 NmVnByteOffset[kNmNumberOfVirtualNets] = 
{
  0x00u /* VN_SLHSSharedDiagnostic, Id: 0, Ch: Channel0 */, 
  0x00u /* VN_AllNodes, Id: 1, Ch: Channel0 */, 
  0x00u /* VN_SLHS_VNReq, Id: 2, Ch: Channel0 */, 
  0x01u /* VN_SLHSSharedDiagnostic, Id: 0, Ch: Channel1 */, 
  0x01u /* VN_AllNodes, Id: 1, Ch: Channel1 */, 
  0x01u /* VN_SLHS_VNReq, Id: 2, Ch: Channel1 */
};

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 NmVnByteStartIndex[kNmNumberOfChannels+1] = 
{
  0, 
  1, 
  2
};

/* Nm channel properties */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 NmCallCycle_Field[kNmNumberOfChannels] = 
{
  10, 
  10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmHighSpeedCnt_Field[kNmNumberOfChannels] = 
{
  ((kNmHighSpeedTime + 10) - 1) / 10, 
  ((kNmHighSpeedTime + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmWakeupFailCnt_Field[kNmNumberOfChannels] = 
{
  ((kNmWakeupFailTime + 10) - 1) / 10, 
  ((kNmWakeupFailTime + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmVnTimerCnt_Field[kNmNumberOfChannels] = 
{
  ((kNmVnTimerTime + 10) - 1) / 10, 
  ((kNmVnTimerTime + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmVnRxTimerCnt_Field[kNmNumberOfChannels] = 
{
  ((kNmVnRxTimerTime + 10) - 1) / 10, 
  ((kNmVnRxTimerTime + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmWakeupSleepCnt_Field[kNmNumberOfChannels] = 
{
  ((kNmWakeupSleepTime + 10) - 1) / 10, 
  ((kNmWakeupSleepTime + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmDeactSleepCnt_Field[kNmNumberOfChannels] = 
{
  ((kNmDeactSleepTime + 10) - 1) / 10, 
  ((kNmDeactSleepTime + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmSleepDeniedCnt_Field[kNmNumberOfChannels] = 
{
  ((kNmSleepDeniedTime + 10) - 1) / 10, 
  ((kNmSleepDeniedTime + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmLastWakeupCnt_Field[kNmNumberOfChannels] = 
{
  ((kNmLastWakeupTime + 10) - 1) / 10, 
  ((kNmLastWakeupTime + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmVNRestartIVNMFCnt_Field[kNmNumberOfChannels] = 
{
  ((kNmVnRestartIVNMFTime + 10) - 1) / 10, 
  ((kNmVnRestartIVNMFTime + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmVNMFConfirmCnt_Field[kNmNumberOfChannels] = 
{
  ((500 + 10) - 1) / 10, 
  ((500 + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 tNmTrcvrType V_MEMROM2 NmTrcvType_Field[kNmNumberOfChannels] = 
{
  NM_HIGHSPEED_NOSLEEP_TRCV, 
  NM_HIGHSPEED_NOSLEEP_TRCV
};


/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 133574485
      #error "The magic number of the generated file <C:\CMSynergy_Projects\Chrysler_C1xx\Chrysler_LWR_EPS_TMS570\SwProject\Source\_GenData\nm_par.c> is different. Please check time and date of generated files!"
  #endif
#else
  #error "The magic number is not defined in the generated file <C:\CMSynergy_Projects\Chrysler_C1xx\Chrysler_LWR_EPS_TMS570\SwProject\Source\_GenData\nm_par.c> "

#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

