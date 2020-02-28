
#include <stdlib.h>
#include "DigitalStopWatch.h"

struct DigitalStopWatch
{
    struct WatchState state;
    // TimeSource source;
    // Display watchDisplay;
};

DigitalStopWatchPtr createWatch(void)
{
    DigitalStopWatchPtr instance = malloc(sizeof(*instance));

    if (NULL != instance)
    {
        transitionToStopped(&instance->state);
        /* Initialize things */
    }
    return instance;
}

void destroyWatch(DigitalStopWatchPtr instance)
{
    free(instance);
}

void startWatch(DigitalStopWatchPtr instance)
{
    instance->state.start(&instance->state);
}

void stopWatch(DigitalStopWatchPtr instance)
{
    instance->state.stop(&instance->state);
}

void X_changeState(DigitalStopWatchPtr instance, WatchStatePtr newState)
{
    /* Provides a good place for controls and trace messages */
    /* All state transitions have to go through this function */
    instance->state = *newState;
}