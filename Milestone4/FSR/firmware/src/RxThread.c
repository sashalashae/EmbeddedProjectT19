/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    rxthread.c

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


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "rxthread.h"

void RXTHREAD_Initialize ( void )
{
    RxISRQueue_Init(MAX_MESSAGE_SIZE);
}


/******************************************************************************
  Function:
    void RXTHREAD_Tasks ( void )

  Remarks:
    See prototype in rxthread.h.
 */

void RXTHREAD_Tasks ( void )
{
    QueueMsg newMove;
    newMove.source = RxThread;
    newMove.type = CommandMsg;
    uint8_t currentChar;
    int index;
    char body[32];
    while(1)
    {
        //receive first char
        currentChar = RxISRQueue_Receive();
        //wait for open brackets
        while(currentChar != '{')
        {
            currentChar = RxISRQueue_Receive();
        }
        index = 0;
        while(currentChar != '}' && index < 32)
        {
            currentChar = RxISRQueue_Receive();
            body[index] = currentChar;
            index++;
        }
    }
}

/*******************************************************************************
 End of File
 */
