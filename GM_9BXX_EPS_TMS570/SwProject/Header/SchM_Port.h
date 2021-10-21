/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : SchM_Port.h
* Module Description: SchM Include
* Product           : Gen II Plus - EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/* Version Control:
 * Date Created:      Mon Jul 29 08:08:40 2013
 * %version:          1 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Mon Jul 29 08:08:40 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 */

#ifndef SCHM_PORT_H
#define SCHM_PORT_H

#include "Os.h"

#define SchM_Enter_Port(ExclusiveAreaNumber)		SuspendAllInterrupts()
#define SchM_Exit_Port(ExclusiveAreaNumber)		ResumeAllInterrupts()

#endif /* SCHM_PORT_H */
