#include "Level.h"

DevitoCult::Level::Level()
{
}

void DevitoCult::Level::drawMap(cocos2d::Scene * s)
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (levelData[i][j] == 1) {
				levelBounds.push_back(SquarePrimitive(cocos2d::Vec2(10, 10), cocos2d::Vec2(20, 20)));
				s->addChild(levelBounds.back().getDrawNode());
				levelBounds.back().getDrawNode()->setPosition(cocos2d::Vec2(10 + (i * 30), 280 - (j * 30)));
			}

		}
	}
	for (auto x : levelBounds)
		x.update();
}
