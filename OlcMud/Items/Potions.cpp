#include "Potions.hpp"

Potion::Potion( int mEffect, int mDuration, int mType, int mMaterial, int mLevel, int mWeight )
	: Item( mType, mMaterial, mLevel, mWeight )
{

}
Potion::~Potion()
{

}

void Potion::Create()
{
}
