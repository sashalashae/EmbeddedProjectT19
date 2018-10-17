/*******************************************************************************
 * Filename:    helper_functions.c
 * Date:        9/20/2018
 * Description: Set of generic helper functions for use on the PIC32 with
 *              FreeRTOS.
 * Author:      Alex Nolan
*******************************************************************************/

#include "helper_functions.h"

/*
 * Function: sleep
 * 
 * Description: Generic sleep function which blocks the execution of the current
 * thread for a set number of milliseconds. Acts as a wrapper to vTaskDelay.
 * 
 * @param milliseconds: The number of millseconds to sleep for.
 * 
 * Returns: void
 */
void sleep(int16_t milliseconds)
{
    dbgOutputLoc(LOC_SLEEP_START);
    //turn on LED, indicating a sleep
    SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
    //return if the sleep is too short
    if(milliseconds >= portTICK_PERIOD_MS)
    {
        vTaskDelay(milliseconds/portTICK_PERIOD_MS);
    }
    //turn off LED    //Set LED on
    SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
    dbgOutputLoc(LOC_SLEEP_END);
}