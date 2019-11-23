#pragma once
#include "Item.hpp"

namespace EAccessoryTypes
{
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
};

class Accessories : public Item
{
public:
	Accessories( int special1, int special2, int type, int material, int level, int weight );
	~Accessories();

	virtual void Create();

private:
	int mSpecial1;
	int mSpecial2;
};