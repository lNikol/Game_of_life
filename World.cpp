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
#include <fstream>
#include <sstream>
#include <regex>
#include <Windows.h>
using namespace std;

World::World(const short& w, const short& h, const bool& fromFile) : width(w + 2), height(h + 2) {
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
				map[i][j]->symbol = "\332"; // naprawic nie dziala char symbol
			}
			if (i == height - 1 && j == width - 1) {
				map[i][j]->symbol = "\331";
			}
			if (j == width - 1 && i == 0) {
				map[i][j]->symbol = "\277";
			}
			else if (j == 0 && i == height - 1) {
				map[i][j]->symbol = "\300";
			}
		}
	}
	if (fromFile) {
		ifstream file("log.log");
		string line;
		if (file.is_open()) {
			getline(file, line);
		}
		// Czytanie danych zwierząt
		regex animalRegex(R"((\w+)\(x,y\): (\d+), (\d+))");
		while (getline(file, line)) {
			smatch match;
			if (regex_search(line, match, animalRegex)) {
				string org = match[1].str();
				short x = stoi(match[2]);
				short y = stoi(match[3]);
				switch (org[0]) {
					case 'A': {
						map[y][x]->org = new Antelope(x, y, this);
						animals.push_back(map[y][x]->org);
						break;
					}
					case 'F': {
						map[y][x]->org = new Fox(x, y, this);
						animals.push_back(map[y][x]->org);
						break;
					}
					case 'W': {
						map[y][x]->org = new Wolf(x, y, this);
						animals.push_back(map[y][x]->org);
						break;
					}
					case 'H': {
						map[y][x]->org = new Human(x, y, this);
						animals.push_back(map[y][x]->org);
						break;
					}
					case 'S': {
						map[y][x]->org = new Sheep(x, y, this);
						animals.push_back(map[y][x]->org);
						break;
					}
					case 'T': {
						map[y][x]->org = new Turtle(x, y, this);
						animals.push_back(map[y][x]->org);
						break;
					}

					case 'B': {
						map[y][x]->org = new BarszczSosnowskiego(x, y, this);
						plants.push_back(map[y][x]->org);
						break;
					}
					case 'g': {
						map[y][x]->org = new Grass(x, y, this);
						plants.push_back(map[y][x]->org);
						break;
					}
					case 'G': {
						map[y][x]->org = new Guarana(x, y, this);
						plants.push_back(map[y][x]->org);
						break;
					}
					case 'M': {
						map[y][x]->org = new Mlecz(x, y, this);
						plants.push_back(map[y][x]->org);
						break;
					}
					case 'J': {
						map[y][x]->org = new WilczeJagody(x, y, this);
						plants.push_back(map[y][x]->org);
						break;
					}
					default: {
						cout << "Other type while reading inputfile: " << org << endl;
						break;
					}
				}
			}
		}
		file.close();
	}
	else {
		ofstream logFile("log.log", ios::beg);
		if (!logFile.is_open()) {
			std::cout << "\n\n\nNie mozna otworzyc log.log\n\n\n";
		}
		else {
			logFile << "World: height (" + to_string(height - 2) + ") width (" + to_string(width - 2) + ")\n";
		}
		logFile.close();

		pair<short, short> randPos = randomPos();
		Human* human = new Human(1, 1, this);
		animals.push_back(human);
		map[human->getY()][human->getX()]->org = human;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if ((j >= 1 && j < width - 1) && (i >= 1 && i < height - 1)) {
					if (j % 4 == 1) {
						pair<short, short> randPos = randomPos();
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
					else if (j % 4 == 0) {
						pair<short, short> randPos = randomPos();
						switch ((i + j) % 5) {
						case 0: {
							map[randPos.second][randPos.first]->org = new Wolf(randPos.first, randPos.second, this);
							break;
						}
						case 1: {
							map[randPos.second][randPos.first]->org = new Sheep(randPos.first, randPos.second, this);
							break;
						}
						case 2: {
							map[randPos.second][randPos.first]->org = new Fox(randPos.first, randPos.second, this);
							break;
						}
						case 3: {
							map[randPos.second][randPos.first]->org = new Turtle(randPos.first, randPos.second, this);
							break;
						}
						case 4: {
							map[randPos.second][randPos.first]->org = new Antelope(randPos.first, randPos.second, this);
							break;
						}
						}
						animals.push_back(map[randPos.second][randPos.first]->org); // robię vector wskaźników na zwierzęta
					}
				}
			}
		}
		for (int i = 0; i < animals.size(); i++) {
			animals[i]->writeToLog();
		}
		for (int i = 0; i < plants.size(); i++) {
			plants[i]->writeToLog();
		}
	}
	
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
			animals[i]->setIsMoved(false);
			dynamic_cast<Animal*>(animals[i])->setAge(dynamic_cast<Animal*>(animals[i])->getAge() + 1);
		}

		// sortowanie po inicjatywie i wieku
		sort(animals.begin(), animals.end(),
			[](Organism* a, Organism* b) {
				if (a->getInitiative() == b->getInitiative()) {
					return (dynamic_cast<Animal*>(a)->getAge() > dynamic_cast<Animal*>(b)->getAge());
				}
				else {
					return a->getInitiative() > b->getInitiative();
				}
			});


		short plSize = plants.size();
		for (int i = 0; i < plSize; i++) {
			plants[i]->setIsMoved(false);
		}
		drawWorld();

		for (auto* animal : animals) {
			if (dynamic_cast<Animal*>(animal) != nullptr) {
				if (!dynamic_cast<Animal*>(animal)->getIsMoved() && animal->getX() != -1) {
					animal->action();
					drawWorld();
				}
			}
		}

		for (auto* plant : plants) {
			if (!dynamic_cast<Plant*>(plant)->getIsMoved() && plant->getX() != -1) {
				plant->action();
			}
			if (plant->getX() == -1) {
				break;
			}
		}
		drawWorld();
	}
}

void World::drawWorld() {
	Sleep(500);
	system("cls");
	cout << "Author: Nikolai Lavrinov 201302\n";
	cout << "Press o to active the skill\n";
	cout << "A - Antelope, F - Fox, W - Wolf\nH - Human, S - Sheep, T - Turtle\n";
	cout << "B - Barszcz, g - Grass, G - Guarana\nM - Mlecz, J - WilczeJagody\n\n";
	cout << worldToString();
}

Organism* World::getOrganism(const short& x, const short& y) {
	if (x == -1) {
		return nullptr;
	}
	Organism* org = map[y][x]->org;
	if (org != nullptr && org->getX() == -1) {
		deleteOrganism(map[y][x]->org, x, y);
		return nullptr;
	}
	else {
		return org;
	}
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
		if (map[y][x]->org != nullptr) {
			children.push_back(map[y][x]->org);
		}
	}
}

void World::addOrganism(Organism* org, const short& x, const short& y) {
	if (dynamic_cast<Animal*>(org)) {
		map[y][x]->org = org;
		children.push_back(org);
	}
	else if (dynamic_cast<Plant*>(org)) {
		map[y][x]->org = org;
		children.push_back(org);
	}
}

void World::deleteOrganism(Organism* org, const short& x, const short& y) {
	if (org != nullptr) {
		map[y][x]->org = nullptr;
		map[y][x]->symbol = "";
		bool isDeleted = false;
		if (dynamic_cast<Animal*>(org)) {
			if (dynamic_cast<Human*>(org)) {
				isEnd = true;
				cout << "\n\n\n\n\n\n\n\nYou was killed\n\n\n\n\n\n\n";
			}
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
		if (!isDeleted) {
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
	else {
		map[y][x]->org = nullptr;
		map[y][x]->symbol = "";
	}
}

void World::replaceOrganism(Organism* org, const short& x, const short& y) {
	if (x == -1) {
		return;
	}
	map[y][x]->org = org;
}

short World::getWidth() const {
	return width;
}

short World::getHeight() const {
	return height;
}

bool World::getIsEnd() const {
	return isEnd;
}

pair<short, short> World::randomPos() {
	srand(time(NULL));
	short h = height - 2;
	short w = width - 2;
	short x = rand() % w + 1;
	short y = rand() % h + 1;
	while (getOrganism(x, y) != nullptr) {
		x = rand() % w + 1;
		y = rand() % h + 1;
	}
	return make_pair<short&, short&>(x, y);
}

string World::worldToString() {
	w_string = "";
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			string symbol = map[i][j]->symbol;
			if (symbol == "") {
				auto org = getOrganism(j, i);
				if (org != nullptr) {
					// zamienić na metodę drawOrganism()
					symbol = org->drawOrganism();
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
