/*******************************************************************************
 * Filename:    arm_library.h
 * Date:        9/17/2018
 * Description: Header file for a set of control functions for the Arm Uno 2.0
 *              robotic arm.
 * Author:      Alex Nolan
*******************************************************************************/

#ifndef ARM_LIBRARY    /* Guard against multiple inclusion */
#define ARM_LIBRARY

//External Includes
#include "C:\Program Files (x86)\Microchip\xc32\v2.10\pic32mx\include\proc\p32mx795f512l.h"
#include "system_definitions.h"

//Function Prototypes
void initializeArmControl();
uint16_t AngleToCompareVal(int16_t servoAngle);
void setCompareVal(uint8_t compareModule, uint16_t compareValue);
void setServoAngle(uint8_t compareModule, int16_t servoAngle);

//Defines
#define BIT0                (1<<0)
#define BIT1                (1<<1)
#define BIT2                (1<<2)
#define BIT3                (1<<3)
#define BIT4                (1<<4)
#define BIT5                (1<<5)
#define BIT6                (1<<6)
#define BIT7                (1<<7)
#define BIT8                (1<<8)
#define BIT9                (1<<9)
#define BIT10               (1<<10)
#define BIT11               (1<<11)
#define BIT12               (1<<12)
#define BIT13               (1<<13)
#define BIT14               (1<<14)
#define BIT15               (1<<15)

#endif
