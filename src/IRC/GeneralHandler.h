#ifndef GENERALHANDLER_H
#define GENERALHANDLER_H

#include <string>

#include "..\Networking\TCPSocket.h"

class GeneralHandler
{
	public:
		bool Handle(const std::string *split, const int paramNum);
};

#endif