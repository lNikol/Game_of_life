#pragma once
#include "Organism.h"
#include "Plant.h"
#include "Animal.h"
#include <vector>
using namespace std;

class World {
private:
	short N = 0, M = 0;
	vector<Organism*> plants;
	vector<Organism*> animals;
public:
	vector < vector<Organism*>> wek;

	World(const short& N, const short& M);
	void takeATurn();
	void drawWorld();
	//Organism* getOrganism(std::pair<const short&, const short&>) const;
	//World* getWorld() const;
	//~World();
};