/* 
 * File:   fsr.h
 * Author: SWAT Loaner
 *
 * Created on November 4, 2018, 4:29 PM
 */

#ifndef FSR_H
#define	FSR_H

#include "../src/system_config/default/system_config.h"
#include "../src/system_config/default/system_definitions.h"
#include "debug.h"

#define FSR_THRESHOLD 50

uint32_t FSRsRead(int *array);

#endif	/* FSR_H */

