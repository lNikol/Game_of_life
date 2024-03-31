#pragma once
#include "Organism.h"
#include "Animal.h"
#include "Plant.h"
#include "Cell.h"
#include <vector>

class World {
protected:
	short width = 0, height = 0;
	std::vector<Organism*> plants;
	std::vector < std::vector<Cell*>> map;
	std::vector<Organism*> animals;
	std::vector<Organism*> children;
public:


	World(const short& w, const short& h);
	void takeATurn();
	void drawWorld();
	Organism* getOrganism(const short& x, const short& y) const;
	void setOrganism(Organism* plant, const short& x, const short& y);
	void addOrganism(Organism* org, const short& x, const short& y);
	short getWidth() const;
	short getHeight() const;
	void deleteOrganism(Organism* org, short x, short y);
	void replaceOrganism(Organism* org, const short& x, const short& y);
	//~World();
};