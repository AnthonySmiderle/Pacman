#pragma once
#include "Primitive.h"

class Fruit : public DevitoCult::SquarePrimitive
{
private:
	int score;
	int type;
	float time;
	
public:
	void update(float dt);
	DevitoCult::SquarePrimitive square;
	Fruit(const cocos2d::Vec2 & startingPosition, const cocos2d::Vec2 & endPosition, const cocos2d::Color4F& COLOUR, int s, int t);

};