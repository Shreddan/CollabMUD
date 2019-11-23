#pragma once

enum Material
{
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
	Item(int mType, int mMaterial, int mLevel, int mWeight);
	~Item();

	virtual void Create(int mType, int mMaterial, int mLevel, int mWeight) = 0;


private:

	int mType;
	int mMaterial;
	int mLevel;
	int mWeight;

};