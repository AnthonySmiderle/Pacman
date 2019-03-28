#pragma once
#include "Primitive.h"
namespace DevitoCult {

	class Fruit : public DevitoCult::SquarePrimitive
	{
	public:
		Fruit(const cocos2d::Vec2 & startingPosition, const cocos2d::Vec2 & endPosition, const cocos2d::Color4F& COLOUR, int s, int t);
		void update(float dt);
		SquarePrimitive* getSquare() const;
	private:
		DevitoCult::SquarePrimitive* square;
		int score;
		int type;
		float time;


	};
}