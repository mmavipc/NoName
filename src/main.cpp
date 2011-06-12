#include <iostream>
#include <ctime>
#include <sstream>

#include "Networking\TCPSocket.h"
#include "IRC\GeneralHandler.h"
#include "Bot\GenericBot.h"
#include "GlobalData.h"

int FindSpaceCount(const std::string &str)
{
	int count = 0;
	size_t pos = 0;
	while(pos != std::string::npos)
	{
		pos = str.find(' ', pos);
		if(pos != std::string::npos)
		{
			count++;
			pos++;
		}
	}
	return count;
}

int main()
{
	TCPSocket tcpsock;
	GlobalData *gData = new GlobalData("NULL", &tcpsock);
	GeneralHandler ghandler;

	tcpsock.Connect("mmavipc.dyndns.org", 6667);
	std::cout << tcpsock.GetError() << std::endl;
	std::string str;
	std::stringstream cTime;
	cTime << (long long)time(NULL);
	if(!tcpsock.SendData("PASS :test\r\nSERVER services.mmavipc.dyndns.org 0 :NoName Services\r\nEOS\r\n"))
	{
		std::cout << "Fatal error: " << tcpsock.GetError();
	}
	GenericBot lolbot("lolbot");
	lolbot.RunCommand("JOIN #lol");
	while(true)
	{
		bool result = tcpsock.RecvLine(str);
		if(!result)
		{
			std::cout << "Fatal error: " << tcpsock.GetError();
			break;
		}
		std::cout << result << " " << str << std::endl;
		int spc = FindSpaceCount(str);
		std::string *split = new std::string[spc+1];
		int pos = 0;
		int oldpos = 0;
		for(int i = 0; i < spc+1; i++)
		{
			pos = str.find(' ', pos+1);
			if(i != 0)
			{
				split[i] = str.substr(oldpos+1, pos-oldpos-1);
			}
			else
			{
				split[i] = str.substr(oldpos, pos-oldpos);
			}
			oldpos = pos;
		}
		ghandler.Handle(split, spc, tcpsock);
		delete [] split;
		str = "";
	}
	std::cin.ignore(10000, '\n');
}