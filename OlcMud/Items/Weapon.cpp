#include "Weapon.hpp"

Weapon::Weapon(int BaseDamage, int nWeaponType, int nType, int nMaterial, int nLevel, int nWeight) 
	: Item(nType, nMaterial, nLevel, nWeight)
{

}

Weapon::~Weapon()
{

}