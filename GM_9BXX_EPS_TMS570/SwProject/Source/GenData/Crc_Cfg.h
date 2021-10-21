/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2008 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Crc_Cfg.h
 *    Component:  SysService_AsrCrc
 *       Module:  Crc
 *    Generator:  MICROSAR EAD
 *
 *  Description:  Crc module is used to calculate CRC values for data to
 *                ensure data integrity. This is the configuration file
 *                generated by MICROSAR EAD.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Generation Details:
 *  -------------------------------------------------------------------------------------------------------------------
 *  Project:     EPS.ecuc
 *  Generated:   2013-07-16 12:57 pm
 *  Licensee:    Nxtr Automotive Corporation (2502600702)
 
    This file is generated by DaVinci Configurator Pro - DAVINCICFG.EXE V4.0.67.0.
    Do not modify this file, otherwise the software may behave in unexpected way.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Tobias Schmid                 Tsd           Vctr Informatik GmbH
 *  Claudia Mausz                 Mz            Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  03.00.00  2007-11-29  Tsd     -             Updated component to AUTOSAR Release 2.1
 *  04.00.00  2008-05-07  Mz      -             Add Crc8 calculation AUTOSAR Release 3.0
 *  04.00.01  2008-07-10  Mz      ESCAN00028271 No changes here
 *                                ESCAN00028267 No changes here
 *  04.00.02  2009-02-13  Mz      ESCAN00033077 Version inconsistency
 *                                              Removed XML-version numbers
 *********************************************************************************************************************/

/* multiple inclusion protection */
#if !( defined CRC_CFG_H )
#define CRC_CFG_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Version identification */
#define CRC_CFG_MAJOR_VERSION   (4u)
#define CRC_CFG_MINOR_VERSION   (0u)
#define CRC_CFG_PATCH_VERSION   (2u)

/* list of calculation methods for 8bit, 16bit and 32bit CRC.
 * although CRC_XX_HARDWARE is required by the AUTOSAR
 * SWS CRC, it is not supported by this implementation
 * and may not be configured as calculation method!
 */
#define CRC_8_RUNTIME           (0u)
#define CRC_8_TABLE             (1u)
#define CRC_8_HARDWARE          (2u)
#define CRC_16_RUNTIME          (0u)
#define CRC_16_TABLE            (1u)
#define CRC_16_HARDWARE         (2u)
#define CRC_32_RUNTIME          (0u)
#define CRC_32_TABLE            (1u)
#define CRC_32_HARDWARE         (2u)

/* configuration of the calculation method for 16bit and 32bit CRC */
#define CRC_8_MODE             (CRC_8_RUNTIME)
#define CRC_16_MODE             (CRC_16_RUNTIME)
#define CRC_32_MODE             (CRC_32_RUNTIME)

/* configuration switch for (de-)activating the version info API */
#define CRC_VERSION_INFO_API    (STD_ON)

#endif /* CRC_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Msn.h
 *********************************************************************************************************************/
