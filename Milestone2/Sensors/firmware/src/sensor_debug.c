/* ************************************************************************** */
// Filename:    debug.c 
// Date:        8/27/2018 
// Author:      Alex Nolan
// Description: Implementation of debug functions to print data over GPIO and UART
/* ************************************************************************** */

#include "sensor_debug.h"

/*******************************************************************************
  Function:
    void dbgOutputVal(uint32_t outVal)

  Summary:

  Description:

  Precondition:

  Parameters:
    outVal: The value to output to the GPIO

  Returns:
    None.
*/
void dbgOutputVal(uint32_t outVal)
{
    //If outval is out of range return
    if (outVal > 127)
    {
        //return;
        dbgErrorHandler(ERROR_BOUNDS);
    }
    
    dbgOutputLoc(DLOC_GPIO_WRITE_START);
        
    //Write values to rest of pins in output value group (31 - 37)
    //Pin 31 = MSB, Pin 37 = LSB
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_6, ((outVal & 0x40) >> 6));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_5, ((outVal & 0x20) >> 5));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_4, ((outVal & 0x10) >> 4));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_3, ((outVal & 0x8) >> 3));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_2, ((outVal & 0x4) >> 2));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_1, ((outVal & 0x2) >> 1));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_0, (outVal & 0x1));
    dbgOutputLoc(DLOC_GPIO_WRITE_END);
    //Toggle pin 30
    SYS_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_7);
}

/*******************************************************************************
  Function:
    void dbgUARTVal(unsigned char outVal)

  Summary:

  Description:

  Precondition:

  Parameters:
    unsigned char outVal: The value to send over UART

  Returns:
    None.
*/
void dbgUARTVal(unsigned char outVal)
{
    UARTWriteByte(outVal);
}

/*******************************************************************************
  Function:
    void dbgOutputLoc(uint32_t outVal)

  Summary:

  Description:

  Precondition:

  Parameters:
    None.

  Returns:
    None.
*/
void dbgOutputLoc(uint32_t outVal)
{
    //If outval is out of range return
    if (outVal > 127)
    {
        dbgErrorHandler(ERROR_BOUNDS);
    }
    
    
    //Write values to rest of pins in output location group (39 - 45)
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_5, ((outVal & 0x40) >> 6));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_11, ((outVal & 0x20) >> 5));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_13, ((outVal & 0x10) >> 4));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_12, ((outVal & 0x8) >> 3));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_8, ((outVal & 0x4) >> 2));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_10, ((outVal & 0x2) >> 1));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_0, (outVal & 0x1));
    //Toggle pin 38
    SYS_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_10);
}

/*******************************************************************************
  Function:
    void dbgErrorHandler(uint32_t errorCode)

  Summary:

  Description:

  Precondition:

  Parameters:
 uint32_t errorCode: a defined code for the error location

  Returns:
    None.
*/
void dbgErrorHandler(uint32_t errorCode)
{
    //Set LED on
    SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
    //Send location over GPIO
    dbgOutputLoc(errorCode);
    //Stop timer ISR
    DRV_TMR0_Stop();
    //Suspend threads
    vTaskSuspendAll();
    //Wait forever
    while(1);
}
