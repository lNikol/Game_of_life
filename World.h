#pragma once
#include "Organism.h"
#include "Animal.h"
#include "Plant.h"
#include "Cell.h"
#include <vector>

class World {
	bool isEnd = false;
protected:
	short width = 0, height = 0;
	std::vector<Organism*> plants;
	std::vector < std::vector<Cell*>> map;
	std::vector<Organism*> animals;
	std::vector<Organism*> children;
	std::string w_string;
public:
	World(const short& w, const short& h);
	void takeATurn();
	void drawWorld();
	Organism* getOrganism(short x, short y) const;
	void setOrganism(Organism* plant, short x, short y);
	void addOrganism(Organism* org, short x, short y);
	short getWidth() const;
	short getHeight() const;
	bool getIsEnd() const;
	void deleteOrganism(Organism* org, short x, short y);
	void replaceOrganism(Organism* org, short x, short y);
	std::pair<short, short> randomPos();
	std::string worldToString();
	//~World();
};