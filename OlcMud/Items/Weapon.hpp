#pragma once
#include "Item.hpp"

enum WeaponType
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

class Weapon : public Item
{
public:
	Weapon(int mBaseDamage, int mWeaponType, int mType, int mMaterial, int mLevel, int mWeight);
	~Weapon();

	virtual void Create();

private:

	int mBaseDamage;
	int mWeaponType;
};