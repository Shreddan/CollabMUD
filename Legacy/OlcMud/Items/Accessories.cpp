#include "Accessories.hpp"

Accessories::Accessories()
{
}

Accessories::Accessories(  int special1, int special2, std::string name, int type, int material, int level, int weight )
	: Item( name, type, material, level, weight )
{

}

Accessories::~Accessories()
{

}

void Accessories::Create()
{

}
