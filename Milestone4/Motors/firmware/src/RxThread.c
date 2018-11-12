/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    rxthread.c

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


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "rxthread.h"

void RXTHREAD_Initialize ( void )
{
    RxISRQueue_Init(MAX_MESSAGE_SIZE);
}


/******************************************************************************
  Function:
    void RXTHREAD_Tasks ( void )

  Remarks:
    See prototype in rxthread.h.
 */

void RXTHREAD_Tasks ( void )
{
    uint8_t currentChar;
    int index;
    char str[32];
    
    while(1)
    {
        MotorQueueData_t msg_to_send;
        //receive first char
        currentChar = RxISRQueue_Receive();
        //wait for open brackets
        while(currentChar != '{')
        {
            currentChar = RxISRQueue_Receive();
        }
        index = 0;
        while(currentChar != '}' && index < 32)
        {
            currentChar = RxISRQueue_Receive();
            str[index] = currentChar;
            index++;
        }
        
        if(str[0] == 'K' && str[1] == 'P' && str[2] == 'K' && str[3] == 'I' && str[4] == 'K' && str[5] == 'D')
        {
            uint16_t kp, ki, kd;
            kp = (str[6] - '0') * 10000;
            kp += (str[7] - '0') * 1000;
            kp += (str[8] - '0') * 100;
            kp += (str[9] - '0') * 10;
            kp += (str[10] - '0');
            ki = (str[11] - '0') * 10000;
            ki += (str[12] - '0') * 1000;
            ki += (str[13] - '0') * 100;
            ki += (str[14] - '0') * 10;
            ki += (str[15] - '0');
            kd = (str[16] - '0') * 10000;
            kd += (str[17] - '0') * 1000;
            kd += (str[18] - '0') * 100;
            kd += (str[19] - '0') * 10;
            kd += (str[20] - '0');
            msg_to_send.type = CALIBRATE;
            msg_to_send.kp = kp;
            msg_to_send.ki = ki;
            msg_to_send.kd = kd;
        }
        else if(str[0] == 'F' && str[1] == 'O' && str[2] == 'R' && str[3] == 'W' && str[4] == 'A' && str[5] == 'R' && str[6] == 'D')
        {   
            uint16_t cm = (str[7] - '0') * 100;
            cm += (str[8] - '0') * 10;
            cm += (str[9] - '0');
            
            msg_to_send.type = MOVEMENT_COMMAND;
            msg_to_send.movement = FORWARD_BOTH;
            msg_to_send.distance = cm * ONE_CM_TRANSITION;
        }
        else if(str[0] == 'R' && str[1] == 'E' && str[2] == 'V' && str[3] == 'E' && str[4] == 'R' && str[5] == 'S' && str[6] == 'E')
        {   
            uint16_t cm = (str[7] - '0') * 100;
            cm += (str[8] - '0') * 10;
            cm += (str[9] - '0');
            
            msg_to_send.type = MOVEMENT_COMMAND;
            msg_to_send.movement = REVERSE_BOTH;
            msg_to_send.distance = cm * ONE_CM_TRANSITION;
        }
        else if(str[0] == 'L' && str[1] == 'E' && str[2] == 'F' && str[3] == 'T')
        {
            uint16_t degrees = (str[4] - '0') * 100;
            degrees += (str[5] - '0') * 10;
            degrees += (str[6] - '0');
            
            msg_to_send.type = MOVEMENT_COMMAND;
            msg_to_send.movement = TURN_LEFT;
            msg_to_send.distance = FIVE_DEGREE_TRANSITION * (degrees/5);
        }
        else if(str[0] == 'R' && str[1] == 'I' && str[2] == 'G' && str[3] == 'H' && str[4] == 'T')
        {
            uint16_t degrees = (str[5] - '0') * 100;
            degrees += (str[6] - '0') * 10;
            degrees += (str[7] - '0');
            
            msg_to_send.type = MOVEMENT_COMMAND;
            msg_to_send.movement = TURN_RIGHT;
            msg_to_send.distance = FIVE_DEGREE_TRANSITION * (degrees/5);
        }
        else if(str[0] == 'S' && str[1] == 'T' && str[2] == 'O' && str[3] == 'P')
        {
            msg_to_send.type = MOVEMENT_COMMAND;
            msg_to_send.movement = STOP;
            msg_to_send.distance = 0;
        }
        else if(str[0] == 'A' && str[1] == 'S' && str[2] == 'Y' && str[3] == 'N' && str[4] == 'C' && str[5] == 'S' && str[6] == 'T' && str[7] == 'O' && str[8] == 'P')
        {
            msg_to_send.type = ASYNC_STOP;
        }
        MotorQueue_SendMsg(msg_to_send);
    }
}

/*******************************************************************************
 End of File
 */
