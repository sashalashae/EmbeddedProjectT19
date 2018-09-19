/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    appthread.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "appthread.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APPTHREAD_Initialize ( void )

  Remarks:
    See prototype in appthread.h.
 */

void APPTHREAD_Initialize ( void )
{
    //Configure LED pin to act as output
    SYS_PORTS_PinDirectionSelect(PORTS_ID_0, SYS_PORTS_DIRECTION_OUTPUT, PORT_CHANNEL_A, PORTS_BIT_POS_3);
    //Set USER LED off initially
    SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
    
    //Pin 38 as output
    SYS_PORTS_PinDirectionSelect(PORTS_ID_0, SYS_PORTS_DIRECTION_OUTPUT, PORT_CHANNEL_D, PORTS_BIT_POS_10);
}


/******************************************************************************
  Function:
    void APPTHREAD_Tasks ( void )

  Remarks:
    See prototype in appthread.h.
 */

void APPTHREAD_Tasks ( void )
{
    //define positions
    ArmPosition defaultPosition;
    defaultPosition.baseServo = AngleToCompareVal(-63);
    defaultPosition.lowerJoint = AngleToCompareVal(28);
    defaultPosition.upperJoint = AngleToCompareVal(27);
    
    ArmPosition startXLeft, endXLeft;
    startXLeft.baseServo = AngleToCompareVal(-20);
    startXLeft.lowerJoint = AngleToCompareVal(80);
    startXLeft.upperJoint = AngleToCompareVal(30);
    
    endXLeft.baseServo = AngleToCompareVal(-20);
    endXLeft.lowerJoint = AngleToCompareVal(-15);
    endXLeft.upperJoint = AngleToCompareVal(5);
    
    ArmPosition startXRight, endXRight;
    
    //define movements
    ArmMovement returnToDefault;
    returnToDefault.destination = defaultPosition;
    returnToDefault.baseSpeed = 5;
    returnToDefault.lowerJointSpeed = 5;
    returnToDefault.upperJointSpeed = 5;
    initializeArmControl();
    
    ArmMovement startXLeftDraw, finishXLeftDraw;
    startXLeftDraw.destination = startXLeft;
    startXLeftDraw.baseSpeed = MAXSPEED;
    startXLeftDraw.lowerJointSpeed = 3;
    startXLeftDraw.upperJointSpeed = 3;
    
    finishXLeftDraw.destination = endXLeft;
    finishXLeftDraw.baseSpeed = MAXSPEED;
    finishXLeftDraw.lowerJointSpeed = 6;
    finishXLeftDraw.upperJointSpeed = 3;
    
    //Initialize PWM modules
    initializeArmControl();
    
    while(1)
    {
        setArmPosition(returnToDefault);
        setArmPosition(startXLeftDraw);
        setArmPosition(finishXLeftDraw);
    }
}

/*******************************************************************************
 End of File
 */
