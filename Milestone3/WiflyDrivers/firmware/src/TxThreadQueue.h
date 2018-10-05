/* ************************************************************************** */
// Filename:    TxTheadQueue.h 
// Date:        10/4/2018
// Author:      Alex Nolan
// Description: Header file for the queue to the UART transmit thread.
/* ************************************************************************** */

#ifndef TX_THREAD_QUEUE
#define TX_THREAD_QUEUE

#include "FreeRTOS.h"
#include "queue.h"
#include "cJSON.h"

void TxThreadQueue_Init(uint32_t size);
void TxThreadQueue_Send(cJSON msg);
uint32_t TxThreadQueue_Count();
cJSON TxThreadQueue_Receive();

#endif