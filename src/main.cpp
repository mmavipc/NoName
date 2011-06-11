#include <iostream>

#include "Networking\TCPSocket.h"


int main()
{
	TCPSocket serversock;
	serversock.Connect("mmavipc.dyndns.org", 6667);
	std::cout << serversock.GetError() << std::endl;
	std::string str;
	int c = 0;
	while(true)
	{
		std::cout << serversock.RecvLine(str) << " " << str << std::endl;
		str = "";
		c++; // lol C++
		if(c == 2)
		{
			if(!serversock.SendData("user mmavipc 0 * :none\nnick mmavipc2\n"))
			{
				std::cout << "Fatal error: " << serversock.GetError();
				break;
			}
		}
	}
	std::cin.ignore(10000, '\n');
}