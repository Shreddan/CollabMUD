#include "Accessories.hpp"

Accessories::Accessories()
{
}

Accessories::Accessories( std::string name, int special1, int special2, int type, int material, int level, int weight )
	: Item( name, type, material, level, weight )
{

}

Accessories::~Accessories()
{

}

void Accessories::Create()
{

}
