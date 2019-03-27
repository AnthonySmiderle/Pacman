#include "Level.h"
#include <iostream>
#define BOXSIZE 15
#define PACDOTSIZE 5
namespace DevitoCult {

	DevitoCult::Level::Level()
	{
	}

	void DevitoCult::Level::drawMap(cocos2d::Scene * s)
	{
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 27; j++) {
				if (levelData[i][j] == 0) {
					pacDots.push_back(new SquarePrimitive(cocos2d::Vec2(37, 303), cocos2d::Vec2(37 + PACDOTSIZE, 303 + PACDOTSIZE), cocos2d::Color4F(1.0f, 1.0f, 0, 1.0f)));
					s->addChild(pacDots.back()->getDrawNode());

					pacDots.back()->setPosition(cocos2d::Vec2(pacDots.back()->getP1().x + (j*BOXSIZE) + (0.35F * BOXSIZE), pacDots.back()->getP1().y - (i*BOXSIZE) + (0.35F * BOXSIZE)),
						cocos2d::Vec2(pacDots.back()->getP2().x + (j*BOXSIZE) + (0.35F * BOXSIZE), pacDots.back()->getP2().y - (i*BOXSIZE) + (0.35F * BOXSIZE)));


					//pacDots.back()->setColour(cocos2d::Color4F(0, 0, 1.0f, 1.0f));
				}
				if (levelData[i][j] == 1) {
					levelBounds.push_back(new SquarePrimitive(cocos2d::Vec2(37, 303), cocos2d::Vec2(37 + BOXSIZE, 303 +BOXSIZE),cocos2d::Color4F(0,0,1.0f,1.0f)));
					s->addChild(levelBounds.back()->getDrawNode());

					levelBounds.back()->setPosition(cocos2d::Vec2(levelBounds.back()->getP1().x + (j*BOXSIZE), levelBounds.back()->getP1().y - (i*BOXSIZE)),
						cocos2d::Vec2(levelBounds.back()->getP2().x + (j*BOXSIZE),levelBounds.back()->getP2().y - (i*BOXSIZE)));

				//	levelBounds.back()->setColour(cocos2d::Color4F(0, 0, 1.0f, 1.0f));
				}

			}
		}
		for (auto x : levelBounds)
			x->update();
		for (auto x : pacDots)
			x->update();
		//for (auto x : levelBounds)
		//	std::cout << x.getP1().x << " " << x.getP1().y << " " << x.getP2().x << " " << x.getP2().y << "\n";
	}

	std::vector<SquarePrimitive*> DevitoCult::Level::getBounds() const
	{
		return levelBounds;
	}


	SquarePrimitive* Level::operator[](const unsigned index) 
	{
		if (index > levelBounds.size() - 1)
			exit(std::stoi("Very unfortunate. Out of index."));
		return levelBounds[index];
	}
}
