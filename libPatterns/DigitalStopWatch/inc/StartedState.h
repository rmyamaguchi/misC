
#ifndef STARTEDSTATE_H
#define STARTEDSTATE_H

#include "WatchState.h"

void transitionToStarted(WatchStatePtr state);

#ifdef _X
WatchStatePtr X_transitionToStarted(void);
#endif

#endif