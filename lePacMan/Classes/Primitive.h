//Anthony Smiderle
//100695532
//this code is from Sedna Games' GDW project, and it was written by Anthony Smiderle
#pragma once
#include "cocos2d.h"

namespace DevitoCult {
	//>=
	class dVec2 : public cocos2d::Vec2{
	public:
		dVec2(const cocos2d::Vec2& v) { x = v.x; y = v.y; }

		bool operator>=(const dVec2& dVec);
		bool operator<=(const dVec2& dVec);
		
	};

	class SquarePrimitive {

	public:
		//using reference operator to denote a pointer, otherwise it won't work. Vec2 &name literally means an integer in the computer's memory
		SquarePrimitive(const cocos2d::Vec2 &startingPosition, const cocos2d::Vec2 &endPosition, const cocos2d::Color4F& colour);
		SquarePrimitive();
		~SquarePrimitive();


		//bool isColliding(SquarePrimitive s);

		bool colliding(SquarePrimitive s);
		cocos2d::DrawNode* getDrawNode() const;
		void setColour(cocos2d::Color4F c);
		cocos2d::Vec2 getP1() const { return p1; }
		void setPosition(const cocos2d::Vec2& P1, const cocos2d::Vec2& P2);
		void setP1x(float X) { p1.x = X; }
		void setP2x(float X) { p2.x = X; }
		void setP1y(float Y) { p1.y = Y; }
		void setP2y(float Y) { p2.y = Y; }
		cocos2d::Vec2 getP2() const { return p2; }
		cocos2d::Vec2 getCentre();
		void addForce(cocos2d::Vec2 v);
		void setForce(cocos2d::Vec2 v);
		void update();
		cocos2d::Vec2 getVelocity() const { return velocity; }
	private:
		cocos2d::Color4F colour;
		cocos2d::DrawNode *Node;
		cocos2d::Vec2 velocity;
		cocos2d::Vec2 location;
		cocos2d::Vec2 p1;
		cocos2d::Vec2 p2;



	};
	//the actually useful one
	class CirclePrimitive {
	public:
		CirclePrimitive(const cocos2d::Vec2 &LOCATION, float RADIUS, float ANGLE, unsigned int SEGMENTS);
		CirclePrimitive();
		~CirclePrimitive();


		void setRadius(float r) { radius = r; }
		float getRadius() const { return radius; }
		cocos2d::DrawNode* getDrawNode() const;
		void update();
		void addForce(float vX, float vY);
		void setForce(cocos2d::Vec2 v);
		void setLocation(cocos2d::Vec2 p);//test function 
		cocos2d::Vec2 getVelocity() const;
		cocos2d::Vec2 getLocation() const;
		bool checkCollision(CirclePrimitive other);
		bool checkTouching(CirclePrimitive other);

		bool checkCloseTouching(CirclePrimitive other);

	private:
		cocos2d::Vec2 location;
		float radius;
		float angle;
		unsigned int segments;
		cocos2d::Vec2 velocity;
		cocos2d::DrawNode* Node;
		bool isTumble;

		float dt = 0, dt2 = 0.01f;
	};

}