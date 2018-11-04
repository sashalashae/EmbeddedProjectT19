/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    navthread.c

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

#include "navthread.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/

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
    void NAVTHREAD_Initialize ( void )

  Remarks:
    See prototype in navthread.h.
 */

void NAVTHREAD_Initialize ( void )
{
    //initialize queue
    NavQueue_Init(10);
}


/******************************************************************************
  Function:
    void NAVTHREAD_Tasks ( void )

  Remarks:
    See prototype in navthread.h.
 */

void NAVTHREAD_Tasks ( void )
{
    int newMove = 0;
    QueueMsg move;
    move.source = NavigationThread;
    move.type = CommandMsg;
    QueueMsg ack;
    QueueMsg serverResponse;
    while(1)
    {
        while(!newMove)
        {
            //ask the server what the next move is (GET request)
            TxThreadQueue_Send(stringToStruct("getmove\0", 1));
            
            //wait for RX thread to send something back
            serverResponse = Queue_Receive_FromThread(NavQueue);
            
            //handle RX thread response
            if(serverResponse.source == RxThread)
            {
                if(serverResponse.type == CommandMsg)
                {
                    if(serverResponse.val0 == DrawX)
                    {
                        newMove = 1;
                        move.val0 = DrawX;
                    }
                    else if(serverResponse.val0 == DrawO)
                    {
                        newMove = 1;
                        move.val0 = DrawO;
                    }
                    else
                    {
                        newMove = 0;
                    }
                }
            }
            sleep(1000);
        }
        
        //send move to arm
        Queue_Send_FromThread(ArmQueue, move);
        
        //wait for ack
        ack.type = UnknownMsg;
        while(ack.type != AckMsg)
        {
            ack = Queue_Receive_FromThread(NavQueue);
        }
        
        //clear new move flag
        newMove = 0;
    }
}

 

/*******************************************************************************
 End of File
 */
