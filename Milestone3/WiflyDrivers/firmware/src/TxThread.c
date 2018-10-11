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
    uint8_t checksum;
    
    //constant header string
    char * get = "GET\nHTTP/1.1\nContent-Type: application/json\nContent-Length: ";
    char * post = "POST\nHTTP/1.1\nContent-Type: application/json\nContent-Length: ";
    strStruct header;
            
    while(1)
    {
        //Initialize the checksum variable;
        checksum = 0xff;
        //receive a JSON string message to transmit
        string = TxThreadQueue_Receive();
        char* messageLength;
        itoa(messageLength, (int)(strlen(string.str)), 10);
        //append a header
        strcpy(header.str, get);
        //set index
        index = strlen(header.str);
        int i = 0;
        while(messageLength[i] != '\0')
        {
            string.str[index] = messageLength[i];
            i++;
            index++;
        }
        
        //begin filling the TxISRQueue in increments of 1 byte        
        currentByte = string.str[index];
        while(currentByte != '\0')
        {
            checksum = checksum ^ currentByte;
            TxISRQueue_Send(currentByte); 
            index++;
            currentByte = string.str[index];
        }
        TxISRQueue_Send('\0'); // Send end character of string
        TxISRQueue_Send(checksum); // Send checksum
        //Enable TX interrupts
        SYS_INT_SourceEnable(INT_SOURCE_USART_1_TRANSMIT);
    }
}

 

/*******************************************************************************
 End of File
 */
