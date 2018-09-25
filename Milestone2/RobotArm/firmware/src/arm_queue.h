/*******************************************************************************
 * Filename:    arm_queue.h
 * Date:        9/25/2018
 * Description: Header file for the robot arm command queue
 * Author:      Alex Nolan
*******************************************************************************/

#ifndef ARM_QUEUE

#define ARM_QUEUE

#include "system_definitions.h"
#include "FreeRTOS.h"
#include "queue.h"

//type definitions

typedef enum 
{
    TimerTick = 0,
    ResetArm,
    DrawX,
    Draw0,
    SetServoAngle,
    CalibrateArm
            
}MessageType;

typedef struct
{
    MessageType msgType;
    uint32_t msgValue;
}ArmMessage;

//function prototypes
void ArmQueue_Initialize(uint32_t size);
ArmMessage ArmQueue_ReceiveMsg();
BaseType_t ArmQueue_SendMsg();

#endif
        