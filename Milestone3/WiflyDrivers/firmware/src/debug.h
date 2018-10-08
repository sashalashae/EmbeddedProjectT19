/* ************************************************************************** */
// Filename:    debug.h
// Date:        8/27/2018
// Author:      Alex Nolan
// Description: Header file for debug functions
/* ************************************************************************** */

#ifndef _DEBUG_H
#define _DEBUG_H

#include <stdint.h>
#include "system_config.h"
#include "system_definitions.h"

/*
 * Function Headers
 */

void dbgOutputLoc(uint32_t outVal);

void dbgErrorHandler(uint32_t errorCode); 

void dbgInit();

/*
 * Defines for code locations
 */
#define LOC_SLEEP_START                 255
#define LOC_SLEEP_END                   254

/*
 * Milestone 3 specific loctions
 */

#define LOC_ENTER_UART_ISR
#define LOC_ENTER_UART_TX
#define LOC_EXIT_UART_TX
#define LOC_ENTER_UART_RX
#define LOC_EXIT_UART_RX
#define LOC_EXIT_UART_ISR

#define TX_THREAD_WAITING_FOR_QUEUE
#define TX_THREAD_QUEUE_RECEIVED
#define TX_THREAD_SERIALIZATION_DONE
#define TX_THREAD_BYTE_ENQUEUE_DONE

/*
 * Defines for error codes
 */

#define ERROR_UNKNOWN                   255
#define ERROR_BOUNDS                    254

#endif