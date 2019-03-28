#include "Fruit.h"

void Fruit::update(float dt)
{
	time -= dt;
	if (time <= 0)
	{
		delete this;
	}
}

Fruit::Fruit(const cocos2d::Vec2 & startingPosition, const cocos2d::Vec2 & endPosition, const cocos2d::Color4F& COLOUR, int s, int t) : square(startingPosition, endPosition, COLOUR)
{
	score = s;
	type = t;
	time = 10.0f;
}
