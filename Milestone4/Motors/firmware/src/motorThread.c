/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    motorthread.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "motorthread.h"

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void MOTORTHREAD_Initialize ( void )

  Remarks:
    See prototype in motorthread.h.
 */

void MOTORTHREAD_Initialize ( void )
{
    //Set USER LED off initially
    SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
    motors_initialize();
    
    // initialize this thread's queue
    MotorQueue_Initialize(5);
    motors_timer_init();
}


/******************************************************************************
  Function:
    void MOTORTHREAD_Tasks ( void )

  Remarks:
    See prototype in motorthread.h.
 */

void MOTORTHREAD_Tasks ( void )
{
    //Start the timers
    DRV_TMR0_Start();
    DRV_TMR1_Start();
    
    uint32_t distance_target_val = 0;
    TestQueueData_t ack_msg;
    uint32_t current_left;
    uint32_t current_right;
    int32_t accumulated_left_error = 0;
    int32_t accumulated_right_error = 0;
    int32_t prev_left_error = 0;
    int32_t prev_right_error = 0;
    uint32_t expected_val = TIMER_100_MS_TRANSITIONS;
    const uint8_t DUTY_CYCLE = 50;
    const uint8_t DELTA_TIME_MS = ENCODER_PERIOD_MS; // period of timer interrupts
    
    strStruct coefficient_msg = stringToStruct("Coefficients\0", 1);
    TxThreadQueue_Send(coefficient_msg);
    
    uint8_t KP = 0;
    uint8_t KI = 0;
    uint8_t KD = 0;
    
    bool running = false;
    
    while(true)
    {
        MotorQueueData_t msg = MotorQueue_ReceiveMsg();
        if(running)
        {
            if(msg.type != TIMER_TICK && msg.type != ASYNC_STOP)
            {
                continue;
            }
        }
        else
        {
            if(msg.type == TIMER_TICK)
            {
                continue;
            }
        }
        strStruct debug_msg;
        switch(msg.type)
        {
            case MOVEMENT_COMMAND:
                motors_stop();
                DRV_TMR0_CounterClear();
                DRV_TMR1_CounterClear();
                distance_target_val = msg.distance;
                switch(msg.movement)
                {
                    case FORWARD_BOTH:
                        motors_forward(DUTY_CYCLE);
                        break;
                    case REVERSE_BOTH:
                        motors_reverse(DUTY_CYCLE);
                        break;
                    case TURN_RIGHT:
                        motors_turn_right(DUTY_CYCLE);
                        break;
                    case TURN_LEFT:
                        motors_turn_left(DUTY_CYCLE);
                        break;
                    case STOP:
                        motors_stop();
                        distance_target_val = 0;
                        break;
                }
                running = true;
                break;
            case TIMER_TICK:
                current_left = DRV_TMR0_CounterValueGet();
                current_right = DRV_TMR1_CounterValueGet();
                if(current_left >= distance_target_val && current_right >= distance_target_val)
                {
                    motors_stop();
                    accumulated_left_error = 0;
                    accumulated_right_error = 0;
                    prev_left_error = 0;
                    prev_right_error = 0;
                    running = false;
                    ack_msg.ack = true;
                    TestQueue_SendMsg(ack_msg);
                    expected_val = TIMER_100_MS_TRANSITIONS;
                }
                else if(current_left >= distance_target_val)
                {
                    motor_left_stop();
                }
                else if(current_right >= distance_target_val)
                {
                    motor_right_stop();
                }
                else
                {
                    int32_t left_error = expected_val - current_left;                       // proportional
                    accumulated_left_error += left_error * DELTA_TIME_MS;                   // integral
                    int32_t derivative_left_error = (left_error - prev_left_error)/DELTA_TIME_MS;   // derivative
                    prev_left_error = left_error;
                    int32_t right_error = expected_val - current_right;                     // proportional
                    accumulated_right_error += right_error * DELTA_TIME_MS;                 // integral
                    int32_t derivative_right_error = (right_error - prev_left_error)/DELTA_TIME_MS;  // derivative
                    prev_right_error = right_error;
                    /*char msg[256] = "{\"left\":\"";
                    msg[10] = (left_error/10000) + '0';
                    msg[11] = ((left_error%10000)/1000) + '0';
                    msg[12] = ((left_error%1000)/100) + '0';
                    msg[13] = ((left_error%100)/10) + '0';
                    msg[14] = (left_error%10) + '0';
                    msg[15] = '\"';
                    msg[16] = ',';
                    msg[17] = '\"';
                    msg[18] = 'r';
                    msg[19] = 'i';
                    msg[20] = 'g';
                    msg[21] = 'h';
                    msg[22] = 't';
                    msg[23] = '\"';
                    msg[24] = ':';
                    msg[25] = '\"';
                    msg[26] = (right_error/10000) + '0';
                    msg[27] = ((right_error%10000)/1000) + '0';
                    msg[28] = ((right_error%1000)/100) + '0';
                    msg[29] = ((right_error%100)/10) + '0';
                    msg[30] = (right_error%10) + '0';
                    msg[31] = '\"';
                    msg[32] = '}';
                    msg[33] = '\0';
                    TxThreadQueue_Send(stringToStruct(msg, 0));*/
                    motors_pid_adjust(left_error, right_error, accumulated_left_error, accumulated_right_error, derivative_left_error, derivative_right_error, KP, KI, KD);
                    expected_val += TIMER_100_MS_TRANSITIONS;
                }
                break;
            case ASYNC_STOP:
                motors_stop();
                accumulated_left_error = 0;
                accumulated_right_error = 0;
                prev_left_error = 0;
                prev_right_error = 0;
                running = false;
                ack_msg.ack = true;
                TestQueue_SendMsg(ack_msg);
                expected_val = TIMER_100_MS_TRANSITIONS;
                break;
            case CALIBRATE:
                KP = msg.kp;
                KI = msg.ki;
                KD = msg.kd;
                ack_msg.ack = true;
                TestQueue_SendMsg(ack_msg);
                break;
        }
    }
}

 

/*******************************************************************************
 End of File
 */
