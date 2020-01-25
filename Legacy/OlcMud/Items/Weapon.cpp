#include "Weapon.hpp"

Weapon::Weapon() : Item()
{

}

Weapon::Weapon( int baseDamage, int weaponType, std::string name, int type, int material, int level, int weight )
	: Item( name, type, material, level, weight )
{

}

Weapon::~Weapon()
{

}

void Weapon::Create()
{

}
