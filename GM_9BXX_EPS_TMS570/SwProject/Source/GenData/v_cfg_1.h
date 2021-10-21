/* -----------------------------------------------------------------------------
  Filename:    v_cfg_1.h
  Description: Toolversion: 12.00.01.01.11.00.60.01.00.00
               
               Serial Number: CBD1110060
               Customer Info: Nxtr GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments tbd
               
               
               Generator Fwk   : GENy 
               Generator Module: GenTool_GenyVcfgNameDecorator
               
               Configuration   : C:\CMSynergy_Projects\Chrysler_C1xx\Chrysler_LWR_EPS_TMS570\Tools\AsrProject\Config\DEM\gmHS_AFS_HS.ecuc.vdsxml
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570PSFC66
               
               Channel "CAN00":
                       Databasefile: 
                       Bussystem:    CAN
                       Manufacturer: Vector
                       Node:         CanStateManagerConfiguration

  Generated by , 2013-07-16  15:38:55
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

#if !defined(__V_CFG_1_H__)
#define __V_CFG_1_H__

#ifndef VGEN_GENY
#define VGEN_GENY
#endif

#ifndef GENy
#define GENy
#endif

#ifndef SUPPLIER_CANBEDDED
#define SUPPLIER_CANBEDDED                   30
#endif

/* -----------------------------------------------------------------------------
    &&&~ General Switches
 ----------------------------------------------------------------------------- */

#ifndef V_OSTYPE_AUTOSAR
#define V_OSTYPE_AUTOSAR
#endif



/* -----------------------------------------------------------------------------
    &&&~ Processor specific
 ----------------------------------------------------------------------------- */

#ifndef C_CPUTYPE_32BIT
#define C_CPUTYPE_32BIT
#endif


#ifndef V_CPUTYPE_BITARRAY_32BIT
#define V_CPUTYPE_BITARRAY_32BIT
#endif


#ifndef C_CPUTYPE_BIGENDIAN
#define C_CPUTYPE_BIGENDIAN
#endif


#ifndef C_CPUTYPE_BITORDER_MSB2LSB
#define C_CPUTYPE_BITORDER_MSB2LSB
#endif


#ifndef V_DISABLE_USE_DUMMY_FUNCTIONS
#define V_DISABLE_USE_DUMMY_FUNCTIONS
#endif


#ifndef V_ENABLE_USE_DUMMY_STATEMENT
#define V_ENABLE_USE_DUMMY_STATEMENT
#endif


#ifndef C_COMP_TI_TMS470_DCAN
#define C_COMP_TI_TMS470_DCAN
#endif


#ifndef V_CPU_TMS470
#define V_CPU_TMS470
#endif

#ifndef V_COMP_TI
#define V_COMP_TI
#endif

#ifndef V_COMP_TI_TMS470
#define V_COMP_TI_TMS470
#endif

#ifndef V_PROCESSOR_TI_TMS470_PSFC66
#define V_PROCESSOR_TI_TMS470_PSFC66
#endif


#ifndef C_PROCESSOR_TI_TMS470_PSFC66
#define C_PROCESSOR_TI_TMS470_PSFC66
#endif




/* -----------------------------------------------------------------------------
    &&&~ Used Modules
 ----------------------------------------------------------------------------- */

#define VGEN_ENABLE_DIAG_ASRDEM


#ifndef kVNumberOfIdentities
#define kVNumberOfIdentities                 1
#endif

#ifndef tVIdentityMsk
#define tVIdentityMsk                        vuint8
#endif

#ifndef kVIdentityEcuMConfiguration
#define kVIdentityEcuMConfiguration          (vuint8) 0
#endif

#ifndef VSetActiveIdentity
#define VSetActiveIdentity(identityLog)
#endif

#ifndef V_ACTIVE_IDENTITY_MSK
#define V_ACTIVE_IDENTITY_MSK                1
#endif

#ifndef V_ACTIVE_IDENTITY_LOG
#define V_ACTIVE_IDENTITY_LOG                0
#endif


/* -----------------------------------------------------------------------------
    &&&~ ExtendedAsrVersionCheck
 ----------------------------------------------------------------------------- */

/* V_SUPPRESS_EXTENDED_VERSION_CHECK */


/* -----------------------------------------------------------------------------
    &&&~ Optimization
 ----------------------------------------------------------------------------- */

#define V_ATOMIC_BIT_ACCESS_IN_BITFIELD      STD_OFF
#define V_ATOMIC_VARIABLE_ACCESS             16




/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 133575247
      #error "The magic number of the generated file <C:\CMSynergy_Projects\Chrysler_C1xx\Chrysler_LWR_EPS_TMS570\SwProject\Source\_GenData\v_cfg_1.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 133575247
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __V_CFG_1_H__ */
