/* ************************************************************************** */
// Filename:    test_queue.h
// Date:        9/30/2018
// Author:      Sajan Ronvelwala
// Description: Header file for the test thread message queue
/* ************************************************************************** */

#ifndef _TEST_QUEUE_H
#define _TEST_QUEUE_H

#include <stdint.h>

#include "FreeRTOS.h"
#include "queue.h"

#include "debug.h"

//Struct for the test queue entry
typedef struct{
    // acknowledge
    bool ack;
} TestQueueData_t;

// Initializes the test queue with the specified size
void TestQueue_Initialize(uint32_t size);

// Sends message into the test queue
BaseType_t TestQueue_SendMsg(TestQueueData_t msg);

// Sends message into the test queue from ISR
BaseType_t TestQueue_SendMsgISR(TestQueueData_t msg, BaseType_t *pxHigherPriorityTaskWoken);

// Receives message from the test queue
TestQueueData_t TestQueue_ReceiveMsg();

#endif