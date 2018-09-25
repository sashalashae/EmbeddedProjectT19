/*******************************************************************************
 * Filename:    armThread.c
 * Date:        9/25/2018
 * Description: Thread which handles commands sent to the robot arm.
 * Author:      Alex Nolan
*******************************************************************************/

#include "armThread.h"

void ARMTHREAD_Initialize ( void )
{
    //Initialize arm control
    armInit();
}

void ARMTHREAD_Tasks ( void )
{
    while(1)
    {
        
    }
}