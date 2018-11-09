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

#define DLOC_TIMER_ISR_START                1
#define DLOC_TIMER_ISR_END                  2
#define LOC_TEST_QUEUE_SEND                 3
#define LOC_TEST_QUEUE_ISR_SEND             4
#define LOC_TEST_QUEUE_RECEIVE_WAITING      5
#define LOC_TEST_QUEUE_RECEIVE_FINISHED     6
#define LOC_MOTOR_QUEUE_SEND                7
#define LOC_MOTOR_QUEUE_ISR_SEND            8
#define LOC_MOTOR_QUEUE_RECEIVE_WAITING     9
#define LOC_MOTOR_QUEUE_RECEIVE_FINISHED    10
#define LOC_PID_ADJUST_START                31
#define LOC_PID_ADJUST_END                  32

/*
 * Defines for error codes
 */

#define ERROR_UNKNOWN                   255
#define ERROR_BOUNDS                    254

#endif