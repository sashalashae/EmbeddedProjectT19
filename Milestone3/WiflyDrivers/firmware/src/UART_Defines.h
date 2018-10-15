/* 
 * File:   UART_Defines.h
 * Author: Thomas
 *
 * Created on October 7, 2018, 2:51 PM
 */

#ifndef UART_DEFINES_H
#define	UART_DEFINES_H

#define MAX_MESSAGE_SIZE    256
#define PIC_NUMBER          4

typedef struct{
    uint8_t get; //get (1) or post (0)
    uint16_t count; //length of string
    uint8_t str[MAX_MESSAGE_SIZE];//string
}strStruct;

#endif	/* UART_DEFINES_H */

