#include <iostream>

#include "Networking\TCPSocket.h"


int main()
{
	TCPSocket tcpsock;
	tcpsock.Connect("mmavipc.dyndns.org", 6667);
	std::cout << tcpsock.GetError() << std::endl;
	std::string str;
	int c = 0;
	while(true)
	{
		std::cout << tcpsock.RecvLine(str) << " " << str << std::endl;
		str = "";
		c++; // lol C++
		if(c == 2)
		{
			if(!tcpsock.SendData("user mmavipc 0 * :none\nnick mmavipc2\n"))
			{
				std::cout << "Fatal error: " << tcpsock.GetError();
				break;
			}
		}
	}
	std::cin.ignore(10000, '\n');
}