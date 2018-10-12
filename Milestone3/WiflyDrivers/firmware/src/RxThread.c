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
    uint8_t data;
    int count = 0;
    uint8_t str[MAX_MESSAGE_SIZE];
    while(1)
    {
        //receive a byte from the Rx ISR
        data = RxISRQueue_Receive();
        //waiting on a new message
        if(count == 0)
        {
            //new JSON body starts with '{'
            if(data == '{')
            {
                str[count] = data;
                count = 1;
            }
        }
        //else add to the current message
        else if (count < MAX_MESSAGE_SIZE)
        {
            str[count] = data;
            count++;
            //check for end of json message
            if(data == '}')
            {
                count = 0;
                //string is now full formatted, do something with it
            }
        }
        else
        //handle case of message being too large
        {
            count = 0;
        }
    }
}

/*******************************************************************************
 End of File
 */
