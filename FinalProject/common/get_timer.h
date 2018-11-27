/* 
 * File:   get_timer.h
 * Author: Thomas
 *
 * Created on November 26, 2018, 10:30 PM
 */

#ifndef GET_TIMER_H
#define	GET_TIMER_H

#include "FreeRTOS.h"
#include "timers.h"
#include "queue.h"
#include "system_definitions.h"
#include "../../../common/helper_functions.h"
#include "../../../common/UART_Defines.h"
#include "../../../common/queue_definitions.h"


void Timer_Init();


void Nav_Timer_Cb(TimerHandle_t xTimer);

#endif	/* GET_TIMER_H */

