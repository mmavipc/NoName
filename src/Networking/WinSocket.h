#ifndef WINSOCKET_H
#define WINSOCKET_H

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#include <string>

#pragma comment(lib, "ws2_32.lib")

class TCPSocket
{
	public:
		TCPSocket();
		~TCPSocket();

		bool Connect(std::string host, unsigned short ip);

	private:
		SOCKET m_socket;
};

#endif