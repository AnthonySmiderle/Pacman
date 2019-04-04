//the following code takes inspiration from Sedna Games' GDW project

#include "Pacman.h"
#include "Input.h"
#include "Events.h"
#include<iostream>

OOP::Pacman::Pacman(cocos2d::Scene* s, float x1, float y1, float x2, float y2)
{
	//makes a new sprite and a new hitbox
	sprite = cocos2d::Sprite::create("HelloWorld.png");
	altHitBox = new SquarePrimitive(cocos2d::Vec2(x1, y1), cocos2d::Vec2(x2, y2), cocos2d::Color4F(1.0f, 1.0f, 0, 1.0f));
	sprite->setVisible(false);

	s->addChild(altHitBox->getDrawNode(), 100);
	s->addChild(sprite);
	//altHitBox->getDrawNode()->setPosition(cocos2d::Vec2(x, y));

	this->setHP(1);

}

OOP::Pacman::~Pacman()
{
	sprite->removeFromParent();
	altHitBox->getDrawNode()->removeFromParent();
}

void OOP::Pacman::update(float dt)
{
	if (powerPelletMode)
		powermodeTimer += dt;
	if (powermodeTimer >= 5.0f) //might need to change
		powerPelletMode = false;

	//if (isEating)
	//	movementSpeed = 1.5f*0.0001f;

	if (isEvent(Events::D))
		this->getAltBox()->setForce(cocos2d::Vec2(movementSpeed, 0));
	else if (isEvent(Events::A))
		this->getAltBox()->setForce(cocos2d::Vec2(-movementSpeed, 0));
	if (isEvent(Events::W))
		this->getAltBox()->setForce(cocos2d::Vec2(0, movementSpeed));
	else if (isEvent(Events::S))
		this->getAltBox()->setForce(cocos2d::Vec2(0, -movementSpeed));


	this->updateGameObject();

}

void OOP::Pacman::die()
{
	//ya ded
	lives--;
	//play death animation
	///this->getBox()->setLocation(cocos2d::Vec2(250, 250));
}

bool OOP::Pacman::isPowerPelletMode() const
{
	return powerPelletMode;
}

void OOP::Pacman::setPowerPelletMode(bool yn)
{
	powerPelletMode = yn;
}
