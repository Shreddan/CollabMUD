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
	Weapon( int BaseDamage, int nWeaponType, int nType, int nMaterial, int nLevel, int nWeight );
	~Weapon();

	virtual void Create();

private:

	int BaseDamage;
	int nWeaponType;
};