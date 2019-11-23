#pragma once

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

class Item
{
public:
	Item( int nType, int nMaterial, int nLevel, int nWeight );
	~Item();

	virtual void Create( int nType, int nMaterial, int nLevel, int nWeight ) = 0;


private:

	int nType;
	int nMaterial;
	int nLevel;
	int nWeight;

};