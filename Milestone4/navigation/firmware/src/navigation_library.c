#include "navigation_library.h"

void position_tracker(uint16_t FSRs, Position_Data * pdToCpy) {
    Position_Data pd = *pdToCpy;
    switch (pd.current_position) {
        case bottom_left_corner:
            dbgOutputLoc(LOC_BOTTOM_LEFT_CORNER);
            if (FSRs == 0b1100000011 || FSRs == 0b1100000001 || FSRs == 1000000011)
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
            {
                pd.current_position = off_track;
                pd.prevDbg = bottom_left_corner;
            }
            /*else if (FSRs == 0b0000000001 || FSRs == 0b1000000000)
                pd.current_position = off_outside;
            else if (FSRs == 0b0000000010 || FSRs == 0b0100000000)
                pd.current_position = off_inside;*/
            *pdToCpy = pd;
            break;
        case bottom_left:
            dbgOutputLoc(LOC_BOTTOM_LEFT);
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
                pd.prevDbg = bottom_left;
            }
            /*else if(FSRs == 0b1000000000 || FSRs == 0b1000000010 || FSRs == 0b1000000100)
            {
                pd.current_position = off_outside;
                pd.check = 0;
            }
            else if(FSRs == 0b0100000000 || FSRs == 0b0100000100 || FSRs == 0b0100000010)
            {
                pd.current_position = off_inside;
                pd.check = 0;
            }*/
            *pdToCpy = pd;
            break;
        case true_bottom:
            dbgOutputLoc(LOC_TRUE_BOTTOM);
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
                pd.prevDbg = true_bottom;
            }
            /*else if(FSRs == 0b1000000000 || FSRs == 0b1000000100 || FSRs == 0b1000001000)
            {
                pd.current_position = off_outside;
                pd.check = 0;
            }
            else if(FSRs == 0b0100000000 || FSRs == 0b0100001000 || FSRs == 0b0100000100)
            {
                pd.current_position = off_inside;
                pd.check = 0;
            }*/
            *pdToCpy = pd;
            break;
        case bottom_right:
            dbgOutputLoc(LOC_BOTTOM_RIGHT);
            if (FSRs == 0b1100000100)
                pd.current_position = true_bottom;
            else if (FSRs == 0b1100000000)
                pd.current_position = bottom_right;
            else if (FSRs == 0b1100001000)
                pd.current_position = bottom_right_corner;
            else if (FSRs == 0 || FSRs == 0b0000000100 || FSRs == 0b0000001000)
            {
                pd.current_position = off_track;
                pd.prevDbg = bottom_right;
            }
            /*else if(FSRs == 0b1000000000 || FSRs == 0b1000000100 || FSRs == 0b1000001000)
                pd.current_position = off_outside;
            else if(FSRs == 0b0100000000 || FSRs == 0b0100001000 || FSRs == 0b0100000100)
                pd.current_position = off_inside;*/
            *pdToCpy = pd;
            break;
        case bottom_right_corner:
            dbgOutputLoc(LOC_BOTTOM_RIGHT_CORNER);
            if (FSRs == 0b1100011000 || FSRs == 0b1100010000 || FSRs == 0b1000011000)
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
            {
                pd.current_position = off_track;
                pd.prevDbg = bottom_right_corner;
            }
           /* else if (FSRs == 0b1000000000 || FSRs == 0b0000010000)
                pd.current_position = off_outside;
            else if (FSRs == 0b0100000000 || FSRs == 0b0000001000)
                pd.current_position = off_inside;*/
            *pdToCpy = pd;
            break;
        case right_bottom:
            dbgOutputLoc(LOC_RIGHT_BOTTOM);
            if (FSRs == 0b0010011000)
                pd.current_position = true_right;
            else if (FSRs == 0b0000011000)
                pd.current_position = right_bottom;
            else if (FSRs == 0b0100011000)
                pd.current_position = bottom_right_corner;
            else if (FSRs == 0 || FSRs == 0b0100000000 || FSRs == 0b0010000000)
            {
                pd.current_position = off_track;
                pd.prevDbg = right_bottom;
            }
            /*else if (FSRs == 0b0000001000 || FSRs == 0b0100001000 || FSRs == 0b0010001000)
                pd.current_position = off_inside;
            else if (FSRs == 0b0000010000 || FSRs == 0b0100010000 || FSRs == 0b0010010000)
                pd.current_position = off_outside;*/
            *pdToCpy = pd;
            break;
        case true_right:
            dbgOutputLoc(LOC_TRUE_RIGHT);
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
                pd.prevDbg = true_right;
            }
            /*else if (FSRs == 0b0000001000 || FSRs == 0b0100001000 || FSRs == 0b0010001000)
            {
                pd.current_position = off_inside;
                pd.check = 0;
            }
            else if (FSRs == 0b0000010000 || FSRs == 0b0100010000 || FSRs == 0b0010010000)
            {
                pd.current_position = off_ouside;
                pd.check = 0;
            }*/
            *pdToCpy = pd;
            break;
        case right_top:
            dbgOutputLoc(LOC_RIGHT_TOP);
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
                pd.prevDbg = right_top;
            }
            /*else if (FSRs == 0b0000001000 || FSRs == 0b0001001000 || FSRs == 0b0010001000)
            {
                pd.current_position = off_inside;
                pd.check = 0;
            }
            else if (FSRs == 0b0000010000 || FSRs == 0b0001010000 || FSRs == 0b0010010000)
            {
                pd.current_position = off_ouside;
                pd.check = 0;
            }*/
            *pdToCpy = pd;
            break;
        case top_right_corner:
            dbgOutputLoc(LOC_TOP_RIGHT_CORNER);
            if (FSRs == 0b0001111000 || FSRs == 0b0000111000 || FSRs == 0b0001110000)
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
            {
                pd.current_position = off_track;
                pd.prevDbg = top_right_corner;
            }
            /*else if (FSRs == 0b0000100000 || FSRs == 0b0000010000)
                pd.current_position = off_outside;
            else if (FSRs == 0b0000001000 || FSRs == 0b0001000000)
                pd.current_position = off_inside;*/
            *pdToCpy = pd;
            break;
        case top_right:
            dbgOutputLoc(LOC_TOP_RIGHT);
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
                pd.prevDbg = top_right;
            }
            *pdToCpy = pd;
            break;
        case true_top:
            dbgOutputLoc(LOC_TRUE_TOP);
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
                pd.current_position = top_right_corner;
                pd.check = 0;
            } else if (FSRs == 0 || FSRs == 0b0000000100 || FSRs == 0b0000001000) {
                pd.current_position = off_track;
                pd.check = 0;
                pd.prevDbg = true_top;
            }
            *pdToCpy = pd;
            break;
        case top_left:
            dbgOutputLoc(LOC_TOP_LEFT);
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
                pd.prevDbg = top_left;
            }
            *pdToCpy = pd;
            break;
        case top_left_corner:
            dbgOutputLoc(LOC_TOP_LEFT_CORNER);
            if (FSRs == 0b0001100011 || FSRs == 0b0001100010 || FSRs == 0b0001000011 || FSRs == 0b0000100011 || FSRs == 0b0001100001)
                pd.current_position = top_left_corner;
            else if (FSRs == 0b0001100000)
                pd.current_position = top_left;
            else if (FSRs == 0b0000000011)
                pd.current_position = left_top;
            else if (FSRs == 0 || FSRs == 0b0000000010 || FSRs == 0b0001000000)   
            {
                pd.current_position = off_track;
                pd.prevDbg = top_left_corner;
            }
            *pdToCpy = pd;
            break;
        case left_top:
            dbgOutputLoc(LOC_LEFT_TOP);
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
                pd.prevDbg = left_top;
            }
            *pdToCpy = pd;
            break;
        case true_left:
            dbgOutputLoc(LOC_TRUE_LEFT);
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
                pd.prevDbg = true_left;
            }
            *pdToCpy = pd;
            break;
        case left_bottom:
            dbgOutputLoc(LOC_LEFT_BOTTOM);
            if (FSRs == 0b0010000011)
                pd.current_position = true_left;
            else if (FSRs == 0b0100000011)
                pd.current_position = bottom_left_corner;
            else if (FSRs == 0b0000000011)
                pd.current_position = left_bottom;
            else if (FSRs == 0 || FSRs == 0b0100000000 || FSRs == 0b0010000000)
            {
                pd.current_position = off_track;
                pd.prevDbg = left_bottom;
            }
            *pdToCpy = pd;
            break;
        case off_track:
            dbgOutputLoc(LOC_OFF_TRACK);
            if(FSRs == 0b0000000010 || FSRs == 0b0100000000 || FSRs == 0b0000001000 || FSRs == 0b0001000000 || FSRs == 0b0100000001 || FSRs == 0b0100000010 || FSRs == 0b0100000100 || FSRs == 0b0100001000 || FSRs == 0b0100010000 ||
                    FSRs == 0b1000001000 || FSRs == 0b0100001000 || FSRs == 0b0010001000 || FSRs == 0b0001001000 || FSRs == 0b0000101000 || FSRs == 0b0001010000 || FSRs == 0b0001001000 || FSRs == 0b0001000100 || FSRs == 0b0001000010 || 
                    FSRs == 0b0001000001 || FSRs == 0b0000100010 || FSRs == 0b0001000010 || FSRs == 0b0010000010 || FSRs == 0b0100000010 || FSRs == 0b1000000010)
                pd.current_position = off_inside;
            else if(FSRs == 0b0000000001 || FSRs == 0b1000000000 || FSRs == 0b0000010000 || FSRs == 0b0000100000 || FSRs == 0b1000000001 || FSRs == 0b1000000010 || FSRs == 0b1000000100 || FSRs == 0b1000001000 || FSRs == 0b1000010000 ||
                    FSRs == 0b1000010000 || FSRs == 0b0100010000 || FSRs == 0b0010010000 || FSRs == 0b0001010000 || FSRs == 0b0000110000 || FSRs == 0b0000110000 || FSRs == 0b0000101000 || FSRs == 0b0000100100 || FSRs == 0b0000100010 || 
                    FSRs == 0b0000100001 || FSRs == 0b0000100001 || FSRs == 0b0001000001 || FSRs == 0b0010000001 || FSRs == 0b0100000001 || FSRs == 0b1000000001)
                pd.current_position = off_outside;
            *pdToCpy = pd;
            break;
        case off_inside:
            dbgOutputLoc(LOC_OFF_INSIDE);
            pd.current_position = pd.prevDbg;
            //CALL REORIENT ALGORITHM
            *pdToCpy = pd;
            break;
        case off_outside:
            //CALL REORIENT ALGORITHM
            dbgOutputLoc(LOC_OFF_OUTSIDE);
            pd.current_position = pd.prevDbg;
            *pdToCpy = pd;
            break;
        default:
            dbgOutputLoc(ERROR_DEFAULT_CASE);
            /*
             * Should never go here ideally, but if the FSRs are depressed or 
             * subject to noise in a way that the rover could never press this
             * will be the next state. Will reset to bottom right but only bottom right to signify a reset
             */
            if(FSRs == 0b1100000011)
                pd.current_position = bottom_left_corner;
            *pdToCpy = pd;
            break;
    }
}

void dirTravel(Position_Data * pdToCpy, int nextPos)
{
    Position_Data pd = *pdToCpy;
    if(nextPos == 0) //bottom left corner
        {
            if(pd.current_position < 8 && pd.current_position > 1)
                pd.dir = reverse;
            else if((pd.current_position >= 8 && pd.current_position < 15) || pd.current_position == 0)
                pd.dir = forwards;
            else if(pd.current_position == 15 || pd.current_position == 1)
                pd.dir = stop;
            else {} // ERROR
        }
        else if(nextPos == 1) // bottom
        {
            if(pd.current_position < 10 && pd.current_position > 2)
                pd.dir = reverse;
            else if((pd.current_position >= 10 && pd.current_position <= 15) || pd.current_position < 2)
                pd.dir = forwards;
            else if(pd.current_position == 2)
                pd.dir = stop;
            else {} //ERROR
        }
        else if(nextPos == 2) // bottom right corner
        {
            if(pd.current_position < 12 && pd.current_position > 5)
                pd.dir = reverse;
            else if ((pd.current_position >= 12 && pd.current_position <= 15) || pd.current_position < 3 || pd.current_position == 4)
                pd.dir = forwards;
            else if(pd.current_position == 3 || pd.current_position == 5)
                pd.dir = stop;
            else {} // ERROR
        }
        else if(nextPos == 3) // right
        {
            if(pd.current_position < 14 && pd.current_position > 6)
                pd.dir = reverse;
            else if(pd.current_position == 14 || pd.current_position == 15 || pd.current_position <= 5 )
                pd.dir = forwards;
            else if(pd.current_position == 6)
                pd.dir = stop;
        }
        else if(nextPos == 4) // middle
        {
            // TODO: implement navigate to middle and back
        }
        else if(nextPos == 5) // left
        {
            if(pd.current_position < 6 || pd.current_position == 15)
                pd.dir = reverse;
            else if(pd.current_position >= 6 && pd.current_position < 14)
                pd.dir = forwards;
            else if(pd.current_position == 14)
                pd.dir = stop;
        }
        else if(nextPos == 6) // top left corner
        {
            if(pd.current_position < 4 || pd.current_position > 14 || pd.current_position == 15)
                pd.dir = reverse;
            else if((pd.current_position >= 4 && pd.current_position < 11) || pd.current_position == 12)
                pd.dir = forwards;
            else if(pd.current_position == 11 || pd.current_position == 13)
                pd.dir = stop;
            else {} //ERROR
        }
        else if(nextPos == 7) // top
        {
            if(pd.current_position < 2 || (pd.current_position <= 15 && pd.current_position > 10))
                pd.dir = reverse;
            else if(pd.current_position >= 2 && pd.current_position < 10)
                pd.dir = forwards;
            else if(pd.current_position == 10)
                pd.dir = stop;
            else {} //ERROR
        }
        else if(nextPos == 8) // top right corner
        {
            if(pd.current_position < 7)
                pd.dir = reverse;
            else if((pd.current_position > 9 && pd.current_position <= 15) || pd.current_position == 8)
                pd.dir = forwards;
            else {} //ERROR
        }
    *pdToCpy = pd;
}

void toNextLoc(Position_Data * pdToCpy, int nextPos)
{
    Position_Data pd = *pdToCpy;
    static int initCheck = 1;
    static int firstCorner = 1;
    if(initCheck)
    {
        initCheck = 0; 
        while(pd.current_position != bottom_left_corner) {} //wait for rover to be placed and FSRs to send data
    }
    else
    {
        while(1) {} // Wait for first move location
        dirTravel(&pd, nextPos);
        if(pd.dir == stop)
        {
            // Send stop to rover
            // TODO: Send draw command and wait for ack
            // Send ack to server
        }
        else if(pd.dir == forwards)
        {
            if(pd.current_position == 0 || pd.current_position == 4 || pd.current_position == 8 || pd.current_position == 12)
            {
                if(firstCorner)
                {
                    firstCorner = 0;
                    //Send drive forwards
                }
                else
                {
                    //Send turn 90 degrees left
                }
            }
            else if(pd.current_position <= 15)
            {
                //send drive forwards
            }
        }
        else
        {
            if(pd.current_position == 0 || pd.current_position == 4 || pd.current_position == 8 || pd.current_position == 12)
            {
                firstCorner = 0;
                //Send turn 90 degrees right
            }
            else if(pd.current_position <= 15)
            {
                //send drive forwards
            }
        }
    }
}




