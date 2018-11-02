#include "testQueue.h"

static QueueHandle_t TestQueue;

void TestQueue_Initialize(uint32_t size)
{
    TestQueue = xQueueCreate(size, sizeof(uint16_t));
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