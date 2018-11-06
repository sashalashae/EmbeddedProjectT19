/* 
 * File:   navigation_thread.h
 * Author: Thomas
 *
 * Created on September 18, 2018, 8:31 AM
 */

#ifndef NAVIGATION_THREAD_H
#define	NAVIGATION_THREAD_H

#include <stdint.h>
#include "pdStruct.h"
#include "../../../common/debug.h"
#include "../../../common/helper_functions.h"
#include "../../../common/queue_definitions.h"

void position_tracker(uint16_t FSRs, Position_Data * pdToCpy);

void toNextLoc(Position_Data * pdToCpy, int nextPos);

void dirTravel(Position_Data * pdToCpy, int nextPos);

#endif	/* NAVIGATION_THREAD_H */

