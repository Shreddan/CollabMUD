#include "Weapon.hpp"

Weapon::Weapon(int mBaseDamage, int mWeaponType, int mType, int mMaterial, int mLevel, int mWeight) 
	: Item(mType, mMaterial, mLevel, mWeight)
{

}

Weapon::~Weapon()
{

}

void Weapon::Create()
{

}
