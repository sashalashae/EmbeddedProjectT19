/* ************************************************************************** */
// Filename:    RxISRQueue.h 
// Date:        10/4/2018 
// Author:      Alex Nolan
// Description: Header file for the UART receive queue
/* ************************************************************************** */

#ifndef RX_ISR_QUEUE
#define RX_ISR_QUEUE

#include "FreeRTOS.h"
#include "queue.h"
#include "UART_Defines.h"

void RxISRQueue_Init(uint32_t size);
void RxISRQueue_Send(uint8_t msg, BaseType_t *pxHigherPriorityTaskWoken);
uint32_t RxISRQueue_Count();
uint8_t RxISRQueue_Receive();

#endif