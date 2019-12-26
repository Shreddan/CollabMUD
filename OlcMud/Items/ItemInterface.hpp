#pragma once

#include "Weapon.hpp"
#include "Armour.hpp"
#include "Accessories.hpp"
#include "Potions.hpp"

#include <vector>
#include <fstream>
#include <iostream>

#include "../Util/single_include/nlohmann/json.hpp"

class ItemInterface
{
public:
	ItemInterface();
	~ItemInterface();

	void addWeapons(std::vector<Weapon> &weapons);
	void addArmour(std::vector<Armour> &armours);
	void addAccessories(std::vector<Accessories> &accessories);
	void addPotions(std::vector<Potion> &potions);

	std::vector<Weapon> weapons;
	std::vector<Armour> armours;
	std::vector<Accessories> accessories;
	std::vector<Potion> potions;

	nlohmann::json js;

};