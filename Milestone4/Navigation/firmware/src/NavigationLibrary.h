/* 
 * File:   NavigationLibrary.h
 * Author: Thomas
 *
 * Created on November 6, 2018, 11:54 PM
 */

#ifndef NAVIGATIONLIBRARY_H
#define	NAVIGATIONLIBRARY_H

#include <stdint.h>
#include "pdStruct.h"
#include "../../../common/debug.h"
#include "../../../common/helper_functions.h"
#include "../../../common/queue_definitions.h"
#include "../../../common/UART_Defines.h"
#include "timers.h"


void position_tracker(uint16_t FSRs, Position_Data * pdToCpy, int nextPos);

void toNextLoc(Position_Data * pdToCpy, int nextPos, uint32_t symbol);

void dirTravel(Position_Data * pdToCpy, int nextPos);

void Nav_Timer_Cb(TimerHandle_t xTimer);

#endif	/* NAVIGATIONLIBRARY_H */

