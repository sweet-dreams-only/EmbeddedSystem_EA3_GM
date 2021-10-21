/* -----------------------------------------------------------------------------
  Filename:    Dem_PBcfg.c
  Description: Toolversion: 12.00.01.01.11.00.60.01.00.00
               
               Serial Number: CBD1110060
               Customer Info: Nxtr GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments tbd
               
               
               Generator Fwk   : GENy 
               Generator Module: Dem
               
               Configuration   : C:\02_EA3Int\9Bxx\Wip_fz9hxm\GM_9BXX_EPS_TMS570\Tools\AsrProject\Config\DEM\gmHS_AFS_HS.ecuc.vdsxml
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570PSFC66
               
               Channel "CAN00":
                       Databasefile: 
                       Bussystem:    CAN
                       Manufacturer: Vector
                       Node:         CanStateManagerConfiguration

  Generated by , 2017-03-21  00:24:07
 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2011 by Vctr Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vctr Informatik 
  GmbH.
  
  Vctr Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vctr Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
    &&&~ Includes
 ----------------------------------------------------------------------------- */

/* configuration, interrupt handling implementations differ from the 
 * source identification define used here. The naming 
 * schemes for those files can be taken from this list: 
 * 
 * Dem.c:         DEM_SOURCE
 * Dem_Lcfg.c:    DEM_LCFG_SOURCE
 * Dem_PBcfg.c:   DEM_PBCFG_SOURCE */
#define DEM_PBCFG_SOURCE
#include "Dem.h"
#include "Dem_Lcfg.h"
#include "Dem_PBcfg.h"


/* -----------------------------------------------------------------------------
    &&&~ Version Check
 ----------------------------------------------------------------------------- */

#if (DIAG_ASRDEM_GENTOOL_GENY_MAJOR_VERSION != 0x03)
#error "Dem_PBcfg.c : Incompatible DIAG_ASRDEM_GENTOOL_GENY_MAJOR_VERSION in generated File!"
#endif

#if (DIAG_ASRDEM_GENTOOL_GENY_MINOR_VERSION != 0x10)
#error "Dem_PBcfg.c : Incompatible DIAG_ASRDEM_GENTOOL_GENY_MINOR_VERSION in generated File!"
#endif

#if (DIAG_ASRDEM_GENTOOL_GENY_PATCH_VERSION != 0x00)
#error "Dem_PBcfg.c : Incompatible DIAG_ASRDEM_GENTOOL_GENY_PATCH_VERSION in generated File!"
#endif



/* -----------------------------------------------------------------------------
    &&&~ Post-build changeable config data tables
 ----------------------------------------------------------------------------- */

#define DEM_START_SEC_PBCONST_ROOT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

CONST(Dem_PBConfigType, DEM_PBCFG) Dem_PBConfig = 
{
  0xDE021602u /* Implementation Version */, 
  0xFFFFFFFFu, 
  0xDEDEDEDEu
}; /* PRQA S 0850 */ /* MD_MSR_19.8 */
#define DEM_STOP_SEC_PBCONST_ROOT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


#define DEM_START_SEC_PBCONST
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

CONST(uint8, DEM_PBCFG) Dem_PostBuildProperty[] = 
{
  0, 3, 3, 3, 3, 3, 2, 3, 2, 3, 3, 3, 2, 3, 2, 2, 
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};
CONST(uint16, DEM_PBCFG) Dem_DTCNumberTable[] = 
{
  0xFFFFu, 0xE502u, 0xD833u, 0xC56Bu, 0xC45Au, 0xC422u, 0xC415u, 0xC402u, 0xC401u, 0xC26Au, 0xC159u, 0xC140u, 0xC121u, 0xC101u, 0xC100u, 0xC077u, 
  0xC073u, 0x5597u, 0x5512u, 0x5512u, 0x5512u, 0x544Bu, 0x544Au, 0x5437u, 0x5437u, 0x51EFu, 0x51D2u, 0x50A9u, 0x4051u, 0x4051u, 0x4051u, 0xFFFFu, 
  0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 
  0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu, 0xFFFFu
};
CONST(uint8, DEM_PBCFG) Dem_DTC_FTB_Table[] = 
{
  0xFFu, 0x71u, 0x00u, 0x71u, 0x71u, 0x71u, 0x71u, 0x71u, 0x71u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 
  0x00u, 0x00u, 0x12u, 0x07u, 0x03u, 0x42u, 0x00u, 0x4Bu, 0x00u, 0x00u, 0x00u, 0x54u, 0x5Au, 0x58u, 0x4Bu, 0xFFu, 
  0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 
  0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu
};
CONST(uint8, DEM_PBCFG) Dem_AgingCountTable[] = 
{
  0, 0, 49, 49
};
CONST(uint8, DEM_PBCFG) Dem_EventFlagsTable[] = 
{
  0, 0, 5, 4
};
CONST(Dem_DTCKindType, DEM_PBCFG) Dem_DtcKindTable[] = 
{
  0, 1, 1, 1
};
CONST(uint8, DEM_PBCFG) Dem_EventDestinationTable[] = 
{
  0, 0, 2, 2
};
CONST(uint8, DEM_PBCFG) Dem_EventDidIndexTable[] = 
{
  0, 0, 0, 0
};
CONST(uint8, DEM_PBCFG) Dem_EventDidCountTable[] = 
{
  0, 0, 19, 19
};
CONST(uint16, DEM_PBCFG) Dem_DidNumberTable[] = 
{
  0x4016u, 0x401Bu, 0x4074u, 0x40ACu, 0x40ADu, 0x40BCu, 0x40BDu, 0x41D3u, 0x41D4u, 0x41D5u, 0x41D6u, 0x41D7u, 0x41D9u, 0x43D0u, 0x446Fu, 0x8002u, 
  0x8078u, 0xC000u, 0xC050u
};
CONST(uint8, DEM_PBCFG) Dem_DidSizeTable[] = 
{
  2, 1, 2, 2, 1, 2, 1, 2, 2, 1, 1, 2, 2, 1, 2, 1, 
  1, 4, 5
};
CONST(uint8, DEM_PBCFG) Dem_SnapshotIndexTable[] = 
{
  0, 0, 0, 0
};
CONST(uint8, DEM_PBCFG) Dem_SnapshotCountTable[] = 
{
  0, 0, 1, 1
};
CONST(uint8, DEM_PBCFG) Dem_SnapshotNumberTable[] = 
{
  0, 255
};
CONST(uint8, DEM_PBCFG) Dem_SnapshotSizeTable[] = 
{
  35
};
CONST(uint8, DEM_PBCFG) Dem_SnapshotDidIndexTable[] = 
{
  0
};
CONST(uint8, DEM_PBCFG) Dem_SnapshotDidCountTable[] = 
{
  19
};
#define DEM_STOP_SEC_PBCONST
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"





/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 133575247
      #error "The magic number of the generated file <C:\02_EA3Int\9Bxx\Wip_fz9hxm\GM_9BXX_EPS_TMS570\SwProject\Source\_GenData\Dem_PBcfg.c> is different. Please check time and date of generated files!"
  #endif
#else
  #error "The magic number is not defined in the generated file <C:\02_EA3Int\9Bxx\Wip_fz9hxm\GM_9BXX_EPS_TMS570\SwProject\Source\_GenData\Dem_PBcfg.c> "

#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */
