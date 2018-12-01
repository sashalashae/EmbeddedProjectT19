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

#define ERR_TURN_RIGHT 36
#define ERR_TURN_LEFT  31
#define DUTY_CYCLE     50
#define SHORT          20
#define TURN_LEFT_NORMAL     600
#define TURN_RIGHT_NORMAL    600
#define FROM_CORNER         850
#define FROM_INTERMEDIATE_FSR 600
#define INTER_LONG          1400
#define DISPLACED           900

int globPos;
int dumbLeft = 0;
int dumbRight = 0;

void position_tracker(uint16_t FSRs, Position_Data * pdToCpy, int nextPos);

void toNextLoc(Position_Data * pdToCpy, int nextPos, uint32_t symbol, uint16_t FSRs);

void dirTravel(Position_Data * pdToCpy, int nextPos);

void Nav_Timer_Cb(TimerHandle_t xTimer);

void Dumb_Timer_Cb(TimerHandle_t xTimer);

void sendTurnLeft();

void sendTurnRight();

#endif	/* NAVIGATIONLIBRARY_H */

