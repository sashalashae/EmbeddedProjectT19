/* ************************************************************************** */
// Filename:    user_drivers.c 
// Date:        8/30/2018 
// Author:      Alex Nolan
// Description: User defined hardware interfacing functions
/* ************************************************************************** */

#include "user_drivers.h"

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
uint16_t FSRsRead(){
    //Analog Pins
    uint16_t out = 0;
    //start a new sample
    dbgOutputLoc(DLOC_ADC_START);
    DRV_ADC_Start();
    //Wait for ADC value to be available
    while(!DRV_ADC_SamplesAvailable());
    //Reads the Values of Analog Pins 0-9
    uint32_t L0 = DRV_ADC_SamplesRead(0);
    uint32_t L1 = DRV_ADC_SamplesRead(1);
    uint32_t L2 = DRV_ADC_SamplesRead(2);
    uint32_t L3 = DRV_ADC_SamplesRead(3);
    uint32_t L4 = DRV_ADC_SamplesRead(4);
    uint32_t L5 = DRV_ADC_SamplesRead(5);
    uint32_t L6 = DRV_ADC_SamplesRead(6);

    uint32_t L7 = DRV_ADC_SamplesRead(7);
    uint32_t L8 = DRV_ADC_SamplesRead(8);
    uint32_t L9 = DRV_ADC_SamplesRead(9);
    dbgOutputLoc(DLOC_ADC_READ);  
    //Sensor 0
    if(L0 >= 800){
        out = 1; //0b0000000001
        SYS_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
        if(L8 >= 800){
            out = 257;//0b0100000001;
            if(L9 >= 800){
                out = 769;//0b1100000001;
                if(L1 >= 800){
                    out = 771; //0b1100000011
                }
            }
        }
        else if(L9 >= 800)
        {
            out = 513; //0b1000000001;
        }
        if(L7 >= 800){
            out = 129; //0b0010000001;
        }
        else if(L6 >= 800){
            out = 65; //0b0001000001;
            if(L5 >= 800){
                out = 97;//0b0001100001;
                if(L1 >= 800){
                    out = 99; //0b0001100011
                }
            }
        }
        else if(L5 >= 800){
            out = 33;//0b0000100001;
        }
        
    }
    //Sensors 1
    if(L1 >= 800){
        out = 2; //0b0000000010
        if(L8 >= 800){
            out = 258;//0b0100000010;
            if(L9 >= 800){
                out = 770;//0b1100000010;
            }
        }
        else if(L9 >= 800)
        {
            out = 514; //0b1000000010;
        }
        else if(L7 >= 800){
            out = 130; //0b0010000010;
        }
        else if(L6 >= 800){
            out = 66; //0b0001000010;
            if(L5 >= 800){
                out = 98;//0b0001100010;
            }
        }
        else if(L5 >= 800){
            out = 34;//0b0000100010;
        }
    }
    //Sensors 2
    else if(L2 >= 800){
        out = 4;//0b0000000100;
        if(L8 >= 800){
            out = 260;//0b0100000100;
            if(L9 >= 800){
                out = 772;//0b1100000100;
            }
        }
        else if(L9 >= 800)
        {
            out = 516; //0b1000000100;
        }
        else if(L7 >= 800){
            out = 132; //0b0010000100;
        }
        else if(L6 >= 800){
            out = 68; //0b0001000100;
            if(L5 >= 800){
                out = 100;//0b0001100100;
            }
        }
        else if(L5 >= 800){
            out = 36;//0b0000100100;
        }
        
    }
    //Sensors 3
    else if(L3 >= 800){
        out = 8; //0b0000001000;
        if(L8 >= 800){
            out = 264;//0b0100001000;
            if(L9 >= 800){
                out = 776;//0b1100001000;
            }
        }
        else if(L9 >= 800)
        {
            out = 520; //0b1000001000;
        }
        else if(L7 >= 800){
            out = 136; //0b0010001000;
        }
        else if(L6 >= 800){
            out = 72; //0b0001001000;
            if(L5 >= 800){
                out = 104;//0b0001101000;
            }
        }
        else if(L5 >= 800){
            out = 40;//0b0000101000;
        }       
    }
    //Sensors 4
    else if(L4 >= 800){
        out = 16; //0b0000010000;
        if(L8 >= 800){
            out = 272;//0b0100010000;
            if(L9 >= 800){
                out = 784;//0b1100010000;
            }
        }
        else if(L9 >= 800)
        {
            out = 528; //0b1000010000;
        }
        else if(L7 >= 800){
            out = 144; //0b0010010000;
        }
        else if(L6 >= 800){
            out = 80; //0b0001010000;
            if(L5 >= 800){
                out = 112;//0b0001110000;
            }
        }
        else if(L5 >= 800){
            out = 48;//0b0000110000;
        }
    }
    return out;
}
uint32_t ScaleADCData(uint32_t value, uint16_t tableNum)
{
    switch(tableNum)
    {
        case 0:
            //return table0[value];
            return table0[value];
            break;
        case 1:
            //return table1[value]
            return table1[value];
            break;
        case 2:
            return table2[value];
            break;
        case 3:
            break;
        default:
            return 0;
            break;
    }
}

/*
uint32_t ADCConversion(uint32_t value){
    while(tim == 1)
    {
        if(value >= lower && value <= upper)
        {
            retcenti = centi;
        }
        else{
            lower = upper
                    
        }
        
    }
}
 **/