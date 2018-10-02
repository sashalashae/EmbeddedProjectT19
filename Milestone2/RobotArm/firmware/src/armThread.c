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
    ArmQueue_Initialize(10);
}

void ARMTHREAD_Tasks ( void )
{
    uint16_t calValue;
    CalibrateMode calMode;
    ArmCalibration cal;
    ArmMessage currentMessage;
    
    //Set the default calibration values
    cal.BaseMin = 750;
    cal.LowerMin = 1250;
    cal.UpperMin = 1250;
    cal.BaseMax = 2600;
    cal.LowerMax = 2500;
    cal.UpperMax = 2500;
    
    while(1)
    {
        //receive a command message
        currentMessage = ArmQueue_ReceiveMsg();
        //state machine for the message type
        switch(currentMessage.msgType)
        {
            case DrawX:
                //send control flow to drawX function
                drawX(cal);
                //Acknowledge that operation is done
                Arm_SendAck();
                break;
            case DrawO:
                //send control flow to drawO function
                drawO(cal);
                //Acknowledge that operation is done
                Arm_SendAck();
                break;
            case ResetArm:
                //send control flow to resetArm function
                resetArm(cal);
                //Acknowledge that operation is done
                Arm_SendAck();
                break;
            case SetServoAngle:
                //Set the desired servo to the desired angle
                setServoAngle(cal, (ArmServo) ((currentMessage.msgValue & 0xFFFF0000) >> 16), (currentMessage.msgValue & 0xFFFF));
                //Acknowledge that operation is done
                Arm_SendAck();
                break;
            case TimerTick:
                //Ignore timer ticks in idle state
                break;
            case CalibrateArm:
                //calibrate arm works by updating the calibration values to the most recently received value
                calMode = (CalibrateMode) ((currentMessage.msgValue & 0xFFFF0000) >> 16);
                calValue = (currentMessage.msgValue & 0xFFFF);
                switch(calMode)
                {
                    case BaseMin:
                        cal.BaseMin = calValue;
                        setCompareVal(BASE_SERVO, calValue);
                        break;
                    case BaseMax:
                        cal.BaseMax = calValue;
                        setCompareVal(BASE_SERVO, calValue);
                        break;
                    case LowerMin:
                        cal.LowerMin = calValue;
                        setCompareVal(LOWER_JOINT_SERVO, calValue);
                        break;
                    case LowerMax:
                        cal.LowerMax = calValue;
                        setCompareVal(LOWER_JOINT_SERVO, calValue);
                        break;
                    case UpperMin:
                        cal.UpperMin = calValue;
                        setCompareVal(UPPER_JOINT_SERVO, calValue);
                        break;
                    case UpperMax:
                        cal.UpperMax = calValue;
                        setCompareVal(UPPER_JOINT_SERVO, calValue);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
}