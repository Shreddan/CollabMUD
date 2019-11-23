#include "Potions.hpp"

Potion::Potion( int effect, int duration, int type, int material, int level, int weight )
	: Item( type, material, level, weight )
{

}
Potion::~Potion()
{

}

void Potion::Create()
{
}
