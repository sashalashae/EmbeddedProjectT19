/* 
 * File:   testQueue.h
 * Author: Thomas
 *
 * Created on October 4, 2018, 1:47 AM
 */

#ifndef TESTQUEUE_H
#define	TESTQUEUE_H

#include "system_definitions.h"
#include "FreeRTOS.h"
#include "queue.h"

//enum for the possible message types supported
typedef enum 
{
    NavAck
}TestMessageType;

//struct to hold each message
typedef struct
{
    TestMessageType msgType;
    uint32_t msgValue;
}TestMessage;

//function prototypes
void TestQueue_Initialize(uint32_t size);
TestMessage TestQueue_ReceiveMsg();
BaseType_t TestQueue_SendMsg(TestMessage msg);

#endif	/* TESTQUEUE_H */

