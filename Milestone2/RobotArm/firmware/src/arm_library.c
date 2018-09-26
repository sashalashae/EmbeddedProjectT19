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
    //Tick counter for VTaskDelayUntil
    TickType_t LastWakeTime;
    //Set the period (MOVEMENT_PERIOD_MS)
    const TickType_t period = MOVEMENT_PERIOD_MS / portTICK_PERIOD_MS;
    //Set last wake time to function start time
    LastWakeTime = xTaskGetTickCount();
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
        //Sleep function for 100ms
        vTaskDelayUntil(&LastWakeTime, period);
    }
}

/*
 * Function: armCalibrate
 * 
 * Description: Runs a calibration routine for the arm, to find the min and max
 *              PWM widths for each servo.
 * 
 * Returns: void
 */
void armCalibrate()
{
    
}

/*
 * Function: setServoAngle
 * 
 * Description: Sets the angle for the servo attached to the specified
 * compare module.
 * 
 * @param compareModule: The module number to set the value for (1 - 3)
 * 
 * @param servoAngle: The servo angle for the specified module.
 * 
 * Returns: void
 */
void setServoAngle(uint8_t compareModule, int16_t servoAngle)
{
    switch(compareModule)
    {
        case 1:
            OC1RS = AngleToCompareVal(servoAngle);
            break;
        case 2:
            OC2RS = AngleToCompareVal(servoAngle);
            break;
        case 3:
            OC3RS = AngleToCompareVal(servoAngle);
            break;
        default:
            //Invalid compare module ID
            return;
            break;
    }
}

/*
 * Function: AngleToCompareVal
 * 
 * Description: Converts a desired servo angle to a control value for the 
 * compare module threshold register.
 * 
 * @param servoAngle: The angle to set the servo to. Valid values are in the 
 * range of -90 degrees to 90 degrees.
 * 
 * Returns: a 16 bit unsigned integer containing the value to write to the 
 * OCxRS register to achieve the desired servo angle.
 */
uint16_t AngleToCompareVal(int16_t servoAngle)
{
    uint32_t OCxRSVal;
    //-90 degrees corresponds to 1ms positive width
    //For 1ms positive width, OCxRS = 1250
    //90 degrees corresponds to 2ms positive width
    //For 2ms positive width, OCxRS = 2500
    // 1250 - 625 = 625 over 180 degrees
    if(servoAngle > 90)
    {
        return 2 * TICKS_PER_180;
    }
    if(servoAngle < -90)
    {
        return TICKS_PER_180;
    }
    //Add the 90 degree offset (min value of 0, max of 180)
    OCxRSVal = servoAngle + 90;
    //scale from degrees to OCxRS value
    OCxRSVal = OCxRSVal * TICKS_PER_180;
    OCxRSVal = OCxRSVal / 180;
    //Add minimum offset (for -90 degrees)
    OCxRSVal = OCxRSVal + TICKS_PER_180;
    return (OCxRSVal & 0xFFFF);
}

uint16_t degreesPerSecToMoveSpeed(uint16_t degreesPerSecond)
{
    uint32_t retValue = degreesPerSecond;
    //Convert degrees per second to ticks per movement period
    retValue = retValue * TICKS_PER_180;
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
void drawX()
{
    //Print debug location
    dbgOutputLoc(LOC_DRAW_X_START);
    
    //Starting position for left half of X
    ArmPosition startXLeft;
    startXLeft.baseServo = AngleToCompareVal(-40);
    startXLeft.lowerJoint = AngleToCompareVal(80);
    startXLeft.upperJoint = AngleToCompareVal(10);
    
    //position for middle of the left X
    ArmPosition middleXLeft;
    middleXLeft.baseServo = AngleToCompareVal(-40);
    middleXLeft.lowerJoint = AngleToCompareVal(30);
    middleXLeft.upperJoint = AngleToCompareVal(-13);
    
    //Ending position for left half of X
    ArmPosition endXLeft;
    endXLeft.baseServo = AngleToCompareVal(-40);
    endXLeft.lowerJoint = AngleToCompareVal(-25);
    endXLeft.upperJoint = AngleToCompareVal(-9);
    
    //Starting position for right half of X
    ArmPosition startXRight;
    startXRight.baseServo = AngleToCompareVal(-65);
    startXRight.lowerJoint = AngleToCompareVal(35);
    startXRight.upperJoint = AngleToCompareVal(-13);
    
    //Ending position for right half of X
    ArmPosition endXRight; 
    endXRight.baseServo = AngleToCompareVal(-15);
    endXRight.lowerJoint = AngleToCompareVal(35);
    endXRight.upperJoint = AngleToCompareVal(-13);
    
    //Movement profile to reach start X left
    ArmMovement startXLeftDraw;
    startXLeftDraw.destination = startXLeft;
    startXLeftDraw.baseSpeed = degreesPerSecToMoveSpeed(60);
    startXLeftDraw.lowerJointSpeed = degreesPerSecToMoveSpeed(15);
    startXLeftDraw.upperJointSpeed = degreesPerSecToMoveSpeed(15);
    
    //movement profile to draw first half of X left
    ArmMovement middleXLeftDraw;
    middleXLeftDraw.destination = middleXLeft;
    middleXLeftDraw.baseSpeed = 0;
    middleXLeftDraw.lowerJointSpeed = degreesPerSecToMoveSpeed(25);
    middleXLeftDraw.upperJointSpeed = degreesPerSecToMoveSpeed(18);
    
    //Movement profile to actually second first half of X left
    ArmMovement finishXLeftDraw;
    finishXLeftDraw.destination = endXLeft;
    finishXLeftDraw.baseSpeed = 0;
    finishXLeftDraw.lowerJointSpeed = degreesPerSecToMoveSpeed(30);
    finishXLeftDraw.upperJointSpeed = degreesPerSecToMoveSpeed(12);
    
    //Movement profile to reach start X right
    ArmMovement startXRightDraw;
    startXRightDraw.destination = startXRight;
    startXRightDraw.baseSpeed = degreesPerSecToMoveSpeed(90);
    startXRightDraw.lowerJointSpeed = degreesPerSecToMoveSpeed(20);
    startXRightDraw.upperJointSpeed = degreesPerSecToMoveSpeed(20);
    
    //Movement profile to actually draw X right
    ArmMovement finishXRightDraw;
    finishXRightDraw.destination = endXRight;
    finishXRightDraw.baseSpeed = degreesPerSecToMoveSpeed(25);
    finishXRightDraw.lowerJointSpeed = 0;
    finishXRightDraw.upperJointSpeed = 0;
    
    //Reset arm to default position before beginning motion path
    resetArm();
    
    //Perform left line draw
    setArmPosition(startXLeftDraw);
    setArmPosition(middleXLeftDraw);
    setArmPosition(finishXLeftDraw);
    
    //Reset to default
    resetArm();
    
    //Perform right line draw
    setArmPosition(startXRightDraw);
    setArmPosition(finishXRightDraw);
    
    //Reset arm after motion profile is complete
    resetArm();
    
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
void drawO()
{
    //send the debug location
    dbgOutputLoc(LOC_DRAW_O_START);
    
    //define all arm positions for O
    
    ArmPosition startRight;
    startRight.baseServo = AngleToCompareVal(-88);
    startRight.lowerJoint = AngleToCompareVal(80);
    startRight.upperJoint = AngleToCompareVal(10);
    
    ArmPosition startLeft;
    startLeft.baseServo = AngleToCompareVal(-25);
    startLeft.lowerJoint = AngleToCompareVal(28);
    startLeft.upperJoint = AngleToCompareVal(-13);
    
    ArmPosition endLeft;
    endLeft.baseServo = AngleToCompareVal(-28);
    endLeft.lowerJoint = AngleToCompareVal(85);
    endLeft.upperJoint = AngleToCompareVal(12);
    
    ArmPosition startTop;
    startTop.baseServo = AngleToCompareVal(-35);
    startTop.lowerJoint = AngleToCompareVal(85);
    startTop.upperJoint = AngleToCompareVal(12);
    
    ArmPosition endTop;
    endTop.baseServo = AngleToCompareVal(-85);
    endTop.lowerJoint = AngleToCompareVal(85);
    endTop.upperJoint = AngleToCompareVal(12);
    
    ArmPosition startBottom;
    startBottom.baseServo = AngleToCompareVal(-90);
    startBottom.lowerJoint = AngleToCompareVal(25);
    startBottom.upperJoint = AngleToCompareVal(-15);
    
    ArmPosition endBottom;
    endBottom.baseServo = AngleToCompareVal(-30);
    endBottom.lowerJoint = AngleToCompareVal(25);
    endBottom.upperJoint = AngleToCompareVal(-15);
    
    //define all arm movements for O
    
    //lower right hand corner
    ArmMovement beginBottom;
    beginBottom.destination = startBottom;
    beginBottom.baseSpeed = degreesPerSecToMoveSpeed(60);
    beginBottom.lowerJointSpeed = degreesPerSecToMoveSpeed(15);
    beginBottom.upperJointSpeed = degreesPerSecToMoveSpeed(15);
    
    //lower left hand corner
    ArmMovement finishBottom;
    finishBottom.destination = endBottom;
    finishBottom.baseSpeed = degreesPerSecToMoveSpeed(25);
    finishBottom.lowerJointSpeed = 0;
    finishBottom.upperJointSpeed = 0;
    
    //lower left
    ArmMovement beginLeft;
    beginLeft.destination = startLeft;
    beginLeft.baseSpeed = degreesPerSecToMoveSpeed(10);
    beginLeft.lowerJointSpeed = degreesPerSecToMoveSpeed(10);
    beginLeft.upperJointSpeed = degreesPerSecToMoveSpeed(5);
    
    //upper left
    ArmMovement finishLeft;
    finishLeft.destination = endLeft;
    finishLeft.baseSpeed = degreesPerSecToMoveSpeed(10);
    finishLeft.lowerJointSpeed = degreesPerSecToMoveSpeed(30);
    finishLeft.upperJointSpeed = degreesPerSecToMoveSpeed(12);
    
    //upper left
    ArmMovement beginTop;
    beginTop.destination = startTop;
    beginTop.baseSpeed = degreesPerSecToMoveSpeed(60);
    beginTop.lowerJointSpeed = degreesPerSecToMoveSpeed(15);
    beginTop.upperJointSpeed = degreesPerSecToMoveSpeed(15);
    
    //upper right
    ArmMovement finishTop;
    finishTop.destination = endTop;
    finishTop.baseSpeed = degreesPerSecToMoveSpeed(25);
    finishTop.lowerJointSpeed = 0;
    finishTop.upperJointSpeed = 0;
    
    //upper right
    ArmMovement beginRight;
    beginRight.destination = startRight;
    beginRight.baseSpeed = degreesPerSecToMoveSpeed(5);
    beginRight.lowerJointSpeed = degreesPerSecToMoveSpeed(15);
    beginRight.upperJointSpeed = degreesPerSecToMoveSpeed(5);
    
    //lower right (back at start)
    ArmMovement finishRight;
    finishRight.destination = startBottom;
    finishRight.baseSpeed = degreesPerSecToMoveSpeed(5);
    finishRight.lowerJointSpeed = degreesPerSecToMoveSpeed(30);
    finishRight.upperJointSpeed = degreesPerSecToMoveSpeed(12);
    
    //Reset arm to default position before beginning motion path
    resetArm();
    
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
    resetArm();
 
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
void resetArm()
{
    //define position
    ArmPosition defaultPosition;
    defaultPosition.baseServo = AngleToCompareVal(-63);
    defaultPosition.lowerJoint = AngleToCompareVal(28);
    defaultPosition.upperJoint = AngleToCompareVal(27);
    
    //define movement
    ArmMovement returnToDefault;
    returnToDefault.destination = defaultPosition;
    returnToDefault.baseSpeed = degreesPerSecToMoveSpeed(25);
    returnToDefault.lowerJointSpeed = degreesPerSecToMoveSpeed(30);
    returnToDefault.upperJointSpeed = degreesPerSecToMoveSpeed(30);
    
    //Move arm to default position
    setArmPosition(returnToDefault);
}