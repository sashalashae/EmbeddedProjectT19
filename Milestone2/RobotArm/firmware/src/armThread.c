/*******************************************************************************
 * Filename:    armThread.c
 * Date:        9/25/2018
 * Description: Thread which handles commands sent to the robot arm.
 * Author:      Alex Nolan
*******************************************************************************/

#include "armThread.h"

void ARMTHREAD_Initialize ( void )
{
    //Initialize arm control
    armInit();
    //Initialize command queue
    ArmQueue_Initialize(1);
}

void ARMTHREAD_Tasks ( void )
{
    ArmMessage currentMessage;
    while(1)
    {
        //receive a command message
        currentMessage = ArmQueue_ReceiveMsg();
        //state machine for the message type
        switch(currentMessage.msgType)
        {
            case DrawX:
                drawX();
                Arm_SendAck();
                break;
            case DrawO:
                drawO();
                Arm_SendAck();
                break;
            case ResetArm:
                resetArm();
                Arm_SendAck();
                break;
            case SetServoAngle:
                setServoAngle((currentMessage.msgValue & 0xF00) >> 16, (currentMessage.msgValue & 0xFF));
                Arm_SendAck();
                break;
            case TimerTick:
                break;
            case CalibrateArm:
                armCalibrate();
                Arm_SendAck();
                break;
            default:
                break;
        }
    }
}