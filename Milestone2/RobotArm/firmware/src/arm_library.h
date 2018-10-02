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
#include "debug.h"
#include "helper_functions.h"

//Maximum movement speed for servo
#define MAXSPEED            (1250)

//Period of one MS in movement function
#define MOVEMENT_PERIOD_MS  (60)

//Number of compare register ticks per 180 degrees
#define TICKS_PER_180       (1250)

//defines for servo output compare module mappings
#define BASE_SERVO          1
#define LOWER_JOINT_SERVO   2
#define UPPER_JOINT_SERVO   3

//Bit defines
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

//Data structure which stores servo angles for a given arm position
typedef struct
{
    //The compare register value for the base servo
    int16_t baseServo;
    //The compare register value for the lower joint servo
    int16_t lowerJoint;
    //The compare register value for the upper join servo
    int16_t upperJoint;
}ArmPosition;

typedef struct
{
    //Destination to move to
    ArmPosition destination;
    //Base Speed (OC1RS ticks per 40ms) 1 degree = 6.94 ticks
    uint16_t baseSpeed;
    //Lower joint Speed (OC2RS ticks per 40ms) 1 degree = 6.94 ticks
    uint16_t lowerJointSpeed;
    //Upper joint Speed (OC2RS ticks per 40ms) 1 degree = 6.94 ticks
    uint16_t upperJointSpeed;
}ArmMovement;

typedef struct
{
    uint16_t BaseMin;
    uint16_t BaseMax;
    uint16_t LowerMin;
    uint16_t LowerMax;
    uint16_t UpperMin;
    uint16_t UpperMax;
}ArmCalibration;

typedef enum
{
    BaseMin = 0,
    BaseMax,
    LowerMin,
    LowerMax,
    UpperMin,
    UpperMax,
    NumCalModes
}CalibrateMode;

typedef enum
{
    BaseServo = BASE_SERVO,
    LowerServo = LOWER_JOINT_SERVO,
    UpperServo = UPPER_JOINT_SERVO
}ArmServo;

//Configuration Functions
void armInit();

//Calibration function
void armCalibrate();

//Helper Functions
uint16_t AngleToCompareVal(ArmCalibration cal, ArmServo servo, int16_t servoAngle);
uint16_t degreesPerSecToMoveSpeed(ArmCalibration cal, ArmServo servo, uint16_t degreesPerSecond);

//Lower Level Functions
void setCompareVal(uint8_t compareModule, uint16_t compareValue);
void setServoAngle(ArmCalibration cal, ArmServo servo, int16_t servoAngle);
void setArmPosition(ArmMovement movement);

//Higher Level action functions
void drawX(ArmCalibration cal);
void drawO(ArmCalibration cal);
void resetArm(ArmCalibration cal);

#endif
