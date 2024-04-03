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
#include "Human.h"
#include <iostream>
using namespace std;

//Przy uruchomieniu programu na planszy powinno się
//pojawić po kilka sztuk wszystkich rodzajów zwierząt oraz roślin

World::World(const short& w, const short& h) :width(w + 2), height(h + 2) {
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
				map[i][j]->symbol = "┌"; // naprawic nie dziala char symbol
			}
			if (i == height - 1 && j == width - 1) {
				map[i][j]->symbol = "┘";
			}
			if (j == width - 1 && i == 0) {
				map[i][j]->symbol = "┐";
			}
			else if (j == 0 && i == height - 1) {
				map[i][j]->symbol = "└";
			}			
		}
	}
	
	Human* human = new Human(1, 1, this);
	animals.push_back(human);
	map[1][1]->org = human;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if ((j >= 1 && j < width - 1) && (i >= 1 && i < height - 1)) {
				if (j % 4 == 1) {
					std::pair<short, short> randPos = randomPos();
					switch ((i + j) % 5) {
					case 0: {
						map[randPos.second][randPos.first]->org = new Guarana(randPos.first, randPos.second, this);
						break;
					}
					case 1: {
						map[randPos.second][randPos.first]->org = new WilczeJagody(randPos.first, randPos.second, this);
						break;
					}
					case 2: {
						map[randPos.second][randPos.first]->org = new BarszczSosnowskiego(randPos.first, randPos.second, this);
						break;
					}
					case 3: {
						map[randPos.second][randPos.first]->org = new Grass(randPos.first, randPos.second, this);
						break;
					}
					case 4: {
						map[randPos.second][randPos.first]->org = new Mlecz(randPos.first, randPos.second, this);
						break;
					}
					}
					plants.push_back(map[randPos.second][randPos.first]->org); // robię vector wskaźników na rośliny
				}
				//else if (j % 4 == 0) {
				//	std::pair<short, short> randPos = randomPos();
				//	switch ((i + j) % 5) {
				//	case 0: {
				//		map[randPos.second][randPos.first]->org = new Wolf(randPos.first, randPos.second, this);
				//		break;
				//	}
				//	case 1: {
				//		map[randPos.second][randPos.first]->org = new Sheep(randPos.first, randPos.second, this);
				//		break;
				//	}
				//	case 2: {
				//		map[randPos.second][randPos.first]->org = new Fox(randPos.first, randPos.second, this);
				//		break;
				//	}
				//	case 3: {
				//		map[randPos.second][randPos.first]->org = new Turtle(randPos.first, randPos.second, this);
				//		break;
				//	}
				//	case 4: {
				//		map[randPos.second][randPos.first]->org = new Antelope(randPos.first, randPos.second, this);
				//		break;
				//	}
				//	}
				//	animals.push_back(map[randPos.second][randPos.first]->org); // robię vector wskaźników na zwierzęta
				//}
			}
		}
	}
}

void World::drawWorld() {
	cout << "Author: Nikolai Lavrinov 201302\n";
	cout << worldToString();
}

bool World::getIsEnd() const {
	return isEnd;
}

std::string World::worldToString() {
	w_string = "";
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			string symbol = map[i][j]->symbol;
			if (symbol == "") {
				// karta nie usuwa symbol czlowieka, zobaczyc dlaczego
				auto org = getOrganism(j, i);
				if (org != nullptr) {
					// zamienić na metodę drawOrganism()
					symbol = org->getIkona();
				}
				else {
					symbol = ".";
				}
			}
			w_string += symbol;
		}
		w_string += '\n';
	}
	w_string += '\n';
	return w_string;
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
		this->map[y][x]->symbol = "";
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
	if (org == nullptr) map[y][x]->symbol = "";
}

short World::getWidth() const {
	return width;
}

short World::getHeight() const {
	return height;
}

void World::takeATurn() {
	if (isEnd) return;
	else {
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
		cout << worldToString();

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
					if (dynamic_cast<Human*>(animal)) {
						isEnd = true;
						cout << "You was killed\n";
						return;
					}
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
		cout << worldToString();
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
			map[y][x]->org = new Grass(x, y, this);
		}
		else if (dynamic_cast<Guarana*>(cast)) {
			map[y][x]->org = new Guarana(x, y, this);
		}
		else if (dynamic_cast<Mlecz*>(cast)) {
			map[y][x]->org = new Mlecz(x, y, this);
		}
		else if (dynamic_cast<WilczeJagody*>(cast)) {
			map[y][x]->org = new WilczeJagody(x, y, this);
		}
		else if (dynamic_cast<BarszczSosnowskiego*>(cast)) {
			map[y][x]->org = new BarszczSosnowskiego(x, y, this);
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