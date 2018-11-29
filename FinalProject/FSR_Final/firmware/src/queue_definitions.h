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
#include "UART_Defines.h"

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

//RxISRQueue
void RxISRQueue_Init(uint32_t size);
void RxISRQueue_Send(uint8_t msg, BaseType_t *pxHigherPriorityTaskWoken);
uint32_t RxISRQueue_Count();
uint8_t RxISRQueue_Receive();

//TxISRQueue
void TxISRQueue_Init(uint32_t size);
void TxISRQueue_Send(uint8_t msg);
BaseType_t TxISRQueue_IsEmpty();
uint8_t TxISRQueue_Receive();

//TxThreadQueue
void TxThreadQueue_Init(uint32_t size);
BaseType_t TxThreadQueue_Send(strStruct string);
uint32_t TxThreadQueue_Count();
strStruct TxThreadQueue_Receive();

#endif