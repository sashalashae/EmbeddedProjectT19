/* ************************************************************************** */
// Filename:    user_drivers.h
// Date:        8/30/2018
// Author:      asha 
// Description: User defined hardware interfacing functions
/* ************************************************************************** */

#ifndef _SENSORDRIVERS_H
#define _SENSORDRIVERS_H

#include "system_config.h"
#include "system_definitions.h"



void UARTInitialize();

void UARTWriteByte(uint8_t data);

uint32_t ReadADCData(uint8_t bufNum);

uint32_t ScaleADCData(uint32_t value);

#endif
