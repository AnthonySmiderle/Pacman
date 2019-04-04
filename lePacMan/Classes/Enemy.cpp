#include "Enemy.h"
#include "Pacman.h"
namespace OOP {

Enemy::Enemy()
{
}

Enemy::Enemy(std::string FILEPATH, float x, float y, float x2, float y2)
{

	altHitBox = new SquarePrimitive(cocos2d::Vec2(x, y), cocos2d::Vec2(x2, y2), cocos2d::Color4F(0, 0, 1.0f, 1.0f));
	sprite = cocos2d::Sprite::create("replacethis");

	//other ghost stuff

}

Enemy::~Enemy()
{
	sprite->removeFromParent();
	altHitBox->getDrawNode()->removeFromParent();
}

bool Enemy::getState()
{
	return false;
}

void Enemy::setState(bool s)
{
}

void Enemy::respawn()
{
}

void Enemy::update(float dt)
{
}

bool Enemy::hitDetect(Pacman * p)
{
	if (this->getAltBox()->colliding(*p->getAltBox()) && !p->isPowerPelletMode()) {
		//pacman dies
		p->die();
		return false;
	}
	else if (this->getAltBox()->colliding(*p->getAltBox()) && p->isPowerPelletMode()) {
		//this-> dies
		//handle deleting OUTSIDE of the class, so we dont risk some form of memory issue
		return true;
	}
}

//void Enemy::hitDetect(OOP::Pacman P)
//{
//}
}
