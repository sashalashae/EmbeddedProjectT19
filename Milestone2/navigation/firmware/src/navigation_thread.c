#include "navigation_thread.h"

void position_tracker(uint16_t FSRs, Position_Data pd) {
    switch (pd.current_position) {
        case bottom_left_corner:
            dbgOutputLoc(DLOC_BOTTOM_LEFT_CORNER);
            if (FSRs == 0b1100000011)
                pd.current_position = bottom_left_corner; //On all 4, absolute corner
            else if (FSRs == 0b1100000010)
                pd.current_position = bottom_left_corner; //Leaving/Coming to/from right
            else if (FSRs == 0b0100000011)
                pd.current_position = bottom_left_corner; //Leaving/Coming to/from top
            else if (FSRs == 0b1100000000)
                pd.current_position = bottom_left; //Post leaving to the right, yet to hit strip 2
            else if (FSRs == 0b0000000011)
                pd.current_position = left_bottom; //Post leaving to the top
            else if (FSRs == 0)
                pd.current_position = off_track; //TODO: GOTO: Error Handling thread
            break;
        case bottom_left:
            dbgOutputLoc(DLOC_BOTTOM_LEFT);
            if (FSRs == 0b1100000100) {
                pd.current_position = bottom_left; //Hit strip 2
                pd.check = 1;
            } else if (FSRs == 0b1100000000 && pd.dir == forwards && pd.check) {
                pd.current_position = true_bottom; //Left the 3rd strip heading right
                pd.check = 0;
            } else if (FSRs == 0b1100000000) {
                pd.current_position = bottom_left; //On bottom left still, if it hit the strip but is not going forwards it is still on bottom left
                pd.check = 0;
            } else if (FSRs == 0b1100000010) {
                pd.current_position = bottom_left_corner; //Has now entered the corner
                pd.check = 0;
            } else if (FSRs == 0 || FSRs == 0b0000000100 || FSRs == 0b0000000010) //Error handling
            {
                pd.current_position = off_track;
                pd.check = 0;
            }
            break;
        case true_bottom:
            dbgOutputLoc(DLOC_TRUE_BOTTOM);
            if (FSRs == 0b1100000000 && pd.dir == reverse && pd.check) //Is back on bottom left
            {
                pd.current_position = bottom_left;
                pd.check = 0;
            } else if (FSRs == 0b1100000000) //Is somewhere on the bottom track right of FSR 2
            {
                pd.current_position = true_bottom;
                pd.check = 0;
            } else if (FSRs == 0b1100000100) //On top of resistor
            {
                pd.current_position = true_bottom;
                pd.check = 1;
            } else if (FSRs == 0b1100001000) //Has hit FSR 3
            {
                pd.current_position = bottom_right_corner;
                pd.check = 0;
            } else if (FSRs == 0 || FSRs == 0b0000000100 || FSRs == 0b0000001000) //Error handling
            {
                pd.current_position = off_track;
                pd.check = 0;
            }
            break;
        case bottom_right:
            dbgOutputLoc(DLOC_BOTTOM_RIGHT);
            if (FSRs == 0b1100000100)
                pd.current_position = true_bottom;
            else if (FSRs == 0b1100000000)
                pd.current_position = bottom_right;
            else if (FSRs == 0b1100001000)
                pd.current_position = bottom_right_corner;
            else if (FSRs == 0 || FSRs == 0b0000000100 || FSRs == 0b0000001000)
                pd.current_position = off_track;
            break;
        case bottom_right_corner:
            dbgOutputLoc(DLOC_BOTTOM_RIGHT_CORNER);
            if (FSRs == 0b1100011000)
                pd.current_position = bottom_right_corner; //On all 4
            else if (FSRs == 0b1100001000)
                pd.current_position = bottom_right_corner; //On bottom left side of corner
            else if (FSRs == 0b0100011000)
                pd.current_position = bottom_right_corner; //On right bottom side of corner
            else if (FSRs == 0b1100000000)
                pd.current_position = bottom_right; //Left the corner to the left
            else if (FSRs == 0b0000011000)
                pd.current_position = right_bottom; //Left the corner to to top
            else if (FSRs == 0 || FSRs == 0b0100000000 || FSRs == 0b0000001000) //Error handling
                pd.current_position = off_track;
            break;
        case right_bottom:
            dbgOutputLoc(DLOC_RIGHT_BOTTOM);
            if (FSRs == 0b0010011000)
                pd.current_position = true_right;
            else if (FSRs == 0b0000011000)
                pd.current_position = right_bottom;
            else if (FSRs == 0b0100011000)
                pd.current_position = bottom_right_corner;
            else if (FSRs == 0 || FSRs == 0b0100000000 || FSRs == 0b0010000000)
                pd.current_position = off_track;
            break;
        case true_right:
            dbgOutputLoc(DLOC_TRUE_RIGHT);
            if (FSRs == 0b0010011000) {
                pd.current_position = true_right;
                pd.check = 1;
            } else if (FSRs == 0b0000011000 && pd.dir == forwards && pd.check) {
                pd.current_position = right_top;
                pd.check = 0;
            } else if (FSRs == 0b0000011000) {
                pd.current_position = true_right;
                pd.check = 0;
            } else if (FSRs == 0b0100011000) {
                pd.current_position = bottom_right_corner;
                pd.check = 0;
            } else if (FSRs == 0 || FSRs == 0b0010000000 || FSRs == 0b0100000000) {
                pd.current_position = off_track;
                pd.check = 0;
            }
            break;
        case right_top:
            dbgOutputLoc(DLOC_RIGHT_TOP);
            if (FSRs == 0b0010011000) {
                pd.current_position = right_top;
                pd.check = 1;
            } else if (FSRs == 0b0000011000 && pd.check == 1 && pd.dir == reverse) {
                pd.current_position = true_right;
                pd.check = 0;
            } else if (FSRs == 0b0000011000) {
                pd.current_position = right_top;
                pd.check = 0;
            } else if (FSRs == 0b0001011000) {
                pd.current_position = top_right_corner;
            } else if (FSRs == 0b0000000000 || FSRs == 0b0010000000 || FSRs == 0b0001000000) {
                pd.current_position = off_track;
                pd.check = 0;
            }
            break;
        case top_right_corner:
            dbgOutputLoc(DLOC_TOP_RIGHT_CORNER);
            if (FSRs == 0b0001111000)
                pd.current_position = top_right_corner;
            else if (FSRs == 0b0001011000)
                pd.current_position = top_right_corner;
            else if (FSRs == 0b0001101000)
                pd.current_position = top_right_corner;
            else if (FSRs == 0b0001100000)
                pd.current_position = top_right;
            else if (FSRs == 0b0000011000)
                pd.current_position = right_top;
            else if (FSRs == 0 || FSRs == 0b0001000000 || FSRs == 0b0000001000)
                pd.current_position = off_track;
            break;
        case top_right:
            dbgOutputLoc(DLOC_TOP_RIGHT);
            if (FSRs == 0b0001100100) {
                pd.current_position = true_top;
                pd.check = 1;
            } else if (FSRs == 0b0001100000 && pd.check == 1 && pd.dir == forwards) {
                pd.current_position = top_left;
                pd.check = 0;
            } else if (FSRs == 0b0001100000) {
                pd.current_position = top_right;
                pd.check = 0;
            } else if (FSRs == 0 || FSRs == 0b0000001000 || FSRs == 0b0000000100) {
                pd.current_position = off_track;
                pd.check = 0;
            }
            break;
        case true_top:
            dbgOutputLoc(DLOC_TRUE_TOP);
            if (FSRs == 0b0001100100) {
                pd.current_position = true_top;
                pd.check = 1;
            } else if (FSRs == 0b0001100000 && pd.check && pd.dir == forwards) {
                pd.current_position = top_left;
                pd.check = 0;
            } else if (FSRs == 0b0001100000) {
                pd.current_position = true_top;
                pd.check = 0;
            } else if (FSRs == 0b0001101000) {
                pd.current_position = top_left_corner;
                pd.check = 0;
            } else if (FSRs == 0 || FSRs == 0b0000000100 || FSRs == 0b0000001000) {
                pd.current_position = off_track;
                pd.check = 0;
            }
            break;
        case top_left:
            dbgOutputLoc(DLOC_TOP_LEFT);
            if (FSRs == 0b0001100100) {
                pd.current_position = top_left;
                pd.check = 1;
            } else if (FSRs == 0b0001100000 && pd.check && pd.dir == reverse) {
                pd.current_position = true_top;
                pd.check = 0;
            } else if (FSRs == 0b0001100000) {
                pd.current_position = top_left;
                pd.check = 0;
            } else if (FSRs == 0b0001100010) {
                pd.current_position = top_left_corner;
                pd.check = 0;
            } else if (FSRs == 0 || FSRs == 0b0000000010 || FSRs == 0b0000000100) {
                pd.current_position = off_track;
                pd.check = 0;
            }
            break;
        case top_left_corner:
            dbgOutputLoc(DLOC_TOP_LEFT_CORNER);
            if (FSRs == 0b0001100011 || FSRs == 0b0001100010 || FSRs == 0b0001000011)
                pd.current_position = top_left_corner;
            else if (FSRs == 0b0001100000)
                pd.current_position = top_left;
            else if (FSRs == 0b0000000011)
                pd.current_position = left_top;
            else if (FSRs == 0 || FSRs == 0b0000000010 || FSRs == 0b0001000000)
                pd.current_position = off_track;
            break;
        case left_top:
            dbgOutputLoc(DLOC_LEFT_TOP);
            if (FSRs == 0b0010000011) {
                pd.current_position = left_top;
                pd.check = 1;
            } else if (FSRs == 0b0000000011 && pd.check && pd.dir == forwards) {
                pd.current_position = true_left;
                pd.check = 0;
            } else if (FSRs == 0b0000000011) {
                pd.current_position = left_top;
                pd.check = 0;
            } else if (FSRs == 0b0001000011) {
                pd.current_position = top_left_corner;
                pd.check = 0;
            } else if (FSRs == 0 || FSRs == 0b0001000000 || FSRs == 0b0010000000) {
                pd.current_position = off_track;
                pd.check = 0;
            }
            break;
        case true_left:
            dbgOutputLoc(DLOC_TRUE_LEFT);
            if (FSRs == 0b0010000011) {
                pd.current_position = true_left;
                pd.check = 1;
            } else if (FSRs == 0b0000000011 && pd.check && pd.dir == reverse) {
                pd.current_position = left_top;
                pd.check = 0;
            } else if (FSRs == 0b0000000011) {
                pd.current_position = true_left;
                pd.check = 0;
            } else if (FSRs == 0b0100000011) {
                pd.current_position = bottom_left_corner;
                pd.check = 0;
            } else if (FSRs == 0 || FSRs == 0b0100000000 || FSRs == 0b0010000000) {
                pd.current_position = off_track;
                pd.check = 0;
            }
            break;
        case left_bottom:
            dbgOutputLoc(DLOC_LEFT_BOTTOM);
            if (FSRs == 0b0010000011)
                pd.current_position = true_left;
            else if (FSRs == 0b0100000011)
                pd.current_position = bottom_left_corner;
            else if (FSRs == 0b0000000011)
                pd.current_position = left_bottom;
            else if (FSRs == 0 || FSRs == 0b0100000000 || FSRs == 0b0010000000)
                pd.current_position = off_track;
            break;
        case off_track:
            dbgOutputLoc(DLOC_OFF_TRACK);
            break;
        default:
            dbgOutputLoc(ERROR_DEFAULT_CASE);
            /*
             * Should never go here ideally, but if the FSRs are depressed or 
             * subject to noise in a way that the rover could never press this
             * will be the next state.
             */
            break;
    }
}




