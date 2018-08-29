/* ************************************************************************** */
// Filename:    debug.c 
// Date:        8/27/2018 
// Author:      Alex Nolan
// Description: Implementation of debug functions to print data over GPIO and UART
/* ************************************************************************** */

#include "debug.h"

void dbgOutputVal(uint32_t outVal)
{
    //If outval is out of range return
    if (outVal > 127)
    {
        return;
    }
    
    //Toggle pin 37
    SYS_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_0);
    //Write values to rest of pins in output value group
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_2, ((outVal & 0x40) >> 6));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_4, ((outVal & 0x20) >> 5));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_6, ((outVal & 0x10) >> 4));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_7, ((outVal & 0x8) >> 3));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_2, ((outVal & 0x4) >> 2));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_3, ((outVal & 0x2) >> 1));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_3, (outVal & 0x1));
}

void dbgUARTVal(unsigned char outVal)
{
    DRV_USART0_WriteByte(outVal);
}

void dbgOutputLoc(uint32_t outVal)
{
    //If outval is out of range return
    if (outVal > 127)
    {
        return;
    }
    
    //Toggle pin 53
    SYS_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_9);
    //Write values to rest of pins in output value group
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_8, ((outVal & 0x40) >> 6));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_11, ((outVal & 0x20) >> 5));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_6, ((outVal & 0x10) >> 4));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_0, ((outVal & 0x8) >> 3));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_8, ((outVal & 0x4) >> 2));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_13, ((outVal & 0x2) >> 1));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_5, (outVal & 0x1));
}