/* ************************************************************************** */
// Filename:    user_drivers.h 
// Date:        8/30/2018 
// Author:      Alex Nolan
// Description: User defined hardware interfacing functions
/* ************************************************************************** */

#ifndef _USERDRIVERS_H
#define _USERDRIVERS_H

#include "system_config.h"
#include "system_definitions.h"
#include "user_tables.h"

void UARTInitialize();

void UARTWriteByte(uint8_t data);

uint32_t ReadADCData(uint8_t bufNum);
uint16_t FSRsRead();

uint32_t ScaleADCData(uint32_t value, uint16_t tableNum);

#endif