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
#include "system_definitions.h"

/*
 * Function Headers
 */

void dbgOutputLoc(uint32_t outVal);

void dbgErrorHandler(uint32_t errorCode); 

void dbgInit();

/*
 * Defines for code locations
 */
#define LOC_ENTER_THREAD                1
#define LOC_DRAW_X_START                2
#define LOC_DRAW_X_END                  3
#define LOC_DRAW_O_START                4
#define LOC_DRAW_O_END                  5
#define LOC_SLEEP_START                 6
#define LOC_SLEEP_END                   7
#define LOC_ACK_SEND                    8

/*
 * Defines for error codes
 */

#define ERROR_UNKNOWN                   255
#define ERROR_BOUNDS                    254

#endif