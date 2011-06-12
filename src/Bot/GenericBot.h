#ifndef GENERICBOT_H
#define GENERICBOT_H

#include <string>
#include "..\Networking\TCPSocket.h"

class GenericBot
{
	public:
		GenericBot(const std::string &name, TCPSocket tcpsock);
		void RunCommand(const std::string &cmd);

	private:
		std::string m_name;
		long long m_createTime;

		TCPSocket m_sock;
};

#endif