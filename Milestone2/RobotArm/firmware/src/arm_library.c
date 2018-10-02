/*******************************************************************************
 * Filename:    arm_library.c
 * Date:        9/17/2018
 * Description: Implementation for all the ArmUno 2.0 Robotic arm control
 *              functions.
 * Author:      Alex Nolan
*******************************************************************************/

#include "arm_library.h"

/*
 * Function: armInit
 * 
 * Description: Initializes output compare modules 1 - 3 to act as PWM outputs.
 * Also initializes timer 2 to run at 50Hz (20ms PWM period).
 * 
 * Returns: void
 */
void armInit()
{
    //Initially disable all output compare modules
    OC1CON = 0;
    OC2CON = 0;
    OC3CON = 0;
    
    //OCxRS / PR2 = Duty Cycle
    //Positive pulse needs to be from 1ms (-90 degrees) to 2m (90 degrees)
    //OCxRS / PR2 = 1.5ms/20ms -> OCxRS = 1875
    OC1RS = 1875;
    OC2RS = 1875;
    OC3RS = 1875;
    
    //Initialize OCxR before enabling compare module
    OC1R = 1875;
    OC2R = 1875;
    OC3R = 1875;
    
    //Set output compare modules to PWM mode (fault pin disabled)
    OC1CON = 6;
    OC2CON = 6;
    OC3CON = 6;
    
    //PR = Timer Source Clock / (PWM Frequency * Prescaler) - 1
    //PR = 80000000Hz / (64 Prescaler * 50 Hz) - 1 = 24999
    PR2 = 24999;
    
    //Set timer 2 prescaler to 64
    T2CON = 0x60;
    
    //Enable timer 2
    T2CONSET = BIT15;
    
    //Enable output compare modules
    OC1CONSET = BIT15;
    OC2CONSET = BIT15;
    OC3CONSET = BIT15;
}

/*
 * Function: armCalibrate
 * 
 * Description: calibrates the arm 
 * 
 * Returns: void
 */
void armCalibrate()
{
    bool pinValue;
    uint16_t calValue;
    CalibrateMode mode = 0;
    ArmMessage calMessage;
    calMessage.msgType = CalibrateArm;
    while(mode < NumCalModes)
    {
        //wait for pin to be low again
        while(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_6));
        //want 1.5ms period for starting pulse
        calValue = 1875;
        pinValue = false;
        while(!pinValue)
        {
            switch(mode)
            {
                case BaseMin:
                case LowerMin:
                case UpperMin:
                    calValue = calValue - 5;
                    break;
                case BaseMax:
                case LowerMax:
                case UpperMax:
                    calValue = calValue + 5;
                    break;
                default:
                    break;
            }
            calMessage.msgValue = (mode << 16) + calValue;
            ArmQueue_SendMsg(calMessage);
            //poll GPIO
            if(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_6))
            {
                pinValue = true;
            }
            sleep(50);
        }
        //switch to next mode
        mode++;
    }
}

/*
 * Function: setArmPosition
 * 
 * Description: Sets the arm to a known, predefined position, at a given speed. 
 * 
 * @param position: A data structure containing the servo angles for each of 
 * the three arm servos. Corresponds to a single known arm position.
 * 
 * Returns: void
 */
void setArmPosition(ArmMovement movement)
{
    bool movementDone, baseDone, lowerDone, upperDone;
    movementDone = false;
    ArmMessage tickMessage;
    //check if each servo motion is needed
    baseDone = (movement.baseSpeed == 0);
    lowerDone = (movement.lowerJointSpeed == 0);
    upperDone = (movement.upperJointSpeed == 0);
    //loop until arm motion is done
    while(!movementDone)
    {
        //update movement for base
        if(!baseDone)
        {
            if(OC1RS < movement.destination.baseServo)
            {
                //current reg value is smaller than desired position
                if((OC1RS + movement.baseSpeed) > movement.destination.baseServo)
                {
                    OC1RS = movement.destination.baseServo;
                    baseDone = true;
                }
                else
                {
                    OC1RS += movement.baseSpeed;
                }
            }
            else if(OC1RS > movement.destination.baseServo)
            {
                //current reg value is greater than desired position
                if((OC1RS - movement.baseSpeed) < movement.destination.baseServo)
                {
                    OC1RS = movement.destination.baseServo;
                    baseDone = true;
                }
                else
                {
                    OC1RS -= movement.baseSpeed;
                }
            }
            else
            {
                baseDone = true;
            }
        }
        //update movement for lower joint
        if(!lowerDone)
        {
            if(OC2RS < movement.destination.lowerJoint)
            {
                //current reg value is smaller than desired position
                if((OC2RS + movement.lowerJointSpeed) > movement.destination.lowerJoint)
                {
                    OC2RS = movement.destination.lowerJoint;
                    lowerDone = true;
                }
                else
                {
                    OC2RS += movement.lowerJointSpeed;
                }
            }
            else if(OC2RS > movement.destination.lowerJoint)
            {
                //current reg value is greater than desired position
                if((OC2RS - movement.lowerJointSpeed) < movement.destination.lowerJoint)
                {
                    OC2RS = movement.destination.lowerJoint;
                    lowerDone = true;
                }
                else
                {
                    OC2RS -= movement.lowerJointSpeed;
                }
            }
            else
            {
                lowerDone = true;
            }
        }
        //update movement for upper joint
        if(!upperDone)
        {
            if(OC3RS < movement.destination.upperJoint)
            {
                //current reg value is smaller than desired position
                if((OC3RS + movement.upperJointSpeed) > movement.destination.upperJoint)
                {
                    OC3RS = movement.destination.upperJoint;
                    upperDone = true;
                }
                else
                {
                    OC3RS += movement.upperJointSpeed;
                }
            }
            else if(OC3RS > movement.destination.upperJoint)
            {
                //current reg value is greater than desired position
                if((OC3RS - movement.upperJointSpeed) < movement.destination.upperJoint)
                {
                    OC3RS = movement.destination.upperJoint;
                    upperDone = true;
                }
                else
                {
                    OC3RS -= movement.upperJointSpeed;
                }
            }
            else
            {
                upperDone = true;
            }
        }
        movementDone = (baseDone && lowerDone && upperDone);
        //Wait until timer tick is received in the queue to procede
        tickMessage.msgType = Null;
        while(tickMessage.msgType != TimerTick)
        {
            tickMessage = ArmQueue_ReceiveMsg();
        }
    }
}

/*
 * Function: setServoAngle
 * 
 * Description: Sets the angle for the servo attached to the specified
 * compare module.
 * 
 * @param cal: The current calibration to use
 * 
 * @param servo: The servo to set to the specified angle
 * 
 * @param servoAngle: The angle to set the servo to
 * 
 * Returns: void
 */
void setServoAngle(ArmCalibration cal, ArmServo servo, int16_t servoAngle)
{
    switch(servo)
    {
        case BaseServo:
            OC1RS = AngleToCompareVal(cal, servo, servoAngle);
            break;
        case LowerServo:
            OC2RS = AngleToCompareVal(cal, servo, servoAngle);
            break;
        case UpperServo:
            OC3RS = AngleToCompareVal(cal, servo, servoAngle);
            break;
        default:
            //Invalid servo
            break;
    }
}

/*
 * Function: setCompareVal
 * 
 * Description: Sets the OCxRS value for a specified compare module, x
 * 
 * @param compareModule: The module number to set the value for (1 - 5)
 * 
 * @param compareValue: The value to set OCxRS to.
 * 
 * Returns: void
 */
void setCompareVal(uint8_t compareModule, uint16_t compareValue)
{
    switch(compareModule)
    {
        case 1:
            OC1RS = compareValue;
            break;
        case 2:
            OC2RS = compareValue;
            break;
        case 3:
            OC3RS = compareValue;
            break;
        case 4:
            OC4RS = compareValue;
        case 5:
            OC5RS = compareValue;
        default:
            //Invalid compare module ID
            break;
    }
}

/*
 * Function: AngleToCompareVal
 * 
 * Description: Converts a desired servo angle to a control value for the 
 * compare module threshold register. Assumes that the min and max values set in
 * cal correspond to -90 degrees and 90 degrees, respectively.
 * 
 * @param servoAngle: The angle to set the servo to. Valid values are in the 
 * range of -90 degrees to 90 degrees.
 * 
 * Returns: a 16 bit unsigned integer containing the value to write to the 
 * OCxRS register to achieve the desired servo angle.
 */
uint16_t AngleToCompareVal(ArmCalibration cal, ArmServo servo, int16_t servoAngle)
{
    uint32_t OCxRSVal;
    uint16_t minVal, maxVal, range;
    switch(servo)
    {
        case BaseServo:
            minVal = cal.BaseMin;
            maxVal = cal.BaseMax;
            break;
        case LowerServo:
            minVal = cal.LowerMin;
            maxVal = cal.LowerMax;
            break;
        case UpperServo:
            minVal = cal.UpperMin;
            maxVal = cal.UpperMax;
            break;
        default:
            minVal = TICKS_PER_180;
            maxVal = 2 * TICKS_PER_180;
            break;
    }
    range = maxVal - minVal;
    if(servoAngle > 90)
    {
        return maxVal;
    }
    if(servoAngle < -90)
    {
        return minVal;
    }
    //zero the angle
    OCxRSVal = servoAngle + 90;
    //scale to ticks
    OCxRSVal = OCxRSVal * range;
    OCxRSVal = OCxRSVal / 180;
    //add minimum offset
    OCxRSVal = OCxRSVal + minVal;
    return (OCxRSVal & 0xFFFF);
}

uint16_t degreesPerSecToMoveSpeed(ArmCalibration cal, ArmServo servo, uint16_t degreesPerSecond)
{
    uint32_t retValue = degreesPerSecond;
    uint16_t ticksPer180;
    switch(servo)
    {
        case BaseServo:
            ticksPer180 = cal.BaseMax - cal.BaseMin;
            break;
        case LowerServo:
            ticksPer180 = cal.LowerMax - cal.LowerMin;
            break;
        case UpperServo:
            ticksPer180 = cal.UpperMax - cal.UpperMin;
            break;
        default:
            ticksPer180 = TICKS_PER_180;
            break;
    }
    //Convert degrees per second to ticks per movement period
    retValue = retValue * ticksPer180;
    retValue = retValue * MOVEMENT_PERIOD_MS;
    retValue = retValue / (180 * 1000);
    //check if it exceeds max/min allowed value
    if(retValue > MAXSPEED)
    {
        retValue = MAXSPEED;
    }
    else if(retValue < 1 && degreesPerSecond)
    {
        retValue = 1;
    }
    return (retValue & 0xFFFF);
}

/*
 * Function: drawX
 * 
 * Description: Draws an "X" in front of the robot arm.
 * 
 * Returns: void
 */
void drawX(ArmCalibration cal)
{
    //Print debug location
    dbgOutputLoc(LOC_DRAW_X_START);
    
    //Starting position for left half of X
    ArmPosition startXLeft;
    startXLeft.baseServo = AngleToCompareVal(cal, BaseServo, -21);
    startXLeft.lowerJoint = AngleToCompareVal(cal, LowerServo, 80);
    startXLeft.upperJoint = AngleToCompareVal(cal, UpperServo, 10);
    
    //position for middle of the left X
    ArmPosition middleXLeft;
    middleXLeft.baseServo = AngleToCompareVal(cal, BaseServo, -21);
    middleXLeft.lowerJoint = AngleToCompareVal(cal, LowerServo, 30);
    middleXLeft.upperJoint = AngleToCompareVal(cal, UpperServo, -13);
    
    //Ending position for left half of X
    ArmPosition endXLeft;
    endXLeft.baseServo = AngleToCompareVal(cal, BaseServo, -21);
    endXLeft.lowerJoint = AngleToCompareVal(cal, LowerServo, -25);
    endXLeft.upperJoint = AngleToCompareVal(cal, UpperServo, -9);
    
    //Starting position for right half of X
    ArmPosition startXRight;
    startXRight.baseServo = AngleToCompareVal(cal, BaseServo, -36);
    startXRight.lowerJoint = AngleToCompareVal(cal, LowerServo, 35);
    startXRight.upperJoint = AngleToCompareVal(cal, UpperServo, -13);
    
    //Ending position for right half of X
    ArmPosition endXRight; 
    endXRight.baseServo = AngleToCompareVal(cal, BaseServo, 0);
    endXRight.lowerJoint = AngleToCompareVal(cal, LowerServo, 35);
    endXRight.upperJoint = AngleToCompareVal(cal, UpperServo, -13);
    
    //Movement profile to reach start X left
    ArmMovement startXLeftDraw;
    startXLeftDraw.destination = startXLeft;
    startXLeftDraw.baseSpeed = degreesPerSecToMoveSpeed(cal, BaseServo, 60);
    startXLeftDraw.lowerJointSpeed = degreesPerSecToMoveSpeed(cal, LowerServo, 15);
    startXLeftDraw.upperJointSpeed = degreesPerSecToMoveSpeed(cal, UpperServo, 15);
    
    //movement profile to draw first half of X left
    ArmMovement middleXLeftDraw;
    middleXLeftDraw.destination = middleXLeft;
    middleXLeftDraw.baseSpeed = 0;
    middleXLeftDraw.lowerJointSpeed = degreesPerSecToMoveSpeed(cal, LowerServo, 25);
    middleXLeftDraw.upperJointSpeed = degreesPerSecToMoveSpeed(cal, UpperServo, 18);
    
    //Movement profile to actually second first half of X left
    ArmMovement finishXLeftDraw;
    finishXLeftDraw.destination = endXLeft;
    finishXLeftDraw.baseSpeed = 0;
    finishXLeftDraw.lowerJointSpeed = degreesPerSecToMoveSpeed(cal, LowerServo, 30);
    finishXLeftDraw.upperJointSpeed = degreesPerSecToMoveSpeed(cal, UpperServo, 12);
    
    //Movement profile to reach start X right
    ArmMovement startXRightDraw;
    startXRightDraw.destination = startXRight;
    startXRightDraw.baseSpeed = degreesPerSecToMoveSpeed(cal, BaseServo, 90);
    startXRightDraw.lowerJointSpeed = degreesPerSecToMoveSpeed(cal, LowerServo, 20);
    startXRightDraw.upperJointSpeed = degreesPerSecToMoveSpeed(cal, UpperServo, 20);
    
    //Movement profile to actually draw X right
    ArmMovement finishXRightDraw;
    finishXRightDraw.destination = endXRight;
    finishXRightDraw.baseSpeed = degreesPerSecToMoveSpeed(cal, BaseServo, 25);
    finishXRightDraw.lowerJointSpeed = 0;
    finishXRightDraw.upperJointSpeed = 0;
    
    //Reset arm to default position before beginning motion path
    resetArm(cal);
    
    //Perform left line draw
    setArmPosition(startXLeftDraw);
    setArmPosition(middleXLeftDraw);
    setArmPosition(finishXLeftDraw);
    
    //Reset to default
    resetArm(cal);
    
    //Perform right line draw
    setArmPosition(startXRightDraw);
    setArmPosition(finishXRightDraw);
    
    //Reset arm after motion profile is complete
    resetArm(cal);
    
    //indicate that X is done
    dbgOutputLoc(LOC_DRAW_X_END);
}

/*
 * Function: drawO
 * 
 * Description: Draws an "O" in front of the robot arm.
 * 
 * Returns: void
 */
void drawO(ArmCalibration cal)
{
    //send the debug location
    dbgOutputLoc(LOC_DRAW_O_START);
    
    //define all arm positions for O
    
    ArmPosition startRight;
    startRight.baseServo = AngleToCompareVal(cal, BaseServo, -35);
    startRight.lowerJoint = AngleToCompareVal(cal, LowerServo, 80);
    startRight.upperJoint = AngleToCompareVal(cal, UpperServo, 10);
    
    ArmPosition startLeft;
    startLeft.baseServo = AngleToCompareVal(cal, BaseServo, 5);
    startLeft.lowerJoint = AngleToCompareVal(cal, LowerServo, 30);
    startLeft.upperJoint = AngleToCompareVal(cal, UpperServo, -12);
    
    ArmPosition endLeft;
    endLeft.baseServo = AngleToCompareVal(cal, BaseServo, 0);
    endLeft.lowerJoint = AngleToCompareVal(cal, LowerServo, 75);
    endLeft.upperJoint = AngleToCompareVal(cal, UpperServo, 8);
    
    ArmPosition startTop;
    startTop.baseServo = AngleToCompareVal(cal, BaseServo, -3);
    startTop.lowerJoint = AngleToCompareVal(cal, LowerServo, 85);
    startTop.upperJoint = AngleToCompareVal(cal, UpperServo, 12);
    
    ArmPosition endTop;
    endTop.baseServo = AngleToCompareVal(cal, BaseServo, -25);
    endTop.lowerJoint = AngleToCompareVal(cal, LowerServo, 85);
    endTop.upperJoint = AngleToCompareVal(cal, UpperServo, 12);
    
    ArmPosition startBottom;
    startBottom.baseServo = AngleToCompareVal(cal, BaseServo, -30);
    startBottom.lowerJoint = AngleToCompareVal(cal, LowerServo, 20);
    startBottom.upperJoint = AngleToCompareVal(cal, UpperServo, -18);
    
    ArmPosition endBottom;
    endBottom.baseServo = AngleToCompareVal(cal, BaseServo, 0);
    endBottom.lowerJoint = AngleToCompareVal(cal, LowerServo, 20);
    endBottom.upperJoint = AngleToCompareVal(cal, UpperServo, -18);
    
    //define all arm movements for O
    
    //lower right hand corner
    ArmMovement beginBottom;
    beginBottom.destination = startBottom;
    beginBottom.baseSpeed = degreesPerSecToMoveSpeed(cal, BaseServo, 60);
    beginBottom.lowerJointSpeed = degreesPerSecToMoveSpeed(cal, LowerServo, 15);
    beginBottom.upperJointSpeed = degreesPerSecToMoveSpeed(cal, UpperServo, 15);
    
    //lower left hand corner
    ArmMovement finishBottom;
    finishBottom.destination = endBottom;
    finishBottom.baseSpeed = degreesPerSecToMoveSpeed(cal, BaseServo, 25);
    finishBottom.lowerJointSpeed = 0;
    finishBottom.upperJointSpeed = 0;
    
    //lower left
    ArmMovement beginLeft;
    beginLeft.destination = startLeft;
    beginLeft.baseSpeed = degreesPerSecToMoveSpeed(cal, BaseServo, 10);
    beginLeft.lowerJointSpeed = degreesPerSecToMoveSpeed(cal, LowerServo, 10);
    beginLeft.upperJointSpeed = degreesPerSecToMoveSpeed(cal, UpperServo, 5);
    
    //upper left
    ArmMovement finishLeft;
    finishLeft.destination = endLeft;
    finishLeft.baseSpeed = degreesPerSecToMoveSpeed(cal, BaseServo, 10);
    finishLeft.lowerJointSpeed = degreesPerSecToMoveSpeed(cal, LowerServo, 30);
    finishLeft.upperJointSpeed = degreesPerSecToMoveSpeed(cal, UpperServo, 12);
    
    //upper left
    ArmMovement beginTop;
    beginTop.destination = startTop;
    beginTop.baseSpeed = degreesPerSecToMoveSpeed(cal, BaseServo, 60);
    beginTop.lowerJointSpeed = degreesPerSecToMoveSpeed(cal, LowerServo, 15);
    beginTop.upperJointSpeed = degreesPerSecToMoveSpeed(cal, UpperServo, 15);
    
    //upper right
    ArmMovement finishTop;
    finishTop.destination = endTop;
    finishTop.baseSpeed = degreesPerSecToMoveSpeed(cal, BaseServo, 25);
    finishTop.lowerJointSpeed = 0;
    finishTop.upperJointSpeed = 0;
    
    //upper right
    ArmMovement beginRight;
    beginRight.destination = startRight;
    beginRight.baseSpeed = degreesPerSecToMoveSpeed(cal, BaseServo, 5);
    beginRight.lowerJointSpeed = degreesPerSecToMoveSpeed(cal, LowerServo, 15);
    beginRight.upperJointSpeed = degreesPerSecToMoveSpeed(cal, UpperServo, 5);
    
    //lower right (back at start)
    ArmMovement finishRight;
    finishRight.destination = startBottom;
    finishRight.baseSpeed = degreesPerSecToMoveSpeed(cal, BaseServo, 5);
    finishRight.lowerJointSpeed = degreesPerSecToMoveSpeed(cal, LowerServo, 30);
    finishRight.upperJointSpeed = degreesPerSecToMoveSpeed(cal, UpperServo, 12);
    
    //Reset arm to default position before beginning motion path
    resetArm(cal);
    
    //draw bottom
    setArmPosition(beginBottom);
    setArmPosition(finishBottom);
    
    //draw left
    setArmPosition(beginLeft);
    setArmPosition(finishLeft);
    
    //draw top
    setArmPosition(beginTop);
    setArmPosition(finishTop);
    
    //draw right
    setArmPosition(beginRight);
    setArmPosition(finishRight);
    
    //Reset arm to default position at end
    resetArm(cal);
 
    //indicate that the O is done
    dbgOutputLoc(LOC_DRAW_O_END);
}

/*
 * Function: resetArm
 * 
 * Description: Returns the arm to its default position.
 * 
 * Returns: void
 */
void resetArm(ArmCalibration cal)
{
    //define position
    ArmPosition defaultPosition;
    defaultPosition.baseServo = AngleToCompareVal(cal, BaseServo, -21);
    defaultPosition.lowerJoint = AngleToCompareVal(cal, LowerServo, 25);
    defaultPosition.upperJoint = AngleToCompareVal(cal, UpperServo, 31);
    
    //define movement
    ArmMovement returnToDefault;
    returnToDefault.destination = defaultPosition;
    returnToDefault.baseSpeed = degreesPerSecToMoveSpeed(cal, BaseServo, 25);
    returnToDefault.lowerJointSpeed = degreesPerSecToMoveSpeed(cal, LowerServo, 30);
    returnToDefault.upperJointSpeed = degreesPerSecToMoveSpeed(cal, UpperServo, 25);
    
    //Move arm to default position
    setArmPosition(returnToDefault);
}