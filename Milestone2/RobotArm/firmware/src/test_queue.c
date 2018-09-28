/*******************************************************************************
 * Filename:    test_queue.c
 * Date:        9/27/2018
 * Description: Implementation for command queue to testThread.
 * Author:      Alex Nolan
*******************************************************************************/

#include "test_queue.h"

static QueueHandle_t TestQueue;

void TestQueue_Initialize(uint32_t size)
{
    TestQueue = xQueueCreate(size, sizeof(ArmMessage));
}

TestMessage TestQueue_ReceiveMsg()
{
    TestMessage data;
    BaseType_t status = xQueueReceive(TestQueue, &data, portMAX_DELAY);
    return data;
}

BaseType_t TestQueue_SendMsg(TestMessage msg)
{
    return xQueueSend(TestQueue, &msg, 0);
}