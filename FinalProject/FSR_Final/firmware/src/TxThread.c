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
    TxISRQueue_Init(MAX_MESSAGE_SIZE);
}


/******************************************************************************
  Function:
    void TXTHREAD_Tasks ( void )
  Remarks:
    See prototype in txthread.h.
 */

void TXTHREAD_Tasks ( void )
{
    int index;
    uint8_t currentByte;
    strStruct string;
    char * header;
    
    //constant header string
    //ADD KEEP ALIVE
    char * get = "GET / HTTP/1.1\r\nKeep-Alive: timeout=10\r\nContent-Type: application/json\r\nContent-Length: \0";
    char * post = "POST / HTTP/1.1\r\nContent-Type: application/json\r\nContent-Length: \0";
            
    while(1)
    {
        //Add sequence number to JSON
        //receive a JSON string message to transmit
        dbgOutputLoc(TX_THREAD_WAITING_FOR_QUEUE);
        string = TxThreadQueue_Receive();
        dbgOutputLoc(TX_THREAD_QUEUE_RECEIVED);

        //add new line and carriage return
        
        //add post or get request
        if(string.get)
        {
            header = get;
        }
        else
        {
            header = post;
        }   
        index = 0;
        currentByte = header[index];
        while(currentByte != '\0')
        {
            TxISRQueue_Send(currentByte);
            index++;
            currentByte = header[index];
        }
        
        //add message length (3 digits)        
        TxISRQueue_Send(((string.count / 100) % 10) | 0x30);
        TxISRQueue_Send(((string.count / 10) % 10) | 0x30);
        TxISRQueue_Send(((string.count) % 10) | 0x30);
        
        //add final newline/returns
        TxISRQueue_Send('\r');
        TxISRQueue_Send('\n');
        TxISRQueue_Send('\r');
        TxISRQueue_Send('\n');
        
        dbgOutputLoc(TX_THREAD_SERIALIZATION_DONE);
        
        //begin filling the TxISRQueue in increments of 1 byte 
        index = 0;
        currentByte = string.str[index];
        while(currentByte != '\0')
        {
            TxISRQueue_Send(currentByte); 
            index++;
            currentByte = string.str[index];
        }
        TxISRQueue_Send('\r');
        TxISRQueue_Send('\n');
        dbgOutputLoc(TX_THREAD_BYTE_ENQUEUE_DONE);
        //Enable TX interrupts
        SYS_INT_SourceEnable(INT_SOURCE_USART_1_TRANSMIT);
    }
}

 

/*******************************************************************************
 End of File
 */