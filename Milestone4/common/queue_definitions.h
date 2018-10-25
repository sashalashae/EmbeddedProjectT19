/*******************************************************************************
 * Filename:    helper_functions.h
 * Date:        10/9/2018
 * Description: Header file for a generic queue functions for team 19
 * Author:      Alex Nolan
*******************************************************************************/

#ifndef QUEUE_DEFINITIONS
#define QUEUE_DEFINITIONS

#include "FreeRTOS.h"
#include "queue.h"
#include "system_definitions.h"

//Define data types for the queue
typedef enum 
{
    UnknownMsg = 0
}MsgType;

typedef enum 
{
    UnknownThread = 0,
    NavigationThread,
    ArmThread,
    MovementThread,
    TxThread,
    RxThread
}MsgSource;

//Add definition for a generic queue message structure
typedef struct
{
    //the message type
    MsgType type;
    //which thread the message originated from
    MsgSource source;
    //optional values associated with the message
    uint32_t val0;
    uint32_t val1;
    uint32_t val2;
    uint32_t val3;
}QueueMsg;

//functions to interface with queues
void ArmQueue_Init(uint32_t size);
QueueMsg Queue_Receive_FromISR(QueueHandle_t queue);
QueueMsg Queue_Receive_FromThread(QueueHandle_t queue);
void Queue_Send_FromISR(QueueHandle_t queue, QueueMsg msg);
void Queue_Send_FromThread(QueueHandle_t queue, QueueMsg msg);
bool Queue_IsEmpty(QueueHandle_t queue);

#endif