/* ************************************************************************** */
/** Descriptive File Name

  @Author
    Sajan Ronvelwala

  @File Name
    motor_library.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#include "motor_library.h"

void motors_timer_cb(TimerHandle_t xTimer)
{
    //Toggle LED
    SYS_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
    
    MotorQueueData_t msg;
    msg.type = TIMER_TICK;
    MotorQueue_SendMsg(msg);
}

void motors_timer_init()
{
    TimerHandle_t timer_encoder;
    timer_encoder = xTimerCreate("Motor Timer", pdMS_TO_TICKS(ENCODER_PERIOD_MS), pdTRUE, ( void * ) 0, motors_timer_cb);
    xTimerStart(timer_encoder, 0);
}

void motors_initialize()
{
    //Set left direction pin off initially
    SYS_PORTS_PinClear(PORT_ID, MOTOR_PORT_LEFT, MOTOR_PIN_LEFT);
    //Set right direction pin off initially
    SYS_PORTS_PinClear(PORT_ID, MOTOR_PORT_RIGHT, MOTOR_PIN_RIGHT);
    
    //Disable timer interrupts on encoders
    PLIB_INT_SourceDisable(INT_ID_0,INT_SOURCE_TIMER_4);
    PLIB_INT_SourceDisable(INT_ID_0,INT_SOURCE_TIMER_5);
    
    //Initially disable all output compare modules
    OC1CON = 0;
    OC2CON = 0;
    
    //OCxRS / PR2 = Duty Cycle
    OC1R = 0;
    OC2R = 0;
    OC1RS = 0;
    OC2RS = 0;
    
    //Set output compare modules to PWM mode (fault pin disabled)
    OC1CON = 6;
    OC2CON = 6;
    
    //PR = Timer Source Clock / (PWM Frequency * Prescaler) - 1
    //PR = 80000000Hz / (64 Prescaler * 50 Hz) - 1 = 24999
    PR2 = 24999;
    
    //Set timer 2 prescaler to 64
    T2CON = 0x60;
    
    //Enable timer 2
    T2CONSET = BIT15;
    
    //Enable output compare modules
    OC1CONSET = BIT15;
    OC2CONSET = BIT15;
}

void motor_left_duty_cycle(uint8_t duty_cycle)
{
    //check for duty cycle that is too high
    if(duty_cycle > 100)
    {
        duty_cycle = 100;
    }
    OC2RS = duty_cycle*DUTY_CYCLE_COEFFICIENT;
}

void motor_right_duty_cycle(uint8_t duty_cycle)
{
    //check for duty cycle that is too high
    if(duty_cycle > 100)
    {
        duty_cycle = 100;
    }
    OC1RS = duty_cycle*DUTY_CYCLE_COEFFICIENT;
}

void motor_left(direction_t direction, uint8_t duty_cycle)
{
    SYS_PORTS_PinWrite(PORT_ID, MOTOR_PORT_LEFT, MOTOR_PIN_LEFT, direction);
    motor_left_duty_cycle(duty_cycle);
}

void motor_right(direction_t direction, uint8_t duty_cycle)
{
    SYS_PORTS_PinWrite(PORT_ID, MOTOR_PORT_RIGHT, MOTOR_PIN_RIGHT, direction);
    motor_right_duty_cycle(duty_cycle);
}

void motors_forward(uint8_t duty_cycle)
{
    motor_right(FORWARD, duty_cycle);
    motor_left(FORWARD, duty_cycle);
}

void motors_reverse(uint8_t duty_cycle)
{
    motor_right(REVERSE, duty_cycle);
    motor_left(REVERSE, duty_cycle);
}

void motor_right_stop()
{
    motor_right(FORWARD, 0);
}

void motor_left_stop()
{
    motor_left(FORWARD, 0);
}

void motors_stop()
{
    motor_right_stop();
    motor_left_stop();
}

void motors_turn_right(uint8_t duty_cycle)
{
    motor_right(REVERSE, duty_cycle);
    motor_left(FORWARD, duty_cycle);
}

void motors_turn_left(uint8_t duty_cycle)
{
    motor_left(REVERSE, duty_cycle);
    motor_right(FORWARD, duty_cycle);
}

void motors_pid_adjust(int32_t left_error, int32_t right_error, int32_t total_left_error, int32_t total_right_error, int32_t derivative_left_error, int32_t derivative_right_error, uint8_t kp, uint8_t ki, uint8_t kd)
{
    dbgOutputLoc(LOC_PID_ADJUST_START);
    // left Proportional, Integral
    OC2RS += (left_error * kp) + (total_left_error * ki) + (derivative_left_error * kd);
    // right Proportional, Integral
    OC1RS += (right_error * kp) + (total_right_error * ki) + (derivative_right_error * kd);
    dbgOutputLoc(LOC_PID_ADJUST_END);
}

/* *****************************************************************************
 End of File
 */
