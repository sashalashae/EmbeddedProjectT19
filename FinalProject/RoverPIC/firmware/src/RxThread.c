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
    int index = 0;
    uint32_t val = 0;
    QueueMsg fromServer;
    char str[MAX_MESSAGE_SIZE];
    
    while(1)
    {
        //receive a byte from the Rx ISR
        index = 0;
        //receive first char
        data = RxISRQueue_Receive();
        //wait for open brackets
        while(data != '{')
        {
            data = RxISRQueue_Receive();
        }
        index = 0;
        while(data != '}')
        {
            data = RxISRQueue_Receive();
            str[index] = data;
            index++;
        }
        str[index] = '\0';
            
        //TxThreadQueue_Send(stringToStruct(str, 1));
        
        int i;
        int checknext = 0;
        int checkFSRs = 0;
        int checkDraw = 0;
        
        for(i = 0; i < index; i++)
        {
            if(str[i] == 'n' && str[i+1] == 'e' && str[i+2] == 'x' && str[i+3] == 't')
            {
                checknext = 1;
                fromServer.val0 = str[i+8] & 0b001111;
            }
            else if(str[i] == 'F' && str[i+1] == 'S' && str[i+2] == 'R' && str[i+3] == 's')
            {
                checkFSRs = 1;
                val = ((str[i+8] & 0b001111) * 1000);
                val = val + ((str[i+9] & 0b001111) * 100);
                val = val + ((str[i+10] & 0b001111) * 10);
                val = val + (str[i+11] & 0b001111);
                fromServer.val1 = val;
            }
            else if(str[i] == 'd' && str[i+1] == 'r' && str[i+2] == 'a' && str[i+3] == 'w')
            {
                checkDraw = 1;
                fromServer.val2 = str[i+9];
            }
        }
                
        //if(checknext && checkFSRs && checkDraw)
        if(checkDraw)
        {
            fromServer.source = RxThread;
            Queue_Send_FromThread(NavQueue, fromServer);
        }
    }
}

/*******************************************************************************
 End of File
 */