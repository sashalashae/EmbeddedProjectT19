/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    sensor.c

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

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "sensor.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/

SENSOR_DATA sensorData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void SENSOR_Initialize ( void )

  Remarks:
    See prototype in sensor.h.
 */

void SENSOR_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    sensorData.state = SENSOR_STATE_INIT;
    DRV_ADC_Open();
    //Initialize the sensor queue
    SensorQueue_Init(100);
    
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void SENSOR_Tasks ( void )

  Remarks:
    See prototype in sensor.h.
 */

void SENSOR_Tasks ( void )
{   
    strStruct value;
    QueueMsg latestValue;
    //SYS_PORTS_PinDirectionSelect(PORTS_ID_0, SYS_PORTS_DIRECTION_OUTPUT, PORT_CHANNEL_A, PORTS_BIT_POS_3);
    while(1)
    {
        //wait 500ms for next transmission
        //sleep(500);
        //enable ADC interrupt
        //SYS_INT_SourceStatusSet(INT_SOURCE_ADC_1);
        //receive message
        latestValue = Queue_Receive_FromThread(SensorQueue);
        //transmit to server
        //stringToStructValue("{\"Source\":\"SensorPIC\", \"Value\":\"$\"}\0", 0, valueStr)
        value.str[0] = '{';
        value.str[1] = '\"';
        value.str[2] = 'S';
        value.str[3] = 'o';
        value.str[4] = 'u';
        value.str[5] = 'r';
        value.str[6] = 'c';
        value.str[7] = 'e';
        value.str[8] = '\"';
        value.str[9] = ':';
        value.str[10] = '\"';
        value.str[11] = 'S';
        value.str[12] = 'e';
        value.str[13] = 'n';
        value.str[14] = 's';
        value.str[15] = 'o';
        value.str[16] = 'r';
        value.str[17] = 'P';
        value.str[18] = 'I';
        value.str[19] = 'C';
        value.str[20] = '\"';
        value.str[21] = ',';
        value.str[22] = '\"';
        value.str[23] = 'V';
        value.str[24] = 'a';
        value.str[25] = 'l';
        value.str[26] = 'u';
        value.str[27] = 'e';
        value.str[28] = '\"';
        value.str[29] = ':';
        value.str[30] = '\"';       
        value.str[31] = ((latestValue.val0/1000) % 10) | 0x30;
        value.str[32] = ((latestValue.val0/100) % 10) | 0x30;
        value.str[33] = ((latestValue.val0/10) % 10) | 0x30;
        value.str[34] = ((latestValue.val0) % 10) | 0x30;
        value.str[35] = '\"';
        value.str[36] = '}';
        value.str[37] = '\0';
        value.get = 0;
        value.count = 38;
        TxThreadQueue_Send(value);
        DRV_ADC_Open();
        sleep(500);
//        Queue_Clear(SensorQueue);
    }
}

 

/*******************************************************************************
 End of File
 */
