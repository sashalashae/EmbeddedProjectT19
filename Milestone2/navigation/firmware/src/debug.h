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
#include "navigation_thread.h"
#include "pdStruct.h"

void dbgOutputLoc(uint32_t outLoc);
void dbgErrorHandler(uint32_t errorCode); 
void navigation_test_bench(Position_Data pd);

/*
 * Defines for code locations
 */

#define DLOC_BOTTOM_LEFT_CORNER     0
#define DLOC_BOTTOM_LEFT            1
#define DLOC_TRUE_BOTTOM            2
#define DLOC_BOTTOM_RIGHT           3
#define DLOC_BOTTOM_RIGHT_CORNER    4
#define DLOC_RIGHT_BOTTOM           5
#define DLOC_TRUE_RIGHT             6
#define DLOC_RIGHT_TOP              7
#define DLOC_TOP_RIGHT_CORNER       8
#define DLOC_TOP_RIGHT              9
#define DLOC_TRUE_TOP               10
#define DLOC_TOP_LEFT               11
#define DLOC_TOP_LEFT_CORNER        12
#define DLOC_LEFT_TOP               13
#define DLOC_TRUE_LEFT              14
#define DLOC_LEFT_BOTTOM            15
#define DLOC_OFF_TRACK              16
#define DLOC_SLEEP_START            17
#define DLOC_SLEEP_END              18

/*
 * Defines for error codes
 */

#define ERROR_UNKNOWN               19
#define ERROR_BOUNDS                20
#define ERROR_DEFAULT_CASE          21



#endif	/* DEBUG_H */

