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

#include "testThread.h"

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
    dbgInit();
    
    TimerHandle_t testTimer;
    testTimer = xTimerCreate("testTimer", pdMS_TO_TICKS(100), pdTRUE, ( void * ) 0, Timer_Cb);
    xTimerStart(testTimer, 0);

}

void Timer_Cb()
{
    TxThreadQueue_Send(stringToStruct("{\"RID\":\"xxxxxx\", \"Source\":\"4\", \"MsgType\":\"Type Test\", \"Key\":\"Value\"}\0", 1));
}


/******************************************************************************
  Function:
    void TESTTHREAD_Tasks ( void )

  Remarks:
    See prototype in testthread.h.
 */

void TESTTHREAD_Tasks ( void )
{
    /*while(1)
    {
        strStruct sensorMessage = stringToStruct("some stuff", 1);
        TxThreadQueue_Send(stringToStruct("{\"RID\":\"xxxxxx\", \"Source\":\"4\", \"MsgType\":\"Type Test\", \"Key\":\"Value\"}\0", 1));
        sleep(100);
    }*/
}

/*******************************************************************************
 End of File
 */
