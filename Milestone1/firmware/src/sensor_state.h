/* ************************************************************************** */
// Filename:    sensor_state.h
// Date:        8/27/2018
// Author:      Alex Nolan
// Description: Header file for sensor state machine
/* ************************************************************************** */

#ifndef _SENSORSTATE_H
#define _SENSORSTATE_H

#include "sensor_queue.h"

//Enum for possible sensor sampling states
typedef enum
{
    Sample0  = 0, 
    Sample1,
    Sample2,
    Sample3,
    Sample4
}SensorState;

//Function header for state machine
void sensor_state_machine(SensorState currentState, SensorState *nextState, QueueData currentData, uint32_t *runningAverage);

#endif