/*******************************************************************************
 * Filename:    arm_queue.c
 * Date:        9/25/2018
 * Description: Implementation for command queue to armThread.
 * Author:      Alex Nolan
*******************************************************************************/

#include "arm_queue.h"

static QueueHandle_t ArmQueue;

void ArmQueue_Initialize(uint32_t size)
{
    ArmQueue = xQueueCreate(size, sizeof(ArmMessage));
}

ArmMessage ArmQueue_ReceiveMsg()
{
    ArmMessage data;
    BaseType_t status = xQueueReceive(ArmQueue, &data, portMAX_DELAY);
    return data;
}

BaseType_t ArmQueue_SendMsg(ArmMessage msg)
{
    return xQueueOverwrite(ArmQueue, &msg);
}

void Arm_SendAck()
{
    
}