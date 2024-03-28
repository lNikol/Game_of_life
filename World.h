#pragma once
#include "Organism.h"
//#include "Plant.h"
//#include "Animal.h"
#include <vector>

class World {
private:
	short N = 0, M = 0;
	std::vector<Organism*> plants;
	std::vector<Organism*> animals;
public:
	std::vector < std::vector<Organism*>> wek;

	World(const short& N, const short& M);
	void takeATurn();
	void drawWorld();
	//Organism* getOrganism(std::pair<const short&, const short&>) const;
	//World* getWorld() const;
	//~World();
};