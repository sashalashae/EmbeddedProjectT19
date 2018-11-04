/*******************************************************************************
 * Filename:    armThread.c
 * Date:        9/25/2018
 * Description: Thread which handles commands sent to the robot arm.
 * Author:      Alex Nolan
*******************************************************************************/

#include "armThread.h"

void ARMTHREAD_Initialize ( void )
{
    //initialize queue
    ArmQueue_Init(10);
    //initialize the PWM
    initPWM();
}

void ARMTHREAD_Tasks ( void )
{   
    //Initialize arm timer
    initArmTimer();
    
    //variable declaration
    uint16_t calValue;
    CalibrateMode calMode;
    ArmCalibration cal;
    QueueMsg currentMessage;
    
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
        currentMessage = Queue_Receive_FromThread(ArmQueue);
        //state machine for the message type
        switch(currentMessage.type)
        {
            case CommandMsg:
                //perform actions depending on the ArmCommand (in val0)
                switch(currentMessage.val0)
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
                    //Set the desired servo to the desired angle (val1 is servo, val2 is angle)
                    setServoAngle(cal, (ArmServo) currentMessage.val1, currentMessage.val2);
                    //Acknowledge that operation is done
                    Arm_SendAck();
                    break;
                case Calibrate:
                    //calibrate arm works by updating the calibration values to the most recently received value
                    calMode = (CalibrateMode) currentMessage.val1;
                    calValue = currentMessage.val2;
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
                } // end switch(currentMessage.val0)
                break;
            default:
                //do nothing right now
                break;
        }//end switch(currentMessage.type)
    } //end while(1)
}//end ARMTHREAD_TASKS