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
	GlobalData::GetGlobalData()->m_botList.insert(GlobalData::GetGlobalData()->m_botList.end(), this);
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
	m_channelList.insert(m_channelList.end(), channelName);
}

void GenericBot::RecvMsg(const std::string &origin, const std::string &destination, const std::string &msg)
{
	if(destination.substr(0,1) == "#")
	{
		bool found = false;
		for(unsigned int i = 0; i < m_channelList.size(); i++)
		{
			if(m_channelList[i] == destination)
			{
				found = true;
				break;
			}
		}
		if(found)
		{
			RunCommand("PRIVMSG " + destination + " :" + origin + ": " + msg);
			GlobalData::GetGlobalData()->GetSocket().SendData(msg + "\r\n");
		}
	}
	else
	{
		RunCommand("PRIVMSG " + origin + " :" + origin + ": " + msg);
		RunCommand(msg);
	}
}