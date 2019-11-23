#pragma once

#include "Item.hpp"

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

class Potion : public Item
{
public:
	Potion(int mEffect, int mDuration, int mType, int mMaterial, int mLevel, int mWeight);
	~Potion();

	virtual void Create();

private:
	int mEffect;
	int mDuration;
};