#pragma once

#include <string>

namespace EItemTypes
{
	enum Material
	{
		None,
		Wood,
		Stone,
		Copper,
		Bronze,
		Iron,
		Steel,
		Anicate,
		Benalite,
		Danicrute,
		Fiskite,
		Javidite,
		Stackate,
		Slicite,
		Tutasite

	};

	enum Type
	{
		Weapon,
		Armour,
		Potion,
		Accessory,
		Special
	};
};

class Item
{
public:
	Item();
	Item( std::string name, int type, int material, int level, int weight );
	~Item();

	virtual void Create() = 0;

	std::string name;
	int mType;
	int mMaterial;
	int mLevel;
	int mWeight;

};