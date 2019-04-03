//the following code takes inspiration from Sedna Games' GDW project

#include "Pacman.h"

DevitoCult::Pacman::Pacman(cocos2d::Scene* s, XinputManager MANAGER,float x1, float y1,float x2,float y2)
{
	//makes a new sprite and a new hitbox
	sprite = cocos2d::Sprite::create("HelloWorld.png");
	altHitBox = new SquarePrimitive(cocos2d::Vec2(x1,y1),cocos2d::Vec2(x2,y2),cocos2d::Color4F(1.0f,1.0f,0,1.0f));
	sprite->setVisible(false);

	s->addChild(altHitBox->getDrawNode(),100);
	s->addChild(sprite);
	//altHitBox->getDrawNode()->setPosition(cocos2d::Vec2(x, y));

	this->setHP(1);

	//initialize the controller and the sticks
	pController = MANAGER.getController(0);
	pController->updateSticks(pSticks);
}

DevitoCult::Pacman::~Pacman()
{
	
}

void DevitoCult::Pacman::update()
{
	//updates the sticks
	pController->updateSticks(pSticks);

	//check which way the stick is, then move in that direction
	if (pSticks[0].x > 0.3f)
		this->getAltBox()->setForce(cocos2d::Vec2(1.5f, 0));
	else if (pSticks[0].x < -0.3f)
		this->getAltBox()->setForce(cocos2d::Vec2(-1.5f, 0));
	if (pSticks[0].y > 0.3f)
		this->getAltBox()->setForce(cocos2d::Vec2(0, 1.5f));
	else if (pSticks[0].y < -0.3f)
		this->getAltBox()->setForce(cocos2d::Vec2(0, -1.5f));


	this->updateGameObject();
	
}

void DevitoCult::Pacman::die()
{
	//ya ded
	lives--;
	//play death animation
	///this->getBox()->setLocation(cocos2d::Vec2(250, 250));
}
