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
#include "user_drivers.h"

/*
 * Function Headers
 */

void dbgOutputVal(uint32_t outVal);

void dbgUARTVal(unsigned char outVal);

void dbgOutputLoc(uint32_t outVal);

void dbgErrorHandler(uint32_t errorCode); 

/*
 * Defines for code locations
 */

#define DLOC_TIMER_ISR_START            0
#define DLOC_TIMER_ISR_END              1
#define DLOC_ISR_QUEUE_SEND             2
#define DLOC_QUEUE_RECEIVE_WAITING      3
#define DLOC_QUEUE_RECEIVE_FINISHED     4
#define DLOC_ADC_START                  5
#define DLOC_ADC_READ                   6
#define DLOC_UART_WRITE_START           7
#define DLOC_UART_WRITE_END             8
#define DLOC_GPIO_WRITE_START           9
#define DLOC_GPIO_WRITE_END             10

/*
 * Defines for error codes
 */

#define ERROR_UNKNOWN                   0
#define ERROR_BOUNDS                    1


#endif