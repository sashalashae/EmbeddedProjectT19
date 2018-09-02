/* ************************************************************************** */
// Filename:    sensor_queue.h
// Date:        8/27/2018
// Author:      Alex Nolan
// Description: Header file for the sensor data message queue
/* ************************************************************************** */

#ifndef _SENSORQUEUE_H
#define _SENSORQUEUE_H

#include <stdint.h>

#include "FreeRTOS.h"
#include "queue.h"

//Struct for the queue entry
typedef struct{
    //32 bit unsigned integer for the raw sensor data
    uint32_t sensorData;
    //Char array for the units (must be null terminated)
    char *units;
}QueueData;

// Initializes the sensor queue with the specified size
void SensorQueue_Initialize(uint32_t size);

// Sends message onto the sensor queue
BaseType_t SensorQueue_SendMsgISR(QueueData msg);

// Receives message from the sensor queue
QueueData SensorQueue_ReceiveMsg();

#endif

