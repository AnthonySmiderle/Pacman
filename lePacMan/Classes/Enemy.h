#pragma once
#include "GameObject.h"
namespace OOP {
	class Pacman;
class Enemy : public GameObject
{
public:
	Enemy();
	Enemy(std::string FILEPATH, float x, float y, float x2, float y2);
	~Enemy();
	bool getState();
	void setState(bool s);
	void respawn();
	void update(float dt);

	/*there is already a collision detection algorithm that i made within the game object
	void hitDetect(OOP::Pacman* P);
	here is a function that handles collision with power pellet stuff
	return 0 for pacman death, return 1 for ghost death*/
	bool hitDetect(Pacman* p);

private:
	bool state = false;
	bool alive = true;
	cocos2d::Vec2 spd = (0,0);

};
}