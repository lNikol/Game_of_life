#include "World.h"
#include "WilczeJagody.h"
#include "Grass.h"
#include "BarszczSosnowskiego.h"
#include "Guarana.h"
#include "Mlecz.h"
#include "Antelope.h"
#include "Fox.h"
#include "Sheep.h"
#include "Turtle.h"
#include "Wolf.h"
#include <iostream>
using namespace std;

//Przy uruchomieniu programu na planszy powinno się
//pojawić po kilka sztuk wszystkich rodzajów zwierząt oraz roślin

World::World(const short& w, const short& h) :height(h + 2), width(w + 2) {
	map.resize(height, vector<Cell*>(width));
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = new Cell;
			map[i][j]->x = j;
			map[i][j]->y = i;
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
		}
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if ((j >= 1 && j < width - 1) && (i >= 1 && i < height - 1)) {
				if (j % 4 == 1) {
					std::pair<short, short> randPos = randomPos();
					switch ((i + j) % 5) {
					case 0: {
						map[randPos.second][randPos.first]->org = new Guarana("nic", "Guarana" + to_string(j + i * 2), 0, 0, 0, randPos.first, randPos.second, this);
						break;
					}
					case 1: {
						map[randPos.second][randPos.first]->org = new WilczeJagody("nic", "Jagody" + to_string(j + i * 2), 99, 0, 0, randPos.first, randPos.second, this);
						break;
					}
					case 2: {
						map[randPos.second][randPos.first]->org = new BarszczSosnowskiego("nic", "Barszcz" + to_string(j + i * 2), 10, 0, 0, randPos.first, randPos.second, this);
						break;
					}
					case 3: {
						map[randPos.second][randPos.first]->org = new Grass("nic", "Grass" + to_string(j + i * 2), 0, 0, 0, randPos.first, randPos.second, this);
						break;
					}
					case 4: {
						map[randPos.second][randPos.first]->org = new Mlecz("nic", "Mlecz" + to_string(j + i * 2), 0, 0, 0, randPos.first, randPos.second, this);
						break;
					}
					}
					plants.push_back(map[randPos.second][randPos.first]->org); // robię vector wskaźników na rośliny
				}
				else if (j % 4 == 0) {
					std::pair<short, short> randPos = randomPos();
					switch ((i + j) % 5) {
					case 0: {
						map[randPos.second][randPos.first]->org = new Wolf("nic", "Wolf" + to_string(j + i * 2), 9, 5, 0, randPos.first, randPos.second, this);
						break;
					}
					case 1: {
						map[randPos.second][randPos.first]->org = new Sheep("nic", "Sheep" + to_string(j + i * 2), 4, 4, 0, randPos.first, randPos.second, this);
						break;
					}
					case 2: {
						map[randPos.second][randPos.first]->org = new Fox("nic", "Fox" + to_string(j + i * 2), 3, 7, 0, randPos.first, randPos.second, this);
						break;
					}
					case 3: {
						map[randPos.second][randPos.first]->org = new Turtle("nic", "Turtle" + to_string(j + i * 2), 2, 1, 0, randPos.first, randPos.second, this);
						break;
					}
					case 4: {
						map[randPos.second][randPos.first]->org = new Antelope("nic", "Antelope" + to_string(j + i * 2), 4, 4, 0, randPos.first, randPos.second, this);
						break;
					}
					}
					animals.push_back(map[randPos.second][randPos.first]->org); // robię vector wskaźników na zwierzęta
				}
			}
		}
	}
}

void World::drawWorld() {
	cout << "Author: Nikolai Lavrinov 201302\n";
}


std::pair<short, short> World::randomPos() {
	short h = height - 2;
	short w = width - 2;
	short x = rand() % w + 1;
	short y = rand() % h + 1;
	while (getOrganism(x, y) != nullptr) {
		x = rand() % w + 1;
		y = rand() % h + 1;
	}
	return std::make_pair<short&, short&>(x, y);
}

Organism* World::getOrganism(const short& x, const short& y) const {
	return this->map[y][x]->org;
}

void World::deleteOrganism(Organism* org, short x, short y) {

	if (org != nullptr) {
		cout << "World::deleteOrganism: " << org->getName();
		cout << " " << org->getX() << " " << org->getY() << endl;
		this->map[y][x]->org = nullptr;
		bool isDeleted = false;
		if (dynamic_cast<Animal*>(org)) {
			for (int i = 0; i < animals.size(); i++) {
				if (animals[i] == org) {
					animals[i]->deleteOrganism();
					animals.erase(animals.begin() + i);
					isDeleted = true;
					return;
				}
			}
		}
		else if (dynamic_cast<Plant*>(org)) {
			for (int i = 0; i < plants.size(); i++) {
				if (plants[i] == org) {
					plants[i]->deleteOrganism();
					plants.erase(plants.begin() + i);
					isDeleted = true;
					return;
				}
			}
		}
		else if (!isDeleted) {
			short childrenSize = children.size();
			for (int i = 0; i < childrenSize; i++) {
				if (children[i] == org) {
					children[i]->deleteOrganism();
					children.erase(children.begin() + i);
					return;
				}
			}
		}
	}
}

void World::replaceOrganism(Organism* org, const short& x, const short& y) {
	map[y][x]->org = org;
}

short World::getWidth() const {
	return width;
}

short World::getHeight() const {
	return height;
}

void World::takeATurn() {
	short childrenSize = children.size();
	for (int i = 0; i < childrenSize; i++) {
		if (children[i] != nullptr) {
		if (dynamic_cast<Animal*>(children[i])) {
			animals.push_back(children[i]);
		}
		else if (dynamic_cast<Plant*>(children[i])) {
			plants.push_back(children[i]);
		}
		}
	}
	children.clear();

	short anSize = animals.size();
	for (int i = 0; i < anSize; i++) {
		dynamic_cast<Animal*>(animals[i])->setIsMoved(false);
		animals[i]->setAge(animals[i]->getAge() + 1);
		//cout <<"XY: " << animals[i]->getX() << " " << animals[i]->getY() << endl;
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

	//int k = 0;

	for (auto* animal : animals) {
		//cout << "auto size: " << animals.size() << endl;
		//k++;
		//cout << "Auto* animal: " << animal;
		//cout << " " << animal->getX() << ", " << animal->getY() << endl;
		//cout << "k: " << k << endl;
		if (dynamic_cast<Animal*>(animal) != nullptr) {
			cout << "auto XY: " << animal->getX() << " " << animal->getY() << endl;
			if (!dynamic_cast<Animal*>(animal)->getIsMoved() && animal->getX() != -1) {
				animal->action();
			}
			if (animal->getX() == -1) {
				cout << "\n\n-------  " << animal->getName() << "  ------------------------------- MINUS JEDEN ---------------------------------------\n\n";
				cout << endl;
				break;
			}
		}
	}

	for (auto* plant : plants) {
		if (!dynamic_cast<Plant*>(plant)->getIsMoved() && plant->getX() != -1) {
			plant->action();
		}
		if (plant->getX() == -1) {
			cout << "\n\n-------  " << plant->getName() << "  ------------------------------- MINUS KWIAT ---------------------------------------\n\n";
			cout << endl;
			break;
		}
	}
}

void World::addOrganism(Organism* org, const short& x, const short& y) {
	//cout << "addOrganism size before: " << children.size() << endl;
	if (dynamic_cast<Animal*>(org)) {
		map[y][x]->org = org;
		children.push_back(org);
		//cout << "add organism: " << org << endl;
	}
	else if (dynamic_cast<Plant*>(org)) {
		map[y][x]->org = org;
		children.push_back(org);
	}
	else if (org == nullptr) {
		cout << "It is not possible to add an organism\n";
	}
	//cout << "addOrganism size after: " << children.size() << endl;
}

void World::setOrganism(Organism* plant, const short& x, const short& y) {
	if (getOrganism(x, y) == nullptr) {
		Plant* cast = dynamic_cast<Plant*>(plant);
		if (dynamic_cast<Grass*>(cast)) {
			map[y][x]->org = new Grass("nic", "Nowa", 0, 0, 0, x, y, this);
		}
		else if (dynamic_cast<Guarana*>(cast)) {
			map[y][x]->org = new Guarana("nic", "Guarana", 0, 0, 0, x, y, this);
		}
		else if (dynamic_cast<Mlecz*>(cast)) {
			map[y][x]->org = new Mlecz("nic", "Mlecz", 0, 0, 0, x, y, this);
		}
		else if (dynamic_cast<WilczeJagody*>(cast)) {
			map[y][x]->org = new WilczeJagody("nic", "WilczeJagody", 99, 0, 0, x, y, this);
		}
		else if (dynamic_cast<BarszczSosnowskiego*>(cast)) {
			map[y][x]->org = new BarszczSosnowskiego("nic", "BarszczSosnowskiego", 10, 0, 0, x, y, this);
		}
		else {
			cout << "\nbrak tego gotunku czy inny błąd\n";
		}
		if (map[y][x]->org != nullptr) {
			children.push_back(map[y][x]->org);
		}
	}
	else {
		cout << "The plant could not be added, the cell is occupied\n";
	}
}