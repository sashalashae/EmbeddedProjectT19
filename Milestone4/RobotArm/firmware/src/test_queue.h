/*******************************************************************************
 * Filename:    test_queue.h
 * Date:        9/27/2018
 * Description: Header file for command queue to testThread.
 * Author:      Alex Nolan
*******************************************************************************/

#ifndef TEST_QUEUE
#define TEST_QUEUE

#include "system_definitions.h"
#include "FreeRTOS.h"
#include "queue.h"

//enum for the possible message types supported
typedef enum 
{
    ArmAck
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

#endif