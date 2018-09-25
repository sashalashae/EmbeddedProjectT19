#include "debug.h"


void dbgOutputLoc(uint32_t outLoc)
{
    //If outloc is out of range return
    if (outLoc > 127)
    {
        //return;
        dbgErrorHandler(ERROR_BOUNDS);
    }
        
    //Write values to rest of pins in output value group (31 - 37)
    //Pin 31 = MSB, Pin 37 = LSB
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_6, ((outLoc & 0x40) >> 6));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_5, ((outLoc & 0x20) >> 5));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_4, ((outLoc & 0x10) >> 4));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_3, ((outLoc & 0x8) >> 3));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_2, ((outLoc & 0x4) >> 2));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_1, ((outLoc & 0x2) >> 1));
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_0, (outLoc & 0x1));
    //Toggle pin 30
    SYS_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_7);
}

void dbgErrorHandler(uint32_t errorCode)
{
    //Set LED on
    SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
    //Send location over GPIO
    dbgOutputLoc(errorCode);
    //Stop timer ISR
        //DRV_TMR0_Stop();
    //Suspend threads
    vTaskSuspendAll();
    //Wait forever
    while(1);
}
