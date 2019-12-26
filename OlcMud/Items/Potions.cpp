#include "Potions.hpp"

Potion::Potion()
{
}

Potion::Potion( std::string name, int effect, int duration, int type, int material, int level, int weight )
	: Item( name, type, material, level, weight )
{

}
Potion::~Potion()
{

}

void Potion::Create()
{
}
