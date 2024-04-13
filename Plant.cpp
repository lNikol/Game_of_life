#include "Plant.h"
#include <iostream>
using namespace std;

Plant::Plant(const string& ikona, const string& name, const short& power, 
	const short& initiative, const short& x, const short& y, World* world) :
	Organism(ikona, name, power, initiative, x, y, world) {

}

World* Plant::getWorld() const {
	return world;
}

std::string Plant::getName() const {
	return name;
};

short Plant::getX() const {
	return this->x;
}

short Plant::getY() const {
	return this->y;
}

short Plant::getPower() const {
	return power;
}

short Plant::getInitiative() const {
	return initiative;
}

void Plant::setPosition(const short& xx, const short& yy) {
	x = xx;
	y = yy;
}


void Plant::setIsMoved(bool moved) {
	isMoved = moved;
}

bool Plant::getIsMoved() const {
	return isMoved;
}

void Plant::collision(Organism* other) {
	auto cost = dynamic_cast<Animal*>(other);
	//cout << "\nAnimal " << "(" << cost->getName() << ", " << cost->getX() << ", " << cost->getY() << ")"
		//<< " ate me (" << name << ", " << x << ", " << y << ") and nothing happend\n";
	world->deleteOrganism(this, x, y);
	world->replaceOrganism(cost, cost->getX(), cost->getY());
	world->replaceOrganism(nullptr, cost->getOldX(), cost->getOldY());
}

void Plant::action() {
	isMoved = true;
	//cout << "\nAction in plant (" << name << ", " << x << ", " << y << ")\n";

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(1, 10);
	short dest = dist(gen);
	if (dest <= 2) {
		short width = world->getWidth() - 2;
		short height = world->getHeight() - 2;
		short newX = x;
		short newY = y;
		//cout << name << " roprzestrzanie " << name << " (x, y) : " << x << ", " << y << endl;
		if ((x >= 1 && x <= width) && (y >= 1 && y <= height)) {
			if (y == 1) {
				if (x == 1) {
					uniform_int_distribution<> distr(1, 2);
					short destination = distr(gen);
					switch (destination) {
					case 1: { // down
						newY += 1;
						break;
					}
					case 2: { // right
						newX += 1;
						break;
					}
					}
				}
				else if (x == width) {
					uniform_int_distribution<> distr(1, 2);
					short destination = distr(gen);
					switch (destination) {
					case 1: { // down
						newY += 1;
						break;
					}
					case 2: { // left
						newX -= 1;
						break;
					}
					}
				}
				else {
					uniform_int_distribution<> distr(1, 3);
					short destination = distr(gen);
					switch (destination) {
					case 1: { // down
						newY += 1;
						break;
					}
					case 2: { // right
						newX += 1;
						break;
					}
					case 3: { // left
						newX -= 1;
						break;
					}
					}
				}
			}
			else if (y == height) {
				if (x == 1) {
					uniform_int_distribution<> distr(1, 2);
					short destination = distr(gen);
					switch (destination) {
					case 1: { // top
						newY -= 1;
						break;
					}
					case 2: { // right
						newX += 1;
						break;
					}
					}
				}
				else if (x == width) {
					uniform_int_distribution<> distr(1, 2);
					short destination = distr(gen);
					switch (destination) {
					case 1: { // top
						newY -= 1;
						break;
					}
					case 2: { // left
						newX -= 1;
						break;
					}
					}
				}
				else {
					uniform_int_distribution<> distr(1, 3);
					short destination = distr(gen);
					switch (destination) {
					case 1: { // top
						newY -= 1;
						break;
					}
					case 2: { // left
						newX -= 1;
						break;
					}
					case 3: { // right
						newX += 1;
						break;
					}
					}
				}
			}
			else if (x == width && (y >= 2 && y < height)) {
				uniform_int_distribution<> distr(1, 3);
				short destination = distr(gen);
				switch (destination) {
				case 1: { // down
					newY += 1;
					break;
				}
				case 2: { // top
					newY -= 1;
					break;
				}
				case 3: { // left
					newX -= 1;
					break;
				}
				}
			}
			else if (x == 1 && (y >= 2 && y < height)) {
				uniform_int_distribution<> distr(1, 3);
				short destination = distr(gen);
				switch (destination) {
				case 1: { // down
					newY += 1;
					break;
				}
				case 2: { // top
					newY -= 1;
					break;
				}
				case 3: { // right
					newX += 1;
					break;
				}
				}
			}
			else {
				uniform_int_distribution<> distr(1, 4);
				short destination = distr(gen);
				switch (destination) {
				case 1: { // down
					newY += 1;
					break;
				}
				case 2: { // top
					newY -= 1;
					break;
				}
				case 3: { // right
					newX += 1;
					break;
				}
				case 4: { // left
					newX -= 1;
					break;
				}
				}
			}
		}
		else {
			//cout << "\npoza granica (x,y): " << x << ", " << y << ")\n";
		}
		//cout << "new x,y: " << newX << ", " << newY << "\n";
		world->setOrganism(this, newX, newY);
	}
	else {
		//cout << "Action in (" << name << ", " << x << ", " << y << ") nothing happend\n";
	}


	
}

Plant::~Plant() {
	//cout << "~Plant......\n";
}