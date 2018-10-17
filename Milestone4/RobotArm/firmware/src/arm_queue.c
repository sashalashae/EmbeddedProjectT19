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
    TimerHandle_t tickTimer;
    ArmQueue = xQueueCreate(size, sizeof(ArmMessage));
    //Start arm timer (feeds into queue)
    tickTimer = xTimerCreate("Timer", pdMS_TO_TICKS(MOVEMENT_PERIOD_MS), pdTRUE, ( void * ) 0, Arm_Timer_Cb);
    xTimerStart(tickTimer, 0);
}

void Arm_Timer_Cb(TimerHandle_t xTimer)
{
    ArmMessage timerTick;
    timerTick.msgType = TimerTick;
    timerTick.msgValue = 0;
    ArmQueue_SendMsg(timerTick);
}

ArmMessage ArmQueue_ReceiveMsg()
{
    ArmMessage data;
    BaseType_t status = xQueueReceive(ArmQueue, &data, portMAX_DELAY);
    return data;
}

BaseType_t ArmQueue_SendMsg(ArmMessage msg)
{
    return xQueueSend(ArmQueue, &msg, 0);
}

void Arm_SendAck()
{
    TestMessage msg;
    msg.msgType = ArmAck;
    msg.msgValue = 0;
    TestQueue_SendMsg(msg);
}