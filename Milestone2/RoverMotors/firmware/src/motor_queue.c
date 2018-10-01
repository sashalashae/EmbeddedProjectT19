/* ************************************************************************** */
// Filename:    motor_queue.c 
// Date:        9/30/2018 
// Author:      Sajan Ronvelwala
// Description: Implementation for the motor thread queue
/* ************************************************************************** */

#include "motor_queue.h"

static QueueHandle_t MotorQueue;

void MotorQueue_Initialize(uint32_t size)
{
    MotorQueue = xQueueCreate(size, sizeof(MotorQueueData_t));
}

BaseType_t MotorQueue_SendMsg(MotorQueueData_t msg)
{
    BaseType_t status = xQueueSend(MotorQueue, &msg, 0);
    dbgOutputLoc(LOC_MOTOR_QUEUE_SEND);
    return status;
}

MotorQueueData_t MotorQueue_ReceiveMsg()
{
    MotorQueueData_t data;
    dbgOutputLoc(LOC_MOTOR_QUEUE_RECEIVE_WAITING);
    BaseType_t status = xQueueReceive(MotorQueue, &data, portMAX_DELAY);
    dbgOutputLoc(LOC_MOTOR_QUEUE_RECEIVE_FINISHED);
    return data;
}