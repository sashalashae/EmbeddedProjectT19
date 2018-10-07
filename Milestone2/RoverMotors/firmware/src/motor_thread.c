/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app_thread.c

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

#include "motor_thread.h"

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void MOTOR_THREAD_Initialize ( void )

  Remarks:
    See prototype in motor_thread.h.
 */

void MOTOR_THREAD_Initialize ( void )
{
    //Set USER LED off initially
    SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
    motors_initialize();
    
    // initialize this thread's queue
    MotorQueue_Initialize(5);
}


/******************************************************************************
  Function:
    void MOTOR_THREAD_Tasks ( void )

  Remarks:
    See prototype in motor_thread.h.
 */

void MOTOR_THREAD_Tasks ( void )
{
    while(true)
    {
        MotorQueueData_t msg = MotorQueue_ReceiveMsg();
        motors_stop();
        DRV_TMR0_CounterClear();
        DRV_TMR1_CounterClear();
        switch(msg.movement)
        {
            case FORWARD_BOTH:
                motors_forward(msg.duty_cycle);
                break;
            case REVERSE_BOTH:
                motors_reverse(msg.duty_cycle);
                break;
            case FORWARD_RIGHT:
                motors_turn_right(FORWARD, msg.duty_cycle);
                break;
            case FORWARD_LEFT:
                motors_turn_left(FORWARD, msg.duty_cycle);
                break;
            case REVERSE_LEFT:
                motors_turn_right(REVERSE, msg.duty_cycle);
                break;
            case REVERSE_RIGHT:
                motors_turn_left(REVERSE, msg.duty_cycle);
                break;
            case STOP:
                motors_stop();
                break;
        }
    }
    
    //Start the timers
    //DRV_TMR0_Start();
    //DRV_TMR1_Start();
    
    //turn on LED
    //SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
}

 

/*******************************************************************************
 End of File
 */
