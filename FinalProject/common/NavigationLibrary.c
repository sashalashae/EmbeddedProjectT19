
#include "NavigationLibrary.h"

void Timer_Init()
{
    TimerHandle_t testTimer;
    
    testTimer = xTimerCreate("Timer500ms", pdMS_TO_TICKS(500), pdTRUE, ( void * ) 0, Nav_Timer_Cb);
    
    xTimerStart(testTimer, 0);

}

void Nav_Timer_Cb(TimerHandle_t xTimer)
{   
    strStruct currentMsg;
    
    currentMsg.str[0] = '{';
    currentMsg.str[1] = '\"';
    currentMsg.str[2] = 'S';
    currentMsg.str[3] = 'o';
    currentMsg.str[4] = 'u';
    currentMsg.str[5] = 'r';
    currentMsg.str[6] = 'c';
    currentMsg.str[7] = 'e';
    currentMsg.str[8] = '\"';
    currentMsg.str[9] = ':';
    currentMsg.str[10] = '\"';
    currentMsg.str[11] = 'R';
    currentMsg.str[12] = 'o';
    currentMsg.str[13] = 'v';
    currentMsg.str[14] = 'e'; //"{\"Source\":\"RoverPIC\",\"Ack\":\"\",\"RoverPosition\":\"00\",\"Check\":\"N\"}\0"
    currentMsg.str[15] = 'r';
    currentMsg.str[16] = 'P';
    currentMsg.str[17] = 'I';
    currentMsg.str[18] = 'C';
    currentMsg.str[19] = '\"';
    currentMsg.str[20] = ',';
    currentMsg.str[21] = '\"';
    currentMsg.str[22] = 'A';
    currentMsg.str[23] = 'c';
    currentMsg.str[24] = 'k';
    currentMsg.str[25] = '\"';
    currentMsg.str[26] = ':';
    currentMsg.str[27] = '\"';
    currentMsg.str[28] = '\"';
    currentMsg.str[29] = ',';
    currentMsg.str[30] = '\"';
    currentMsg.str[31] = 'R';
    currentMsg.str[32] = 'o';
    currentMsg.str[33] = 'v';
    currentMsg.str[34] = 'e';
    currentMsg.str[35] = 'r';
    currentMsg.str[36] = 'P';
    currentMsg.str[37] = 'o';
    currentMsg.str[38] = 's';
    currentMsg.str[39] = 'i';
    currentMsg.str[40] = 't';//"{\"Source\":\"RoverPIC\",\"Ack\":\"\",\"RoverPosition\":\"00\",\"Check\":\"N\"}\0"
    currentMsg.str[41] = 'i';
    currentMsg.str[42] = 'o';
    currentMsg.str[43] = 'n';
    currentMsg.str[44] = '\"';
    currentMsg.str[45] = ':';
    currentMsg.str[46] = '\"';
    
    currentMsg.str[47] = (globPos / 10) | 0b110000;
    currentMsg.str[48] = (globPos % 10) | 0b110000;
    
    currentMsg.str[49] = '\"';
    currentMsg.str[50] = ',';
    currentMsg.str[51] = '\"';
    currentMsg.str[52] = 'C';
    currentMsg.str[53] = 'h';
    currentMsg.str[54] = 'e';
    currentMsg.str[55] = 'c';
    currentMsg.str[56] = 'k';
    currentMsg.str[57] = '\"';
    currentMsg.str[58] = ':';
    currentMsg.str[59] = '\"';
    currentMsg.str[60] = 'N';
    currentMsg.str[61] = '\"';
    currentMsg.str[62] = '}';
    currentMsg.str[63] = '\0';
    currentMsg.get = 1;
    currentMsg.count = 63;
    //currentMsg = stringToStruct("{\"Source\":\"RoverPIC\",\"Ack\":\"\",\"RoverPosition\":\"00\",\"Check\":\"N\"}\0", 1);
    TxThreadQueue_Send(currentMsg);
}

void position_tracker(uint16_t FSRs, Position_Data * pdToCpy, int nextPos) {
    Position_Data pd = *pdToCpy;
    static int initcheck = 1;
    strStruct currentMsg;
    QueueMsg toMotor;
    QueueMsg toArm;
    QueueMsg motorAck;
    
    toMotor.val2 = true;
    toMotor.val3 = DUTY_CYCLE;
    
    toMotor.source = NavigationThread;
    toArm.source = NavigationThread;

    if ((FSRs == 0b1100000011 || FSRs == 0b0000000011) && initcheck) {
        initcheck = 0;
        pd.current_position = bottom_left_corner;
        dirTravel(&pd, nextPos);
    } else if (!initcheck) {
        dirTravel(&pd, nextPos);
    }
    switch (pd.current_position) {
        case bottom_left_corner:
            dbgOutputLoc(LOC_BOTTOM_LEFT_CORNER);
            FSRs = FSRs & 0b1100000011;
            if (FSRs == 0b1100000011) { // || FSRs == 0b1100000001 || FSRs == 1000000011 || FSRs == 0b1100000010 || FSRs == 0b0100000011
                pd.current_position = bottom_left_corner; //On corner
                pd.check = 0;
            } else if ((FSRs == 0b0000000010 || FSRs == 0b0000000011 || FSRs == 0b0100000010 || FSRs == 0b1000000010 || FSRs == 0b1000000011 || FSRs == 0b0100000011) && pd.dir == forwards) {
                pd.current_position = bottom_left_corner;
                pd.check = 1;
            } else if ((FSRs == 0b0100000000 || FSRs == 0b1100000000 || FSRs == 0b0100000010 || FSRs == 0b1000000010 || FSRs == 0b1100000010 || FSRs == 0b1100000001) && pd.dir == reverse) {
                pd.current_position = bottom_left_corner;
                pd.check = 2;
            } else if ((FSRs == 0 || FSRs == 0b1000000000 || FSRs == 0b0100000000) && pd.check == 1 && pd.dir == forwards) {
                pd.current_position = bottom_left; //Post leaving to the right, yet to hit strip 2
                pd.check = 0;
            } else if ((FSRs == 0 || FSRs == 0b0000000010 || FSRs == 0b0000000001) && pd.check == 2 && pd.dir == reverse) {
                pd.current_position = left_bottom; //Post leaving to the top
                pd.check = 0;
            }
            /*
            else if (FSRs == 0)
            {
                pd.current_position = off_track;
                pd.prevDbg = bottom_left_corner;
                pd.check = 0;
            }
             */
            *pdToCpy = pd;
            break;
        case bottom_left:
            dbgOutputLoc(LOC_BOTTOM_LEFT);
            FSRs = FSRs & 0b1100000111;
            if (FSRs == 0b0000000100) {
                pd.current_position = bottom_left; //Hit strip 2
                pd.check = 1;
            } else if (FSRs == 0 && pd.dir == forwards && pd.check == 1) {
                pd.current_position = true_bottom; // Going right
                pd.check = 0;
            } else if (FSRs == 0 || FSRs == 0b0000000010) {
                pd.current_position = bottom_left; //Stay on same side
                pd.check = 0;
            } else if (FSRs == 0b0000000011 || FSRs == 0b0000000001) {
                pd.current_position = bottom_left_corner; // Enter corner
                pd.check = 0;
            } else if (FSRs == 0b1000000000 || FSRs == 0b1000000100 || FSRs == 0b1000000010) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = bottom_left;
                pd.check = 0;
                if (FSRs == 0b1000000100)
                    pd.check = 1;
            } else if (FSRs == 0b0100000000 || FSRs == 0b0100000100 || FSRs == 0b0100000010) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = bottom_left;
                pd.check = 0;
                if (FSRs == 0b0100000100)
                    pd.check = 1;
            }
            /*
            else if (FSRs == 0 || FSRs == 0b0000000100 || FSRs == 0b0000000010) //Error handling
            {
                pd.current_position = off_track;
                pd.check = 0;
                pd.prevDbg = bottom_left;
            }
             */
            *pdToCpy = pd;
            break;
        case true_bottom:
            dbgOutputLoc(LOC_TRUE_BOTTOM);
            FSRs = FSRs & 0b1100011100;
            if (FSRs == 0 && pd.dir == reverse && pd.check) //Is back on bottom left
            {
                pd.current_position = bottom_left;
                pd.check = 0;
            } else if (FSRs == 0) //Is somewhere on the bottom track right of FSR 2
            {
                pd.current_position = true_bottom;
                pd.check = 0;
            } else if (FSRs == 0b0000001000) {
                pd.current_position = bottom_right; // just hit 3
                pd.check = 0;
            } else if (FSRs == 0b0000000100) //On top of resistor 2
            {
                pd.current_position = true_bottom;
                pd.check = 1;
            } else if (FSRs == 0b0000011000 || FSRs == 0b0000010000 || FSRs == 0b1000010000 || FSRs == 0b0100010000) //Has hit FSR 4
            {
                pd.current_position = bottom_right_corner;
                pd.check = 0;
            } else if (FSRs == 0b1000000000 || FSRs == 0b1000000100) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = true_bottom;
                pd.check = 0;
                if (FSRs == 0b1000000100)
                    pd.check = 1;
            } else if (FSRs == 0b0100000000 || FSRs == 0b0100000100) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = true_bottom;
                pd.check = 0;
                if (FSRs == 0b0100000100)
                    pd.check = 1;
            } else if (FSRs == 0b1000001000) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = bottom_right;
                pd.check = 0;
            } else if (FSRs == 0b0100001000) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = bottom_right;
                pd.check = 0;
            }
            /*
            else if (FSRs == 0 || FSRs == 0b0000000100 || FSRs == 0b0000001000) //Error handling
            {
                pd.current_position = off_track;
                pd.check = 0;
                pd.prevDbg = true_bottom;
            }
            else if(FSRs == 0b1000000000 || FSRs == 0b1000000100 || FSRs == 0b1000001000)
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
            FSRs = FSRs & 0b1100011100;
            if (FSRs == 0b0000000100) {
                pd.current_position = true_bottom;
                pd.check = 1;
            } else if (FSRs == 0 || FSRs == 0b0000001000) {
                pd.current_position = bottom_right;
                pd.check = 0;
            } else if (FSRs == 0b0000011000 || FSRs == 0b0000010000) {
                pd.current_position = bottom_right_corner;
                pd.check = 0;
            } else if (FSRs == 0b1000000000 || FSRs == 0b1000001000) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = bottom_right;
                pd.check = 0;
            } else if (FSRs == 0b1000000100) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = true_bottom;
                pd.check = 1;
            } else if (FSRs == 0b0100000000 || FSRs == 0b0100001000) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = bottom_right;
                pd.check = 0;
            } else if (FSRs == 0b0100000100) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = true_bottom;
                pd.check = 1;
            } else if (FSRs == 0b1000011000 || FSRs == 0b1000010000) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = bottom_right_corner;
                pd.check = 0;
            } else if (FSRs == 0b0100011000 || FSRs == 0b0100010000) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = bottom_right_corner;
                pd.check = 0;
            }
            /*else if (FSRs == 0 || FSRs == 0b0000000100 || FSRs == 0b0000001000) {
                pd.current_position = off_track;
                pd.prevDbg = bottom_right;
                pd.check = 0;
            }
            else if(FSRs == 0b1000000000 || FSRs == 0b1000000100 || FSRs == 0b1000001000)
                pd.current_position = off_outside;
            else if(FSRs == 0b0100000000 || FSRs == 0b0100001000 || FSRs == 0b0100000100)
                pd.current_position = off_inside;*/
            *pdToCpy = pd;
            break;
        case bottom_right_corner:
            dbgOutputLoc(LOC_BOTTOM_RIGHT_CORNER);
            FSRs = FSRs & 0b1100011000;
            if (FSRs == 0b1100011000) { // || FSRs == 0b1100010000 || FSRs == 0b1000011000 || FSRs == 0b1100001000 || FSRs == 0b0100011000
                pd.current_position = bottom_right_corner; //On all 4
                pd.check = 0;
            } else if ((FSRs == 0b0000001000 || FSRs == 0b0000011000 || FSRs == 0b0100001000 || FSRs == 0b1000001000 || FSRs == 0b0100011000 || FSRs == 0b1000011000) && pd.dir == reverse) {
                pd.current_position = bottom_right_corner; //On bottom left side of corner
                pd.check = 1;
            } else if ((FSRs == 0b0100000000 || FSRs == 0b1100000000 || FSRs == 0b0100010000 || FSRs == 0b0100001000 || FSRs == 0b1100010000 || FSRs == 0b1100001000) && pd.dir == forwards) {
                pd.current_position = bottom_right_corner; //On right bottom side of corner
                pd.check = 2;
            } else if ((FSRs == 0 || FSRs == 0b1000000000 || FSRs == 0b0100000000) && pd.check == 1 && pd.dir == reverse) {
                pd.current_position = bottom_right; //Left the corner to the left
                pd.check = 0;
            } else if ((FSRs == 0 || FSRs == 0b0000001000 || FSRs == 0b0000010000) && pd.check == 2 && pd.dir == forwards) {
                pd.current_position = right_bottom; //Left the corner to to top
                pd.check = 0;
            }
            /*else if (FSRs == 0 || FSRs == 0b0100000000 || FSRs == 0b0000001000) //Error handling
            {
                pd.current_position = off_track;
                pd.prevDbg = bottom_right_corner;
                pd.check = 0;
            }
            else if (FSRs == 0b1000000000 || FSRs == 0b0000010000)
                 pd.current_position = off_outside;
             else if (FSRs == 0b0100000000 || FSRs == 0b0000001000)
                 pd.current_position = off_inside;*/
            *pdToCpy = pd;
            break;
        case right_bottom:
            dbgOutputLoc(LOC_RIGHT_BOTTOM);
            FSRs = FSRs & 0b1110011000;
            if (FSRs == 0b0010000000) {
                pd.current_position = true_right;
                pd.check = 1;
            } else if (FSRs == 0 || FSRs == 0b0100000000) {
                pd.current_position = right_bottom;
                pd.check = 0;
            } else if (FSRs == 0b1100000000 || FSRs == 0b1000000000 || FSRs == 0b1000010000 || FSRs == 0b1000001000) {
                pd.current_position = bottom_right_corner;
                pd.check = 0;
            } else if (FSRs == 0b0000010000 || FSRs == 0b0100010000) {
                if (pd.dir == forwards) {
                   sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = right_bottom;
                pd.check = 0;
            } else if (FSRs == 0b0010010000) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = true_right;
                pd.check = 1;
            } else if (FSRs == 0b0000001000 || FSRs == 0b0100001000) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = right_bottom;
                pd.check = 0;
            } else if (FSRs == 0b0010001000) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = true_right;
                pd.check = 1;
            } else if (FSRs == 0b1100010000) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = bottom_right_corner;
                pd.check = 0;
            } else if (FSRs == 0b1100001000) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = bottom_right_corner;
                pd.check = 0;
            }
            /*else if (FSRs == 0 || FSRs == 0b0100000000 || FSRs == 0b0010000000) {
                pd.current_position = off_track;
                pd.prevDbg = right_bottom;
                pd.check = 0;
            }
            else if (FSRs == 0b0000001000 || FSRs == 0b0100001000 || FSRs == 0b0010001000)
                pd.current_position = off_inside;
            else if (FSRs == 0b0000010000 || FSRs == 0b0100010000 || FSRs == 0b0010010000)
                pd.current_position = off_outside;*/
            *pdToCpy = pd;
            break;
        case true_right:
            dbgOutputLoc(LOC_TRUE_RIGHT);
            FSRs = FSRs & 0b0110011000;
            if (FSRs == 0b0010000000) {
                pd.current_position = true_right;
                pd.check = 1;
            } else if (FSRs == 0 && pd.dir == forwards && pd.check) {
                pd.current_position = right_top;
                pd.check = 0;
            } else if (FSRs == 0) {
                pd.current_position = true_right;
                pd.check = 0;
            } else if (FSRs == 0b0100000000) {
                pd.current_position = right_bottom;
                pd.check = 0;
            }
            else if (FSRs == 0b0000010000 || 0b0010010000) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = true_right;
                pd.check = 0;
                if (FSRs == 0b0010010000)
                    pd.check = 1;
            } else if (FSRs == 0b0100010000) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = right_bottom;
                pd.check = 0;
            } else if (FSRs == 0b0000001000 || 0b0010001000) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = true_right;
                pd.check = 0;
                if (FSRs == 0b0010001000)
                    pd.check = 1;
            } else if (FSRs == 0b0100001000) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = right_bottom;
                pd.check = 0;
            }
            /*else if (FSRs == 0 || FSRs == 0b0010000000 || FSRs == 0b0100000000) {
                pd.current_position = off_track;
                pd.check = 0;
                pd.prevDbg = true_right;
            }
            else if (FSRs == 0b0000001000 || FSRs == 0b0100001000 || FSRs == 0b0010001000)
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
            FSRs = FSRs & 0b0011111000;
            if (FSRs == 0b0010000000) {
                pd.current_position = right_top;
                pd.check = 1;
            } else if (FSRs == 0 && pd.check == 1 && pd.dir == reverse) {
                pd.current_position = true_right;
                pd.check = 0;
            } else if (FSRs == 0 || FSRs == 0b0001000000) {
                pd.current_position = right_top;
                pd.check = 0;
            } else if (FSRs == 0b0001100000 || FSRs == 0b0000100000) {
                pd.current_position = top_right_corner;
                pd.check = 0;
            }
            else if (FSRs == 0b0000010000 || FSRs == 0b0010010000 || FSRs == 0b0001010000) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = right_top;
                pd.check = 0;
                if (FSRs == 0b0010010000)
                    pd.check = 1;
            } else if (FSRs == 0b0000001000 || FSRs == 0b0010001000 || FSRs == 0b0001001000) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = right_top;
                pd.check = 0;
                if (FSRs == 0b0010001000)
                    pd.check = 1;
            }
            /*else if (FSRs == 0b0000000000 || FSRs == 0b0010000000 || FSRs == 0b0001000000) {
                pd.current_position = off_track;
                pd.check = 0;
                pd.prevDbg = right_top;
            }
            else if (FSRs == 0b0000001000 || FSRs == 0b0001001000 || FSRs == 0b0010001000)
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
            FSRs = FSRs & 0b0001111000;
            if (FSRs == 0b0001111000) { // || FSRs == 0b0000111000 || FSRs == 0b0001110000 || FSRs == 0b0001011000 || 0b0001101000
                pd.current_position = top_right_corner;
                pd.check = 0;
            } else if ((FSRs == 0b0001000000 || FSRs == 0b0001100000 || FSRs == 0b0001001000 || FSRs == 0b0001010000 || FSRs == 0b0001110000 || FSRs == 0b0001101000) && pd.dir == reverse) {
                pd.current_position = top_right_corner;
                pd.check = 1;
            } else if ((FSRs == 0b0000001000 || FSRs == 0b0000011000 || FSRs == 0b0000101000 || FSRs == 0b0001001000 || FSRs == 0b0001011000|| FSRs == 0b0000111000) && pd.dir == forwards) {
                pd.current_position = top_right_corner;
                pd.check = 2;
            } else if ((FSRs == 0 || FSRs == 0b0001000000 || FSRs == 0b0000100000) && pd.check == 2 && pd.dir == forwards) {
                pd.current_position = top_right;
                pd.check = 0;
            } else if ((FSRs == 0 || FSRs == 0b0000010000 || FSRs == 0b0000001000) && pd.check == 1 && pd.dir == reverse) {
                pd.current_position = right_top;
                pd.check = 0;
            }
            /*else if (FSRs == 0 || FSRs == 0b0001000000 || FSRs == 0b0000001000) {
                pd.current_position = off_track;
                pd.prevDbg = top_right_corner;
                pd.check = 0;
            }
            else if (FSRs == 0b0000100000 || FSRs == 0b0000010000)
                pd.current_position = off_outside;
            else if (FSRs == 0b0000001000 || FSRs == 0b0001000000)
                pd.current_position = off_inside;*/
            *pdToCpy = pd;
            break;
        case top_right:
            dbgOutputLoc(LOC_TOP_RIGHT);
            FSRs = FSRs & 0b0001111100;
            if (FSRs == 0b0000000100) {
                pd.current_position = true_top;
                pd.check = 1;
            } else if (FSRs == 0 && pd.check == 1 && pd.dir == forwards) {
                pd.current_position = top_left;
                pd.check = 0;
            } else if (FSRs == 0) {
                pd.current_position = top_right;
                pd.check = 0;
            } else if (FSRs == 0b0000011000 || FSRs == 0b0000010000) {
                pd.current_position = top_right_corner;
                pd.check = 0;
            }
            else if (FSRs == 0b0000100000 || FSRs == 0b0000101000) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = top_right;
                pd.check = 0;
            } else if (FSRs == 0b0000100100) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = true_top;
                pd.check = 1;
            } else if (FSRs == 0b0001000000 || FSRs == 0b0001001000) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = top_right;
                pd.check = 0;
            } else if (FSRs == 0b0001000100) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = true_top;
                pd.check = 1;
            }
            /*else if (FSRs == 0 || FSRs == 0b0000001000 || FSRs == 0b0000000100) {
                pd.current_position = off_track;
                pd.check = 0;
                pd.prevDbg = top_right;
            }*/
            *pdToCpy = pd;
            break;
        case true_top:
            dbgOutputLoc(LOC_TRUE_TOP);
            FSRs = FSRs & 0b0001111100;
            if (FSRs == 0b0000000100) {
                pd.current_position = true_top;
                pd.check = 1;
            } else if (FSRs == 0 && pd.check && pd.dir == forwards) {
                pd.current_position = top_left;
                pd.check = 0;
            } else if (FSRs == 0) {
                pd.current_position = true_top;
                pd.check = 0;
            } else if (FSRs == 0b0000001000) {
                pd.current_position = top_right;
                pd.check = 0;
            } else if (FSRs == 0b0000011000 || FSRs == 0b0000010000 || FSRs == 0b0000110000 || FSRs == 0b0001010000) {
                pd.current_position = top_right_corner;
                pd.check = 0;
            } else if (FSRs == 0b0000100000 || FSRs == 0b0000100100) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = true_top;
                pd.check = 0;
                if (FSRs == 0b0000100100)
                    pd.check = 1;
            } else if (FSRs == 0b0000101000) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = top_right;
                pd.check = 0;
            } else if (FSRs == 0b0001000000 || FSRs == 0b0001000100) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = true_top;
                pd.check = 0;
                if (FSRs == 0b0001000100)
                    pd.check = 1;
            } else if (FSRs == 0b0001001000) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = top_right;
                pd.check = 0;
            }
            /*else if (FSRs == 0 || FSRs == 0b0000000100 || FSRs == 0b0000001000) {
                pd.current_position = off_track;
                pd.check = 0;
                pd.prevDbg = true_top;
            }*/
            *pdToCpy = pd;
            break;
        case top_left:
            dbgOutputLoc(LOC_TOP_LEFT);
            FSRs = FSRs & 0b0001100111;
            if (FSRs == 0b0000000100) {
                pd.current_position = top_left;
                pd.check = 1;
            } else if (FSRs == 0 && pd.check && pd.dir == reverse) {
                pd.current_position = true_top;
                pd.check = 0;
            } else if (FSRs == 0 || FSRs == 0b0000000010) {
                pd.current_position = top_left;
                pd.check = 0;
            } else if (FSRs == 0b0000000011 || FSRs == 0b0000000001) {
                pd.current_position = top_left_corner;
                pd.check = 0;
            }
            else if (FSRs == 0b0000100000 || FSRs == 0b0000100100 || FSRs == 0b0000100010) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position == top_left;
                pd.check = 0;
                if (FSRs == 0b0000100100)
                    pd.check = 1;
            } else if (FSRs == 0b0001000000 || FSRs == 0b0001000100 || FSRs == 0b0001000010) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position == top_left;
                pd.check = 0;
                if (FSRs == 0b0001000100)
                    pd.check = 1;
            }
            /*else if (FSRs == 0 || FSRs == 0b0000000010 || FSRs == 0b0000000100) {
                pd.current_position = off_track;
                pd.check = 0;
                pd.prevDbg = top_left;
            }*/
            *pdToCpy = pd;
            break;
        case top_left_corner:
            dbgOutputLoc(LOC_TOP_LEFT_CORNER);
            FSRs = FSRs & 0b00011000011;
            if (FSRs == 0b0001100011) { // || FSRs == 0b0001100010 || FSRs == 0b0001000011 || FSRs == 0b0000100011 || FSRs == 0b0001100001
                pd.current_position = top_left_corner;
                pd.check = 0;
            } else if ((FSRs == 0b0001000000 || FSRs == 0b0001100000 || FSRs == 0b0001000010 || FSRs == 0b0001000001 || FSRs == 0b0001100010 || FSRs == 0b0001100001) && pd.dir == forwards) {
                pd.current_position = top_left_corner;
                pd.check = 1;
            } else if ((FSRs == 0b0000000010 || FSRs == 0b0000000011 || FSRs == 0b0001000010 || FSRs == 0b0000100010 || FSRs == 0b0001000011 || FSRs == 0b0000100011) && pd.dir == reverse) {
                pd.current_position = top_left_corner;
                pd.check = 2;
            } else if ((FSRs == 0 || FSRs == 0b0000000010 || FSRs == 0b0000000001) && pd.check == 1 && pd.dir == forwards) {
                pd.current_position = left_top;
                pd.check = 0;
            } else if ((FSRs == 0 || FSRs == 0b0001000000 || FSRs == 0b0000100000) && pd.check == 2 && pd.dir == reverse) {
                pd.current_position = top_left;
                pd.check = 0;
            }
            /*else if (FSRs == 0 || FSRs == 0b0000000010 || FSRs == 0b0001000000) {
                pd.current_position = off_track;
                pd.prevDbg = top_left_corner;
                pd.check = 0;
            }*/
            *pdToCpy = pd;
            break;
        case left_top:
            dbgOutputLoc(LOC_LEFT_TOP);
            FSRs = FSRs & 0b0011100011;
            if (FSRs == 0b0010000000) {
                pd.current_position = left_top;
                pd.check = 1;
            } else if (FSRs == 0 && pd.check && pd.dir == forwards) {
                pd.current_position = true_left;
                pd.check = 0;
            } else if (FSRs == 0 || FSRs == 0b0001000000) {
                pd.current_position = left_top;
                pd.check = 0;
            } else if (FSRs == 0b0001100000) {
                pd.current_position = top_left_corner;
                pd.check = 0;
            }
            else if (FSRs == 0b0000000001 || FSRs == 0b0010000001 || FSRs == 0b0001000001) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = left_top;
                pd.check = 0;
                if (FSRs == 0b0010000001)
                    pd.check = 1;
            } else if (FSRs == 0b0000000010 || FSRs == 0b0010000010 || FSRs == 0b0001000010) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = left_top;
                pd.check = 0;
                if (FSRs == 0b0010000010)
                    pd.check = 1;
            }
            /*else if (FSRs == 0 || FSRs == 0b0001000000 || FSRs == 0b0010000000) {
                pd.current_position = off_track;
                pd.check = 0;
                pd.prevDbg = left_top;
            }*/
            *pdToCpy = pd;
            break;
        case true_left:
            dbgOutputLoc(LOC_TRUE_LEFT);
            FSRs = FSRs & 0b1110000011;
            if (FSRs == 0b0010000000) {
                pd.current_position = true_left;
                pd.check = 1;
            } else if (FSRs == 0 && pd.check && pd.dir == reverse) {
                pd.current_position = left_top;
                pd.check = 0;
            } else if (FSRs == 0) {
                pd.current_position = true_left;
                pd.check = 0;
            } else if (FSRs == 0b1100000000 || FSRs == 0b1000000000 || FSRs == 0b1000000001 || FSRs == 0b1000000010) {
                pd.current_position = bottom_left_corner;
                pd.check = 0;
            }
            else if (FSRs == 0b0000000001 || FSRs == 0b0010000001) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = true_left;
                pd.check = 0;
                if (FSRs == 0b0010000001)
                    pd.check = 1;
            } else if (FSRs == 0b0100000001) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = left_bottom;
                pd.check = 0;
            } else if (FSRs == 0b0000000010 || FSRs == 0b0010000010) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = true_left;
                pd.check = 0;
                if (FSRs == 0b0010000010)
                    pd.check = 1;
            } else if (FSRs == 0b0100000010) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = left_bottom;
                pd.check = 0;
            }
            /*else if (FSRs == 0 || FSRs == 0b0100000000 || FSRs == 0b0010000000) {
                pd.current_position = off_track;
                pd.check = 0;
                pd.prevDbg = true_left;
            }*/
            *pdToCpy = pd;
            break;
        case left_bottom:
            dbgOutputLoc(LOC_LEFT_BOTTOM);
            FSRs = FSRs & 0b1110000011;
            if (FSRs == 0b0010000000) {
                pd.current_position = true_left;
                pd.check = 1;
            } else if (FSRs == 0b1100000000 || FSRs == 0b1000000000) {
                pd.current_position = bottom_left_corner;
                pd.check = 0;
            } else if (FSRs == 0) {
                pd.current_position = left_bottom;
                pd.check = 0;
            } else if (FSRs == 0b0000000001 || FSRs == 0b0100000001) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = left_bottom;
                pd.check = 0;
            } else if (FSRs == 0b0010000001) {
                if (pd.dir == forwards) {
                    sendTurnRight();
                } else if (pd.dir == reverse) {
                    sendTurnLeft();
                }
                pd.current_position = true_left;
                pd.check = 1;
            } else if (FSRs == 0b0000000010 || FSRs == 0b0100000010) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = left_bottom;
                pd.check = 0;
            } else if (FSRs == 0b0010000010) {
                if (pd.dir == forwards) {
                    sendTurnLeft();
                } else if (pd.dir == reverse) {
                    sendTurnRight();
                }
                pd.current_position = true_left;
                pd.check = 1;
            }
            /*else if (FSRs == 0 || FSRs == 0b0100000000 || FSRs == 0b0010000000) {
                pd.current_position = off_track;
                pd.prevDbg = left_bottom;
                pd.check = 0;
            }*/
            *pdToCpy = pd;
            break;
        case off_track:
            if (pd.dir == forwards) {
                toMotor.type = CommandMsg;
                toMotor.val0 = FORWARD_BOTH;
                toMotor.val1 = SHORT; // 1 cm
                
                Queue_Send_FromThread(MotorQueue, toMotor);
                while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
            }//currentMsg = stringToStruct("{\"MoveCmd\":\"DriveForward1\",\"ArmCmd\":\"wait\",\"Beside\":\"9\"}\0", 0);
            else if (pd.dir == reverse) {
                toMotor.type = CommandMsg;
                toMotor.val0 = REVERSE_BOTH;
                toMotor.val1 = 75;
                
                Queue_Send_FromThread(MotorQueue, toMotor);
                while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);

                //currentMsg = stringToStruct("{\"MoveCmd\":\"DriveBackward1\",\"ArmCmd\":\"wait\",\"Beside\":\"9\"}\0", 0);
            }
            //TxThreadQueue_Send(currentMsg);
            dbgOutputLoc(LOC_OFF_TRACK);
            if (FSRs == 0b0000000010 || FSRs == 0b0100000000 || FSRs == 0b0000001000 || FSRs == 0b0001000000 || FSRs == 0b0100000001 || //These account for every possible resistor combination the rover can touch
                    FSRs == 0b0100000010 || FSRs == 0b0100000100 || FSRs == 0b0100001000 || FSRs == 0b0100010000 ||
                    FSRs == 0b1000001000 || FSRs == 0b0100001000 || FSRs == 0b0010001000 || FSRs == 0b0001001000 ||
                    FSRs == 0b0000101000 || FSRs == 0b0001010000 || FSRs == 0b0001001000 || FSRs == 0b0001000100 ||
                    FSRs == 0b0001000010 || FSRs == 0b0001000001 || FSRs == 0b0000100010 || FSRs == 0b0001000010 ||
                    FSRs == 0b0010000010 || FSRs == 0b0100000010 || FSRs == 0b1000000010)
                pd.current_position = off_inside;
            else if (FSRs == 0b0000000001 || FSRs == 0b1000000000 || FSRs == 0b0000010000 || FSRs == 0b0000100000 ||
                    FSRs == 0b1000000001 || FSRs == 0b1000000010 || FSRs == 0b1000000100 || FSRs == 0b1000001000 ||
                    FSRs == 0b1000010000 || FSRs == 0b1000010000 || FSRs == 0b0100010000 || FSRs == 0b0010010000 ||
                    FSRs == 0b0001010000 || FSRs == 0b0000110000 || FSRs == 0b0000101000 ||
                    FSRs == 0b0000100100 || FSRs == 0b0000100010 || FSRs == 0b0000100001 || FSRs == 0b0000100001 ||
                    FSRs == 0b0001000001 || FSRs == 0b0010000001 || FSRs == 0b0100000001 || FSRs == 0b1000000001)
                pd.current_position = off_outside;
            *pdToCpy = pd;
            break;
        case off_inside:
            dbgOutputLoc(LOC_OFF_INSIDE);

            toMotor.type = AsyncStopMsg;
            toMotor.val0 = STOP;
            toMotor.val1 = 0;
            
            Queue_Send_FromThread(MotorQueue, toMotor);
            while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                motorAck = Queue_Receive_FromThread(NavQueue);

            if (pd.dir == forwards) {
                toMotor.type = CommandMsg;
                toMotor.val0 = REVERSE_BOTH;
                toMotor.val1 = FROM_CORNER; // 10 cm
                
                Queue_Send_FromThread(MotorQueue, toMotor);
                while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);

                toMotor.type = CommandMsg;
                toMotor.val0 = TURN_RIGHT;
                toMotor.val1 = 31; // 5 Degrees
                
                Queue_Send_FromThread(MotorQueue, toMotor);
                while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                //currentMsg = stringToStruct("{\"MoveCmd\":\"stop, DriveBackward10, TurnRight5\",\"ArmCmd\":\"wait\",\"Beside\":\"9\"}\0", 0);
            } else if (pd.dir == reverse) {
                toMotor.type = CommandMsg;
                toMotor.val0 = FORWARD_BOTH;
                toMotor.val1 = FROM_CORNER; // 10 cm
                
                Queue_Send_FromThread(MotorQueue, toMotor);
                while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);

                toMotor.type = CommandMsg;
                toMotor.val0 = TURN_LEFT;
                toMotor.val1 = 31; // 5 Degrees
                
                Queue_Send_FromThread(MotorQueue, toMotor);
                while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                //currentMsg = stringToStruct("{\"MoveCmd\":\"stop, DriveForward10, TurnLeft5\",\"ArmCmd\":\"wait\",\"Beside\":\"9\"}\0", 0);
            }
            //TxThreadQueue_Send(currentMsg);
            pd.check = 0;
            pd.current_position = pd.prevDbg;
            *pdToCpy = pd;
            break;
        case off_outside:
            dbgOutputLoc(LOC_OFF_OUTSIDE);

            toMotor.type = AsyncStopMsg;
            toMotor.val0 = STOP;
            toMotor.val1 = 0;
            
            Queue_Send_FromThread(MotorQueue, toMotor);
            while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                motorAck = Queue_Receive_FromThread(NavQueue);

            if (pd.dir == forwards) {
                toMotor.type = CommandMsg;
                toMotor.val0 = REVERSE_BOTH;
                toMotor.val1 = FROM_CORNER; // 10 cm
                
                Queue_Send_FromThread(MotorQueue, toMotor);
                while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);

                toMotor.type = CommandMsg;
                toMotor.val0 = TURN_LEFT;
                toMotor.val1 = 31; // 5 Degrees
                
                Queue_Send_FromThread(MotorQueue, toMotor);
                while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);

                //currentMsg = stringToStruct("{\"MoveCmd\":\"stop, DriveBackward10, TurnLeft5\",\"ArmCmd\":\"wait\",\"Beside\":\"9\"}\0", 0);
            } else if (pd.dir == reverse) {
                toMotor.type = CommandMsg;
                toMotor.val0 = FORWARD_BOTH;
                toMotor.val1 = FROM_CORNER; // 10 cm
                
                Queue_Send_FromThread(MotorQueue, toMotor);
                while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);

                toMotor.type = CommandMsg;
                toMotor.val0 = TURN_RIGHT;
                toMotor.val1 = 31; // 5 Degrees
                
                Queue_Send_FromThread(MotorQueue, toMotor);
                while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);

                //currentMsg = stringToStruct("{\"MoveCmd\":\"stop, DriveForward10, TurnRight5\",\"ArmCmd\":\"wait\",\"Beside\":\"9\"}\0", 0);
            }
            TxThreadQueue_Send(currentMsg);
            pd.check = 0;
            pd.current_position = pd.prevDbg;
            *pdToCpy = pd;
            break;
        default:
            dbgOutputLoc(ERROR_DEFAULT_CASE);
            /*
             * Should never go here ideally, but if the FSRs are depressed or 
             * subject to noise in a way that the rover could never press
             * this will be the next state. Will be allowed to reset to bottom 
             * left but only bottom left.
             */
            if (FSRs == 0b1100000011)
                pd.current_position = bottom_left_corner;
            *pdToCpy = pd;
            break;
    }
}

void dirTravel(Position_Data * pdToCpy, int nextPos) {
    Position_Data pd = *pdToCpy;
    pd.flip = 0;
    if (nextPos == 0) //bottom left corner
    {
        if (pd.current_position < 8 && pd.current_position > 1)
            pd.dir = reverse;
        else if ((pd.current_position >= 8 && pd.current_position < 15) || pd.current_position == 0)
            pd.dir = forwards;
        else if (pd.current_position == 15 || pd.current_position == 1)
            pd.dir = stop;
        else {
        } // ERROR
    } else if (nextPos == 1) // bottom
    {
        if (pd.current_position < 10 && pd.current_position > 2)
            pd.dir = reverse;
        else if ((pd.current_position >= 10 && pd.current_position <= 15) || pd.current_position < 2)
            pd.dir = forwards;
        else if (pd.current_position == 2)
            pd.dir = stop;
        else {
        } //ERROR
    } else if (nextPos == 2) // bottom right corner
    {
        if (pd.current_position < 12 && pd.current_position > 5)
            pd.dir = reverse;
        else if (pd.current_position == 4 && pd.dir == reverse) {
            pd.dir = forwards;
            pd.flip = 1;
        } else if ((pd.current_position >= 12 && pd.current_position <= 15) || pd.current_position < 3 || pd.current_position == 4)
            pd.dir = forwards;
        else if (pd.current_position == 3 || pd.current_position == 5)
            pd.dir = stop;
        else {
        } // ERROR
    } else if (nextPos == 3) // right
    {
        if (pd.current_position < 14 && pd.current_position > 6)
            pd.dir = reverse;
        else if (pd.current_position == 14 || pd.current_position == 15 || pd.current_position <= 5)
            pd.dir = forwards;
        else if (pd.current_position == 6)
            pd.dir = stop;
        else {
        } // ERROR
    } else if (nextPos == 4) // middle
    {
        if (pd.current_position == 3 || pd.current_position == 7 || pd.current_position == 11 || pd.current_position == 15) {
            pd.dir = stop;
        } else if (pd.current_position == 4 && pd.dir == forwards) {
            pd.dir = reverse;
            pd.flip = 1;
        } else if (pd.current_position == 0 || pd.current_position == 4 || pd.current_position == 8 || pd.current_position == 12)
            pd.dir = reverse;
        else
            pd.dir = forwards;
    } else if (nextPos == 5) // left
    {
        if (pd.current_position < 6 || pd.current_position == 15)
            pd.dir = reverse;
        else if (pd.current_position >= 6 && pd.current_position < 14)
            pd.dir = forwards;
        else if (pd.current_position == 14)
            pd.dir = stop;
        else {
        } // ERROR
    } else if (nextPos == 6) // top left corner
    {
        if (pd.current_position < 4 || pd.current_position > 14 || pd.current_position == 15)
            pd.dir = reverse;
        else if ((pd.current_position >= 4 && pd.current_position < 11) || pd.current_position == 12)
            pd.dir = forwards;
        else if (pd.current_position == 11 || pd.current_position == 13)
            pd.dir = stop;
        else {
        } //ERROR
    } else if (nextPos == 7) // top
    {
        if (pd.current_position < 2 || (pd.current_position <= 15 && pd.current_position > 10))
            pd.dir = reverse;
        else if (pd.current_position >= 2 && pd.current_position < 10)
            pd.dir = forwards;
        else if (pd.current_position == 10)
            pd.dir = stop;
        else {
        } //ERROR
    } else if (nextPos == 8) // top right corner
    {
        if (pd.current_position == 8 && pd.dir == reverse) {
            pd.flip = 1;
            pd.dir = forwards;
        } else if (pd.current_position < 7 || pd.current_position == 8)
            pd.dir = forwards;
        else if (pd.current_position > 9 && pd.current_position <= 15)
            pd.dir = reverse;
        else if (pd.current_position == 7 || pd.current_position == 9)
            pd.dir = stop;
        else {
        } //ERROR
    } else if (nextPos == 9) {
        pd.dir = stop;
    }
    *pdToCpy = pd;
}

void toNextLoc(Position_Data * pdToCpy, int nextPos, uint32_t symbol, uint16_t FSRs) {
    Position_Data pd = *pdToCpy;
    globPos = pd.current_position;
    static int initCheck = 1;
    static int firstCorner = 1;
    strStruct currentMsg;
    int draw = 0; // 0 = O; 1 = X;
    static int turnCheck = 1;
    QueueMsg motorAck;
    QueueMsg armAck;
    static int drawcheck0 = 1;
    QueueMsg toMotor;
    QueueMsg toArm;
    toMotor.val2 = true;
    toMotor.val3 = DUTY_CYCLE;
    static int prevPos;
    static int checkDisplacement = 0;
    
    toMotor.source = NavigationThread;
    toArm.source = NavigationThread;

    if (symbol == 'X')
        draw = 1;
    
    if(prevPos != nextPos)
        drawcheck0 = 1;
    prevPos = nextPos;
    

    if (initCheck && pd.current_position == bottom_left_corner) {
        initCheck = 0;
    } else {
        Direction prevDir = pd.dir;
        dirTravel(&pd, nextPos);
        
        if(nextPos == 2 && pd.dir == forwards && pd.current_position == true_bottom)
        {
            toMotor.type = AsyncStopMsg;
            toMotor.val0 = STOP;
            toMotor.val1 = 0;

            Queue_Send_FromThread(MotorQueue, toMotor);
            while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                motorAck = Queue_Receive_FromThread(NavQueue);

            motorAck.type = UnknownMsg;
            motorAck.source = UnknownThread;
                
            toMotor.type = CommandMsg;
            toMotor.val0 = FORWARD_BOTH;
            if(checkDisplacement)
                toMotor.val1 = 900;
            else            
                toMotor.val1 = 1125; // 15 cm

            Queue_Send_FromThread(MotorQueue, toMotor);
            while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                motorAck = Queue_Receive_FromThread(NavQueue);

            motorAck.type = UnknownMsg;
            motorAck.source = UnknownThread;
            
            pd.dir = stop;
            pd.current_position = bottom_right;
            *pdToCpy = pd;
        }
        else if(nextPos == 0 && pd.dir == forwards && pd.current_position == true_left)
        {
            toMotor.type = AsyncStopMsg;
            toMotor.val0 = STOP;
            toMotor.val1 = 0;

            Queue_Send_FromThread(MotorQueue, toMotor);
            while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                motorAck = Queue_Receive_FromThread(NavQueue);

            motorAck.type = UnknownMsg;
            motorAck.source = UnknownThread;
                
            toMotor.type = CommandMsg;
            toMotor.val0 = FORWARD_BOTH;
            if(checkDisplacement)
                toMotor.val1 = 900;
            else            
                toMotor.val1 = 1125; // 15 cm

            Queue_Send_FromThread(MotorQueue, toMotor);
            while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                motorAck = Queue_Receive_FromThread(NavQueue);

            motorAck.type = UnknownMsg;
            motorAck.source = UnknownThread;
            
            pd.dir = stop;
            pd.current_position = left_bottom;
            *pdToCpy = pd;
        }
        else if(nextPos == 8 && pd.dir == reverse && pd.current_position == true_top)
        {
            toMotor.type = AsyncStopMsg;
            toMotor.val0 = STOP;
            toMotor.val1 = 0;

            Queue_Send_FromThread(MotorQueue, toMotor);
            while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                motorAck = Queue_Receive_FromThread(NavQueue);

            motorAck.type = UnknownMsg;
            motorAck.source = UnknownThread;
                
            toMotor.type = CommandMsg;
            toMotor.val0 = REVERSE_BOTH;
            if(checkDisplacement)
                toMotor.val1 = 900;
            else            
                toMotor.val1 = 1125; // 15 cm

            Queue_Send_FromThread(MotorQueue, toMotor);
            while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                motorAck = Queue_Receive_FromThread(NavQueue);

            motorAck.type = UnknownMsg;
            motorAck.source = UnknownThread;
            
            pd.dir = stop;
            pd.current_position = top_right;
            *pdToCpy = pd;
        }
        else if(nextPos == 2 && pd.dir == reverse && pd.current_position == true_right)
        {
            toMotor.type = AsyncStopMsg;
            toMotor.val0 = STOP;
            toMotor.val1 = 0;

            Queue_Send_FromThread(MotorQueue, toMotor);
            while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                motorAck = Queue_Receive_FromThread(NavQueue);

            motorAck.type = UnknownMsg;
            motorAck.source = UnknownThread;
                
            toMotor.type = CommandMsg;
            toMotor.val0 = REVERSE_BOTH;
            if(checkDisplacement)
                toMotor.val1 = 900;
            else            
                toMotor.val1 = 1125; // 15 cm

            Queue_Send_FromThread(MotorQueue, toMotor);
            while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                motorAck = Queue_Receive_FromThread(NavQueue);

            motorAck.type = UnknownMsg;
            motorAck.source = UnknownThread;
            
            pd.dir = stop;
            pd.current_position = right_bottom;
            *pdToCpy = pd;
        }
        else if(pd.dir == forwards && ((nextPos == 1 && pd.current_position == bottom_left && (FSRs == 0b0000000100 || FSRs == 0b1000000100 || FSRs == 0b0100000100)) 
                || (nextPos == 8 && pd.current_position == true_right && (FSRs == 0b0010000000 || FSRs == 0b0010001000 || FSRs == 0b0010010000)) 
                || (nextPos == 6 && pd.current_position == true_top && (FSRs == 0b0000000100 || FSRs == 0b0000100100 || FSRs == 0b0001000100)) 
                || (nextPos == 5 && pd.current_position == left_top && (FSRs == 0b0010000000 || FSRs == 0b0010000001 || FSRs == 0b0010000010))))
        {
            checkDisplacement = 1;
            
            toMotor.type = AsyncStopMsg;
            toMotor.val0 = STOP;
            toMotor.val1 = 0;

            Queue_Send_FromThread(MotorQueue, toMotor);
            while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                motorAck = Queue_Receive_FromThread(NavQueue);

            motorAck.type = UnknownMsg;
            motorAck.source = UnknownThread;
            
            toMotor.type = CommandMsg;
            toMotor.val0 = FORWARD_BOTH;
            toMotor.val1 = FROM_INTERMEDIATE_FSR; // 9 cm

            Queue_Send_FromThread(MotorQueue, toMotor);
            while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                motorAck = Queue_Receive_FromThread(NavQueue);

            motorAck.type = UnknownMsg;
            motorAck.source = UnknownThread;
            
            if(nextPos == 1)
            {
                pd.current_position = true_bottom;
            }
            else if(nextPos == 8)
            {
                pd.current_position = right_top;
            }
            else if(nextPos == 6)
            {
                pd.current_position = top_left;
            }
            else if(nextPos == 5)
            {
                pd.current_position = true_left;
            }
            pd.dir = stop;
            *pdToCpy = pd;
        }
        else if(pd.dir == reverse && ((nextPos == 6 && pd.current_position == true_left && (FSRs == 0b0010000000 || FSRs == 0b0010000001 || FSRs == 0b0010000010)) 
                || (nextPos == 7 && pd.current_position == top_left && (FSRs == 0b0000000100 || FSRs == 0b0000100100 || FSRs == 0b0001000100)) 
                || (nextPos == 3 && pd.current_position == right_top && (FSRs == 0b0010000000 || FSRs == 0b0010001000 || FSRs == 0b0010010000)) 
                || (nextPos == 0 && pd.current_position == true_bottom && (FSRs == 0b0000000100 || FSRs == 0b1000000100 || FSRs == 0b0100000100))))
        {
            checkDisplacement = 1;
            
            toMotor.type = AsyncStopMsg;
            toMotor.val0 = STOP;
            toMotor.val1 = 0;

            Queue_Send_FromThread(MotorQueue, toMotor);
            while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                motorAck = Queue_Receive_FromThread(NavQueue);

            motorAck.type = UnknownMsg;
            motorAck.source = UnknownThread;
            
            toMotor.type = CommandMsg;
            toMotor.val0 = REVERSE_BOTH;
            toMotor.val1 = FROM_INTERMEDIATE_FSR; // 9 cm

            Queue_Send_FromThread(MotorQueue, toMotor);
            while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                motorAck = Queue_Receive_FromThread(NavQueue);

            motorAck.type = UnknownMsg;
            motorAck.source = UnknownThread;
            
            if(nextPos == 6)
            {
                pd.current_position = left_top;
            }
            else if(nextPos == 7)
            {
                pd.current_position = true_top;
            }
            else if(nextPos == 3)
            {
                pd.current_position = true_right;
            }
            else if(nextPos == 0)
            {
                pd.current_position = left_bottom;
            }
            pd.dir = stop;
            *pdToCpy = pd;
        }
        if (pd.dir == stop) {
            if (nextPos == 4 && drawcheck0) {
                drawcheck0 = 0;

                toMotor.type = AsyncStopMsg;
                toMotor.val0 = STOP;
                toMotor.val1 = 0;
                
                Queue_Send_FromThread(MotorQueue, toMotor);
                while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                
                motorAck.type = UnknownMsg;
                motorAck.source = UnknownThread;

                toMotor.type = CommandMsg;
                toMotor.val0 = TURN_LEFT;
                toMotor.val1 = TURN_LEFT_NORMAL; // 90 Degrees
                
                Queue_Send_FromThread(MotorQueue, toMotor);
                while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                
                motorAck.type = UnknownMsg;
                motorAck.source = UnknownThread;

                toMotor.type = CommandMsg;
                toMotor.val0 = FORWARD_BOTH;
                toMotor.val1 = 1875; // 25 cm
                
                Queue_Send_FromThread(MotorQueue, toMotor);
                while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                
                motorAck.type = UnknownMsg;
                motorAck.source = UnknownThread;

                if (draw) {
                    toArm.type = CommandMsg;
                    toArm.val0 = DrawX;
                    Queue_Send_FromThread(ArmQueue, toArm);
                    while (armAck.source != ArmThread && armAck.type != AckMsg)
                        armAck = Queue_Receive_FromThread(NavQueue);
                    armAck.type = UnknownMsg;
                    armAck.source = UnknownThread;
                } else {
                    toArm.type = CommandMsg;
                    toArm.val0 = DrawO;
                    Queue_Send_FromThread(ArmQueue, toArm);
                    while (armAck.source != ArmThread && armAck.type != AckMsg)
                        armAck = Queue_Receive_FromThread(NavQueue);
                    
                    armAck.type = UnknownMsg;
                    armAck.source = UnknownThread;
                }

                toMotor.type = CommandMsg;
                toMotor.val0 = REVERSE_BOTH;
                toMotor.val1 = 1875; // 25 cm
                
                Queue_Send_FromThread(MotorQueue, toMotor);
                while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                
                motorAck.type = UnknownMsg;
                motorAck.source = UnknownThread;

                toMotor.type = CommandMsg;
                toMotor.val0 = TURN_RIGHT;
                toMotor.val1 = TURN_RIGHT_NORMAL; // 90 Degrees
                
                Queue_Send_FromThread(MotorQueue, toMotor);
                while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                
                motorAck.type = UnknownMsg;
                motorAck.source = UnknownThread;
                
                
                QueueMsg checkQ;
                checkQ.val2 = 0;
                checkQ = Queue_Receive_FromThread(NavQueue);
                
                while(checkQ.val2 != 'P')
                {
                    currentMsg = stringToStruct("{\"Source\":\"RoverPIC\",\"Ack\":\"1\",\"RoverPosition\":\"00\"}\0", 0);
                    TxThreadQueue_Send(currentMsg); //Send Ack
                    checkQ = Queue_Receive_FromThread(NavQueue);
                }
                
            } else if (nextPos == 9) {
                //Do nothing
                //currentMsg = stringToStructValue("{\"MoveCmd\":\"stop\",\"ArmCmd\":\"wait\",\"Beside\":\"$\"}\0", 0, pd.beside);
                //TxThreadQueue_Send(currentMsg);
            } else if (drawcheck0) {
                drawcheck0 = 0;

                toMotor.type = AsyncStopMsg;
                toMotor.val0 = STOP;
                toMotor.val1 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                
                motorAck.type = UnknownMsg;
                motorAck.source = UnknownThread;

                if(prevDir == forwards && (pd.current_position == true_right || pd.current_position == true_top))
                {
                    toMotor.type = CommandMsg;
                    toMotor.val0 = REVERSE_BOTH;
                    toMotor.val1 = 225; // 2 cm

                    Queue_Send_FromThread(MotorQueue, toMotor);
                    while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                        motorAck = Queue_Receive_FromThread(NavQueue);

                    motorAck.type = UnknownMsg;
                    motorAck.source = UnknownThread;
                }
                if(prevDir == reverse && (pd.current_position == true_left || pd.current_position == true_bottom))
                {
                    toMotor.type = CommandMsg;
                    toMotor.val0 = FORWARD_BOTH;
                    toMotor.val1 = 225; // 3 cm

                    Queue_Send_FromThread(MotorQueue, toMotor);
                    while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                        motorAck = Queue_Receive_FromThread(NavQueue);

                    motorAck.type = UnknownMsg;
                    motorAck.source = UnknownThread;
                }
                
                if (draw) {
                    toArm.type = CommandMsg;
                    toArm.val0 = DrawX;
                    Queue_Send_FromThread(ArmQueue, toArm);
                    while (armAck.source != ArmThread && armAck.type != AckMsg)
                        armAck = Queue_Receive_FromThread(NavQueue);
                    
                    armAck.type = UnknownMsg;
                    armAck.source = UnknownThread;
                    //currentMsg = stringToStructValue("{\"MoveCmd\":\"stop\",\"ArmCmd\":\"drawX\",\"Beside\":\"$\"}\0", 0, pd.beside);
                } else {
                    toArm.type = CommandMsg;
                    toArm.val0 = DrawO;
                    Queue_Send_FromThread(ArmQueue, toArm);
                    while (armAck.source != ArmThread && armAck.type != AckMsg)
                        armAck = Queue_Receive_FromThread(NavQueue);
                    
                    armAck.type = UnknownMsg;
                    armAck.source = UnknownThread;
                    //currentMsg = stringToStructValue("{\"MoveCmd\":\"stop\",\"ArmCmd\":\"drawO\",\"Beside\":\"$\"}\0", 0, pd.beside);
                }

                QueueMsg checkQ;
                checkQ.val2 = 0;
                checkQ = Queue_Receive_FromThread(NavQueue);
                
                while(checkQ.val2 != 'P')
                {
                    currentMsg = stringToStruct("{\"Source\":\"RoverPIC\",\"Ack\":\"1\",\"RoverPosition\":\"00\"}\0", 0);
                    TxThreadQueue_Send(currentMsg); //Send Ack
                    checkQ = Queue_Receive_FromThread(NavQueue);
                }
                
                //volatile int x = 1;
            }
        } else if (pd.dir == forwards) {
            drawcheck0 = 1;
            checkDisplacement = 0;
            if (pd.current_position == 0 || pd.current_position == 4 || pd.current_position == 8 || pd.current_position == 12) {

                if (firstCorner) {
                    firstCorner = 0;
                    turnCheck = 0;

                    toMotor.type = CommandMsg;
                    toMotor.val0 = FORWARD_BOTH;
                    toMotor.val1 = FROM_CORNER; // 10 cm
                    
                    Queue_Send_FromThread(MotorQueue, toMotor);
                    
                    while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                        motorAck = Queue_Receive_FromThread(NavQueue);

                    motorAck.type = UnknownMsg;
                    motorAck.source = UnknownThread;

                    //currentMsg = stringToStructValue("{\"MoveCmd\":\"DriveForward10\",\"ArmCmd\":\"wait\",\"Beside\":\"$\"}\0", 0, pd.beside);
                    //TxThreadQueue_Send(currentMsg);
                } else if (turnCheck) {
                    turnCheck = 0;
                    if (pd.flip) {
                        toMotor.type = CommandMsg;
                        toMotor.val0 = FORWARD_BOTH;
                        toMotor.val1 = FROM_CORNER; // 10 cm
                        
                        Queue_Send_FromThread(MotorQueue, toMotor);
                        
                        while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                            motorAck = Queue_Receive_FromThread(NavQueue);
                        
                        motorAck.type = UnknownMsg;
                        motorAck.source = UnknownThread;

                        //currentMsg = stringToStructValue("{\"MoveCmd\":\"DriveForward10\",\"ArmCmd\":\"wait\",\"Beside\":\"$\"}\0", 0, pd.beside);
                        pd.flip = 0;
                    } else {
                        toMotor.type = AsyncStopMsg;
                        toMotor.val0 = STOP;
                        toMotor.val1 = 0;
                        
                        Queue_Send_FromThread(MotorQueue, toMotor);
                        while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                            motorAck = Queue_Receive_FromThread(NavQueue);
                        
                        motorAck.type = UnknownMsg;
                        motorAck.source = UnknownThread;

                        toMotor.type = CommandMsg;
                        toMotor.val0 = TURN_LEFT;
                        toMotor.val1 = TURN_LEFT_NORMAL; // 90 Degrees
                        
                        Queue_Send_FromThread(MotorQueue, toMotor);
                        while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                            motorAck = Queue_Receive_FromThread(NavQueue);
                        
                        motorAck.type = UnknownMsg;
                        motorAck.source = UnknownThread;

                        toMotor.type = CommandMsg;
                        toMotor.val0 = FORWARD_BOTH;
                        toMotor.val1 = FROM_CORNER; // 10 cm
                        
                        Queue_Send_FromThread(MotorQueue, toMotor);

                        while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                            motorAck = Queue_Receive_FromThread(NavQueue);
                        
                        motorAck.type = UnknownMsg;
                        motorAck.source = UnknownThread;
                        //currentMsg = stringToStructValue("{\"MoveCmd\":\"stop, TurnLeft90, DriveForward10\",\"ArmCmd\":\"wait\",\"Beside\":\"$\"}\0", 0, pd.beside);
                    }
                    //TxThreadQueue_Send(currentMsg);
                }
            } else if (pd.current_position <= 15) {
                turnCheck = 1;
                //currentMsg = stringToStructValue("{\"MoveCmd\":\"DriveForward4\",\"ArmCmd\":\"wait\",\"Beside\":\"$\"}\0", 0, pd.beside);

                toMotor.type = CommandMsg;
                toMotor.val0 = FORWARD_BOTH;
                toMotor.val1 = SHORT; // 1 cm
                
                Queue_Send_FromThread(MotorQueue, toMotor);

                //TxThreadQueue_Send(currentMsg);
            }
        } else {
            drawcheck0 = 1;
            checkDisplacement = 0;
            if (pd.current_position == 0 || pd.current_position == 4 || pd.current_position == 8 || pd.current_position == 12) {

                if (turnCheck) {
                    turnCheck = 0;
                    firstCorner = 0;
                    if (pd.flip) {
                        //currentMsg = stringToStructValue("{\"MoveCmd\":\"DriveBackwards10\",\"ArmCmd\":\"wait\",\"Beside\":\"$\"}\0", 0, pd.beside);
                        toMotor.type = CommandMsg;
                        toMotor.val0 = REVERSE_BOTH;
                        toMotor.val1 = FROM_CORNER; // 10 cm
                        
                        Queue_Send_FromThread(MotorQueue, toMotor);
                        
                        while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                            motorAck = Queue_Receive_FromThread(NavQueue);
                        
                        motorAck.type = UnknownMsg;
                        motorAck.source = UnknownThread;

                        pd.flip = 0;
                    } else {
                        //currentMsg = stringToStructValue("{\"MoveCmd\":\"stop, TurnRight90, DriveBackward10\",\"ArmCmd\":\"wait\",\"Beside\":\"$\"}\0", 0, pd.beside);
                        toMotor.type = AsyncStopMsg;
                        toMotor.val0 = STOP;
                        toMotor.val1 = 0; // Stop
                        
                        Queue_Send_FromThread(MotorQueue, toMotor);
                        while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                            motorAck = Queue_Receive_FromThread(NavQueue);
                        
                        motorAck.type = UnknownMsg;
                        motorAck.source = UnknownThread;

                        toMotor.type = CommandMsg;
                        toMotor.val0 = TURN_RIGHT;
                        toMotor.val1 = TURN_RIGHT_NORMAL; // 90 Degrees
                        
                        Queue_Send_FromThread(MotorQueue, toMotor);
                        while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                            motorAck = Queue_Receive_FromThread(NavQueue);
                        
                        motorAck.type = UnknownMsg;
                        motorAck.source = UnknownThread;

                        toMotor.type = CommandMsg;
                        toMotor.val0 = REVERSE_BOTH;
                        toMotor.val1 = FROM_CORNER; // 10 cm
                        
                        Queue_Send_FromThread(MotorQueue, toMotor);
                        
                        while (motorAck.source != MovementThread && motorAck.type != AckMsg)
                            motorAck = Queue_Receive_FromThread(NavQueue);
                        
                        motorAck.type = UnknownMsg;
                        motorAck.source = UnknownThread;
                    }
                    //TxThreadQueue_Send(currentMsg);   
                }
            } else if (pd.current_position <= 15) {
                turnCheck = 1;
                //currentMsg = stringToStructValue("{\"MoveCmd\":\"DriveBackwards4\",\"ArmCmd\":\"wait\",\"Beside\":\"$\"}\0", 0, pd.beside);
                toMotor.type = CommandMsg;
                toMotor.val0 = REVERSE_BOTH;
                toMotor.val1 = SHORT; // 1 cm
                
                Queue_Send_FromThread(MotorQueue, toMotor);

                //TxThreadQueue_Send(currentMsg);
            }
        }
    }
}

void sendTurnLeft()
{
    QueueMsg toMotor;
    QueueMsg motorAck;

    toMotor.val2 = true;
    toMotor.val3 = DUTY_CYCLE;
    
    toMotor.type = AsyncStopMsg;
    toMotor.val0 = STOP;
    toMotor.val1 = 0;

    Queue_Send_FromThread(MotorQueue, toMotor);
    while (motorAck.source != MovementThread && motorAck.type != AckMsg)
        motorAck = Queue_Receive_FromThread(NavQueue);
    
    motorAck.type = UnknownMsg;
    motorAck.source = UnknownThread;
    
    toMotor.type = CommandMsg;
    toMotor.val0 = TURN_LEFT;
    toMotor.val1 = ERR_TURN_LEFT; // 5 Degrees
    
    Queue_Send_FromThread(MotorQueue, toMotor);
    while (motorAck.source != MovementThread && motorAck.type != AckMsg)
    {
        motorAck = Queue_Receive_FromThread(NavQueue);
    }
    motorAck.type = UnknownMsg;
    motorAck.source = UnknownThread;
}

void sendTurnRight()
{
    QueueMsg toMotor;
    QueueMsg motorAck;

    toMotor.val2 = true;
    toMotor.val3 = DUTY_CYCLE;
    
    toMotor.type = AsyncStopMsg;
    toMotor.val0 = STOP;
    toMotor.val1 = 0;

    Queue_Send_FromThread(MotorQueue, toMotor);
    while (motorAck.source != MovementThread && motorAck.type != AckMsg)
        motorAck = Queue_Receive_FromThread(NavQueue);
    
    motorAck.type = UnknownMsg;
    motorAck.source = UnknownThread;
    
    toMotor.type = CommandMsg;
    toMotor.val0 = TURN_RIGHT;
    toMotor.val1 = ERR_TURN_RIGHT; // 5 Degrees
    
    Queue_Send_FromThread(MotorQueue, toMotor);
    while (motorAck.source != MovementThread && motorAck.type != AckMsg)
    {
        motorAck = Queue_Receive_FromThread(NavQueue);
    }
    motorAck.type = UnknownMsg;
    motorAck.source = UnknownThread;
}