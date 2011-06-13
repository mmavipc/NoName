#include <cassert>

#include "GlobalData.h"

GlobalData *gData = NULL;

GlobalData::GlobalData(const std::string &configFile, TCPSocket *tcpsock) : m_botList()
{
	//Dummy
	m_serverName = "services.mmavipc.dyndns.org";
	m_sock = tcpsock;

	assert(!gData);
	gData = this;
}

GlobalData* GlobalData::GetGlobalData()
{
	assert(gData);
	return gData;
}

const std::string& GlobalData::GetServerName()
{
	return m_serverName;
}

TCPSocket& GlobalData::GetSocket()
{
	return *m_sock;
}