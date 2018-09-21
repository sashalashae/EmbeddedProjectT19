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
    
#define BIT15 (1<<15)

void motors_initialize();
void motors_stop();
void motors_forward(uint8_t duty_cycle);
void motors_reverse(uint8_t duty_cycle);

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
