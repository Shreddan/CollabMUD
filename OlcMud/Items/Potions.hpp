#pragma once

#include "Item.hpp"

namespace EPotionTypes
{
	enum Effects
	{
		Healing,
		ManaRestore,
		AttackEnhance,
		DefenceEnhance,
		DodgeEnhance,
		Special
	};

	enum Duration
	{
		VeryShort,
		Short,
		Medium,
		Long,
		VeryLong,
		Epic
	};
};

class Potion : public Item
{
public:
	Potion( int effect, int duration, int type, int material, int level, int weight );
	~Potion();

	virtual void Create();

private:
	int mEffect;
	int mDuration;
};