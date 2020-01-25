#pragma once

#include "Item.hpp"

namespace EWeaponType
{
	enum Weapon
	{
		Dagger,
		ShortSword,
		LongSword,
		Bow,
		Whip,
		Mace,
		WarHammer,
		Staff,
		Wand
	};
};

class Weapon : public Item
{
public:
	Weapon();
	Weapon( int baseDamage, int weaponType, std::string name, int type, int material, int level, int weight );
	~Weapon();

	virtual void Create();

	int baseDamage;
	int weaponType;
	
};