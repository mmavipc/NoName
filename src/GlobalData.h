#ifndef GlobalData_H
#define GlobalData_H

#include "Networking\TCPSocket.h"

class GlobalData
{
	public:
		GlobalData(const std::string &configFile, TCPSocket *tcpsock); //Dummy for now

		static GlobalData* GetGlobalData();

		const std::string& GetServerName();
		TCPSocket& GetSocket();

	private:
		std::string m_serverName;
		TCPSocket *m_sock;
};

#endif