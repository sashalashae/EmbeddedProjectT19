/* 
 * File:   navigation_thread.h
 * Author: Thomas
 *
 * Created on September 18, 2018, 8:31 AM
 */

#ifndef NAVIGATION_THREAD_H
#define	NAVIGATION_THREAD_H

#include <stdint.h>
#include "debug.h"
#include "pdStruct.h"

void position_tracker(uint16_t FSRs, Position_Data pd);

#endif	/* NAVIGATION_THREAD_H */

