#include "Level.h"
#define BOXSIZE 15
namespace DevitoCult {

	DevitoCult::Level::Level()
	{
	}

	void DevitoCult::Level::drawMap(cocos2d::Scene * s)
	{
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 27; j++) {
				if (levelData[i][j] == 1) {
					levelBounds.push_back(SquarePrimitive(cocos2d::Vec2(37, 303), cocos2d::Vec2(37 + BOXSIZE, 303 +BOXSIZE),cocos2d::Color4F(0,0,1.0f,1.0f)));
					s->addChild(levelBounds.back().getDrawNode());
					levelBounds.back().setPosition(cocos2d::Vec2(levelBounds.back().getP1().x + (j*BOXSIZE), levelBounds.back().getP1().y - (i*BOXSIZE)),
						cocos2d::Vec2(levelBounds.back().getP2().x + (j*BOXSIZE),levelBounds.back().getP2().y - (i*BOXSIZE)));
					levelBounds.back().setColour(cocos2d::Color4F(0, 0, 1.0f, 1.0f));
				}

			}
		}
		for (auto x : levelBounds)
			x.update();
	}

	std::vector<SquarePrimitive> DevitoCult::Level::getBounds() const
	{
		return levelBounds;
	}


	SquarePrimitive Level::operator[](const unsigned index) 
	{
		if (index > levelBounds.size() - 1)
			exit(std::stoi("Very unfortunate. Out of index."));
		return levelBounds[index];
	}
}
