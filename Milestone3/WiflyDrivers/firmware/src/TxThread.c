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
    cJSON *msg;
    uint8_t currentByte;
    char* str;
    uint8_t checksum;
    while(1)
    {
        //Initialize the checksum variable;
        checksum = 0xff;
        //receive a JSON message to transmit
        msg = TxThreadQueue_Receive();
        //get pointer to the message
        str = cJSON_PrintUnformatted(msg);
        //set count to 0
        index = 0;
        //begin filling the TxISRQueue in increments of 1 byte
        currentByte = str[index];
        
        while(currentByte != '\0')
        {
            checksum = checksum ^ currentByte;
            TxISRQueue_Send(currentByte); 
            index++;
            currentByte = str[index];
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
