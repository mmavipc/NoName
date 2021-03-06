#ifndef WINSOCKET_H
#define WINSOCKET_H

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#include <string>

#pragma comment(lib, "ws2_32.lib")

class WinSocket
{
	public:
		WinSocket();
		~WinSocket();

		bool Connect(const std::string &host,const unsigned short &ip);

		bool SendData(const std::string &data);

		bool RecvLine(std::string &line, bool block = true);

		std::string GetError();

	private:
		SOCKET m_socket;
};

#endif