#include "navQueue.h"

//static QueueHandle_t NavQueue;
//static QueueHandle_t RetQueue;

void NavQueue_Initialize(uint32_t size)
{
    TimerHandle_t testTimer;
    NavQueue = xQueueCreate(size, sizeof( testData ));
    //RetQueue = xQueueCreate(size, sizeof(int));
    //Start Nav timer (feeds into queue)
    testTimer = xTimerCreate("Timer100ms", pdMS_TO_TICKS(100), pdTRUE, ( void * ) 0, Nav_Timer_Cb);
    xTimerStart(testTimer, 0);
}


BaseType_t NavQueue_SendMsg(testData msg)
{
    return xQueueSend(NavQueue, &msg, 0);
}

/*BaseType_t RetQueue_SendIndex(uint16_t msg)
{
    return xQueueSend(RetQueue, &msg, 0);
}*/

testData NavQueue_ReceiveMsg()
{
    testData data;
    BaseType_t status = xQueueReceive(NavQueue, &data, portMAX_DELAY);
    dbgOutputLoc(LOC_QUEUE_RECEIVED);
    return data;
}

/*
uint16_t RetQueue_ReceiveIndex()
{
    uint16_t data;
    BaseType_t status = xQueueReceive(RetQueue, &data, portMAX_DELAY);
    return data;
}
 */

void Nav_Timer_Cb(TimerHandle_t xTimer)
{       
    /*
    testData td;
    static uint16_t testArr[] = {0b1100000011, 0b1100000010, 0b1100000000, 0b1100000100, 0b1100000000,
        0b1100001000, 0b1100011000, 0b0100011000, 0b0000011000, 0b0010011000, 0b0010011000, 
        0b0000011000, 0b0001011000, 0b0001111000, 0b0001101000, 0b0001100000, 0b0001100100,
        0b0001100000, 0b0001100010, 0b0001100011, 0b0001000011, 0b0000000011, 0b0010000011,
        0b0000000011, 0b0100000011, 0b1100000011, //Switch to Reverse Here
        0b1100000011, 0b0100000011, 0b0000000011, 0b0010000011, 0b0010000011, 0b0000000011,
        0b0001000011, 0b0001100011, 0b0001100010, 0b0001100000, 0b0001100100, 0b0001100000,
        0b0001101000, 0b0001111000, 0b0001011000, 0b0000011000, 0b0010011000, 0b0000011000,
        0b0100011000, 0b1100011000, 0b1100001000, 0b1100000000, 0b1100000100, 0b1100000100,
        0b1100000000, 0b1100000010, 0b1100000011};
    static int i = 0;
    td.FSRs = testArr[i];
    if (i > 25)
        td.dir = reverse;
    else
        td.dir = forwards;
    i += 1;
    if(i > 52)
        i = 0;
    dbgOutputLoc(DLOC_QUEUE_SEND_BEGIN);
    NavQueue_SendMsg(td);
    dbgOutputLoc(DLOC_QUEUE_SEND_END);*/

}
