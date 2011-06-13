#include <ctime>
#include <sstream>

#include "GenericBot.h"
#include "..\GlobalData.h"

//NICK lolbot 0 " + cTime.str() + " lolbot 127.0.0.1 services.mmavipc.dyndns.org 0 :lolbot
//:lolbot JOIN #lol\r\n

GenericBot::GenericBot(const std::string &name) : m_channelList()
{
	m_name = name;
	m_createTime = time(NULL);

	std::stringstream timestr;
	timestr << m_createTime;

	GlobalData::GetGlobalData()->GetSocket().SendData("NICK " + name + " 0 " + timestr.str() + " " + name + " services.com services.mmavipc.dyndns.org 0 : " + name + "\r\n");
}

void GenericBot::RunCommand(const std::string &cmd)
{
	GlobalData::GetGlobalData()->GetSocket().SendData(":" + m_name + " " + cmd + "\r\n");
}

void GenericBot::JoinChannel(const std::string &channelName, bool execJoinCmd)
{
	if(execJoinCmd)
	{
		RunCommand("JOIN " + channelName);
	}
}