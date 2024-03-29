#include "World.h"
#include "Animal.h"
#include "Plant.h"
#include <iostream>
using namespace std;

// posortować zwierząt względem inicjatywy (od min do max)

World::World(const short& w, const short& h) :width(w + 2), height(h + 2) {
	map.resize(width, vector<Cell*>(height));
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = new Cell;
			if (i == 0 || i == height - 1) {
				map[i][j]->symbol = "-";
			}
			else if (j == 0 || j == width - 1) {
				map[i][j]->symbol = "|";
			}
			if (i == 0 && j == 0) {
				map[i][j]->symbol = char(218); // naprawic nie dziala char symbol
			}
			if (i == height - 1 && j == width - 1) {
				map[i][j]->symbol = char(217);
			}
			if (j == width - 1 && i == 0) {
				map[i][j]->symbol = char(191);
			}
			else if (j == 0 && i == height - 1) {
				map[i][j]->symbol = char(192);
			}

			if ((j >= 1 && j < width - 1) && (i >= 1 && i < height - 1)) {
				if (j % 2 == 0) {
					map[i][j]->org = new Plant("nic", "kwiat", j * 2 + 1, i * 2 + 2, 0, j, i, this);
					plants.push_back(map[i][j]->org); // robię vector wskaźników na rośliny
				}
				else {
					map[i][j]->org = new Animal("nic", "animal", j * 2 + 1, i * 2 + 2, 0, j, i, this);
					animals.push_back(map[i][j]->org); // robię vector wskaźników na zwierzęta
				}
			}
		}
	}

	//wek[1][1] = new Animal("nic", "wilk", 1, 1, 0, 1, 1, this);
	//animals.push_back(wek[1][1]);

	

}
void World::drawWorld() {
	cout << "Author: Nikolai Lavrinov 201302\n";
}

Organism* World::getOrganism(const short& x, const short& y) const {
	return map[y][x]->org;
}
short World::getWidth() const {
	return width;
}
short World::getHeight() const {
	return height;
}
void World::takeATurn() {
	short int anSize = animals.size();
	for (int i = 0; i < anSize; i++) {
		animals[i]->setAge(animals[i]->getAge() + 1);
	}
	// sortowanie po inicjatywie i wieku
	sort(animals.begin(), animals.end(),
		[](const Organism* a, const Organism* b) {
			if (a->getInitiative() == b->getInitiative()) {
				return a->getAge() > b->getAge();
			}
			else {
				return a->getInitiative() > b->getInitiative();
			}
		});

	
	short int plSize = plants.size();
	for (int i = 0; i < plSize; i++) {
		plants[i]->setAge(plants[i]->getAge() + 1);
	}

	for (int i = 0; i < anSize; i++) {
		animals[i]->action();
	}
}