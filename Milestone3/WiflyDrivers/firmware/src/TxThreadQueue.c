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
    TxThreadQueue = xQueueCreate(size, sizeof(cJSON));
    TxThreadQueueSize = size;
}

void TxThreadQueue_Send(cJSON msg)
{
    //sends from thread
    dbgOutputLoc(255);
    xQueueSend(TxThreadQueue, &msg, 0);
}

uint32_t TxThreadQueue_Count()
{
    return (TxThreadQueueSize - uxQueueSpacesAvailable(TxThreadQueue));
}

cJSON TxThreadQueue_Receive()
{
    //receives from thread
    dbgOutputLoc(254);
    cJSON data;
    xQueueReceive(TxThreadQueue, &data, portMAX_DELAY);
    dbgOutputLoc(253);
    return data;
}