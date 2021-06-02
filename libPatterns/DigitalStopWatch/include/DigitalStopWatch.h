
#ifndef DSW_H
#define DSW_H

#include "WatchState.h"

typedef struct DigitalStopWatch *DigitalStopWatchPtr;

DigitalStopWatchPtr createWatch(void);
void destroyWatch(DigitalStopWatchPtr instance);
void startWatch(DigitalStopWatchPtr instance);
void stopWatch(DigitalStopWatchPtr instance);

#ifdef _X
void X_changeState(DigitalStopWatchPtr instance, WatchStatePtr newState);
#endif

#endif