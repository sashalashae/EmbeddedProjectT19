/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    test_thread.c

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

#include "test_thread.h"

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void TEST_THREAD_Initialize ( void )

  Remarks:
    See prototype in test_thread.h.
 */

void TEST_THREAD_Initialize ( void )
{
    // initialize debug
    dbgInit();
    
    // initialize this thread's queue
    TestQueue_Initialize(1);
}


/******************************************************************************
  Function:
    void TEST_THREAD_Tasks ( void )

  Remarks:
    See prototype in test_thread.h.
 */

void TEST_THREAD_Tasks ( void )
{
    //Start the timer
    DRV_TMR0_Start();
    DRV_TMR1_Start();
    DRV_TMR2_Start();
    //uint32_t target_value;
    test_state_t state = INIT;
    test_state_t prev_state;
    while(true)
    {
        MotorQueueData_t msg;
        TestQueueData_t encoder_data = TestQueue_ReceiveMsg();
        uint32_t left = encoder_data.left;
        uint32_t right = encoder_data.right;
        switch(state)
        {
            case INIT:
                prev_state = state;
                state = TEST1;
                break;
            case TEST1:
                if(prev_state != TEST1)
                {
                    msg.movement = FORWARD_BOTH;
                    msg.duty_cycle = 20;
                    MotorQueue_SendMsg(msg);
                    prev_state = state;
                }
                else if(right >= SQUARE_LENGTH_TRANSITION || left >= SQUARE_LENGTH_TRANSITION) 
                {
                    state = TEST2;
                }
                break;
            case TEST2:
                if(prev_state != TEST2)
                {
                    msg.movement = FORWARD_RIGHT;
                    msg.duty_cycle = 50;
                    MotorQueue_SendMsg(msg);
                    prev_state = state;
                }
                else if(left >= LEFT_90_DEGREE_TRANSITION) 
                {
                    state = TEST3;
                }
                break;
            case TEST3:
                if(prev_state != TEST3)
                {
                    msg.movement = FORWARD_LEFT;
                    msg.duty_cycle = 50;
                    MotorQueue_SendMsg(msg);
                    prev_state = state;
                }
                else if(right >= RIGHT_90_DEGREE_TRANSITION)
                {
                    state = TEST4;
                }
                break;
            case TEST4:
                if(prev_state != TEST4)
                {
                    msg.movement = REVERSE_BOTH;
                    msg.duty_cycle = 20;
                    MotorQueue_SendMsg(msg);
                    prev_state = state;
                }
                else if(right >= SQUARE_LENGTH_TRANSITION || left >= SQUARE_LENGTH_TRANSITION)
                {
                    state = TEST5;
                }
                break;
            case TEST5:
                if(prev_state != TEST5)
                {
                    msg.movement = REVERSE_RIGHT;
                    msg.duty_cycle = 50;
                    MotorQueue_SendMsg(msg);
                    prev_state = state;
                }
                else if(right >= RIGHT_90_DEGREE_TRANSITION)
                {
                    state = TEST6;
                }
                break;
            case TEST6:
                if(prev_state != TEST6)
                {
                    msg.movement = REVERSE_LEFT;
                    msg.duty_cycle = 50;
                    MotorQueue_SendMsg(msg);
                    prev_state = state;
                }
                else if(left >= LEFT_90_DEGREE_TRANSITION)
                {
                    state = END;
                }
                break;
            case END:
                if(prev_state != END)
                {
                    msg.movement = STOP;
                    msg.duty_cycle = 0;
                    MotorQueue_SendMsg(msg);
                    prev_state = state;
                }
                break;
        }
    }
}

 

/*******************************************************************************
 End of File
 */
