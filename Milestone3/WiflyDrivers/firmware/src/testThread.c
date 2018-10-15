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
}

/******************************************************************************
  Function:
    void TESTTHREAD_Tasks ( void )

  Remarks:
    See prototype in testthread.h.
 */

void TESTTHREAD_Tasks ( void )
{
    char valueStr[4];
    //strStruct messages[10];
    strStruct currentMsg;
    
    uint8_t index = 0;
    uint8_t counter = 0;
    
    bool post = true;
    
    while(1)
    {
        if(index >= 9)
        {
            stringToStructValue("{\"RID\":\"xxxxxx\", \"Source\":\"x\", \"MsgType\":\"Type Test\", \"Key\":\"$\"}\0", 1, "Reallyreallyreallyreallyreallyreallyreallyreallyreallyreallyreallyreallyreallyreallyreallyreallyreallyreallyreallyreallyreallyreallyreallyreallyreallyreallyreallyreallylongmessage");
            index = 0;
        }
        else if(post)
        {
            valueStr[0] = (counter/100) | 0x30;
            valueStr[1] = ((counter/10) % 10)  | 0x30;
            valueStr[2] = (counter % 10) | 0x30;
            valueStr[3] = '\0';
            currentMsg = stringToStructValue("{\"RID\":\"xxxxxx\", \"Source\":\"x\", \"MsgType\":\"Type Test\", \"Key\":\"$\"}\0", 0, valueStr);
            counter += PIC_NUMBER;
            post = false;
        }
        else
        {
            currentMsg = stringToStruct("{\"RID\":\"xxxxxx\", \"Source\":\"x\", \"MsgType\":\"Value\"}\0", 1);
            post = true;
        }
        TxThreadQueue_Send(currentMsg);
        index++;
        sleep(500);
    }
}

/*******************************************************************************
 End of File
 */
