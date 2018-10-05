/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    txthread.c

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

#include "txthread.h"

/*******************************************************************************
  Function:
    void TXTHREAD_Initialize ( void )

  Remarks:
    See prototype in txthread.h.
 */

void TXTHREAD_Initialize ( void )
{
    TxThreadQueue_Init(10);
    TxISRQueue_Init(256);
}


/******************************************************************************
  Function:
    void TXTHREAD_Tasks ( void )

  Remarks:
    See prototype in txthread.h.
 */

void TXTHREAD_Tasks ( void )
{
    cJSON msg;
    while(1)
    {
        //receive a JSON message to transmit
        msg = TxThreadQueue_Receive();
        
        //begin filling the TxISRQueue
        
        //Enable TX interrupts
    }
}

 

/*******************************************************************************
 End of File
 */
