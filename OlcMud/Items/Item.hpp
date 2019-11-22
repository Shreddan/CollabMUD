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

class Item
{
public:
	Item();
	~Item();

	virtual void Create(int nType, int nMaterial, int nLevel, int nWeight) = 0;


private:

	int nType;
	int nMaterial;
	int nLevel;
	int nWeight;

};