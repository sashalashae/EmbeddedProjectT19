/* ************************************************************************** */
// Filename:    debug.c 
// Date:        8/27/2018 
// Author:      Alex Nolan
// Description: Implementation of debug functions to print data over GPIO and UART
/* ************************************************************************** */

#include "debug.h"

/*
 * Function: dbgInit
 * 
 * Description: Initializes pins needed for debug output
 * 
 * Returns: void
 */
void dbgInit()
{
    //Configure user LED as output
    SYS_PORTS_PinDirectionSelect(PORTS_ID_0, SYS_PORTS_DIRECTION_OUTPUT, PORT_CHANNEL_A, PORTS_BIT_POS_3);
    
    //Set USER LED off initially
    SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
    
    //Configure port E as output
    SYS_PORTS_DirectionSelect(PORTS_ID_0, SYS_PORTS_DIRECTION_OUTPUT, PORT_CHANNEL_E, 0xFF);
    
    //Set initial output value to 0
    SYS_PORTS_Write(PORTS_ID_0, PORT_CHANNEL_E, 0);
}

/*
 * Function: dbgOutputLoc
 * 
 * Description: Sends a location value to the GPIO port E.
 * 
 * @param outVal: The location value to send over the GPIO.
 * 
 * Returns: void
 */
void dbgOutputLoc(uint32_t outVal)
{
    if(outVal > 255)
    {
        outVal = 255;
    }
    //Write location to port E
    SYS_PORTS_Write(PORTS_ID_0, PORT_CHANNEL_E, outVal);
}

/*
 * Function: dbgErrorHandler
 * 
 * Description: Handles fatal errors encountered in runtime
 * 
 * @param errorCode: The error code from the location of the fatal error.
 * 
 * Returns: void
 */
void dbgErrorHandler(uint32_t errorCode)
{
    //Set LED on
    SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
    //Send location over GPIO
    dbgOutputLoc(errorCode);
    //Suspend threads
    vTaskSuspendAll();
    //Wait forever
    while(1);
}