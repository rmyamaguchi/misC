
#include "StoppedState.h"

/* Possible transition to */
#include "StartedState.h"

static void startWatch(WatchStatePtr state)
{
    transitionToStarted(state);
}

void transitionToStopped(WatchStatePtr state)
{
    defaultImplementation(state);
    state->name = "Stopped";
    state->start = startWatch;
}

#ifdef _X
static void X_startWatch(DigitalStopWatchPtr context)
{
    X_changeState(context, X_transitionToStarted());
}
#endif