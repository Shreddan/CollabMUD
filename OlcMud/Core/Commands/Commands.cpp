#include "Commands.hpp"

Commands::Commands()
{
	Close = false;
}
Commands::~Commands()
{
}

std::smatch Commands::regexify(std::string &sent)
{
	std::regex cmd("(\\w+) ?(\\w+)? ?(\\w+)? ?(\\w+)? ?(\\w+)?");
	std::regex_match(sent, sm, cmd);

	return sm;
}

void Commands::commandlist(std::smatch &sm)
{
	if (sm[1] == "l" || sm[1] == "look")
	{
		std::cout << "You see a vast emptiness, there is nothing here yet" << std::endl;
	}
	else if (sm[1] == "q" || sm[1] == "quit")
	{
		std::cout << "Shutting down" << std::endl;
		Close = true;
	}
}
