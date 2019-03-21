#pragma once
#include "Primitive.h"
#include <vector>
namespace DevitoCult {

	class Level {
	public:
		Level();
	///	Level(int LEVELDATA[8][8]);
		//0 = blank space
		//1 = regular square
		void drawMap(cocos2d::Scene* s);


	private:
		std::vector<SquarePrimitive> levelBounds;
		int levelData[9][9] = {
			{1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,1},
			{0,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,1},
			{1,1,1,1,1,1,1,1}

		
		};
	};
}