#ifndef DIAGNOSTICSSERVER_H
#define DIAGNOSTICSSERVER_H

typedef struct DiagnosticsServer *DiagnosticsServerPtr;

DiagnosticsServerPtr createServer(unsigned int tcpPort);
void destroyServer(DiagnosticsServerPtr server);

#endif