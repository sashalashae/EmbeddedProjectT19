/* 
 * File:   pdStruct.h
 * Author: Thomas
 *
 * Created on September 25, 2018, 9:41 AM
 */

#ifndef PDSTRUCT_H
#define	PDSTRUCT_H


// 0 - 15
typedef enum {bottom_left_corner = 0, bottom_left, true_bottom, bottom_right, 
    bottom_right_corner, right_bottom, true_right, right_top, 
    top_right_corner, top_right, true_top, top_left, top_left_corner, 
    left_top, true_left, left_bottom, off_track, off_inside, off_outside} Position;
    
typedef enum {forwards, reverse, stop} Direction;

typedef struct {
    Position current_position;
    Position prevDbg;
    Direction dir;
    int check;
}Position_Data;

#endif	/* PDSTRUCT_H */

