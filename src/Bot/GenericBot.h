#ifndef GENERICBOT_H
#define GENERICBOT_H

#include <string>

class GenericBot
{
	public:
		GenericBot(const std::string &name);
		void RunCommand(const std::string &cmd);

	private:
		std::string m_name;
		long long m_createTime;
};

#endif