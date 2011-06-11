#include "GeneralHandler.h"

bool GeneralHandler::Handle(const std::string *split, const int paramNum, TCPSocket &sock)
{
	if(split[0] == "PING")
	{
		sock.SendData("PONG " + split[1] + "\n");
	}
	return false;
}