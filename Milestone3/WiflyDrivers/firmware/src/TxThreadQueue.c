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
    TxThreadQueue = xQueueCreate(size, MAX_MESSAGE_SIZE);
    TxThreadQueueSize = size;
}

void TxThreadQueue_Send(char str[])
{
    //sends from thread
    xQueueSend(TxThreadQueue, &str, 0);
}

uint32_t TxThreadQueue_Count()
{
    return (TxThreadQueueSize - uxQueueSpacesAvailable(TxThreadQueue));
}

char* TxThreadQueue_Receive()
{
    //receives from thread
    char *data;
    xQueueReceive(TxThreadQueue, &data, portMAX_DELAY);
    return data;
}