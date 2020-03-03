
#include "util.h"
#include "DiagnosticsServer.h"
#include "ReactorEventLoop.h"

int main()
{
    const unsigned int serverPort = 0xC001;
    DiagnosticsServerPtr server = createServer(serverPort);

    if (NULL == server)
        printf("\r\nFailed to create the server");

    for (;;)
        HandleEvents();
}