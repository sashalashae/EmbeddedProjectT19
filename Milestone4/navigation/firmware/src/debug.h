/* 
 * File:   debug.h
 * Author: Thomas
 *
 * Created on September 25, 2018, 4:29 AM
 */

#ifndef DEBUG_H
#define	DEBUG_H

#include <stdint.h>
#include "system_config.h"
#include "system_definitions.h"
#include "navigation_library.h"
#include "pdStruct.h"

void dbgOutputLoc(uint32_t outLoc);
void dbgErrorHandler(uint32_t errorCode); 
void navigation_test_bench();

/*
 * Defines for rover location
 */

#define LOC_BOTTOM_LEFT_CORNER     0
#define LOC_BOTTOM_LEFT            1
#define LOC_TRUE_BOTTOM            2
#define LOC_BOTTOM_RIGHT           3
#define LOC_BOTTOM_RIGHT_CORNER    4
#define LOC_RIGHT_BOTTOM           5
#define LOC_TRUE_RIGHT             6
#define LOC_RIGHT_TOP              7
#define LOC_TOP_RIGHT_CORNER       8
#define LOC_TOP_RIGHT              9
#define LOC_TRUE_TOP               10 // A
#define LOC_TOP_LEFT               11 // B
#define LOC_TOP_LEFT_CORNER        12 // C
#define LOC_LEFT_TOP               13 // D
#define LOC_TRUE_LEFT              14 // E
#define LOC_LEFT_BOTTOM            15 // F
#define LOC_OFF_TRACK              16 // 10
#define LOC_OFF_INSIDE             17 // 11
#define LOC_OFF_OUTSIDE            18 // 12
#define LOC_SLEEP_START            19 // 13
#define LOC_SLEEP_END              20 // 14

/*
 * Defines for error codes
 */

#define ERROR_UNKNOWN               21 // 15
#define ERROR_BOUNDS                22 // 16
#define ERROR_DEFAULT_CASE          23 // 17

// Defines for code locations

#define LOC_QUEUE_SEND_BEGIN       24 // 18
#define LOC_QUEUE_SEND_END         25 // 19
#define LOC_QUEUE_WAITING          26 // 1A
#define LOC_QUEUE_RECEIVED         27 // 1B
#define LOC_APP_TASKS_START        28 // 1C

/*
#define DLOC_BEFORE_TIMER_START     29 // 1D
#define DLOC_BEFORE_TIMER           30 // 1E
*/


#endif	/* DEBUG_H */

