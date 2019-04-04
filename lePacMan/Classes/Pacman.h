//the following code takes inspiration from Sedna Games' GDW project

#pragma once
#include "GameObject.h"
namespace OOP {

	class Pacman :public GameObject {
	public:
		//236.5 159
		Pacman(cocos2d::Scene* s, float x = 236 , float y = 158 , float x2 = 244 , float y2 = 166 );
		~Pacman();
		void update(float dt);
		void die() override;
		unsigned score = 0;
		bool isPowerPelletMode() const;
		void setPowerPelletMode(bool yn);
		bool isEating = false;
	private:
		float movementSpeed = 1.5f;
		float powermodeTimer = 0.0f;
		bool powerPelletMode = false;
		int lives = 3;


	};
}