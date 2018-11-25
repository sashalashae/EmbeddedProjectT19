/* 
 * File:   pdStruct.h
 * Author: Thomas
 *
 * Created on November 6, 2018, 11:56 PM
 */

#ifndef PDSTRUCT_H
#define	PDSTRUCT_H

// 0 - 15
typedef enum {bottom_left_corner = 0, bottom_left, true_bottom, bottom_right, 
    bottom_right_corner, right_bottom, true_right, right_top, 
    top_right_corner, top_right, true_top, top_left, top_left_corner, 
    left_top, true_left, left_bottom, off_track, off_inside, off_outside} Position;
    
typedef enum {forwards = 0b00000001, reverse = 0b00000010, stop = 0b00000011} Direction;

typedef struct {
    uint8_t current_position;
    Position prevDbg;
    Direction dir;
    uint8_t check;
    char beside[2];
    uint8_t flip;
}Position_Data;

typedef enum
{
    FORWARD_BOTH,
    REVERSE_BOTH,
    TURN_RIGHT,
    TURN_LEFT,
    STOP
} movement_type_t;

typedef enum 
{
    Null = 0,
    ResetArm,
    DrawX,
    DrawO,
    SetServoAngle,
    Calibrate,
    CancelCommand
}ArmCommand;

#endif	/* PDSTRUCT_H */

