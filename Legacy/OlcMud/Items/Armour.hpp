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
public:
	Armour();
	Armour( int slot, int defence, std::string name, int type, int material, int level, int weight );
	~Armour();

	virtual void Create();

	int slot;
	int defence;
};