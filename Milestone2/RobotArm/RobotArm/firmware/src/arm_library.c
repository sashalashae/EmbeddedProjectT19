/*******************************************************************************
 * Filename:    arm_library.c
 * Date:        9/17/2018
 * Description: Implementation for all the ArmUno 2.0 Robotic arm control
 *              functions.
 * Author:      Alex Nolan
*******************************************************************************/

#include "arm_library.h"

void initializeArmControl()
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
    
    //Enable output compare modu;es
    OC1CONSET = BIT15;
    OC2CONSET = BIT15;
    OC3CONSET = BIT15;
}

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
        case 4:
            OC4RS = AngleToCompareVal(servoAngle);
            break;
        case 5:
            OC5RS = AngleToCompareVal(servoAngle);
            break;
        default:
            //Invalid compare module ID
            return;
            break;
    }
}

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