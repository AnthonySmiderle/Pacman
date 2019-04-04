#pragma once
#include "GameObject.h"
namespace OOP {

	enum Fruit_Types{
		cherry = 1
	};
	class Fruit : public GameObject
	{
	public:
		Fruit(const cocos2d::Vec2 & startingPosition, const cocos2d::Vec2 & endPosition, const cocos2d::Color4F& COLOUR, int s, Fruit_Types t);
		//void update(float dt);
		SquarePrimitive* getSquare() const;
	private:
		OOP::SquarePrimitive* square;
		int scoreValue;
		int type;
		float time;


	};
}