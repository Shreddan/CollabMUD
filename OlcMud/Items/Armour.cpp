#include "Armour.hpp"

Armour::Armour()
{
}

Armour::Armour( int slot, int defence, std::string name, int type, int material, int level, int weight )
	: Item( name, type, material, level, weight )
{

}
Armour::~Armour()
{

}

void Armour::Create()
{

}
