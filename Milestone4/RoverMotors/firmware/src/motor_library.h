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

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

#define PORT_ID                     PORTS_ID_0
#define MOTOR_PORT_LEFT             PORT_CHANNEL_C
#define MOTOR_PIN_LEFT              PORTS_BIT_POS_14
#define MOTOR_PORT_RIGHT            PORT_CHANNEL_G
#define MOTOR_PIN_RIGHT             PORTS_BIT_POS_1
    
#define BIT15                       (1<<15)

#define DUTY_CYCLE_COEFFICIENT      250
    
// Enum type to define motor direction
typedef enum direction
{
    FORWARD = false,
    REVERSE = true,
} direction_t;
    
void motors_initialize();
void motor_left(direction_t direction, uint8_t duty_cycle);
void motor_right(direction_t direction, uint8_t duty_cycle);
void motors_forward(uint8_t duty_cycle);
void motors_reverse(uint8_t duty_cycle);
void motors_stop();
void motors_turn_right(uint8_t duty_cycle);
void motors_turn_left(uint8_t duty_cycle);

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
