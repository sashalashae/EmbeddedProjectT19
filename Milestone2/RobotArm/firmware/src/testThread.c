/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    testthread.c

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

#include "testthread.h"

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
    void TESTTHREAD_Initialize ( void )

  Remarks:
    See prototype in testthread.h.
 */

void TESTTHREAD_Initialize ( void )
{
    //initialize debug
    dbgInit();
    
    //initialize queue
    TestQueue_Initialize(10);
    
    //configure pin 52 for digital in (for calibrate)
    SYS_PORTS_PinDirectionSelect(PORTS_ID_0, SYS_PORTS_DIRECTION_INPUT, PORT_CHANNEL_G, PORTS_BIT_POS_6);
}


/******************************************************************************
  Function:
    void TESTTHREAD_Tasks ( void )

  Remarks:
    See prototype in testthread.h.
 */

void TESTTHREAD_Tasks ( void )
{
    //Command messages to be sent
    ArmMessage msg;
    
    //angle to set
    int16_t angle;
    
    //Ack message for receiving done notifications
    TestMessage ackMsg;
    
    //set upper and lower joints
    msg.msgType = SetServoAngle;
    angle = 25;
    msg.msgValue = (LowerServo << 16) | (angle & 0xFFFF);
    ArmQueue_SendMsg(msg);
    ackMsg = TestQueue_ReceiveMsg();
    angle = 31;
    msg.msgValue = (UpperServo << 16) | (angle & 0xFFFF);
    ArmQueue_SendMsg(msg);
    ackMsg = TestQueue_ReceiveMsg();
    
    //Test sweeping across motion range on base
    angle = -90;
    while(angle <= 90)
    {
        msg.msgValue = (BaseServo << 16) | (angle & 0xFFFF);
        ArmQueue_SendMsg(msg);
        ackMsg = TestQueue_ReceiveMsg();
        angle += 30;
        sleep(3000);
    }
    
    //Test motion on lower joint
    angle = 0;
    while(angle <= 90)
    {
        msg.msgValue = (LowerServo << 16) | (angle & 0xFFFF);
        ArmQueue_SendMsg(msg);
        ackMsg = TestQueue_ReceiveMsg();
        angle += 15;
        sleep(3000);
    }
    
    //Test motion on upper joint
    angle = -30;
    while(angle <= 15)
    {
        msg.msgValue = (UpperServo << 16) | (angle & 0xFFFF);
        ArmQueue_SendMsg(msg);
        ackMsg = TestQueue_ReceiveMsg();
        angle += 15;
        sleep(3000);
    }

    //demo the reset command
    msg.msgType = ResetArm;
    ArmQueue_SendMsg(msg);
    ackMsg = TestQueue_ReceiveMsg();
    sleep(5000);
    
    //demo drawX
    msg.msgType = DrawX;
    ArmQueue_SendMsg(msg);
    ackMsg = TestQueue_ReceiveMsg();
    sleep(5000);
    
    //demo draw0
    msg.msgType = DrawO;
    ArmQueue_SendMsg(msg);
    ackMsg = TestQueue_ReceiveMsg();
    sleep(5000);
    
    //test calibration routine
    armCalibrate(BaseMin, BaseMax);
    
    //set to -90 degrees
    msg.msgType = SetServoAngle;
    angle = -90;
    msg.msgValue = (BaseServo << 16) | (angle & 0xFFFF);
    ArmQueue_SendMsg(msg);
    ackMsg = TestQueue_ReceiveMsg();
    
    sleep(5000);
    
    //set to 90 degrees
    angle = 90;
    msg.msgValue = (BaseServo << 16) | (angle & 0xFFFF);
    ArmQueue_SendMsg(msg);
    ackMsg = TestQueue_ReceiveMsg();
    //block forever
    ackMsg = TestQueue_ReceiveMsg();
}

/*******************************************************************************
 End of File
 */
