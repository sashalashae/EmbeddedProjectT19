/* ************************************************************************** */
// Filename:    user_drivers.c 
// Date:        8/30/2018 
// Author:      Alex Nolan
// Description: User defined hardware interfacing functions
/* ************************************************************************** */

#include "sensor_drivers.h"

void UARTInitialize()
{
    uint32_t clockFreq;
    
    //Initially disable UART module
    USART_Disable_Default(_UART1B_BASE_ADDRESS);
    //Initialize
    USART_InitializeModeGeneral_Default(_UART1B_BASE_ADDRESS, false, false, false, false, false);
    //Set line control
    USART_LineControlModeSelect_RXandTXCombined(_UART1B_BASE_ADDRESS, USART_8N1);
    //Get the system clock frequency
    clockFreq = SYS_CLK_PeripheralFrequencyGet(CLK_BUS_PERIPHERAL_1);
    //Set the baud rate
    USART_BaudSetAndEnable_Default(_UART1B_BASE_ADDRESS, clockFreq, 9600);
    //Init UART
    USART_Enable_Default(_UART1B_BASE_ADDRESS);
}

void UARTWriteByte(uint8_t data)
{
    dbgOutputLoc(DLOC_UART_WRITE_START);
    //Wait until UART buffer is not full
    while(PLIB_USART_TransmitterBufferIsFull(_UART1B_BASE_ADDRESS));
    /* Send one byte */
    PLIB_USART_TransmitterByteSend(_UART1B_BASE_ADDRESS, data);
    dbgOutputLoc(DLOC_UART_WRITE_END);
}

uint32_t ReadADCData(uint8_t bufNum)
{
    //start a new sample
    dbgOutputLoc(DLOC_ADC_START);
    DRV_ADC_Start();
    //Wait for ADC value to be available
    while(!DRV_ADC_SamplesAvailable());
    //Read in value from the ADC
    dbgOutputLoc(DLOC_ADC_READ);
    return DRV_ADC_SamplesRead(bufNum);
}

uint32_t ScaleADCData(uint32_t value)
{
    uint32_t threshold = 450;
    uint32_t ret = 0;
    if(value >= threshold)
    {
        ret = 1;
    }
    return ret;
}


uint32_t FSRPressure(uint32_t value)
{
    
}