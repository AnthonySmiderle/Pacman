#pragma once
#include "cocos2d.h"
#include "Pacman.h"

class Enemy : cocos2d::Sprite
{
private:
	bool state = false;
	bool alive = true;
	cocos2d::Vec2 spd = (0,0);
public:
	Enemy();
	bool getState();
	void setState(bool s);
	void respawn();
	void update(float dt);
	void hitDetect(DevitoCult::Pacman P);

};