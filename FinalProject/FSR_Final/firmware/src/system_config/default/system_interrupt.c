/*******************************************************************************
 System Interrupts File
  File Name:
    system_interrupt.c
  Summary:
    Raw ISR definitions.
  Description:
    This file contains a definitions of the raw ISRs required to support the
    interrupt sub-system.
  Summary:
    This file contains source code for the interrupt vector functions in the
    system.
  Description:
    This file contains source code for the interrupt vector functions in the
    system.  It implements the system and part specific vector "stub" functions
    from which the individual "Tasks" functions are called for any modules
    executing interrupt-driven in the MPLAB Harmony system.
  Remarks:
    This file requires access to the systemObjects global data structure that
    contains the object handles to all MPLAB Harmony module objects executing
    interrupt-driven in the system.  These handles are passed into the individual
    module "Tasks" functions to identify the instance of the module to maintain.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2011-2014 released Microchip Technology Inc.  All rights reserved.
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

#include "system/common/sys_common.h"
#include "sensor.h"
#include "rxthread.h"
#include "txthread.h"
#include "system_definitions.h"

static int configArray[11];
static int flag = 0;

// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************
void IntHandlerDrvUsartInstance0(void)
{
        //UART interrupt handler
    
    //dbg
    dbgOutputLoc(LOC_ENTER_UART_ISR);
    
    //variable declaration
    BaseType_t pxHigherPriorityTaskWoken = pdFALSE;
    uint8_t TxData;
    
    //Check for Tx interrupts
    if(SYS_INT_SourceStatusGet(INT_SOURCE_USART_1_TRANSMIT))
    {
        //debug location
        dbgOutputLoc(LOC_ENTER_UART_TX);
        
        //send bytes until full
        while(!PLIB_USART_TransmitterBufferIsFull(USART_ID_1) && !TxISRQueue_IsEmpty())
        {
            TxData = TxISRQueue_Receive();
            PLIB_USART_TransmitterByteSend(USART_ID_1, TxData);
        }
        
        //if the no messages left in TxISRQueue, disable the interrupt
        if(TxISRQueue_IsEmpty())
        {
            SYS_INT_SourceDisable(INT_SOURCE_USART_1_TRANSMIT);
        }

        //clear the interrupt flag
        SYS_INT_SourceStatusClear(INT_SOURCE_USART_1_TRANSMIT);
        
        //debug location
        dbgOutputLoc(LOC_EXIT_UART_TX);
    }
    
    //Check for Rx Interrupts
    if(SYS_INT_SourceStatusGet(INT_SOURCE_USART_1_RECEIVE))
    {   
        //debug location
        dbgOutputLoc(LOC_ENTER_UART_RX);
        
        //read the data into the RxISRQueue
        while(PLIB_USART_ReceiverDataIsAvailable(USART_ID_1))
        {
            RxISRQueue_Send(PLIB_USART_ReceiverByteReceive(USART_ID_1), &pxHigherPriorityTaskWoken);
        }
        
        //clear the interrupt flag
        SYS_INT_SourceStatusClear(INT_SOURCE_USART_1_RECEIVE);
        
        //Tell scheduler that ISR is done
        portEND_SWITCHING_ISR(pxHigherPriorityTaskWoken);
        
        //debug location
        dbgOutputLoc(LOC_EXIT_UART_RX);
    }
    
    //check for error interrupt flags
    if(SYS_INT_SourceStatusGet(INT_SOURCE_USART_1_ERROR))
    {
        //debug location
        dbgOutputLoc(LOC_ENTER_UART_ERROR);
        
        //clear the flag
        SYS_INT_SourceStatusClear(INT_SOURCE_USART_1_ERROR);
        
        //debug location
        dbgOutputLoc(LOC_EXIT_UART_ERROR);
    }
    
    //debug location
    dbgOutputLoc(LOC_EXIT_UART_ISR);
}
 
 
void IntHandlerDrvAdc(void)
{
    BaseType_t pxHigherPriorityTaskWoken = pdFALSE;
    QueueMsg newSample;
    uint32_t sensorValue;
    
    //Send ISR start message over GPIO
    dbgOutputLoc(LOC_ADC_ISR_Q_START);
    if(flag == 0){
        int i;
        for(i = 0; i<11; i++)
        {
            configArray[i] = DRV_ADC_SamplesRead(i);
        }
        flag = 1;
        }
    //Read in value from the ADC
    sensorValue = FSRsRead(configArray);//ReadADCData(0);
    
    //Queue Data Build
    newSample.val0 = sensorValue;
    //Add to message queue
    Queue_Send_FromISR(SensorQueue, newSample, &pxHigherPriorityTaskWoken);
    dbgOutputLoc(LOC_ADC_ISR_Q_END);
     
   /* Clear ADC Interrupt Flag */
    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_ADC_1);
    
    //disable adc interrupt
    DRV_ADC_Close();
    
    portEND_SWITCHING_ISR(pxHigherPriorityTaskWoken);
}

 

void IntHandlerDrvTmrInstance0(void)
{
    PLIB_INT_SourceFlagClear(INT_ID_0,INT_SOURCE_TIMER_2);
}
 /*******************************************************************************
 End of File
*/