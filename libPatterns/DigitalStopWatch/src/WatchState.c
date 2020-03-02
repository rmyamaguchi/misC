#include <stdio.h>
#include "WatchState.h"

static void defaultStop(WatchStatePtr state)
{
    printf("\r\nStop event: %s", state->name);
}

static void defaultStart(WatchStatePtr state)
{
    printf("\r\nStart event: %s", state->name);
}

void defaultImplementation(WatchStatePtr state)
{
    state->start = defaultStart;
    state->stop = defaultStop;
}