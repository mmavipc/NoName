#include <iostream>

#include "Networking\TCPSocket.h"


int main()
{
	TCPSocket serversock;
	serversock.Connect("mmavipc.dyndns.org", 6667);
	std::cout << serversock.GetError() << std::endl;
	std::cin.ignore(10000, '\n');
}