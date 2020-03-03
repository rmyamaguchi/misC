
#include <stdlib.h>

#include "DiagnosticsServer.h"
#include "EventHandler.h"
#include "Reactor.h"

struct DiagnosticsServer
{
    Handle listeningSocket;
    EventHandler eventHandler;
};

static Handle getServerSocket(void *instance)
{
    const DiagnosticsServerPtr server = instance;
    return server->listeningSocket;
}

static void handleConnectRequest(void *instance)
{
    DiagnosticsServerPtr server = instance;
    /* etc */
}

DiagnosticsServerPtr createServer(unsigned int tcpPort)
{
    DiagnosticsServerPtr newServer = malloc(sizeof *newServer);

    if (NULL != newServer)
    {
        newServer->listeningSocket = createServerSocket(tcpPort); // Placeholder

        newServer->eventHandler.instance = newServer;
        newServer->eventHandler.getHandle = getServerSocket;
        newServer->eventHandler.handleEvent = handleConnectRequest;

        Register(&newServer->eventHandler);
    }
    return newServer;
}

void destroyServer(DiagnosticsServerPtr server)
{
    Unregister(&server->eventHandler);
    free(server);
}