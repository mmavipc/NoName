#include "GeneralHandler.h"

bool GeneralHandler::Handle(const std::string *split, const int paramNum, TCPSocket &sock)
{
	std::string origin = "";
	std::string command = "";
	int paramStart = 1;
	if(split[0].substr(0,1)==":")
	{
		origin = split[0].substr(1, split[0].length()-1);
		command = split[1];
		paramStart = 2;
	}
	if(command == "PING")
	{
		sock.SendData("PONG " + split[paramStart] + "\r\n");
		return true;
	}
	return false;
}