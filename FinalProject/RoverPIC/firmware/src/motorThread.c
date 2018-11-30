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
    MotorQueue_Init(5);
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
    
    uint32_t distance_target_val_right = 0;
    uint32_t distance_target_val_left = 0;
    QueueMsg ack_msg;
    uint32_t current_left;
    uint32_t current_right;
    int32_t accumulated_left_error = 0;
    int32_t accumulated_right_error = 0;
    int32_t prev_left_error = 0;
    int32_t prev_right_error = 0;
    uint32_t expected_val;// = TIMER_100_MS_TRANSITIONS;
    uint8_t duty_cycle;
    const uint8_t DELTA_TIME_MS = ENCODER_PERIOD_MS; // period of timer interrupts
    
    strStruct coefficient_msg = stringToStruct("Coefficients\0", 1);
    TxThreadQueue_Send(coefficient_msg);
    
    uint8_t KP = 70;
    uint8_t KI = 30;
    uint8_t KD = 25;
    
    bool running = false;
    
    while(true)
    {
        QueueMsg msg = Queue_Receive_FromThread(MotorQueue);
        if(running)
        {
            if(msg.type != TimerMsg && msg.type != AsyncStopMsg)
            {
                continue;
            }
        }
        else
        {
            if(msg.type == TimerMsg)
            {
                continue;
            }
        }
        switch(msg.type)
        {
            case CommandMsg:
                motors_stop();
                DRV_TMR0_CounterClear();
                DRV_TMR1_CounterClear();
                distance_target_val_right = msg.val1;
                distance_target_val_left = msg.val1;
                if(msg.val2)
                {
                    duty_cycle = msg.val3 & 0xFF;
                }
                else
                {
                    duty_cycle = 50;
                }
                switch(msg.val0)
                {
                    case FORWARD_BOTH:
                        motors_forward(duty_cycle);
                        break;
                    case REVERSE_BOTH:
                        motors_reverse(duty_cycle);
                        break;
                    case TURN_RIGHT:
                        motors_turn_right(duty_cycle);
                        break;
                    case TURN_LEFT:
                        motors_turn_left(duty_cycle);
                        break;
                    case RIGHT_FORWARD:
                        motor_right(FORWARD, duty_cycle);
                        motor_left_stop();
                        distance_target_val_left = 0;
                        break;
                    case RIGHT_REVERSE:
                        motor_right(REVERSE, duty_cycle);
                        motor_left_stop();
                        distance_target_val_left = 0;
                        break;
                    case LEFT_FORWARD:
                        motor_left(FORWARD, duty_cycle);
                        motor_right_stop();
                        distance_target_val_right = 0;
                        break;
                    case LEFT_REVERSE:
                        motor_left(REVERSE, duty_cycle);
                        motor_right_stop();
                        distance_target_val_right = 0;
                        break;
                    case STOP:
                        motors_stop();
                        distance_target_val_right = 0;
                        distance_target_val_left = 0;
                        break;
                }
                running = true;
                break;
            case TimerMsg:
                current_left = DRV_TMR0_CounterValueGet();
                current_right = DRV_TMR1_CounterValueGet();
                if(current_left >= distance_target_val_left && current_right >= distance_target_val_right)
                {
                    motors_stop();
                    accumulated_left_error = 0;
                    accumulated_right_error = 0;
                    prev_left_error = 0;
                    prev_right_error = 0;
                    running = false;
                    ack_msg.type = AckMsg;
                    ack_msg.source = MovementThread;
                    Queue_Send_FromThread(NavQueue, ack_msg);
                }
                else if(current_left >= distance_target_val_left)
                {
                    motor_left_stop();
                }
                else if(current_right >= distance_target_val_right)
                {
                    motor_right_stop();
                }
                else
                {
                    expected_val = (current_left + current_right)/2;
                    int32_t left_error = expected_val - current_left;                       // proportional
                    accumulated_left_error += left_error * DELTA_TIME_MS;                   // integral
                    int32_t derivative_left_error = (left_error - prev_left_error)/DELTA_TIME_MS;   // derivative
                    prev_left_error = left_error;
                    int32_t right_error = expected_val - current_right;                     // proportional
                    accumulated_right_error += right_error * DELTA_TIME_MS;                 // integral
                    int32_t derivative_right_error = (right_error - prev_right_error)/DELTA_TIME_MS;  // derivative
                    prev_right_error = right_error;
                    motors_pid_adjust(left_error, right_error, accumulated_left_error, accumulated_right_error, derivative_left_error, derivative_right_error, KP, KI, KD);
                    /*
                    char msg[137] = "{\"Type\":\"Error\",\"Content\":{\"left\":\"+xxxxx\",\"right\":\"+xxxxx\",\"total_l\":\"+xxxxxxx\",\"total_r\":\"+xxxxxxx\",\"KP\":\"xxx\",\"KI\":\"xxx\",\"KD\":\"xxx\"}}\0";
                    
                    if(left_error < 0)
                    {
                        msg[35] = '-';
                        left_error = -left_error;
                    }
                    msg[36] = (left_error/10000) + '0';
                    msg[37] = ((left_error%10000)/1000) + '0';
                    msg[38] = ((left_error%1000)/100) + '0';
                    msg[39] = ((left_error%100)/10) + '0';
                    msg[40] = (left_error%10) + '0';
                    if(right_error < 0)
                    {
                        msg[52] = '-';
                        right_error = -right_error;
                    }
                    msg[53] = (right_error/10000) + '0';
                    msg[54] = ((right_error%10000)/1000) + '0';
                    msg[55] = ((right_error%1000)/100) + '0';
                    msg[56] = ((right_error%100)/10) + '0';
                    msg[57] = (right_error%10) + '0';
                    
                    if(accumulated_left_error < 0)
                    {
                        msg[71] = '-';
                        accumulated_left_error = -accumulated_left_error;
                    }
                    msg[72] = (accumulated_left_error/1000000) + '0';
                    msg[73] = ((accumulated_left_error%1000000)/100000) + '0';
                    msg[74] = ((accumulated_left_error%100000)/10000) + '0';
                    msg[75] = ((accumulated_left_error%10000)/1000) + '0';
                    msg[76] = ((accumulated_left_error%1000)/100) + '0';
                    msg[77] = ((accumulated_left_error%100)/10) + '0';
                    msg[78] = (accumulated_left_error%10) + '0';
                    
                    if(accumulated_right_error < 0)
                    {
                        msg[92] = '-';
                        accumulated_right_error = -accumulated_right_error;
                    }
                    msg[93] = (accumulated_right_error/1000000) + '0';
                    msg[94] = ((accumulated_right_error%1000000)/100000) + '0';
                    msg[95] = ((accumulated_right_error%100000)/10000) + '0';
                    msg[96] = ((accumulated_right_error%10000)/1000) + '0';
                    msg[97] = ((accumulated_right_error%1000)/100) + '0';
                    msg[98] = ((accumulated_right_error%100)/10) + '0';
                    msg[99] = (accumulated_right_error%10) + '0';
                    
                    msg[108] = (KP/100) + '0';
                    msg[109] = ((KP%100)/10) + '0';
                    msg[110] = (KP%10) + '0';
                    
                    msg[119] = (KI/100) + '0';
                    msg[120] = ((KI%100)/10) + '0';
                    msg[121] = (KI%10) + '0';
                    
                    msg[130] = (KD/100) + '0';
                    msg[131] = ((KD%100)/10) + '0';
                    msg[132] = (KD%10) + '0';
                    TxThreadQueue_Send(stringToStruct(msg, 0));
                    */
                }
                break;
            case AsyncStopMsg:
                motors_stop();
                accumulated_left_error = 0;
                accumulated_right_error = 0;
                prev_left_error = 0;
                prev_right_error = 0;
                running = false;
                ack_msg.type = AckMsg;
                ack_msg.source = MovementThread;
                Queue_Send_FromThread(NavQueue, ack_msg);
                break;
            case CalibrateMsg:
                KP = msg.val0;
                KI = msg.val1;
                KD = msg.val2;
                ack_msg.type = AckMsg;
                ack_msg.source = MovementThread;
                Queue_Send_FromThread(NavQueue, ack_msg);
                break;
        }
    }
}

 

/*******************************************************************************
 End of File
 */
