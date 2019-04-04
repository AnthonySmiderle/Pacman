#include "Level.h"
#include "Pacman.h"
#include <iostream>
#define BOXSIZE 15
#define PACDOTSIZE 2
namespace OOP {

	OOP::Level::Level()
	{
	}

	Level::Level(unsigned levelNumber)
	{
		if (levelNumber == 1) {

			int levelData1[21][27] = {//20,
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,0,3,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,3,0,1},
				{1,0,1,1,1,1,0,1,1,2,1,1,2,2,2,1,1,2,1,1,0,1,1,1,1,0,1},
				{1,0,1,1,1,1,0,1,1,2,1,2,2,2,2,2,1,2,1,1,0,1,1,1,1,0,1},
				{1,0,0,0,0,0,0,1,1,2,1,1,1,1,1,1,1,2,1,1,0,0,0,0,0,0,1},
				{1,1,1,1,0,1,0,0,2,2,2,2,2,2,2,2,2,2,2,0,0,1,0,1,1,1,1},
				{2,2,2,1,0,1,0,1,1,2,1,1,1,1,1,1,1,2,1,1,0,1,0,1,2,2,2},
				{2,2,2,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,2,2,2},
				{1,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,1},
				{2,2,2,2,0,0,0,0,0,1,1,1,0,1,0,1,1,1,0,0,0,0,0,2,2,2,2},
				{1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1},
				{2,2,2,1,0,1,0,1,1,1,0,1,1,0,1,1,0,1,1,1,0,1,0,1,2,2,2},
				{2,2,2,1,0,1,0,1,0,0,0,1,1,0,1,1,0,0,0,1,0,1,0,1,2,2,2},
				{1,1,1,1,0,1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,0,1,0,1,1,1,1},
				{1,0,0,0,0,0,0,1,0,1,0,1,1,0,1,1,0,1,0,1,0,0,0,0,0,0,1},
				{1,0,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,0,1},
				{1,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,1},
				{1,0,1,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,0,1},
				{1,3,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,3,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},


			};
			for (unsigned i = 0; i < 21; ++i)
				for (unsigned j = 0; j < 27; ++j)
					levelData[i][j] = levelData1[i][j];

		}
		else if (levelNumber == 2) {
			int levelData2[21][27] = {//20,
			{2,1,1,1,1,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,2},
			{2,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,2},
			{2,1,0,1,1,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,1,1,0,1,2},
			{2,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,2},
			{2,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,2},
			{2,1,1,1,0,1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,0,1,1,1,2},
			{2,2,2,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,2,2,2},
			{2,2,2,1,0,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,0,1,2,2,2},
			{1,1,1,1,0,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,0,1,1,1,1},
			{2,2,2,2,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,2,2,2,2},
			{1,1,1,1,0,1,0,1,1,2,1,1,1,1,1,1,1,2,1,1,0,1,0,1,1,1,1},
			{2,2,2,1,0,1,0,0,2,2,2,2,2,2,2,2,2,2,2,0,0,1,0,1,2,2,2},
			{2,2,2,1,0,1,1,1,1,2,1,1,1,1,1,1,1,2,1,1,1,1,0,1,2,2,2},
			{2,2,2,1,0,1,0,0,2,2,1,2,2,2,2,2,1,2,2,0,0,1,0,1,2,2,2},
			{2,2,1,1,0,1,0,1,1,2,1,1,1,1,1,1,1,2,1,1,0,1,0,1,1,2,2},
			{2,2,1,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,1,2,2},
			{2,2,1,0,1,1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,1,0,1,2,2},
			{2,2,1,0,1,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,1,2,2},
			{2,2,1,0,1,1,0,1,1,1,1,0,1,0,1,0,1,1,1,1,0,1,1,0,1,2,2},
			{2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2},
			{2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2},

			};

			for (unsigned i = 0; i < 21; ++i)
				for (unsigned j = 0; j < 27; ++j)
					levelData[i][j] = levelData2[i][j];
		}
		else
			exit(std::stoi("out of index"));
	}

	void OOP::Level::drawMap(cocos2d::Scene * s)
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
				else if (levelData[i][j] == 1) {
					levelBounds.push_back(new SquarePrimitive(cocos2d::Vec2(37, 303), cocos2d::Vec2(37 + BOXSIZE, 303 + BOXSIZE), cocos2d::Color4F(0, 0, 1.0f, 1.0f),true));
					s->addChild(levelBounds.back()->getDrawNode());

					//put the walls where they're supposed to be
					levelBounds.back()->setPosition(cocos2d::Vec2(levelBounds.back()->getP1().x + (j*BOXSIZE), levelBounds.back()->getP1().y - (i*BOXSIZE)),
						cocos2d::Vec2(levelBounds.back()->getP2().x + (j*BOXSIZE), levelBounds.back()->getP2().y - (i*BOXSIZE)));

				}


				//path...might not use. The ghosts dont need to track
				else if (levelData[i][j] == 2) {
					path.push_back(new SquarePrimitive(cocos2d::Vec2(37, 303), cocos2d::Vec2(37 + BOXSIZE, 303 + BOXSIZE), cocos2d::Color4F(0, 0, 1.0f, 1.0f)));
					s->addChild(path.back()->getDrawNode());

					//put the walls where they're supposed to be
					path.back()->setPosition(cocos2d::Vec2(path.back()->getP1().x + (j*BOXSIZE), path.back()->getP1().y - (i*BOXSIZE)),
						cocos2d::Vec2(path.back()->getP2().x + (j*BOXSIZE), path.back()->getP2().y - (i*BOXSIZE)));

					path.back()->getDrawNode()->setVisible(false);
				}

				//power pellets
				else if (levelData[i][j] == 3) {
					//make a new square and slap it into the list of pacdots
					pacDots.push_back(new SquarePrimitive(cocos2d::Vec2(37, 303), cocos2d::Vec2(37 + PACDOTSIZE * 3, 303 + PACDOTSIZE * 3), cocos2d::Color4F(1.0f, 1.0f, 0, 1.0f), true));
					s->addChild(pacDots.back()->getDrawNode());

					//put the pacdots in the place they're supposed to be
					pacDots.back()->setPosition(cocos2d::Vec2(pacDots.back()->getP1().x + (j*BOXSIZE) + (0.38F * BOXSIZE), pacDots.back()->getP1().y - (i*BOXSIZE) + (0.38F * BOXSIZE)),
						cocos2d::Vec2(pacDots.back()->getP2().x + (j*BOXSIZE) + (0.33F * BOXSIZE), pacDots.back()->getP2().y - (i*BOXSIZE) + (0.33F * BOXSIZE)));


				}
				//grey walls for ghosts
				else if (levelData[i][j] == 4) {
					levelBounds.push_back(new SquarePrimitive(cocos2d::Vec2(37, 303), cocos2d::Vec2(37 + BOXSIZE, 303 + BOXSIZE), cocos2d::Color4F(0.5f, 0.5f, 0.5f, 1.0f),true));
					s->addChild(levelBounds.back()->getDrawNode());

					//put the walls where they're supposed to be
					levelBounds.back()->setPosition(cocos2d::Vec2(levelBounds.back()->getP1().x + (j*BOXSIZE), levelBounds.back()->getP1().y - (i*BOXSIZE)),
						cocos2d::Vec2(levelBounds.back()->getP2().x + (j*BOXSIZE), levelBounds.back()->getP2().y - (i*BOXSIZE)));

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
				
				if (pacDots[i]->isFilled()) {
					p->score += 50;//might have to change this
					p->setPowerPelletMode(true);
				}
				else
					p->score += 10;//might have to change this
				p->isEating = true;


				pacDots[i]->getDrawNode()->removeFromParent();
				pacDots.erase(pacDots.begin() + i);
				i--;

			}
			else
				p->isEating = false;
		}

	}

	void Level::checkWall(GameObject * P)
	{
		//keep that pesky player out of the walls
		//get the direction vector
		auto norm = P->getAltBox()->getVelocity() / sqrt(P->getAltBox()->getVelocity().x*P->getAltBox()->getVelocity().x + P->getAltBox()->getVelocity().y*P->getAltBox()->getVelocity().y);
		for (unsigned i = 0; i < levelBounds.size(); i++) {
			if (levelBounds[i]->colliding(*P->getAltBox())) {
				P->getAltBox()->setPosition(P->getAltBox()->getP1() - norm * 4, P->getAltBox()->getP2() - norm * 4);
				P->getAltBox()->addForce(cocos2d::Vec2(0, 0));
			}
		}
	}

	cocos2d::Vec2 Level::checkPath(Pacman * p)
	{
		for (unsigned i = 0; i < path.size(); ++i)
			if (path[i]->colliding(*p->getAltBox()))
				return path[i]->getCentre();

	}

	std::vector<SquarePrimitive*> OOP::Level::getBounds() const
	{
		return levelBounds;
	}

	std::vector<SquarePrimitive*> Level::getPacdots() const
	{
		return pacDots;
	}

	std::vector<SquarePrimitive*> Level::getPath() const
	{
		return path;
	}


	SquarePrimitive* Level::operator[](const unsigned index)
	{
		if (index > levelBounds.size() - 1)
			exit(std::stoi("Very unfortunate. Out of index."));
		return levelBounds[index];
	}
}
