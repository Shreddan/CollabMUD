#pragma once

#include "Item.hpp"

namespace EAccessoryTypes
{
	enum Specials
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
	Accessories();
	Accessories( int special1, int special2, std::string name, int type, int material, int level, int weight );
	~Accessories();

	virtual void Create();

	int mSpecial1;
	int mSpecial2;
};