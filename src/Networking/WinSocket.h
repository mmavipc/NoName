#ifndef WINSOCKET_H
#define WINSOCKET_H

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

class TCPSocket
{
	public:
		TCPSocket();
		~TCPSocket();
};

#endif