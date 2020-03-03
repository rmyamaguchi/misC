#ifndef TIMESUBJECT_H
#define TIMESUBJECT_H

#include "TimeObserver.h"

void attach(const TimeObserver* observer);
void detach(const TimeObserver* observer);

#endif