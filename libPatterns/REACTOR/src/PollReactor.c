#define _GNU_SOURCE

#include <stdlib.h>
#include <poll.h>
#include "Reactor.h"
#include "ReactorEventLoop.h"

#define MAX_NO_OF_HANDLES 10

typedef struct
{
    EventHandler handler;
    struct pollfd fd;
} HandlerRegistration;

static HandlerRegistration registeredHandlers[MAX_NO_OF_HANDLES];

/* Add a copy of the given handler to the first free position in registeredHandlers */
static void addToRegistry(EventHandler *handler);

/* Identify the event handler in the registeredHandlers and remove it */
static void removeFromRegistry(EventHandler *handler);

void Register(EventHandler *handler)
{
    if (NULL != handler)
        addToRegistry(handler);
}

void Unregister(EventHandler *handler)
{
    if (NULL != handler)
        removeFromRegistry(handler);
}

static size_t buildPollArray(struct pollfd *fds);

static EventHandler *findHandler(int fd);

static void dispatchSignalledHandles(const struct pollfd *fds, size_t noOfHandles)
{
    size_t i = 0;

    for (i = 0; i < noOfHandles; ++i)
    {
        if ((POLLRDNORM | POLLERR) & fds[i].revents) {
            EventHandler *signalledHandler = findHandler(fds[i].fd);
            if(NULL != signalledHandler)
                signalledHandler->handleEvent(signalledHandler->instance);
        }
    }
}

void HandleEvents(void)
{
    /* Build the array required to interact with poll() */
    struct pollfd fds[MAX_NO_OF_HANDLES] = {0};

    const size_t noOfHandles = buildPollArray(fds);

    /* Inoke the synchronous event demultiplexer */
    if (0 < poll(fds, noOfHandles, -1))
        dispatchSignalledHandles(fds, noOfHandles);
    else
        printf("Poll failure");

}