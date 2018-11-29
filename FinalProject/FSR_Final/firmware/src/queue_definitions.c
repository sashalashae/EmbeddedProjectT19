/*******************************************************************************
 * Filename:    helper_functions.h
 * Date:        10/9/2018
 * Description: Header file for a generic queue functions for team 19
 * Author:      Alex Nolan
*******************************************************************************/

#include "queue_definitions.h"

void ArmQueue_Init(uint32_t size)
{
    ArmQueue = xQueueCreate(size, sizeof(QueueMsg));
}

void NavQueue_Init(uint32_t size)
{
    NavQueue = xQueueCreate(size, sizeof(QueueMsg));
}

void MotorQueue_Init(uint32_t size)
{
    MotorQueue = xQueueCreate(size, sizeof(QueueMsg));
}

void SensorQueue_Init(uint32_t size)
{
    SensorQueue = xQueueCreate(size, sizeof(QueueMsg));
}

QueueMsg Queue_Receive_FromISR(QueueHandle_t queue)
{
    QueueMsg data;
    BaseType_t xTaskWokenByReceive = pdFALSE;
    xQueueReceiveFromISR(queue, &data, &xTaskWokenByReceive);
    return data;
}

QueueMsg Queue_Receive_FromThread(QueueHandle_t queue)
{
    QueueMsg data;
    xQueueReceive(queue, &data, portMAX_DELAY);
    return data;
}

BaseType_t Queue_Send_FromISR(QueueHandle_t queue, QueueMsg msg, BaseType_t *pxHigherPriorityTaskWoken)
{
    return xQueueSendFromISR(queue, &msg, pxHigherPriorityTaskWoken);
}

BaseType_t Queue_Send_FromThread(QueueHandle_t queue, QueueMsg msg)
{
    return xQueueSend(queue, &msg, 0);
}

BaseType_t Queue_Clear(QueueHandle_t queue)
{
    return xQueueReset(queue);
}

//RxISRQueue
static QueueHandle_t RxISRQueue;
static uint32_t RxISRQueueSize;

void RxISRQueue_Init(uint32_t size)
{
    RxISRQueue = xQueueCreate(size, sizeof(uint8_t));
    RxISRQueueSize = size;
}

void RxISRQueue_Send(uint8_t msg, BaseType_t *pxHigherPriorityTaskWoken)
{
    //sends from ISR
    xQueueSendFromISR(RxISRQueue, &msg, pxHigherPriorityTaskWoken);
}

uint32_t RxISRQueue_Count()
{
    return (RxISRQueueSize - uxQueueSpacesAvailable(RxISRQueue));
}

uint8_t RxISRQueue_Receive()
{
    //Receives in thread
    uint8_t data;
    xQueueReceive(RxISRQueue, &data, portMAX_DELAY);
    return data;
}

//TxTheadQueue
static QueueHandle_t TxThreadQueue;
static uint32_t TxThreadQueueSize;

void TxThreadQueue_Init(uint32_t size)
{
    TxThreadQueue = xQueueCreate(size, sizeof( strStruct ));
    TxThreadQueueSize = size;
}

BaseType_t TxThreadQueue_Send(strStruct string)
{
    //sends from thread
    return xQueueSend(TxThreadQueue, &string, 0);
}

uint32_t TxThreadQueue_Count()
{
    return (TxThreadQueueSize - uxQueueSpacesAvailable(TxThreadQueue));
}

strStruct TxThreadQueue_Receive()
{
    //receives from thread
    strStruct data;
    xQueueReceive(TxThreadQueue, &data, portMAX_DELAY);
    return data;
}

//TxISRQueue
static QueueHandle_t TxISRQueue;
static uint32_t TxISRQueueSize;

void TxISRQueue_Init(uint32_t size)
{
    TxISRQueue = xQueueCreate(size, sizeof(uint8_t));
    TxISRQueueSize = size;
}

void TxISRQueue_Send(uint8_t msg)
{
    //if queue is full enable Tx and wait for spaces
    while(uxQueueSpacesAvailable(TxISRQueue) == 0)
    {
        dbgOutputLoc(TX_ISR_QUEUE_FULL);
        SYS_INT_SourceEnable(INT_SOURCE_USART_1_TRANSMIT);
    }
    //sends from thread to the ISR    
    xQueueSend(TxISRQueue, &msg, 0);
}

BaseType_t TxISRQueue_IsEmpty()
{
    return xQueueIsQueueEmptyFromISR(TxISRQueue);
}

uint8_t TxISRQueue_Receive()
{
    //receive from ISR
    uint8_t data;
    BaseType_t xTaskWokenByReceive = pdFALSE;
    xQueueReceiveFromISR(TxISRQueue, &data, &xTaskWokenByReceive);
    return data;
}

