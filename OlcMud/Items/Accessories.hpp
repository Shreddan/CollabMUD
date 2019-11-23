#include "Item.hpp"

enum Special1
{
	None,
	DamageUP,
	DodgeUP,

};

enum Special2
{
	None,

};

class Accessories : public Item
{
public:
	Accessories(int mSpecial1, int mSpecial2, int mType, int mMaterial, int mLevel, int mWeight);
	~Accessories();

	virtual void Create();

private:
	int mSpecial1;
	int mSpecial2;
};