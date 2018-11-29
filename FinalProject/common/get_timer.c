
#include "get_timer.h"

void Timer_Init()
{
    TimerHandle_t testTimer;
    
    testTimer = xTimerCreate("Timer500ms", pdMS_TO_TICKS(500), pdTRUE, ( void * ) 0, Nav_Timer_Cb);
    
    xTimerStart(testTimer, 0);

}

void Nav_Timer_Cb(TimerHandle_t xTimer)
{   
    strStruct currentMsg;
    currentMsg = stringToStruct("{\"Source\":\"RoverPIC\",\"Ack\":\"\",\"RoverPosition\":\"q\",\"Check\":\"N\"}\0", 1);
    TxThreadQueue_Send(currentMsg);
}