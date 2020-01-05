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
		std::cout << std::endl;
	}
	else if (sm[1] == "wt" || sm[1] == "weapontest")
	{
		std::cout << std::endl;
		std::cout << "Total Weapons : " << items.weapons.size() << std::endl;
		for (size_t i = 0; i < items.weapons.size(); i++)
		{
			std::cout << "Weapon :  " << items.weapons[i].name << std::endl;
			std::cout << "Level  :  " << items.weapons[i].mLevel << std::endl;
		}
		
	}
	else if (sm[1] == "at" || sm[1] == "armourtest")
	{
		std::cout << std::endl;
		std::cout << "Total Armours : " << items.armours.size() << std::endl;
		for (size_t i = 0; i < items.armours.size(); i++)
		{
			std::cout << "Armour :  " << items.armours[i].name << std::endl;
			std::cout << "Level  :  " << items.armours[i].mLevel << std::endl;
		}
	}
	else if (sm[1] == "at2" || sm[1] == "accessorytest")
	{
		std::cout << std::endl;
		std::cout << "Total Accessories : " << items.accessories.size() << std::endl;
		for (size_t i = 0; i < items.accessories.size(); i++)
		{
			std::cout << "Accessory :  " << items.accessories[i].name << std::endl;
			std::cout << "Level     :  " << items.accessories[i].mLevel << std::endl;
		}
	}
	else if (sm[1] == "pt" || sm[1] == "potiontest")
	{
		std::cout << std::endl;
		std::cout << "Total Potions : "  << items.potions.size() << std::endl;
		for (size_t i = 0; i < items.potions.size(); i++)
		{
			std::cout << "Potion : " << items.potions[i].name << std::endl;
			std::cout << "Effect : " << items.potions[i].mEffect << std::endl;
			std::cout << "Health Regained : " << items.potions[i].hpGain << std::endl;
		}
	}
	else if (sm[1] == "q" || sm[1] == "quit")
	{
		std::cout << "Shutting down" << std::endl;
		Close = true;
	}
}
