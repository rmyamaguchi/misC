
#ifndef WATCHSTATE_H
#define WATCHSTATE_H

typedef struct WatchState *WatchStatePtr;

typedef void (*EventStartFunc)(WatchStatePtr);
typedef void (*EventStopFunc)(WatchStatePtr);

struct WatchState
{
    char *name;
    EventStartFunc start;
    EventStopFunc stop;
};

void defaultImplementation(WatchStatePtr state);

#endif