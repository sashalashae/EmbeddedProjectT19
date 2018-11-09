
#include "get_timer.h"

void Timer_Init()
{
    TimerHandle_t testTimer;

    //Start Nav timer (feeds into queue)
    testTimer = xTimerCreate("Timer100ms", pdMS_TO_TICKS(500), pdTRUE, ( void * ) 0, Nav_Timer_Cb);
    xTimerStart(testTimer, 0);
}

void Nav_Timer_Cb(TimerHandle_t xTimer)
{       
    strStruct currentMsg;
    currentMsg = stringToStruct("{}\0", 1); // actual message doesn't matter for MS4
    TxThreadQueue_Send(currentMsg);
}