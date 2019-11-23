#pragma once
#include "Item.hpp"

enum ArmourSlot
{
	Head,
	LEar,
	REar,
	Torso,
	LWrist,
	RWrist,
	Legs,
	LAnkle,
	RAnkle
};

class Armour : public Item
{
	Armour(int mSlot, int mDefence, int mType, int mMaterial, int mLevel, int mWeight);
	~Armour();

	virtual void Create();

private:
	int mSlot;
	int mDefence;
};