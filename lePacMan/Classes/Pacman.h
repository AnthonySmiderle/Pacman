//the following code takes inspiration from Sedna Games' GDW project

#pragma once
#include "GameObject.h"
#include "XinputManager.h"
namespace DevitoCult {

	class Pacman :public GameObject {
	public:
		//236.5 159
		Pacman(cocos2d::Scene* s, XinputManager MANAGER, float x = 236 , float y = 158 , float x2 = 244 , float y2 = 166 );
		~Pacman();
		void update();
		void die() override;
		unsigned score = 0;
	private:
		XinputController* pController;
		Stick pSticks[2];
		int lives = 3;


	};
}