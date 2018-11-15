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
 * @param milliseconds: The number of milliseconds to sleep for.
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


/*
 * Function: stringToStruct
 * 
 * Description:
 * 
 * @param str: The string to convert
 * 
 * Returns: a struct containing the string
 */
strStruct stringToStruct(char * str, uint8_t get)
{
    strStruct ret;
    ret.get = get;
    char currentChar = str[0];
    uint32_t index = 0;
    
    while(currentChar != '\0')
    {
        ret.str[index] = currentChar;
        index++;
        currentChar = str[index];
    }
    //add null terminator
    ret.str[index] = '\0';
    //add one for checksum
    ret.count = index+1;
    return ret;
}

/*
 * Function: stringToStructValue
 * 
 * Description:
 * 
 * @param str: The string to convert
 * @param value: The string to replace
 * 
 * Returns: a struct containing the string
 */
strStruct stringToStructValue(char * str, uint8_t get, char * value)
{
    strStruct ret;
    ret.get = get;
    char currentChar = str[0];
    uint32_t index = 0;
    uint32_t valueIndex = 0;
    uint32_t strIndex = 0;
    
    while(currentChar != '\0')
    {
        if(currentChar == '$')
        {
            currentChar = value[0];
            while(currentChar != '\0')
            {
                ret.str[index] = currentChar;
                index++;
                valueIndex++;
                currentChar = value[valueIndex];
            }
            strIndex++;
            currentChar = str[strIndex];
        }
        ret.str[index] = currentChar;
        index++;
        strIndex++;
        currentChar = str[strIndex];
    }
    //add null terminator
    ret.str[index] = '\0';
    //add one for checksum
    ret.count = index+1;
    return ret;
}