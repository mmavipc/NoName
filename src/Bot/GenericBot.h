#ifndef GENERICBOT_H
#define GENERICBOT_H

#include <string>
#include <vector>

class GenericBot
{
	public:
		GenericBot(const std::string &name);
		void RunCommand(const std::string &cmd);
		void JoinChannel(const std::string &channelName, bool execJoinCmd = true);

	private:
		std::string m_name;
		long long m_createTime;
		std::vector<std::string> m_channelList;
};

#endif