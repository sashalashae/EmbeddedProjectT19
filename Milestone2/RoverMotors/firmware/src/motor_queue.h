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
    FORWARD_BOTH,
    REVERSE_BOTH,
    FORWARD_RIGHT,
    FORWARD_LEFT,
    REVERSE_RIGHT,
    REVERSE_LEFT,
    STOP
} movement_type_t;

//Struct for the motor queue entry
typedef struct
{
    // Movement type for the instruction
    movement_type_t movement;
    // Duty cycle of PWMs to complete movement
    uint8_t duty_cycle;
} MotorQueueData_t;

// Initializes the motor queue with the specified size
void MotorQueue_Initialize(uint32_t size);

// Sends message onto the motor queue
BaseType_t MotorQueue_SendMsg(MotorQueueData_t msg);

// Receives message from the motor queue
MotorQueueData_t MotorQueue_ReceiveMsg();

#endif