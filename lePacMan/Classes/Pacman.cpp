#include "Pacman.h"

DevitoCult::Pacman::Pacman(cocos2d::Scene* s, XinputManager MANAGER,float x, float y)
{
	//makes a new sprite and a new hitbox
	sprite = cocos2d::Sprite::create("HelloWorld.png");
	hitBox = new CirclePrimitive(cocos2d::Vec2(x, y), 20, 10, 50);

	s->addChild(hitBox->getDrawNode(),100);
	s->addChild(sprite);

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
	//more shit later
	//updates the sticks
	pController->updateSticks(pSticks);

	//check which way the stick is, then move in that direction
	if (pSticks[0].x > 0.3f)
		this->getBox()->setForce(cocos2d::Vec2(3, 0));
	else if (pSticks[0].x < -0.3f)
		this->getBox()->setForce(cocos2d::Vec2(-3, 0));
	if (pSticks[0].y > 0.3f)
		this->getBox()->setForce(cocos2d::Vec2(0, 3));
	else if (pSticks[0].y < -0.3f)
		this->getBox()->setForce(cocos2d::Vec2(0, -3));


	this->updateGameObject();
	
}

void DevitoCult::Pacman::die()
{
	//ya ded
	lives--;
	//play death animation
	this->getBox()->setLocation(cocos2d::Vec2(250, 250));
}
