/* ************************************************************************** */
// Filename:    debug.h
// Date:        8/27/2018
// Author:      Alex Nolan
// Description: Header file for debug functions
/* ************************************************************************** */

#ifndef _DEBUG_H
#define _DEBUG_H

#include <stdint.h>
#include "system_config.h"
#include "user_drivers.h"

/*
 * Function Headers
 */

void dbgOutputVal(uint32_t outVal);

void dbgUARTVal(unsigned char outVal);

void dbgOutputLoc(uint32_t outVal);

void dbgErrorHandler(uint32_t errorCode); 

/*
 * Defines for code locations
 */

#define DLOC_TIMER_ISR_START            0
#define DLOC_TIMER_ISR_END              1
#define DLOC_ISR_QUEUE_START            2
#define DLOC_ISR_QUEUE_END              3

/*
 * Defines for error codes
 */

#define ERROR_UNKNOWN                   0

#endif