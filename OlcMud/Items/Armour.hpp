#pragma once
#include "Item.hpp"

namespace EAmourTypes
{
	enum Slot
	{
		Head,
		Torso,
		LWrist,
		RWrist,
		Legs,
		LAnkle,
		RAnkle
	};
};

class Armour : public Item
{
	Armour( int slot, int defence, int type, int material, int level, int weight );
	~Armour();

	virtual void Create();

private:
	int mSlot;
	int mDefence;
};