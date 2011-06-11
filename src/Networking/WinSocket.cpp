#include "WinSocket.h"

TCPSocket::TCPSocket()
{
	WSADATA wsaData;
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
}

TCPSocket::~TCPSocket()
{
	WSACleanup();
}