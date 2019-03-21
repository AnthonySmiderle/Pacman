#pragma once
#include "cocos2d.h"
#include "Primitive.h"
#include <string>

namespace DevitoCult {

	class GameObject{
	public:
		GameObject() {}
		GameObject(const char* FILEPATH, const cocos2d::Vec2 &LOCATION, float RADIUS, float ANGLE, unsigned int SEGMENTS);
		virtual ~GameObject() { delete sprite; delete hitBox; }
		cocos2d::Sprite* getSprite()const;
		DevitoCult::CirclePrimitive* getBox()const;
		DevitoCult::SquarePrimitive* getAltBox() const;
		void setCircle(CirclePrimitive c) { *hitBox = c; }
		void updateGameObject();
		int getHP() const;
		void setHP(int hp);
		virtual void die() = 0;
		
		const float spriteScale = 0.75f;
	protected:
		int objectHp;
		cocos2d::Sprite *sprite;
		DevitoCult::CirclePrimitive* hitBox;
		DevitoCult::SquarePrimitive* altHitBox;
	};
}