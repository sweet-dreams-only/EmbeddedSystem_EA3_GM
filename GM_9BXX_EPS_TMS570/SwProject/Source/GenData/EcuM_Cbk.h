/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2006-2009 by Vctr Informatik GmbH, all rights reserved
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  EcuM_Cbk.h
 *    Component:  SysService_AsrEcuM
 *       Module:  EcuM
 *    Generator:  EAD
 *
 *  Description:  The ECU State Manager is responsible for
 *                  - initialization of the entire BSW Modules (including OS and RTE
 *                  - configuration of the entire ECU for sleep mode
 *                  - fast and systematic wakeup behavior
 *                  - shutdown of the ECU
 *
 *                To be very independent of different system designs e.g. different Modules to initialize,
 *                external/internal Watchdog, etc., the ECU State Manager provides over a mechanism named "callouts"
 *                a way to adapt the startup and shutdown behavior. The system designer must fill the proper code into
 *                the callouts.
 *********************************************************************************************************************/

/**********************************************************************************************************************
    Bswmd Version : 4.08.00
    Project       : EPS.ecuc
    Generated     : 2013-07-16 01:10 pm
    Licensee      : Nxtr Automotive Corporation (2502600702)
 
    This file is generated by DaVinci Configurator Pro - DAVINCICFG.EXE V4.0.67.0.
    Do not modify this file, otherwise the software may behave in unexpected way.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Christian Marchl              Chm           Vctr Informatik GmbH
 *  Bethina Mausz                 Bmz           Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  03.00.01  2007-09-26  Chm     ESCAN00022372 Quality assurance activities necessary for Component
 *                                              SysService_EcuM
 *  03.00.02  2007-11-21  Chm     ESCAN00023354 No Changes
 *  03.00.03  2007-12-06  Chm     ESCAN00022871 No changes here
 *                                -             Added Revision History
 *  04.00.00  2008-03-01  Chm     ESCAN00024563 No Changes here
 *                                ESCAN00023356 No changes here
 *                                ESCAN00024323 No Changes here
 *                                ESCAN00027863 No Changes here
 *  04.00.01  2008-04-16  Chm     ESCAN00026037 No Changes here
 *                                ESCAN00026537 No Changes here
 *                                ESCAN00026471 No changes here
 *  04.01.00  2008-05-15  Chm     -             Added ASR 2.1 compatibility switches around declaration of functions
 *                                              EcuM_SetWakeupEvent() and EcuM_ValidateWakeupEvent()
 *  04.01.01  2008-06-02  Chm     -             No Changes here
 *  04.01.02  2008-06-06  Chm     ESCAN00027459 Changed compiler abstraction in callout function
 *                                              EcuM_DeterminePbConfiguration()
 *                                ESCAN00027313 No changes here
 *  04.01.03  2008-06-17  Chm     ESCAN00027659 No Changes here
 *  04.02.00  2008-06-30  Chm     ESCAN00027955 No Changes here
 *  04.03.00  2008-07-23  Chm     ESCAN00028372 No Changes here
 *                                ESCAN00028511 No Changes here
 *  04.03.01  2008-08-08  Bmz     -             No changes here
 *  04.03.02  2008-08-13  Bmz     ESCAN00029221 No changes here
 *  04.03.03  2008-09-01  Chm     ESCAN00029621 No changes here
 *                                ESCAN00029300 No changes here
 *  04.03.04  2008-09-24  Chm     ESCAN00027708 No changes here
 *                                ESCAN00029799 No changes here
 *                                ESCAN00029815 No changes here
 *                                ESCAN00029313 No changes here
 *  04.04.00  2008-10-22  Chm     ESCAN00030516 Added PreCompile Variant support
 *  05.00.00  2008-11-28  Chm     ESCAN00031216 No changes here
 *                                ESCAN00031214 Added file EcuM_PrivateCfg.h to component
 *                                ESCAN00030497 No changes here
 *                                ESCAN00030132 No changes here
 *                                ESCAN00031520 Added precompile switch for activation of
 *                                              EcuM_GeneratorCompatibilityError() callout
 *                                ESCAN00031786 No changes here
 *                                ESCAN00031787 No changes here
 *  05.01.00  2009-02-19  Chm     ESCAN00032011 No changes here
 *            2009-02-19  Chm     ESCAN00032502 No changes here
 *            2009-02-19  Chm     ESCAN00033069 No changes here
 *            2009-02-20  Chm     ESCAN00031852 No changes here
 *            2009-02-23  Chm     ESCAN00029165 No changes here
 *            2009-02-24  Chm     ESCAN00031789 No changes here
 *            2009-03-04  Chm     ESCAN00033480 No changes here
 *            2009-03-09  Chm     ESCAN00033718 No changes here
 *            2009-03-16  Chm     ESCAN00033834 No changes here
 *  05.02.00  2009-05-19  Chm     ESCAN00035001 No changes here
 *            2009-07-07  Chm     ESCAN00036192 No changes here
 *  05.03.00  2009-07-13  Chm     ESCAN00036369 No changes here
 *            2009-07-13  Chm     ESCAN00036370 No changes here
 *            2009-07-13  Chm     ESCAN00035287 No changes here
 *            2009-07-15  Chm     ESCAN00036441 No changes here
 *            2009-07-16  Chm     ESCAN00035917 No changes here
 *            2009-07-16  Chm     ESCAN00035535 No changes here
 *            2009-07-17  Chm     ESCAN00036348 No changes here
 *            2009-07-16  Chm     ESCAN00035536 No changes here
 *            2009-07-21  Chm     ESCAN00034788 No changes here
 *  05.03.01  2009-10-22  Chm     ESCAN00037381 No changes here
 *  05.03.02  2009-12-11  Chm     ESCAN00039720 No changes here
 *            2009-12-11  Chm     ESCAN00037612 No changes here
 *            2009-12-14  Chm     ESCAN00039748 No changes here
 *            2009-12-15  Chm     ESCAN00034936 No changes here
 *            2009-12-21  Chm     ESCAN00039882 No changes here
 *            2010-02-19  Chm     ESCAN00040987 No changes here
 *            2010-02-23  Chm     ESCAN00041075 No changes here
 *  05.03.03  2010-04-14  Chm     ESCAN00041836 No changes here
 *            2010-04-19  Chm     ESCAN00041426 No changes here
 *            2010-04-24  Chm     ESCAN00041446 No changes here
 *            2010-04-24  Chm     ESCAN00041827 No changes here
 *  05.03.04  2010-07-29  Bmz     ESCAN00044245 No changes here
 *            2010-07-29  Bmz     ESCAN00044246 No changes here
 *            2010-07-29  Bmz     ESCAN00043065 No changes here
 *  05.04.00  2010-10-18  Bmz     ESCAN00044990 No changes here
 *                                ESCAN00046061 Added new callout: EcuM_McuSetMode
 *  05.06.00  2010-11-26  Bmz     ESCAN00046158 No changes here
 *                                ESCAN00047183 No changes here
 *                                ESCAN00047434 No changes here
 *                                ESCAN00045138 No changes here
 *            2011-01-26  Bmz     Prefix generation for DEM-ERRORS inserted in GenerationS.xml
 *                                G601 updated
 *            2011-02-03  Bmz     ESCAN00048364 No changes here
 *  05.06.01  2011-03-14  Bmz     ESCAN00049201 update version number
 *  05.07.00  2011-04-26  Bmz     ESCAN00049111 No changes here
 *  05.07.01  2011-05-12  Bmz     ESCAN00049989 No changes here
 *********************************************************************************************************************/

#if (!defined ECUM_CBK_H)
# define ECUM_CBK_H

# include "EcuM_Generated_Types.h"
# include "EcuM_Cfg.h"

/*<ECUM_NVM_TYPES_FILE/>*/ #include "Nvm.h"

# define ECUM_CBK_MAJOR_VERSION    (5u)
# define ECUM_CBK_MINOR_VERSION    (7u)
# define ECUM_CBK_PATCH_VERSION    (1u)

# if (!defined ECUM_AR_MAJOR_VERSION)
#  define ECUM_AR_MAJOR_VERSION                                       (1u)
# endif
# if (!defined ECUM_AR_MINOR_VERSION)
#  define ECUM_AR_MINOR_VERSION                                       (2u)
# endif
# if (!defined ECUM_AR_PATCH_VERSION)
#  define ECUM_AR_PATCH_VERSION                                       (0u)
# endif

# define ECUM_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 *  CALLBACK FUNCTIONS
 *********************************************************************************************************************/

# if (STD_ON == ECUM_INCLUDE_NVRAM_MGR)
/*Callback for the NVRAM Manager to indicate JobEnds*/
FUNC(void, ECUM_CODE) EcuM_CB_NfyNvMJobEnd
(
    uint8 ServiceID_u8,
    NvM_RequestResultType JobResult_t
);
# endif

/**********************************************************************************************************************
 *  CALLOUT FUNCTIONS
 *********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitZero(void);

# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_PRECOMPILE)
  FUNC(void, ECUM_CODE) EcuM_AL_DriverInitOne(P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONFIG) ConfigPtr);
  FUNC(void, ECUM_CODE) EcuM_AL_DriverInitTwo(P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONFIG) ConfigPtr);
  FUNC(void, ECUM_CODE) EcuM_AL_DriverInitThree(P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONFIG) ConfigPtr);
  FUNC(void, ECUM_CODE) EcuM_AL_DriverRestart(void);
# endif

FUNC(uint8, ECUM_CODE) EcuM_CheckRamHash(void);

FUNC(void, ECUM_CODE) EcuM_GenerateRamHash(void);

FUNC(void, ECUM_CODE) EcuM_AL_SwitchOff(void);

# if (ECUM_CONFIG_VARIANT == ECUM_VARIANT_POSTBUILD)
  FUNC(EcuM_ConfigRefType, ECUM_CODE) EcuM_DeterminePbConfiguration(void);
# endif

FUNC(void, ECUM_CODE) EcuM_EnableWakeupSources(EcuM_WakeupSourceType wakeupSource);

FUNC(void, ECUM_CODE) EcuM_DisableWakeupSources(EcuM_WakeupSourceType wakeupSource);

FUNC(void, ECUM_CODE) EcuM_StartWakeupSources(EcuM_WakeupSourceType wakeupSource);

FUNC(void, ECUM_CODE) EcuM_StopWakeupSources(EcuM_WakeupSourceType wakeupSource);

FUNC(void, ECUM_CODE) EcuM_CheckWakeup(EcuM_WakeupSourceType wakeupSource);

FUNC(void, ECUM_CODE) EcuM_CheckValidation(EcuM_WakeupSourceType wakeupSource);

# ifndef ECUM_VALIDATE_WAKEUP_EVENT_DECLARATION
#  define ECUM_VALIDATE_WAKEUP_EVENT_DECLARATION
  FUNC(void, ECUM_CODE) EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType WakeupSource_t);
# endif /* ECUM_VALIDATE_WAKEUP_EVENT_DECLARATION */

# ifndef ECUM_SET_WAKEUP_EVENT_DECLARATION
#  define ECUM_SET_WAKEUP_EVENT_DECLARATION
  FUNC(void, ECUM_CODE) EcuM_SetWakeupEvent(EcuM_WakeupSourceType WakeupSource_t);
# endif /* ECUM_SET_WAKEUP_EVENT_DECLARATION */

# if (STD_ON == ECUM_ON_RTESTARTUP_CALLOUT)
FUNC(void, ECUM_CODE) EcuM_OnRTEStartup(void);
# endif

# if (STD_ON == ECUM_ON_ENTER_RUN_CALLOUT)
FUNC(void, ECUM_CODE) EcuM_OnEnterRun(void);
# endif

# if (STD_ON == ECUM_ON_EXIT_RUN_CALLOUT)
FUNC(void, ECUM_CODE) EcuM_OnExitRun(void);
# endif

# if (STD_ON == ECUM_ON_EXIT_POST_RUN_CALLOUT)
FUNC(void, ECUM_CODE) EcuM_OnExitPostRun(void);
# endif

# if (STD_ON == ECUM_ON_PREP_SHUTDOWN_CALLOUT)
FUNC(void, ECUM_CODE) EcuM_OnPrepShutdown(void);
# endif

# if (STD_ON == ECUM_ON_GO_SLEEP_CALLOUT)
FUNC(void, ECUM_CODE) EcuM_OnGoSleep(void);
# endif

# if (STD_ON == ECUM_ON_GO_OFF_ONE_CALLOUT)
FUNC(void, ECUM_CODE) EcuM_OnGoOffOne(void);
# endif

# if (STD_ON == ECUM_ON_GO_OFF_TWO_CALLOUT)
FUNC(void, ECUM_CODE) EcuM_OnGoOffTwo(void);
# endif

# if (STD_ON == ECUM_ON_WAKEUP_REACTION_CALLOUT)
FUNC(EcuM_WakeupReactionType, ECUM_CODE) EcuM_OnWakeupReaction(EcuM_WakeupReactionType wact);
# endif

# if ((!defined (V_SUPPRESS_EXTENDED_VERSION_CHECK)) || (ECUM_GENERATOR_COMPATIBILITY_ERROR == STD_ON))
FUNC(void, ECUM_CODE) EcuM_GeneratorCompatibilityError(uint16 ModuleId, uint8 InstanceId);
# endif

FUNC(void, ECUM_CODE) EcuM_McuSetMode(uint8 mode_u8);

# define ECUM_STOP_SEC_CODE
# include "MemMap.h"

# define ECUM_START_SEC_CODE_SET_BOOT_TARGET
# include "MemMap.h"

FUNC(Std_ReturnType, ECUM_CODE_BOOT_TARGET) EcuM_Appl_SelectBootTarget(EcuM_BootTargetType BootTarget_t);

# define ECUM_STOP_SEC_CODE_SET_BOOT_TARGET
# include "MemMap.h"

# define ECUM_START_SEC_CODE_GET_BOOT_TARGET
# include "MemMap.h"

FUNC(Std_ReturnType, ECUM_CODE_BOOT_TARGET) EcuM_Appl_GetBootTarget
(
  P2VAR(EcuM_BootTargetType, AUTOMATIC, ECUM_VAR_BOOT) BootTarget_pt
);

# define ECUM_STOP_SEC_CODE_GET_BOOT_TARGET
# include "MemMap.h"

#endif /* ECUM_CBK_H */
/**********************************************************************************************************************
 *  END OF FILE: ECUM_CBK.H
 *********************************************************************************************************************/
