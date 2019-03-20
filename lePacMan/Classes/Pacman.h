#pragma once
#include "GameObject.h"
#include "XinputManager.h"
namespace DevitoCult {

	class Pacman :public GameObject {
	public:
		Pacman(cocos2d::Scene* s, XinputManager MANAGER, float x = 250, float y = 250);
		~Pacman();
		//a player needs to move
		void update();
		void die() override;


	private:
		XinputController* pController;
		Stick pSticks[2];
		int lives = 3;


	};
}