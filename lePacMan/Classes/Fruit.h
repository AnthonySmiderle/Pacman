#pragma once
#include "GameObject.h"
namespace OOP {

	enum Fruit_Types{
		cherry = 1
	};
	class Fruit : public GameObject
	{
	public:
		Fruit(cocos2d::Scene* s, float x, float y, float x2, float y2, unsigned score);
		~Fruit();
		//void update(float dt);
		SquarePrimitive* getSquare() const;
	private:
		OOP::SquarePrimitive* square;
		unsigned scoreValue;
		int type;
		float time;


	};
}