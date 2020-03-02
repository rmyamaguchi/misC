
#include "StartedState.h"

/* Possible transition to */
#include "StoppedState.h"

static void stopWatch(WatchStatePtr state)
{
    transitionToStopped(state);
}

void transitionToStarted(WatchStatePtr state)
{
    defaultImplementation(state);
    state->name = "Started";
    state->stop = stopWatch;
}

#ifdef _X
WatchStatePtr X_transitionToStarted(void)
{
    static struct WatchState startedState;
    static int initialized = 0;

    if (0 == initialized)
    {
        defaultImplementation(&startedState);
        startedState.stop = stopWatch;
        initialized = 1;
    }
    return &startedState;
}
#endif