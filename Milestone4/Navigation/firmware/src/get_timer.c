
#include "get_timer.h"

void Timer_Init()
{
    TimerHandle_t testTimer;
    //TimerHandle_t MotorAckTimer;
    //TimerHandle_t ArmAckTimer;
    
    testTimer = xTimerCreate("Timer100ms", pdMS_TO_TICKS(500), pdTRUE, ( void * ) 0, Nav_Timer_Cb);
    //MotorAckTimer = xTimerCreate("MotorAck", pdMS_TO_TICKS(100), pdTRUE, ( void * ) 0, MotorAck_cb);
    //ArmAckTimer = xTimerCreate("ArmAck", pdMS_TO_TICKS(100), pdTRUE, ( void * ) 0, ArmAck_cb);
    
    //xTimerStart(ArmAckTimer, 0);
    xTimerStart(testTimer, 0);
    //xTimerStart(MotorAckTimer, 0);


}

void Nav_Timer_Cb(TimerHandle_t xTimer)
{       
    strStruct currentMsg;
    currentMsg = stringToStruct("{}\0", 1); //GET
    TxThreadQueue_Send(currentMsg);
}

/*
void MotorAck_cb(TimerHandle_t xTimer)
{
    QueueMsg motAck;
    
    motAck.source = MovementThread;
    motAck.type = AckMsg;
    
    Queue_Send_FromThread(NavQueue, motAck);
}

void ArmAck_cb(TimerHandle_t xTimer)
{
    QueueMsg armAck;

    armAck.source = MovementThread;
    armAck.type = AckMsg;
    
    Queue_Send_FromThread(NavQueue, armAck);

}
*/