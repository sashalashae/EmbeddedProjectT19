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

QueueHandle_t ArmQueue;
QueueHandle_t NavQueue;
QueueHandle_t MotorQueue;
QueueHandle_t SensorQueue;

//Define data types for the queue
typedef enum 
{
    UnknownMsg = 0,
    CalibrateMsg,
    CommandMsg,
    AsyncStopMsg,
    TimerMsg,
    AckMsg,
    FsrMsg
}MsgType;

typedef enum 
{
    UnknownThread = 0,
    NavigationThread,
    ArmThread,
    MovementThread,
    SensorThread,
    TxThread,
    RxThread,
    TestThread
}MsgSource;

typedef enum
{
    FORWARD_BOTH,
    REVERSE_BOTH,
    TURN_RIGHT,
    TURN_LEFT,
    STOP
} movement_type_t;

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
void NavQueue_Init(uint32_t size);
void MotorQueue_Init(uint32_t size);
void SensorQueue_Init(uint32_t size);
QueueMsg Queue_Receive_FromISR(QueueHandle_t queue);
QueueMsg Queue_Receive_FromThread(QueueHandle_t queue);
BaseType_t Queue_Send_FromISR(QueueHandle_t queue, QueueMsg msg, BaseType_t *pxHigherPriorityTaskWoken);
BaseType_t Queue_Send_FromThread(QueueHandle_t queue, QueueMsg msg);
BaseType_t Queue_Clear(QueueHandle_t queue);

#endif