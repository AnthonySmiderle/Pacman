#pragma once
#include "Primitive.h"
#include <vector>
#include "Fruit.h"

namespace DevitoCult {
	class Pacman;
	class Level {
	public:
		Level();
		Level(unsigned levelNumber);
		void drawMap(cocos2d::Scene* s);
		void checkEat(Pacman* p);
		void checkWall(Pacman* P);
		cocos2d::Vec2 checkPath(Pacman* p);
		std::vector<SquarePrimitive*> getBounds() const;
		std::vector<SquarePrimitive*> getPacdots() const;
		std::vector<SquarePrimitive*> getPath() const;

		SquarePrimitive* operator[](const unsigned index);

	private:
		std::vector<SquarePrimitive*> levelBounds;
		std::vector<SquarePrimitive*> pacDots;
		std::vector<SquarePrimitive*> path;
		std::vector<Fruit> Fruits;
		int levelData[21][27];


		
	};					   
}						   
