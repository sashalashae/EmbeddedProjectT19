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
#include "system_definitions.h"
#include "../../../common/UART_Defines.h"

void TxISRQueue_Init(uint32_t size);
void TxISRQueue_Send(uint8_t msg);
BaseType_t TxISRQueue_IsEmpty();
uint8_t TxISRQueue_Receive();

#endif