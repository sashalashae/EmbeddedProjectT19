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

#define TX_ISR_QUEUE_FULL               11
#define LOC_ADC_START                  15
#define LOC_ADC_READ                   16
#define LOC_CONFIG_START               17
#define LOC_CONFIG_END                 18
#define LOC_ADC_END                    19
#define LOC_ADC_ISR_START              20
#define LOC_ADC_ISR_END                21


//Queue related
#define TX_ISR_QUEUE_FULL               11

/*
 * Robot Arm Specific Locations
 */

#define LOC_ENTER_THREAD                1
#define LOC_DRAW_X_START                2
#define LOC_DRAW_X_END                  3
#define LOC_DRAW_O_START                4
#define LOC_DRAW_O_END                  5
#define LOC_ACK_SEND                    8

#define DLOC_TIMER_ISR_START                31
#define DLOC_TIMER_ISR_END                  32
#define LOC_TEST_QUEUE_SEND                 33
#define LOC_TEST_QUEUE_ISR_SEND             34
#define LOC_TEST_QUEUE_RECEIVE_WAITING      35
#define LOC_TEST_QUEUE_RECEIVE_FINISHED     36
#define LOC_MOTOR_QUEUE_SEND                37
#define LOC_MOTOR_QUEUE_ISR_SEND            38
#define LOC_MOTOR_QUEUE_RECEIVE_WAITING     39
#define LOC_MOTOR_QUEUE_RECEIVE_FINISHED    40

/*
 * Navigation Specific Locations
 */

#define LOC_BOTTOM_LEFT_CORNER     50
#define LOC_BOTTOM_LEFT            51
#define LOC_TRUE_BOTTOM            52
#define LOC_BOTTOM_RIGHT           53
#define LOC_BOTTOM_RIGHT_CORNER    54
#define LOC_RIGHT_BOTTOM           55
#define LOC_TRUE_RIGHT             56
#define LOC_RIGHT_TOP              57
#define LOC_TOP_RIGHT_CORNER       58
#define LOC_TOP_RIGHT              59
#define LOC_TRUE_TOP               60 
#define LOC_TOP_LEFT               61 
#define LOC_TOP_LEFT_CORNER        62 
#define LOC_LEFT_TOP               63 
#define LOC_TRUE_LEFT              64 
#define LOC_LEFT_BOTTOM            65 
#define LOC_OFF_TRACK              66
#define LOC_OFF_INSIDE             67
#define LOC_OFF_OUTSIDE            68
#define ERROR_DEFAULT_CASE         69
#define LOC_QUEUE_SEND_BEGIN       70 
#define LOC_QUEUE_SEND_END         71 
#define LOC_QUEUE_WAITING          72 
#define LOC_QUEUE_RECEIVED         73 
#define LOC_APP_TASKS_START        74 


#endif