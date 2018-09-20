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
    //Set the period
    const TickType_t period = 100 / portTICK_PERIOD_MS;
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
        return 2500;
    }
    if(servoAngle < -90)
    {
        return 1250;
    }
    //Add the 90 degree offset (min value of 0, max of 180)
    OCxRSVal = servoAngle + 90;
    //scale from degrees to OCxRS value
    OCxRSVal = OCxRSVal * 1250;
    OCxRSVal = OCxRSVal / 180;
    //Add minimum offset (for -90 degrees)
    OCxRSVal = OCxRSVal + 1250;
    return (OCxRSVal & 0xFFFF);
}