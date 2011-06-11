#ifndef WinSocket_H
#define WinSocket_H

#ifdef WIN32
#include "WinSocket.h"
typedef WinSocket TCPSocket;
#else
#include "NixSocket.h"
typedef NixSocket TCPSocket;
#endif

#endif