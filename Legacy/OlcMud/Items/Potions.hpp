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
		Instant,
		Short,
		Medium,
		Long,
	};
};

class Potion : public Item
{
public:
	Potion();
	//Potion(std::string name, int type, int material, int level, int weight, int effect, int duration, int hpGain = 0 );
	~Potion();

	virtual void Create();

	int mEffect;
	int mDuration;
	int hpGain;
};