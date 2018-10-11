/*******************************************************************************
 * Filename:    helper_functions.h
 * Date:        9/20/2018
 * Description: Header file for a set of generic helper functions for use on 
 *              the PIC32 with FreeRTOS.
 * Author:      Alex Nolan
*******************************************************************************/

#ifndef HELPER_FUNCTIONS
#define HELPER_FUNCTIONS

//External includes
#include "system_definitions.h"
#include "debug.h"
#include "UART_Defines.h"

//Function declarations
void sleep(int16_t milliseconds);

//converts a string to a struct
strStruct stringToStruct(char * str);

#endif