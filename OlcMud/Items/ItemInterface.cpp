#include "ItemInterface.hpp"

ItemInterface::ItemInterface()
{
}

ItemInterface::~ItemInterface()
{
}

void ItemInterface::addWeapons(std::vector<Weapon> &weapons)
{
	std::fstream fs;
	if (fs.open("Weapons.txt", std::ios::in | std::ios::binary))
	{
		
	}
	else
	{
		std::cout << "No Weapons Found" << std::endl;
	}
}

void ItemInterface::addArmour(std::vector<Armour>& armours)
{
	std::fstream fs;
	if (fs.open("Armours.txt", std::ios::in | std::ios::binary))
	{

	}
	else
	{
		std::cout << "No Armours Found" << std::endl;
	}
}

void ItemInterface::addAccessories(std::vector<Accessories>& accessories)
{
	std::fstream fs;
	if (fs.open("Accessories.txt", std::ios::in | std::ios::binary))
	{

	}
	else
	{
		std::cout << "No Accessories Found" << std::endl;
	}
}

void ItemInterface::addPotions(std::vector<Potion>& potions)
{
	std::fstream fs;
	if (fs.open("Potions.txt", std::ios::in | std::ios::binary))
	{

	}
	else
	{
		std::cout << "No Potions Found" << std::endl;
	}
}
