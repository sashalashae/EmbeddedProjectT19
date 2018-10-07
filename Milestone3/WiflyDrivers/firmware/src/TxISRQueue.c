/* ************************************************************************** */
// Filename:    TxISRQueue.c
// Date:        10/4/2018
// Author:      Alex Nolan
// Description: Implementation for the UART transmit queue
/* ************************************************************************** */

#include "TxISRQueue.h"

static QueueHandle_t TxISRQueue;
static uint32_t TxISRQueueSize;

void TxISRQueue_Init(uint32_t size)
{
    TxISRQueue = xQueueCreate(size, sizeof(uint8_t));
    TxISRQueueSize = size;
}

void TxISRQueue_Send(uint8_t msg)
{
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
    dbgOutputLoc(60);
    uint8_t data;
    BaseType_t xTaskWokenByReceive = pdFALSE;
    xQueueReceiveFromISR(TxISRQueue, &data, &xTaskWokenByReceive);
    dbgOutputLoc(61);
    return data;
}