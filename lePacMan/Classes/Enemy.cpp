#include "Enemy.h"
#include "Pacman.h"
namespace OOP {

	Enemy::Enemy()
	{
	}

	Enemy::Enemy(cocos2d::Scene* s, std::string FILEPATH, float x, float y, float x2, float y2)
	{
		srand(100);
		altHitBox = new SquarePrimitive(cocos2d::Vec2(x, y), cocos2d::Vec2(x2, y2), cocos2d::Color4F(0, 0, 1.0f, 1.0f));
		sprite = cocos2d::Sprite::create("blinkySide1.png");
		sprite->setScale(0.04f);
		altHitBox->getDrawNode()->setVisible(false);
		s->addChild(sprite);
		s->addChild(altHitBox->getDrawNode());


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
		static float timer = 0.0f;
		timer += dt;
		if (timer >= 2.0f) {
			auto x = rand() % 2;
			this->getAltBox()->setForce(cocos2d::Vec2(x ? rand() % 3 * (rand() % 2 == 1 ? -1 : 1) : 0, x ? 0 : rand() % 3 * (rand() % 2 == 1 ? -1 : 1)));
			timer = 0.0f;
		}

		this->updateGameObject();
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
		return false;
	}

	void Enemy::die()
	{
	}

	//void Enemy::hitDetect(OOP::Pacman P)
	//{
	//}
}
