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
#include "UART_Defines.h"

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
 * Milestone 3 specific locations
 */

//ISR
#define LOC_ENTER_UART_ISR          1
#define LOC_ENTER_UART_TX           2
#define LOC_EXIT_UART_TX            3
#define LOC_ENTER_UART_RX           4
#define LOC_EXIT_UART_RX            5
#define LOC_EXIT_UART_ISR           6
#define LOC_ENTER_UART_ERROR        12
#define LOC_EXIT_UART_ERROR         13

//Tx Thread
#define TX_THREAD_WAITING_FOR_QUEUE     7
#define TX_THREAD_QUEUE_RECEIVED        8
#define TX_THREAD_SERIALIZATION_DONE    9
#define TX_THREAD_BYTE_ENQUEUE_DONE     10

//Queue related
#define TX_ISR_QUEUE_FULL               11

#define DLOC_TIMER_ISR_START                21
#define DLOC_TIMER_ISR_END                  22
#define LOC_TEST_QUEUE_SEND                 23
#define LOC_TEST_QUEUE_ISR_SEND             24
#define LOC_TEST_QUEUE_RECEIVE_WAITING      25
#define LOC_TEST_QUEUE_RECEIVE_FINISHED     26
#define LOC_MOTOR_QUEUE_SEND                27
#define LOC_MOTOR_QUEUE_ISR_SEND            28
#define LOC_MOTOR_QUEUE_RECEIVE_WAITING     29
#define LOC_MOTOR_QUEUE_RECEIVE_FINISHED    30
#define LOC_PID_ADJUST_START                31
#define LOC_PID_ADJUST_END                  32

#endif