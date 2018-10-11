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
    int pos3, pos2, pos1;
    uint8_t currentByte;
    strStruct string;
    uint8_t checksum;
    char * header;
    
    //constant header string
    char * get = "GET\nHTTP/1.1\nContent-Type: application/json\nContent-Length: \0";
    char * post = "POST\nHTTP/1.1\nContent-Type: application/json\nContent-Length: \0";
            
    while(1)
    {
        //receive a JSON string message to transmit
        dbgOutputLoc(TX_THREAD_WAITING_FOR_QUEUE);
        string = TxThreadQueue_Receive();         
        dbgOutputLoc(TX_THREAD_QUEUE_RECEIVED);

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
        pos3 = string.count / 100;
        pos2 = string.count / 10;
        pos1 = string.count % 10;
        
        TxISRQueue_Send(pos3 | 0x30);
        TxISRQueue_Send(pos2 | 0x30);
        TxISRQueue_Send(pos1 | 0x30);
        
        dbgOutputLoc(TX_THREAD_SERIALIZATION_DONE);
        
        //begin filling the TxISRQueue in increments of 1 byte 
        index = 0;
        //Initialize the checksum variable;
        checksum = 0xFF;
        currentByte = string.str[index];
        while(currentByte != '\0')
        {
            checksum = checksum ^ currentByte;
            TxISRQueue_Send(currentByte); 
            index++;
            currentByte = string.str[index];
        }
        TxISRQueue_Send(checksum); // Send checksum
        TxISRQueue_Send('\0'); // Send end character of string
        dbgOutputLoc(TX_THREAD_BYTE_ENQUEUE_DONE);
        //Enable TX interrupts
        SYS_INT_SourceEnable(INT_SOURCE_USART_1_TRANSMIT);
    }
}

 

/*******************************************************************************
 End of File
 */
