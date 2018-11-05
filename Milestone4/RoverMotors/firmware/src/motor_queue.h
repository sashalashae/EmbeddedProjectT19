/* ************************************************************************** */
// Filename:    motor_queue.h
// Date:        9/30/2018
// Author:      Sajan Ronvelwala
// Description: Header file for the motor thread message queue
/* ************************************************************************** */

#ifndef _MOTOR_QUEUE_H
#define _MOTOR_QUEUE_H

#include <stdint.h>

#include "FreeRTOS.h"
#include "queue.h"

#include "debug.h"

typedef enum
{
    MOVEMENT_COMMAND,
    TIMER_TICK,
    ASYNC_STOP
} msg_type_t;

typedef enum
{
    FORWARD_BOTH,
    REVERSE_BOTH,
    TURN_RIGHT,
    TURN_LEFT,
    STOP
} movement_type_t;

//Struct for the motor queue entry
typedef struct
{
    // Message type
    msg_type_t type;
    // Movement type for movement command
    movement_type_t movement;
    // Right encoder value
    uint32_t right;
    // Left encoder value
    uint32_t left;
} MotorQueueData_t;

// Initializes the motor queue with the specified size
void MotorQueue_Initialize(uint32_t size);

// Sends message onto the motor queue
BaseType_t MotorQueue_SendMsg(MotorQueueData_t msg);

// Sends message onto the motor queue from ISR
BaseType_t MotorQueue_SendMsgISR(MotorQueueData_t msg, BaseType_t *pxHigherPriorityTaskWoken);

// Receives message from the motor queue
MotorQueueData_t MotorQueue_ReceiveMsg();

#endif