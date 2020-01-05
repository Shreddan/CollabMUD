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
		js = json::parse(if1);
	}
	else
	{
		std::cout << "No Armours Found" << std::endl;
	}

	for (const auto armour : js["Armour"])
	{
		Armour a;
		a.slot = armour["slot"];
		a.defence = armour["defence"];
		a.name = armour["name"];
		a.mType = armour["type"];
		a.mMaterial = armour["material"];
		a.mLevel = armour["level"];
		a.mWeight = armour["weight"];

		armours.emplace_back(a);
	}
}

void ItemInterface::addAccessories(std::vector<Accessories>& accessories)
{
	std::ifstream if1("C:/Users/User/source/repos/Shreddan/CollabMUD/OlcMud/Resources/Accessories.json");
	if (if1.good())
	{
		js = json::parse(if1);
	}
	else
	{
		std::cout << "No Accessories Found" << std::endl;
	}

	for (const auto accessories1 : js["Accessories"])
	{
		Accessories a;
		a.mSpecial1 = accessories1["special1"];
		a.mSpecial2 = accessories1["special2"];
		a.name = accessories1["name"];
		a.mType = accessories1["type"];
		a.mMaterial = accessories1["material"];
		a.mLevel = accessories1["level"];
		a.mWeight = accessories1["weight"];

		accessories.emplace_back(a);
	}
}

void ItemInterface::addPotions(std::vector<Potion>& potions)
{
	std::ifstream if1("C:/Users/User/source/repos/Shreddan/CollabMUD/OlcMud/Resources/Potions.json");
	if (if1.good())
	{
		js = json::parse(if1);
	}
	else
	{
		std::cout << "No Potions Found" << std::endl;
	}

	for (const auto potion : js["Potions"])
	{
		Potion p;
		p.mEffect = potion["effect"];
		p.mDuration = potion["duration"];
		p.name = potion["name"];
		p.mType = potion["type"];
		p.mMaterial = potion["material"];
		p.mLevel = potion["level"];
		p.mWeight = potion["weight"];
		p.hpGain = potion["hpGain"];

		potions.emplace_back(p);
	}
}
