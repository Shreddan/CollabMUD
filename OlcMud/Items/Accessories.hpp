#pragma once
#include "Item.hpp"

enum Special1
{
	None,
	DamageUP,
	DodgeUP,
	StaminaUP,
	SpeedUP,
	DefenceUP,
	AccuracyUP,
	DamageDWN,
	DodgeDWN,
	StaminaDWN,
	SpeedDWN,
	DefenceDWN,
	AccuracyDWN
};

enum Special2
{
	None,
	DamageUP,
	DodgeUP,
	StaminaUP,
	SpeedUP,
	DefenceUP,
	AccuracyUP,
	DamageDWN,
	DodgeDWN,
	StaminaDWN,
	SpeedDWN,
	DefenceDWN,
	AccuracyDWN
};

class Accessories : public Item
{
public:
	Accessories( int mSpecial1, int mSpecial2, int mType, int mMaterial, int mLevel, int mWeight );
	~Accessories();

	virtual void Create();

private:
	int mSpecial1;
	int mSpecial2;
};