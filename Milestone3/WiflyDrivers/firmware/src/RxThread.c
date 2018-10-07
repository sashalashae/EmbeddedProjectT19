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
    uint8_t check_gen = 0xff;
    uint8_t check_recv;
    int count;
    char R_Data[MAX_MESSAGE_SIZE-1] = ""; // Minus 1 to make room for checksum
    char temp[2];
    cJSON *JSON_Data;
    while(1)
    {
        count++;
        if(count == 512)
        {
            //DbgOutputLoc(MESSAGE_OUT_OF_RANGE)
            check_gen = 0xff;
            count = 0;
            R_Data[0] = '\0';
        }
        else
        {
            //receive current byte
            data = RxISRQueue_Receive();

            check_gen = check_gen ^ data;

            //Concatenate the byte onto a cumulative string
            temp[0] = data;
            temp[1] = '\0';
            strcat(R_Data, temp);

            //parse the data into JSON messages
            if(data == '\0')
            {
                check_recv = RxISRQueue_Receive();
                if(check_recv != check_gen)
                {
                    //Discard the data for being bad
                    //DbgOutputLoc(CHECKSUM_MISMATCH);
                    check_gen = 0xff;
                    R_Data[0] = '\0';
                    count = 0;
                }
                else
                {
                    JSON_Data = cJSON_Parse(R_Data);
                    //TODO: Send into queue to next thread
                    //Forward each message to the appropriate handling thread
                    cJSON_Delete(JSON_Data);
                    R_Data[0] = '\0';
                    check_gen = 0xff;
                    count = 0;
                }
            }
        }
    }
}

/*******************************************************************************
 End of File
 */
