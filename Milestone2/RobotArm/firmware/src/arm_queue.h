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
#include "arm_library.h"
#include "test_queue.h"
#include "timers.h"

//type definitions

//enum for the possible message types supported
typedef enum 
{
    Null = 0,
    TimerTick,
    ResetArm,
    DrawX,
    DrawO,
    SetServoAngle,
    CalibrateArm
}MessageType;

//struct to hold each message
typedef struct
{
    MessageType msgType;
    uint32_t msgValue;
}ArmMessage;

//function prototypes
void ArmQueue_Initialize(uint32_t size);
ArmMessage ArmQueue_ReceiveMsg();
BaseType_t ArmQueue_SendMsg(ArmMessage msg);
void Arm_SendAck();
void Arm_Timer_Cb(TimerHandle_t xTimer);

#endif

        