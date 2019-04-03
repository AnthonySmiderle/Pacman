#include "Level.h"
#include "Pacman.h"
#include <iostream>
#define BOXSIZE 15
#define PACDOTSIZE 2
namespace DevitoCult {

	DevitoCult::Level::Level()
	{
	}

	void DevitoCult::Level::drawMap(cocos2d::Scene * s)
	{
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 27; j++) {
				if (levelData[i][j] == 0) {
					//make a new square and slap it into the list of pacdots
					pacDots.push_back(new SquarePrimitive(cocos2d::Vec2(37, 303), cocos2d::Vec2(37 + PACDOTSIZE, 303 + PACDOTSIZE), cocos2d::Color4F(1.0f, 1.0f, 0, 1.0f)));
					s->addChild(pacDots.back()->getDrawNode());

					//put the pacdots in the place they're supposed to be
					pacDots.back()->setPosition(cocos2d::Vec2(pacDots.back()->getP1().x + (j*BOXSIZE) + (0.40F * BOXSIZE), pacDots.back()->getP1().y - (i*BOXSIZE) + (0.40F * BOXSIZE)),
						cocos2d::Vec2(pacDots.back()->getP2().x + (j*BOXSIZE) + (0.35F * BOXSIZE), pacDots.back()->getP2().y - (i*BOXSIZE) + (0.35F * BOXSIZE)));


				}
				if (levelData[i][j] == 1) {
					levelBounds.push_back(new SquarePrimitive(cocos2d::Vec2(37, 303), cocos2d::Vec2(37 + BOXSIZE, 303 +BOXSIZE),cocos2d::Color4F(0,0,1.0f,1.0f)));
					s->addChild(levelBounds.back()->getDrawNode());

					//put the walls where they're supposed to be
					levelBounds.back()->setPosition(cocos2d::Vec2(levelBounds.back()->getP1().x + (j*BOXSIZE), levelBounds.back()->getP1().y - (i*BOXSIZE)),
						cocos2d::Vec2(levelBounds.back()->getP2().x + (j*BOXSIZE),levelBounds.back()->getP2().y - (i*BOXSIZE)));

				}

			}
		}
		//update all the boxes so they appear in the correct place
		for (auto x : levelBounds)
			x->update();
		for (auto x : pacDots)
			x->update();
	}

	void Level::checkEat(Pacman * p)
	{
		//check to see if the player should eat a pacdot
		for (unsigned i = 0; i < pacDots.size(); i++) {
			if (pacDots[i]->colliding(*p->getAltBox())) {
				pacDots[i]->getDrawNode()->removeFromParent();
				pacDots.erase(pacDots.begin() + i);
				i--;
			}
		}
	}

	void Level::checkWall(Pacman * P)
	{
		//keep that pesky player out of the walls
		//get the direction vector
		auto norm = P->getAltBox()->getVelocity() / sqrt(P->getAltBox()->getVelocity().x*P->getAltBox()->getVelocity().x + P->getAltBox()->getVelocity().y*P->getAltBox()->getVelocity().y);
		for (unsigned i = 0; i < levelBounds.size(); i++) {
			if (levelBounds[i]->colliding(*P->getAltBox())) {
				P->getAltBox()->setPosition(P->getAltBox()->getP1() - norm*4, P->getAltBox()->getP2() - norm*4);
				P->getAltBox()->addForce(cocos2d::Vec2(0, 0));
			}
		}
	}

	std::vector<SquarePrimitive*> DevitoCult::Level::getBounds() const
	{
		return levelBounds;
	}

	std::vector<SquarePrimitive*> Level::getPacdots() const
	{
		return pacDots;
	}


	SquarePrimitive* Level::operator[](const unsigned index) 
	{
		if (index > levelBounds.size() - 1)
			exit(std::stoi("Very unfortunate. Out of index."));
		return levelBounds[index];
	}
}
