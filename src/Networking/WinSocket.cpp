#include "WinSocket.h"
#include <cassert>
#include <sstream>

WinSocket::WinSocket()
{
	WSADATA wsaData;
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	assert(result==0);
}

WinSocket::~WinSocket()
{
	WSACleanup();
}

bool WinSocket::Connect(const std::string &host, const unsigned short &ip)
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

bool WinSocket::SendData(std::string data)
{
	int result;
	result = send(m_socket, data.c_str(), data.length(), 0);

	if(result == SOCKET_ERROR)
	{
		return false;
	}
	return true;
}

bool WinSocket::RecvLine(std::string &line, bool block)
{
	char c = 0;
	bool loop = true;
	int length = 0;
	while(loop)
	{
		length = recv(m_socket, &c, 1, 0);
		if(length < 0)
		{
			return false;
		}
		else if(length==0)
		{
			if(!block)
			{
				loop = false;
			}
		}
		else if(c != '\r')
		{
			if(c == '\n')
			{
				return true;
			}
			line += c;
		}
	}
	return true;
}

std::string WinSocket::GetError()
{
	std::stringstream ss;
	ss << "WSAGetLastError: " << WSAGetLastError();
	int buflen = 64;
	char buf[64];
	int result = getsockopt(m_socket, SOL_SOCKET, SO_ERROR, buf, &buflen);
	ss << " Socket Error: " << std::string(buf, buflen);
	return ss.str();
}