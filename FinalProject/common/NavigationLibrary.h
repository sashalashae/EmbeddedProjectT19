/* 
 * File:   NavigationLibrary.h
 * Author: Thomas
 *
 * Created on November 26, 2018, 10:19 PM
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

#define ERR_TURN_RIGHT 40
#define ERR_TURN_LEFT  40
#define DUTY_CYCLE     50
#define SHORT          20
#define TURN_LEFT_NORMAL     595
#define TURN_RIGHT_NORMAL    605

int globPos;

void position_tracker(uint16_t FSRs, Position_Data * pdToCpy, int nextPos);

void toNextLoc(Position_Data * pdToCpy, int nextPos, uint32_t symbol);

void dirTravel(Position_Data * pdToCpy, int nextPos);

void Nav_Timer_Cb(TimerHandle_t xTimer);

void sendTurnLeft();

void sendTurnRight();

#endif	/* NAVIGATIONLIBRARY_H */

