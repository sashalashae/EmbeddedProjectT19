/* ************************************************************************** */
// Filename:    sensor_queue.c 
// Date:        8/27/2018 
// Author:      Alex Nolan
// Description: Implementation for the sensor data queue
/* ************************************************************************** */

#include "sensor_queue.h"

static QueueHandle_t SensorQueue;

void SensorQueue_Initialize(uint32_t size)
{
    SensorQueue = xQueueCreate(size, sizeof(QueueData));
}

BaseType_t SensorQueue_SendMsgISR(QueueData msg, BaseType_t *pxHigherPriorityTaskWoken)
{
    BaseType_t status = xQueueSendFromISR(SensorQueue, &msg, pxHigherPriorityTaskWoken);
    return status;
}

QueueData SensorQueue_ReceiveMsg()
{
    QueueData data;
    BaseType_t status = xQueueReceive(SensorQueue, &data, portMAX_DELAY);
    return data;
}