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
    //if queue is full enable Tx and wait for spaces
    while(uxQueueSpacesAvailable(TxISRQueue) == 0)
    {
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