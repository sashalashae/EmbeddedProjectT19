/* ************************************************************************** */
// Filename:    fsr.c 
// Date:        11/04/2018 
// Author:      Sasha Morgan
// Description: User defined hardware interfacing functions
/* ************************************************************************** */
#include "fsr.h"

uint32_t FSRsRead(int *array){
    uint32_t out = 0;
    int i;
    //start a new sample
    dbgOutputLoc(LOC_ADC_START);
    for(i = 0; i<10; i++)
    {
        if(DRV_ADC_SamplesRead(i) > array[i] + FSR_THRESHOLD)
        {
            out |= 1 << i;
        }
        //dbgOutputVal(DRV_ADC_SamplesRead(i));
    }
    if(DRV_ADC_SamplesRead(10) > array[10] + FSR_THRESHOLD)
    {
        out |= 1 << 5;
    }
    else
    {
        out &= ~(1<<5);
    }
    dbgOutputLoc(out);
    dbgOutputLoc(LOC_ADC_END);
    return out;
}

