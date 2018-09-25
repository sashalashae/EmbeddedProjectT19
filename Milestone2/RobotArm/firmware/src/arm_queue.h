/*******************************************************************************
 * Filename:    arm_queue.h
 * Date:        9/25/2018
 * Description: Header file for the robot arm command queue
 * Author:      Alex Nolan
*******************************************************************************/

#ifndef ARM_QUEUE

#define ARM_QUEUE

#include "system_definitions.h"

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
    MessageType message;
    uint32_t value;
}ArmMessage;

//function prototypes

#endif