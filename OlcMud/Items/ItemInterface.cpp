#include "ItemInterface.hpp"

using json = nlohmann::json;

ItemInterface::ItemInterface()
{
}

ItemInterface::~ItemInterface()
{
}

void ItemInterface::addWeapons(std::vector<Weapon> &weapons)
{

	std::ifstream if1("C:/Users/User/source/repos/Shreddan/CollabMUD/OlcMud/Resources/Weapons.json");
	if (if1.good())
	{
		js = json::parse(if1);
		//std::cout << js << std::endl;
	}
	else
	{
		std::cout << "Weapons Not Found" << std::endl;
	}

	for (const auto weapon : js["Weapon"])
	{
		Weapon i;
		i.baseDamage = weapon["baseDamage"];
		i.weaponType = weapon["weaponType"];
		i.name = weapon["name"];
		i.mType = weapon["type"];
		i.mMaterial = weapon["material"];
		i.mLevel = weapon["level"];
		i.mWeight = weapon["weight"];
		
		weapons.emplace_back(i);
	}
}

void ItemInterface::addArmour(std::vector<Armour>& armours)
{
	std::ifstream if1("C:/Users/User/source/repos/Shreddan/CollabMUD/OlcMud/Resources/Armour.json");
	if (if1.good())
	{
		json::parse(if1);
	}
	else
	{
		std::cout << "No Armours Found" << std::endl;
	}

	for (const auto armour : js["Armour"])
	{

	}
}

void ItemInterface::addAccessories(std::vector<Accessories>& accessories)
{
	std::ifstream if1("C:/Users/User/source/repos/Shreddan/CollabMUD/OlcMud/Resources/Accessories.json");
	if (if1.good())
	{

	}
	else
	{
		std::cout << "No Accessories Found" << std::endl;
	}
}

void ItemInterface::addPotions(std::vector<Potion>& potions)
{
	std::ifstream if1("C:/Users/User/source/repos/Shreddan/CollabMUD/OlcMud/Resources/Potions.json");
	if (if1.good())
	{

	}
	else
	{
		std::cout << "No Potions Found" << std::endl;
	}
}
