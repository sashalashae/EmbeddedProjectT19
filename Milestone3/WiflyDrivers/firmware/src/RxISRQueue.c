/* ************************************************************************** */
// Filename:    RxISRQueue.c 
// Date:        10/4/2018
// Author:      Alex Nolan
// Description: Implementation for the UART receive queue
/* ************************************************************************** */

#include "RxISRQueue.h"

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