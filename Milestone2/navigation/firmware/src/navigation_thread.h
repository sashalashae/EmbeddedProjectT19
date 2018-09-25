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

typedef enum {bottom_left_corner, bottom_left, true_bottom, bottom_right, 
    bottom_right_corner, right_bottom, true_right, right_top, 
    top_right_corner, top_right, true_top, top_left, top_left_corner, 
    left_top, true_left, left_bottom, off_track} Position;
    
typedef enum {forwards, reverse, stop} Direction;

typedef struct position_data Position_Data;

struct position_data {
    
    Position current_position;
    
    Direction dir;
    
    int check;
};

int position_tracker(uint16_t FSRs, Position_Data *pd);


#endif	/* NAVIGATION_THREAD_H */

