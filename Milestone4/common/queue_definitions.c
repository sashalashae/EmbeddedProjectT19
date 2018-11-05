/*******************************************************************************
 * Filename:    helper_functions.h
 * Date:        10/9/2018
 * Description: Header file for a generic queue functions for team 19
 * Author:      Alex Nolan
*******************************************************************************/

#include "queue_definitions.h"

void ArmQueue_Init(uint32_t size)
{
    ArmQueue = xQueueCreate(size, sizeof(QueueMsg));
}

void NavQueue_Init(uint32_t size)
{
    NavQueue = xQueueCreate(size, sizeof(QueueMsg));
}

void MotorQueue_Init(uint32_t size)
{
    MotorQueue = xQueueCreate(size, sizeof(QueueMsg));
}

void SensorQueue_Init(uint32_t size)
{
    SensorQueue = xQueueCreate(size, sizeof(QueueMsg));
}

QueueMsg Queue_Receive_FromISR(QueueHandle_t queue)
{
    QueueMsg data;
    BaseType_t xTaskWokenByReceive = pdFALSE;
    xQueueReceiveFromISR(queue, &data, &xTaskWokenByReceive);
    return data;
}

QueueMsg Queue_Receive_FromThread(QueueHandle_t queue)
{
    QueueMsg data;
    xQueueReceive(queue, &data, portMAX_DELAY);
    return data;
}

BaseType_t Queue_Send_FromISR(QueueHandle_t queue, QueueMsg msg, BaseType_t *pxHigherPriorityTaskWoken)
{
    return xQueueSendFromISR(queue, &msg, pxHigherPriorityTaskWoken);
}

BaseType_t Queue_Send_FromThread(QueueHandle_t queue, QueueMsg msg)
{
    return xQueueSend(queue, &msg, 0);
}