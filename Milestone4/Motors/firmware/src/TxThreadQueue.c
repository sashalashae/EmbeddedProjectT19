/* ************************************************************************** */
// Filename:    TxThreadQueue.c
// Date:        10/4/2018
// Author:      Alex Nolan
// Description: Implementation for the queue to the UART transmit thread.
/* ************************************************************************** */

#include "TxThreadQueue.h"

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