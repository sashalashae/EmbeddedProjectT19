#include "sleep.h"

void sleep(int16_t milliseconds)
{
    dbgOutputLoc(DLOC_SLEEP_START);
    //return if the sleep is too short
    if(milliseconds < portTICK_PERIOD_MS)
    {
        return;
    }
    vTaskDelay(milliseconds/portTICK_PERIOD_MS);
    dbgOutputLoc(DLOC_SLEEP_END);
}
