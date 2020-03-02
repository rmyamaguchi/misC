/**
 * @file main_dsw.c
 * @author Renan Masashi Yamaguchi
 * @brief Test DigitalStopWatch
 * @version 0.1
 * @date 2020-03-02
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "util.h"
#include "DigitalStopWatch.h"

int main(void)
{
    DigitalStopWatchPtr MyDSW = createWatch();
    stopWatch(MyDSW);

    startWatch(MyDSW);
    startWatch(MyDSW);

    stopWatch(MyDSW);
    stopWatch(MyDSW);

    destroyWatch(MyDSW);

    return 0;
}