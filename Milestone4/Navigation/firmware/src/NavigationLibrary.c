#include "NavigationLibrary.h"

void position_tracker(uint16_t FSRs, Position_Data * pdToCpy, int nextPos) {
    Position_Data pd = *pdToCpy;
    static int initcheck = 1;
    strStruct currentMsg;
    QueueMsg toMotor;
    QueueMsg toArm;
    QueueMsg motorAck;
    
    
    toMotor.source = NavigationThread;
    toArm.source = NavigationThread;
    
    if(FSRs == 0b1100000011 && initcheck)
    {
        initcheck = 0;
        pd.current_position = bottom_left_corner;
        dirTravel(&pd, nextPos);
    }
    else if(!initcheck)
    {
        dirTravel(&pd, nextPos);
    }
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
                pd.check = 0;
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
            } else if (FSRs == 0b1100000000 && pd.dir == forwards && pd.check == 1) {
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
                pd.check = 0;
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
            {
                pd.current_position = right_bottom; //Left the corner to to top
            }
            else if (FSRs == 0 || FSRs == 0b0100000000 || FSRs == 0b0000001000) //Error handling
            {
                pd.current_position = off_track;
                pd.prevDbg = bottom_right_corner;
                pd.check = 0;
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
                pd.check = 0;
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
                pd.check = 0;
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
            } 
			else if(FSRs == 0b0001101000)
			{
				pd.current_position = top_right_corner;
				pd.check = 0;
			}
			else if (FSRs == 0 || FSRs == 0b0000001000 || FSRs == 0b0000000100) {
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
                pd.check = 0;
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
                pd.check = 0;
            }
            *pdToCpy = pd;
            break;
        case off_track:
            if(pd.dir == forwards)
            {
                toMotor.type = CommandMsg;
                toMotor.val0 = FORWARD_BOTH;
                toMotor.val1 = 75; // 1 cm
                toMotor.val2 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
            }
                //currentMsg = stringToStruct("{\"MoveCmd\":\"DriveForward1\",\"ArmCmd\":\"wait\",\"Beside\":\"9\"}\0", 0);
            else if(pd.dir == reverse)
            {
                toMotor.type = CommandMsg;
                toMotor.val0 = REVERSE_BOTH;
                toMotor.val1 = 75; // 1 cm
                toMotor.val2 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                
                //currentMsg = stringToStruct("{\"MoveCmd\":\"DriveBackward1\",\"ArmCmd\":\"wait\",\"Beside\":\"9\"}\0", 0);
            }
            //TxThreadQueue_Send(currentMsg);
            dbgOutputLoc(LOC_OFF_TRACK);
            if(FSRs == 0b0000000010 || FSRs == 0b0100000000 || FSRs == 0b0000001000 || FSRs == 0b0001000000 || FSRs == 0b0100000001 ||  //These account for every possible resistor combination the rover can touch
                    FSRs == 0b0100000010 || FSRs == 0b0100000100 || FSRs == 0b0100001000 || FSRs == 0b0100010000 ||
                    FSRs == 0b1000001000 || FSRs == 0b0100001000 || FSRs == 0b0010001000 || FSRs == 0b0001001000 || 
                    FSRs == 0b0000101000 || FSRs == 0b0001010000 || FSRs == 0b0001001000 || FSRs == 0b0001000100 || 
                    FSRs == 0b0001000010 || FSRs == 0b0001000001 || FSRs == 0b0000100010 || FSRs == 0b0001000010 || 
                    FSRs == 0b0010000010 || FSRs == 0b0100000010 || FSRs == 0b1000000010)
                pd.current_position = off_inside;
            else if(FSRs == 0b0000000001 || FSRs == 0b1000000000 || FSRs == 0b0000010000 || FSRs == 0b0000100000 || 
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
            toMotor.val2 = 0;
            Queue_Send_FromThread(MotorQueue, toMotor);
            while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                motorAck = Queue_Receive_FromThread(NavQueue);

            if(pd.dir == forwards)
            {
                toMotor.type = CommandMsg;
                toMotor.val0 = REVERSE_BOTH;
                toMotor.val1 = 750; // 10 cm
                toMotor.val2 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                
                toMotor.type = CommandMsg;
                toMotor.val0 = TURN_RIGHT;
                toMotor.val1 = 31; // 5 Degrees
                toMotor.val2 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                //currentMsg = stringToStruct("{\"MoveCmd\":\"stop, DriveBackward10, TurnRight5\",\"ArmCmd\":\"wait\",\"Beside\":\"9\"}\0", 0);
            }
            else if(pd.dir == reverse)
            {
                toMotor.type = CommandMsg;
                toMotor.val0 = FORWARD_BOTH;
                toMotor.val1 = 750; // 10 cm
                toMotor.val2 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                
                toMotor.type = CommandMsg;
                toMotor.val0 = TURN_LEFT;
                toMotor.val1 = 31; // 5 Degrees
                toMotor.val2 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while(motorAck.source == MovementThread && motorAck.type == AckMsg)
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
            toMotor.val2 = 0;
            Queue_Send_FromThread(MotorQueue, toMotor);
            while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                motorAck = Queue_Receive_FromThread(NavQueue);
            
            if(pd.dir == forwards)
            {
                toMotor.type = CommandMsg;
                toMotor.val0 = REVERSE_BOTH;
                toMotor.val1 = 750; // 10 cm
                toMotor.val2 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                
                toMotor.type = CommandMsg;
                toMotor.val0 = TURN_LEFT;
                toMotor.val1 = 31; // 5 Degrees
                toMotor.val2 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                
                //currentMsg = stringToStruct("{\"MoveCmd\":\"stop, DriveBackward10, TurnLeft5\",\"ArmCmd\":\"wait\",\"Beside\":\"9\"}\0", 0);
            }
            else if(pd.dir == reverse)
            {
                toMotor.type = CommandMsg;
                toMotor.val0 = FORWARD_BOTH;
                toMotor.val1 = 750; // 10 cm
                toMotor.val2 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                
                toMotor.type = CommandMsg;
                toMotor.val0 = TURN_RIGHT;
                toMotor.val1 = 31; // 5 Degrees
                toMotor.val2 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while(motorAck.source == MovementThread && motorAck.type == AckMsg)
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
            if(FSRs == 0b1100000011)
                pd.current_position = bottom_left_corner;
            *pdToCpy = pd;
            break;
    }
}

void dirTravel(Position_Data * pdToCpy, int nextPos)
{
    Position_Data pd = *pdToCpy;
    pd.flip = 0;
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
            else if(pd.current_position == 4 && pd.dir == reverse)
            {
                pd.dir = forwards;
                pd.flip = 1;
            }
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
            else {} // ERROR
        }
        else if(nextPos == 4) // middle
        {
            if(pd.current_position == 3 || pd.current_position == 7 || pd.current_position == 11 || pd.current_position == 15)
            {
                pd.dir = stop;
            }
            else if(pd.current_position == 4 && pd.dir == forwards)
            {
                pd.dir = reverse;
                pd.flip = 1;
            }
            else if(pd.current_position == 0 || pd.current_position == 4 || pd.current_position == 8 || pd.current_position == 12)
                pd.dir = reverse;
            else
                pd.dir = forwards;
        }
        else if(nextPos == 5) // left
        {
            if(pd.current_position < 6 || pd.current_position == 15)
                pd.dir = reverse;
            else if(pd.current_position >= 6 && pd.current_position < 14)
                pd.dir = forwards;
            else if(pd.current_position == 14)
                pd.dir = stop;
            else {} // ERROR
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
            if(pd.current_position == 8 && pd.dir == reverse)
            {
                pd.flip = 1;
                pd.dir = forwards;
            }
            else if(pd.current_position < 7 || pd.current_position == 8)
                pd.dir = forwards;
            else if(pd.current_position > 9 && pd.current_position <= 15)
                pd.dir = reverse;
            else if(pd.current_position == 7 || pd.current_position == 9)
                pd.dir = stop;
            else {} //ERROR
        }
        else if(nextPos == 9)
        {
            pd.dir = stop;
        }
    *pdToCpy = pd;
}

void toNextLoc(Position_Data * pdToCpy, int nextPos, uint32_t symbol)
{
    Position_Data pd = *pdToCpy;
    static int initCheck = 1;
    static int firstCorner = 1;
    strStruct currentMsg;
    int draw = 0; // 0 = O; 1 = X;
    static int turnCheck = 1;
    QueueMsg motorAck;
    QueueMsg armAck;
    static int drawcheck0 = 1;
    static int drawcheck1 = 1;
    QueueMsg toMotor;
    QueueMsg toArm;
    
    toMotor.source = NavigationThread;
    toArm.source = NavigationThread;
    
    if(symbol == 'X')
        draw = 1;
    
    if(initCheck && pd.current_position == bottom_left_corner)
    {
        initCheck = 0; 
    }
    else
    {
        if(pd.current_position == bottom_left_corner || pd.current_position == bottom_right_corner || pd.current_position == top_left_corner || pd.current_position == top_right_corner)
        {
            pd.beside[0] = 'Q'; // will never match test
            pd.beside[1] = '\0';
        }
        else if(pd.current_position == bottom_left || pd.current_position == left_bottom)
        {
            pd.beside[0] = '0';
            pd.beside[1] = '\0';
        }
        else if(pd.current_position == true_bottom)
        {
            pd.beside[0] = '1';
            pd.beside[1] = '\0';
        }
        else if(pd.current_position == bottom_right || pd.current_position == right_bottom)
        {
            pd.beside[0] = '2';
            pd.beside[1] = '\0';
        }
        else if(pd.current_position == true_right)
        {
            pd.beside[0] = '3';
            pd.beside[1] = '\0';
        }
        else if(pd.current_position == true_left)
        {
            pd.beside[0] = '5';
            pd.beside[1] = '\0';
        }
        else if(pd.current_position == left_top || pd.current_position == top_left)
        {
            pd.beside[0] = '6';
            pd.beside[1] = '\0';
        }
        else if(pd.current_position == true_top)
        {
            pd.beside[0] = '7';
            pd.beside[1] = '\0';
        }
        else if(pd.current_position == top_right || pd.current_position == right_top)
        {
            pd.beside[0] = '8';
            pd.beside[1] = '\0';
        }
        
        dirTravel(&pd, nextPos);
        
        if(pd.dir == stop)
        {
            if(nextPos == 4 && drawcheck0)
            {
                drawcheck0 = 0;
                drawcheck1 = 1;
                
                toMotor.type = AsyncStopMsg;
                toMotor.val0 = STOP;
                toMotor.val1 = 0;
                toMotor.val2 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);

                toMotor.type = CommandMsg;
                toMotor.val0 = TURN_LEFT;
                toMotor.val1 = 558; // 90 Degrees
                toMotor.val2 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);

                toMotor.type = CommandMsg;
                toMotor.val0 = FORWARD_BOTH;
                toMotor.val1 = 1875; // 25 cm
                toMotor.val2 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                
                if(draw)
                {
                    toArm.type = CommandMsg;
                    toArm.val0 = DrawX;
                    Queue_Send_FromThread(ArmQueue, toArm);
                    while(armAck.source == ArmThread && armAck.type == AckMsg)
                        armAck = Queue_Receive_FromThread(NavQueue);
                }
                else
                {
                    toArm.type = CommandMsg;
                    toArm.val0 = DrawO;
                    Queue_Send_FromThread(ArmQueue, toArm);
                    while(armAck.source == ArmThread && armAck.type == AckMsg)
                        armAck = Queue_Receive_FromThread(NavQueue);
                }                
                
                toMotor.type = CommandMsg;
                toMotor.val0 = REVERSE_BOTH;
                toMotor.val1 = 1875; // 25 cm
                toMotor.val2 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                
                toMotor.type = CommandMsg;
                toMotor.val0 = TURN_RIGHT;
                toMotor.val1 = 558; // 90 Degrees
                toMotor.val2 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                currentMsg = stringToStruct("{\"Source\":\"RoverPIC\",\"Ack\":\"\"}\0", 0);
                TxThreadQueue_Send(currentMsg); //Send Ack
            }
            else if(nextPos == 9)
            {
                //Do nothing
                //currentMsg = stringToStructValue("{\"MoveCmd\":\"stop\",\"ArmCmd\":\"wait\",\"Beside\":\"$\"}\0", 0, pd.beside);
                //TxThreadQueue_Send(currentMsg);
            }
            else if(drawcheck1)
            {
                drawcheck1 = 0;
                drawcheck0 = 1;
                
                toMotor.type = AsyncStopMsg;
                toMotor.val0 = STOP;
                toMotor.val1 = 0;
                toMotor.val2 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                
                if(draw)
                {
                    toArm.type = CommandMsg;
                    toArm.val0 = DrawX;
                    Queue_Send_FromThread(ArmQueue, toArm);
                    while(armAck.source == ArmThread && armAck.type == AckMsg)
                        armAck = Queue_Receive_FromThread(NavQueue);
                    //currentMsg = stringToStructValue("{\"MoveCmd\":\"stop\",\"ArmCmd\":\"drawX\",\"Beside\":\"$\"}\0", 0, pd.beside);
                }
                else
                {
                    toArm.type = CommandMsg;
                    toArm.val0 = DrawO;
                    Queue_Send_FromThread(ArmQueue, toArm);
                    while(armAck.source == ArmThread && armAck.type == AckMsg)
                        armAck = Queue_Receive_FromThread(NavQueue);
                    //currentMsg = stringToStructValue("{\"MoveCmd\":\"stop\",\"ArmCmd\":\"drawO\",\"Beside\":\"$\"}\0", 0, pd.beside);
                }
                
                currentMsg = stringToStruct("{\"Source\":\"RoverPIC\",\"Ack\":\"\"}\0", 0);
                TxThreadQueue_Send(currentMsg); //Send Ack
            }
        }
        else if(pd.dir == forwards)
        {
            drawcheck0 = 1;
            drawcheck1 = 1;
            if(pd.current_position == 0 || pd.current_position == 4 || pd.current_position == 8 || pd.current_position == 12)
            {

                if(firstCorner)
                {
                    firstCorner = 0;
                    turnCheck = 0;
                    
                    toMotor.type = CommandMsg;
                    toMotor.val0 = FORWARD_BOTH;
                    toMotor.val1 = 750; // 10 cm
                    toMotor.val2 = 0;
                    Queue_Send_FromThread(MotorQueue, toMotor);
                    while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                    
                    //currentMsg = stringToStructValue("{\"MoveCmd\":\"DriveForward10\",\"ArmCmd\":\"wait\",\"Beside\":\"$\"}\0", 0, pd.beside);
                    //TxThreadQueue_Send(currentMsg);
                }
                else if(turnCheck)
                {
                    turnCheck = 0;
                    if(pd.flip)
                    {
                        toMotor.type = CommandMsg;
                        toMotor.val0 = FORWARD_BOTH;
                        toMotor.val1 = 750; // 10 cm
                        toMotor.val2 = 0;
                        Queue_Send_FromThread(MotorQueue, toMotor);
                        while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                        motorAck = Queue_Receive_FromThread(NavQueue);
                        
                        //currentMsg = stringToStructValue("{\"MoveCmd\":\"DriveForward10\",\"ArmCmd\":\"wait\",\"Beside\":\"$\"}\0", 0, pd.beside);
                        pd.flip = 0;
                    }
                    else
                    {
                        toMotor.type = AsyncStopMsg;
                        toMotor.val0 = STOP;
                        toMotor.val1 = 0;
                        toMotor.val2 = 0;
                        Queue_Send_FromThread(MotorQueue, toMotor);
                        while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                            motorAck = Queue_Receive_FromThread(NavQueue);
                        
                        toMotor.type = CommandMsg;
                        toMotor.val0 = TURN_LEFT;
                        toMotor.val1 = 558; // 90 Degrees
                        toMotor.val2 = 0;
                        Queue_Send_FromThread(MotorQueue, toMotor);
                        while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                            motorAck = Queue_Receive_FromThread(NavQueue);
                        
                        toMotor.type = CommandMsg;
                        toMotor.val0 = FORWARD_BOTH;
                        toMotor.val1 = 750; // 10 cm
                        toMotor.val2 = 0;
                        Queue_Send_FromThread(MotorQueue, toMotor);
                        while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                            motorAck = Queue_Receive_FromThread(NavQueue);
                        
                        //currentMsg = stringToStructValue("{\"MoveCmd\":\"stop, TurnLeft90, DriveForward10\",\"ArmCmd\":\"wait\",\"Beside\":\"$\"}\0", 0, pd.beside);
                    }
                    //TxThreadQueue_Send(currentMsg);
                }
            }
            else if(pd.current_position <= 15)
            {
                turnCheck = 1;
                currentMsg = stringToStructValue("{\"MoveCmd\":\"DriveForward4\",\"ArmCmd\":\"wait\",\"Beside\":\"$\"}\0", 0, pd.beside);
                
                toMotor.type = CommandMsg;
                toMotor.val0 = FORWARD_BOTH;
                toMotor.val1 = 150; // 2 cm
                toMotor.val2 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                
                //TxThreadQueue_Send(currentMsg);
            }
        }
        else
        {
            drawcheck0 = 1;
            drawcheck1 = 1;
            if(pd.current_position == 0 || pd.current_position == 4 || pd.current_position == 8 || pd.current_position == 12)
            {
                
                if(turnCheck)
                {
                    turnCheck = 0;
                    firstCorner = 0;
                    if(pd.flip)
                    {
                        //currentMsg = stringToStructValue("{\"MoveCmd\":\"DriveBackwards10\",\"ArmCmd\":\"wait\",\"Beside\":\"$\"}\0", 0, pd.beside);
                        toMotor.type = CommandMsg;
                        toMotor.val0 = REVERSE_BOTH;
                        toMotor.val1 = 750; // 10 cm
                        toMotor.val2 = 0;
                        Queue_Send_FromThread(MotorQueue, toMotor);
                        while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                            motorAck = Queue_Receive_FromThread(NavQueue);
                            
                        pd.flip = 0;
                    }
                    else
                    {
                        //currentMsg = stringToStructValue("{\"MoveCmd\":\"stop, TurnRight90, DriveBackward10\",\"ArmCmd\":\"wait\",\"Beside\":\"$\"}\0", 0, pd.beside);
                        toMotor.type = AsyncStopMsg;
                        toMotor.val0 = STOP;
                        toMotor.val1 = 0; // Stop
                        toMotor.val2 = 0;
                        Queue_Send_FromThread(MotorQueue, toMotor);
                        while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                            motorAck = Queue_Receive_FromThread(NavQueue);
                        
                        toMotor.type = CommandMsg;
                        toMotor.val0 = TURN_RIGHT;
                        toMotor.val1 = 558; // 90 Degrees
                        toMotor.val2 = 0;
                        Queue_Send_FromThread(MotorQueue, toMotor);
                        while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                            motorAck = Queue_Receive_FromThread(NavQueue);
                        
                        toMotor.type = CommandMsg;
                        toMotor.val0 = REVERSE_BOTH;
                        toMotor.val1 = 750; // 10 cm
                        toMotor.val2 = 0;
                        Queue_Send_FromThread(MotorQueue, toMotor);
                        while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                            motorAck = Queue_Receive_FromThread(NavQueue);
                        
                    }
                    //TxThreadQueue_Send(currentMsg);   
                }
            }
            else if(pd.current_position <= 15)
            {
                turnCheck = 1;
                //currentMsg = stringToStructValue("{\"MoveCmd\":\"DriveBackwards4\",\"ArmCmd\":\"wait\",\"Beside\":\"$\"}\0", 0, pd.beside);
                toMotor.type = CommandMsg;
                toMotor.val0 = REVERSE_BOTH;
                toMotor.val1 = 150; // 2 cm
                toMotor.val2 = 0;
                Queue_Send_FromThread(MotorQueue, toMotor);
                while(motorAck.source == MovementThread && motorAck.type == AckMsg)
                    motorAck = Queue_Receive_FromThread(NavQueue);
                
                //TxThreadQueue_Send(currentMsg);
            }
        }
    }
}

