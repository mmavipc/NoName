#include <ctime>
#include <sstream>

#include "GenericBot.h"

//NICK lolbot 0 " + cTime.str() + " lolbot 127.0.0.1 services.mmavipc.dyndns.org 0 :lolbot
//:lolbot JOIN #lol\r\n

GenericBot::GenericBot(const std::string &name, TCPSocket tcpsock)
{
	m_name = name;
	m_createTime = time(NULL);
	m_sock = tcpsock;

	std::stringstream timestr;
	timestr << m_createTime;

	tcpsock.SendData("NICK " + name + " 0 " + timestr.str() + " " + name + " services.com services.mmavipc.dyndns.org 0 : " + name + "\r\n");
}

void GenericBot::RunCommand(const std::string &cmd)
{
	m_sock.SendData(":" + m_name + " " + cmd + "\r\n");
}