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
    
    jsmn_parser parser;
	jsmn_init(&parser);
    int tok_size = MAX_MESSAGE_SIZE / 3;
	jsmntok_t tokens[tok_size];
    
    int len;
    char substring[tok_size];
    
    int num_tok;
    num_tok = jsmn_parse(&parser, str, strlen(str), tokens, tok_size);

    int i;
    
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
            SYS_PORTS_Write(PORTS_ID_0, PORT_CHANNEL_E, data);
            str[count] = data;
            count++;
            //check for end of json message
            if(data == '}')
            {
                str[count+1] = '\0';
                count = 0;
                
                /*
                //string is now fully formatted, do something with it
                //parse the JSON object
                num_tok = jsmn_parse(&parser, str, strlen(str), tokens, tok_size);
                for (i = 0; i < num_tok; i++)
                {
                    if (tokens[i].type == JSMN_OBJECT)
                    {
                        // do something with objects printf("Object");
                    }
                    else
                    {
                        len = tokens[i].end - tokens[i].start;
                        memcpy(substring, &str[tokens[i].start], len);
                        substring[len] = '\0';
                        if(substring == "Pic 1" || substring == "Pic 2" || substring == "Pic 3" || substring == "Pic 4")
                        {
                            len = tokens[i+1].end - tokens[i+1].start;
                            memcpy(substring, &str[tokens[i+1].start], len);
                            
                            substring[len] = '\0';
                        }
                    }
                }
                 */
            }
        }
        else
        //handle case of message being too large
        {
            //dbgOutputLoc(MESSAGE_OUT_OF_RANGE);
            count = 0;
        }
    }
}

/*******************************************************************************
 End of File
 */
