#pragma once
#include "Organism.h"
#include "Cell.h"
#include <vector>

class World {
protected:
	short width = 0, height = 0;
	std::vector<Organism*> plants;
	std::vector < std::vector<Cell*>> map;
	std::vector<Organism*> animals;
public:


	World(const short& w, const short& h);
	void takeATurn();
	void drawWorld();
	Organism* getOrganism(const short& x, const short& y) const;
	short getWidth() const;
	short getHeight() const;
	void deleteOrganism(Organism* org, const short& x, const short& y);
	void replaceOrganism(Organism* org, const short& x, const short& y);
	//~World();
};