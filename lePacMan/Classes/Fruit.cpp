#include "Fruit.h"
namespace OOP {

	//void Fruit::update(float dt)
	//{
	//	time -= dt;
	//	if (time <= 0)
	//	{
	//		//delete this;
	//	///do somethin that isnt delete this lul
	//	///might be a good idea to handle this somewhere else
	//	}
	//}

	SquarePrimitive * Fruit::getSquare() const
	{
		return square;
	}

	Fruit::Fruit(const cocos2d::Vec2 & startingPosition, const cocos2d::Vec2 & endPosition, const cocos2d::Color4F& COLOUR, int s, Fruit_Types t) 
		: square(new SquarePrimitive(startingPosition, endPosition, COLOUR))
	{
		scoreValue = s;
		type = t;
		time = 10.0f;
	}
}
