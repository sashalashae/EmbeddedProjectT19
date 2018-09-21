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

void motors_initialize()
{
    //Configure left direction pin to act as output
    SYS_PORTS_PinDirectionSelect(PORTS_ID_0, SYS_PORTS_DIRECTION_OUTPUT, PORT_CHANNEL_G, PORTS_BIT_POS_1);
    //Set left direction pin off initially
    SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_1);
    //Configure right direction pin to act as output
    SYS_PORTS_PinDirectionSelect(PORTS_ID_0, SYS_PORTS_DIRECTION_OUTPUT, PORT_CHANNEL_C, PORTS_BIT_POS_14);
    //Set right direction pin off initially
    SYS_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_14);
    
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

void motors_stop()
{
    OC1RS = 0;
    OC2RS = 0;
}

void motors_forward(uint8_t duty_cycle)
{
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_1, false);
    OC1RS = duty_cycle*250;
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_14, false);
    OC2RS = duty_cycle*250;
}

void motors_reverse(uint8_t duty_cycle)
{
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_1, true);
    OC1RS = duty_cycle*250;
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_14, true);
    OC2RS = duty_cycle*250;
}


/* *****************************************************************************
 End of File
 */
