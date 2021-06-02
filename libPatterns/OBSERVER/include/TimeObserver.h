#ifndef TIMEOBSERVER_H
#define TIMEOBSERVER_H

#include "SystemTime.h"

typedef void (*ChangedTimeNotification)(void *instance, const SystemTime *newTime);

typedef struct
{
    void *instance;
    ChangedTimeNotification notification;
} TimeObserver;

#endif