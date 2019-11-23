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
		Staff
	};
};

class Weapon : public Item
{
public:
	Weapon( int baseDamage, int weaponType, int type, int material, int level, int weight );
	~Weapon();

	virtual void Create();

private:

	int mBaseDamage;
	int mWeaponType;
	
};