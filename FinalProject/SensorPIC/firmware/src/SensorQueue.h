/* 
 * File:   SensorQueue.h
 * Author: SWAT Loaner
 *
 * Created on November 4, 2018, 7:35 PM
 */

#ifndef SENSORQUEUE_H
#define	SENSORQUEUE_H

#include <stdint.h>

#include "FreeRTOS.h"
#include "queue.h"

//Struct for the queue entry
typedef struct{
    //32 bit unsigned integer for the raw sensor data
    uint32_t sensorData;
}QueueData;

// Initializes the sensor queue with the specified size
void SensorQueue_Initialize(uint32_t size);

// Sends message onto the sensor queue
BaseType_t SensorQueue_SendMsgISR(QueueData msg, BaseType_t *pxHigherPriorityTaskWoken);

// Receives message from the sensor queue
QueueData SensorQueue_ReceiveMsg();
#endif	/* SENSORQUEUE_H */

