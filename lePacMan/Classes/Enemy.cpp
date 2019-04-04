#include "Enemy.h"
#include "Pacman.h"
namespace OOP {

Enemy::Enemy()
{
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

void Enemy::hitDetect(Pacman * p)
{
	if (this->getAltBox()->colliding(*p->getAltBox()) && !p->isPowerPelletMode()) {
		//pacman dies
		p->die();
	}
	else if (this->getAltBox()->colliding(*p->getAltBox()) && p->isPowerPelletMode()) {
		//this-> dies
		//handle deleting OUTSIDE of the class, so we dont risk some form of memory issue
	}
}

//void Enemy::hitDetect(OOP::Pacman P)
//{
//}
}
