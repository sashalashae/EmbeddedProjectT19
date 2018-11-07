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
#include "../../../common/debug.h"
#include "../../../common/UART_Defines.h"

void TxThreadQueue_Init(uint32_t size);
BaseType_t TxThreadQueue_Send(strStruct string);
uint32_t TxThreadQueue_Count();
strStruct TxThreadQueue_Receive();

#endif