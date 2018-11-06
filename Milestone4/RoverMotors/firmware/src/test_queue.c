/* ************************************************************************** */
// Filename:    test_queue.c 
// Date:        9/30/2018 
// Author:      Sajan Ronvelwala
// Description: Implementation for the test thread queue
/* ************************************************************************** */

#include "test_queue.h"

static QueueHandle_t TestQueue;

void TestQueue_Initialize(uint32_t size)
{
    TestQueue = xQueueCreate(size, sizeof(TestQueueData_t));
}

BaseType_t TestQueue_SendMsg(TestQueueData_t msg)
{
    BaseType_t status = xQueueOverwrite(TestQueue, &msg);
    dbgOutputLoc(LOC_TEST_QUEUE_SEND);
    return status;
}

BaseType_t TestQueue_SendMsgISR(TestQueueData_t msg, BaseType_t *pxHigherPriorityTaskWoken)
{
    BaseType_t status = xQueueOverwriteFromISR(TestQueue, &msg, pxHigherPriorityTaskWoken);
    dbgOutputLoc(LOC_TEST_QUEUE_ISR_SEND);
    return status;
}

TestQueueData_t TestQueue_ReceiveMsg()
{
    TestQueueData_t data;
    dbgOutputLoc(LOC_TEST_QUEUE_RECEIVE_WAITING);
    BaseType_t status = xQueueReceive(TestQueue, &data, portMAX_DELAY);
    dbgOutputLoc(LOC_TEST_QUEUE_RECEIVE_FINISHED);
    return data;
}