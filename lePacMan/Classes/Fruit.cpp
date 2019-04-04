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

	Fruit::Fruit(cocos2d::Scene * s, float x, float y, float x2, float y2, unsigned score)
	{
		altHitBox = new SquarePrimitive(cocos2d::Vec2(x, y), cocos2d::Vec2(x2, y2), cocos2d::Color4F(0, 0, 0, 1));
		altHitBox->getDrawNode()->setVisible(false);
		sprite = cocos2d::Sprite::create("replace this");

		s->addChild(sprite);
		s->addChild(altHitBox->getDrawNode());


	}

	Fruit::~Fruit()
	{
		square->getDrawNode()->removeFromParent();
	}

	SquarePrimitive * Fruit::getSquare() const
	{
		return square;
	}

	
}
