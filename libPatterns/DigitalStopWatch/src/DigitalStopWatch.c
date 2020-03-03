
#include <stdlib.h>
#include "DigitalStopWatch.h"
#include "StoppedState.h"
#include "StartedState.h"

#ifdef _OBSERVER
#include "SystemTime.h"
#include "TimeObserver.h"
#include "TimeSubject.h"
#endif

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

#ifdef _X
void X_changeState(DigitalStopWatchPtr instance, WatchStatePtr newState)
{
    /* Provides a good place for controls and trace messages */
    /* All state transitions have to go through this function */
    instance->state = *newState;
}
#endif

#ifdef _OBSERVER
static void changedTime(void *instance, const SystemTime *newTime)
{
    DigitalStopWatchPtr digitalWatch = instance;
    if (NULL != digitalWatch)
        updateDisplay(digitalWatch, newTime); // PlaceHolder
}

DigitalStopWatchPtr createDigitalWatch(void)
{
    DigitalStopWatchPtr watch = malloc(sizeof *watch);

    if (NULL != watch)
    {
        TimeObserver observer = {0};
        observer.instance = watch;
        observer.notification = changedTime;

        attach(&observer);
    }
    return watch;
}

void destroyDigitalWatch(DigitalStopWatchPtr watch)
{
    TimeObserver observer = {0};
    observer.instance = watch;
    observer.notification = changedTime;

    detach(&observer);
    free(watch);
}
#endif /* OBSERVER */