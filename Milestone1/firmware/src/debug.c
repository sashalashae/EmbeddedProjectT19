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
}

void dbgUARTVal(unsigned char outVal)
{
    DRV_USART0_WriteByte(outVal);
}

void dbgOutputLoc(uint32_t outVal)
{
    
}