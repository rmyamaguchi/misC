#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

typedef int Handle;

typedef Handle (*getHandleFunc)(void *instance);
typedef void (*handleEventFunc)(void *instance);

typedef struct 
{
    void *instance;
    getHandleFunc getHandle;
    handleEventFunc handleEvent;
} EventHandler;

#endif