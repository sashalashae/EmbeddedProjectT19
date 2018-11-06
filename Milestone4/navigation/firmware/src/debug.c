/*
void dbgOutputLoc(uint32_t outLoc) {
    //If outloc is out of range return
    if (outLoc > 127) {
        //return;
        dbgErrorHandler(ERROR_BOUNDS);
    } else {
        //Write values to rest of pins in output value group (31 - 37)
        //Pin 31 = MSB, Pin 37 = LSB
        PLIB_PORTS_Write(PORTS_ID_0, PORT_CHANNEL_E, outLoc);

        //Toggle pin 30
        //SYS_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_7);
    }
}

void dbgErrorHandler(uint32_t errorCode) {
    //Set LED on
    SYS_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
    //Send location over GPIO
    dbgOutputLoc(errorCode);
    //Stop timer ISR
    //DRV_TMR0_Stop();
    //Suspend threads
    vTaskSuspendAll();
    //Wait forever
    while (1);
}
*/
/*
void navigation_test_bench() {
    Position_Data pd;
    pd.check = 0;
    pd.current_position = bottom_left_corner;
    pd.prevDbg = bottom_left_corner;
    uint16_t FSRs;
    int sTime = 5;
    while (1) {
        pd.dir = forwards;
        FSRs = 0b1100000011;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b1100000010;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b1100000000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b1100000100;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b1100000000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b1100001000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b1100011000; // Bottom Right Corner
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0100011000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0000011000; // Right Bottom
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0010011000; // True Right
        sleep(sTime);
        position_tracker(FSRs, &pd);
        sleep(sTime);
        position_tracker(FSRs, &pd); // Must do twice for True Right into Right Top to iterate past 
        FSRs = 0b0000011000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0001011000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0001111000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0001101000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0001100000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0001100100;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0001100000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0001100010;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0001100011;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0001000011;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0000000011;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0010000011;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0000000011;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0100000011;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b1100000011;
        sleep(sTime);
        position_tracker(FSRs, &pd);

        //Reverse Now
        pd.dir = reverse;
        FSRs = 0b1100000011; // Bottom Left
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0100000011; // Bottom Left
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0000000011; // left bottom
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0010000011; // true left
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0010000011; // true left
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0000000011; // left top
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0001000011; // top left corner
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0001100011; //top left corner
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0001100010; // top left corner
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0001100000; // top left
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0001100100;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0001100000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0001101000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0001111000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0001011000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0000011000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0010011000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0000011000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b0100011000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b1100011000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b1100001000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b1100000000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b1100000100;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b1100000100;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b1100000000;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b1100000010;
        sleep(sTime);
        position_tracker(FSRs, &pd);
        FSRs = 0b1100000011;
        sleep(sTime);
        position_tracker(FSRs, &pd);
    }
}

 */