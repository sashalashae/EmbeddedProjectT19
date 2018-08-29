/* ************************************************************************** */
// Filename:    sensor_queue.h
// Date:        8/27/2018
// Author:      Alex Nolan
// Description: Header file for the sensor data message queue
/* ************************************************************************** */

#include <stdint.h>

typedef struct{
    uint32_t sensorData;
    char units[];
}QueueData;