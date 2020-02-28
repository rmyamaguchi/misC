
#include "WatchState.h"

static void defaultStop(WatchStatePtr state)
{
    printf("Stop event: %s", state->name);
}

static void defaultStart(WatchStatePtr state)
{
    printf("Start event: %s", state->name);
}

void defaultImplementation(WatchStatePtr state)
{
    state->start = defaultStart;
    state->stop = defaultStop;
}