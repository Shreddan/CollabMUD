#pragma once
#include "Item.hpp"

enum ArmourSlot
{
	Head,
	Torso,
	LWrist,
	RWrist,
	Legs,
	LAnkle,
	RAnkle
};

class Armour : public Item
{
	Armour( int nSlot, int nDefence, int nType, int nMaterial, int nLevel, int nWeight );
	~Armour();

	virtual void Create();

private:
	int nSlot;
	int nDefence;
};