/* ************************************************************************** */
// Filename:    fsr.c 
// Date:        11/04/2018 
// Author:      Sasha Morgan
// Description: User defined hardware interfacing functions
/* ************************************************************************** */

#include "fsr.h"
#include "../../../common/debug.h"

uint32_t FSRsRead(){
    uint32_t out = 0;
    int i;
    //start a new sample
    dbgOutputLoc(LOC_ADC_START);
    for(i = 0; i<10; i++)
    {
        if(DRV_ADC_SamplesRead(i) > 400)
        {
            out |= 1 << i;
        }
        //dbgOutputVal(DRV_ADC_SamplesRead(i));
    }
    dbgOutputLoc(out);
    dbgOutputLoc(LOC_ADC_END);
    return out;
}
