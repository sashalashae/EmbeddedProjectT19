/* ************************************************************************** */
// Filename:    TxISRQueue.h 
// Date:        10/4/2018
// Author:      Alex Nolan
// Description: Header file for the UART transmit queue
/* ************************************************************************** */

#ifndef TX_ISR_QUEUE
#define TX_ISR_QUEUE

#include "FreeRTOS.h"
#include "queue.h"

void TxISRQueue_Init(uint32_t size);
void TxISRQueue_Send(uint8_t msg);
uint32_t TxISRQueue_Count();
uint8_t TxISRQueue_Receive();

#endif