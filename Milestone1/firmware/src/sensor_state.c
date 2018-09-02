/* ************************************************************************** */
// Filename:    sensor_state.c 
// Date:        8/27/2018 
// Author:
// Description: Implements a state machine to read sensor data from the ADC and 
//              average that data over five polling cycles.
/* ************************************************************************** */

#include "sensor_state.h"

void sensor_state_machine(SensorState currentState, SensorState *nextState, QueueData currentData, uint32_t *runningAverage)
{
    switch(currentState)
    {
        case Sample0:
            //Print message over GPIO
            dbgOutputVal(currentData.sensorData);
            //Update running average counter
            (*runningAverage) = currentData.sensorData;
            //Move to next state
            (*nextState) = Sample1;
            break;
        
        case Sample1:
            //Print message over GPIO
            dbgOutputVal(currentData.sensorData);
            //Update running average counter
            (*runningAverage) += currentData.sensorData;
            //Move to next state
            (*nextState) = Sample2;
            break;
        
        case Sample2:
            //Print message over GPIO
            dbgOutputVal(currentData.sensorData);
            //Update running average counter
            (*runningAverage) += currentData.sensorData;
            //Move to next state
            (*nextState) = Sample3;
            break;
            
        case Sample3:
            //Print message over GPIO
            dbgOutputVal(currentData.sensorData);
            //Update running average counter
            (*runningAverage) += currentData.sensorData;
            //Move to next state
            (*nextState) = Sample4;
            break;
            
        case Sample4:
            //Print message over GPIO
            dbgOutputVal(currentData.sensorData);
            //Calculate average for all five samples
            (*runningAverage) += currentData.sensorData;
            (*runningAverage) = (*runningAverage) / 5;
            //Print average over UART
            UARTWriteByte((*runningAverage));
            //Move to next state
            (*nextState) = Sample0;
            break;
           
        //should never occur
        default:
            break;
    }
}