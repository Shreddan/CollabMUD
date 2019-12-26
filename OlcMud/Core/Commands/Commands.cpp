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
	else if (sm[1] == "wt" || sm[1] == "weapontest")
	{
		std::cout << items.weapons.size() << std::endl;
		for (size_t i = 0; i < items.weapons.size(); i++)
		{
			std::cout << "Weapon :  " << items.weapons[i].name << std::endl;
			std::cout << "Level  :  " << items.weapons[i].mLevel << std::endl;
		}
		
	}
	else if (sm[1] == "at" || sm[1] == "armourtest")
	{
		std::cout << items.armours.size() << std::endl;
		for (size_t i = 0; i < items.armours.size(); i++)
		{
			std::cout << "Weapon :  " << items.armours[i].name << std::endl;
			std::cout << "Level  :  " << items.armours[i].mLevel << std::endl;
		}
	}
	else if (sm[1] == "q" || sm[1] == "quit")
	{
		std::cout << "Shutting down" << std::endl;
		Close = true;
	}
}
