/* 
 * File:   navQueue.h
 * Author: Thomas
 *
 * Created on October 2, 2018, 10:40 AM
 */

#ifndef NAVQUEUE_H
#define	NAVQUEUE_H

#include "system_definitions.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "timers.h"
#include "debug.h"
#include "pdStruct.h"

typedef struct
{
    uint16_t FSRs;
    Direction dir;
} testData;

void NavQueue_Initialize(uint32_t size);
testData NavQueue_ReceiveMsg();
BaseType_t NavQueue_SendMsg(testData msg);
//BaseType_t RetQueue_SendIndex(uint16_t msg);
//uint16_t RetQueue_ReceiveMsg();
void Nav_Timer_Cb(TimerHandle_t xTimer);


#endif	/* NAVQUEUE_H */

