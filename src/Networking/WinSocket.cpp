#include "WinSocket.h"
#include <cassert>

TCPSocket::TCPSocket()
{
	WSADATA wsaData;
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	assert(result==0);
}

TCPSocket::~TCPSocket()
{
	WSACleanup();
}

bool TCPSocket::Connect(std::string host, unsigned short ip)
{
	struct addrinfo *result = NULL;
	struct addrinfo	*ptr = NULL;
	struct addrinfo	hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	char buf[5];
	_itoa_s(ip, buf, 10);

	int fnresult = getaddrinfo(host.c_str(), buf, &hints, &result);
	if(fnresult!=0)
	{
		return false;
	}

	m_socket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

	if(m_socket == INVALID_SOCKET)
	{
		return false;
	}

	fnresult = connect(m_socket, result->ai_addr, result->ai_addrlen);
	if(fnresult == SOCKET_ERROR)
	{
		return false;
	}

	freeaddrinfo(result);

	if(m_socket == INVALID_SOCKET)
	{
		return false;
	}

	return true;
}