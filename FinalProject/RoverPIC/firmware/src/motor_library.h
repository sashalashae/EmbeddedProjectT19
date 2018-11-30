/* ************************************************************************** */
/** Descriptive File Name

  @Author 
    Sajan Ronvelwala

  @File Name
    motor_library.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _MOTOR_LIBRARY_H    /* Guard against multiple inclusion */
#define _MOTOR_LIBRARY_H

//External Includes
#include "C:\Program Files (x86)\Microchip\xc32\v2.10\pic32mx\include\proc\p32mx795f512l.h"
#include "system_definitions.h"
#include "timers.h"
#include "FreeRTOS.h"

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

#define PORT_ID                     PORTS_ID_0
#define MOTOR_PORT_LEFT             PORT_CHANNEL_G
#define MOTOR_PIN_LEFT              PORTS_BIT_POS_1
#define MOTOR_PORT_RIGHT            PORT_CHANNEL_C
#define MOTOR_PIN_RIGHT             PORTS_BIT_POS_14
    
#define BIT15                       (1<<15)

#define DUTY_CYCLE_COEFFICIENT      250

#define TIMER_100_MS_TRANSITIONS    50
#define ENCODER_PERIOD_MS           100

#define ONE_CM_TRANSITION           75
#define FIVE_DEGREE_TRANSITION      31
#define SQUARE_LENGTH_TRANSITION    889
    
// Enum type to define motor direction
typedef enum direction
{
    FORWARD = false,
    REVERSE = true,
} direction_t;

typedef enum
{
    FORWARD_BOTH,
    REVERSE_BOTH,
    TURN_RIGHT,
    TURN_LEFT,
    RIGHT_FORWARD,
    RIGHT_REVERSE,
    LEFT_FORWARD,
    LEFT_REVERSE,
    STOP
} movement_type_t;

void motors_timer_cb(TimerHandle_t xTimer);
void motors_timer_init();
void motors_initialize();
void motor_left_duty_cycle(uint8_t duty_cycle);
void motor_right_duty_cycle(uint8_t duty_cycle);
void motor_left(direction_t direction, uint8_t duty_cycle);
void motor_right(direction_t direction, uint8_t duty_cycle);
void motors_forward(uint8_t duty_cycle);
void motors_reverse(uint8_t duty_cycle);
void motor_right_stop();
void motor_left_stop();
void motors_stop();
void motors_turn_right(uint8_t duty_cycle);
void motors_turn_left(uint8_t duty_cycle);
void motors_pid_adjust(int32_t left_error, int32_t right_error, int32_t total_left_error, int32_t total_right_error, int32_t derivative_left_error, int32_t derivative_right_error, uint8_t kp, uint8_t ki, uint8_t kd);


    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
