#include "Plant.h"
#include <iostream>
using namespace std;
Plant::Plant(const string& ikona, const string& name, const short& power, const short& initiative,
	const short& age, const short& x, const short& y, World* world) :
	Organism(ikona, name, power, initiative, age, x, y, world) {

}

void Plant::collision(Organism* other) {
	cout << "Plant collision: ";
	cout << other->getName() << endl;
}

World* Plant::getWorld() const {
	return world;
}

std::string Plant::getName() const {
	return name;
};

short Plant::getX() const {
	return x;
}

short Plant::getY() const {
	return y;
}
short Plant::getPower() const {
	return power;
}

short Plant::getInitiative() const {
	return initiative;
}

short Plant::getAge() const {
	return age;
}

void Plant::setAge(const short& a) {
	age = a;
}
void Plant::setPosition(const short& xx, const short& yy) {
	x = xx;
	y = yy;
}
std::pair<const short, const short> Plant::getPosition() const {
	return std::make_pair<const short&, const short&>(x, y);
}

void Plant::drawOrganism() const {
	cout << "Plant:" << name << "\n";
}

void Plant::action() {
	cout << "action in plant\n";

	random_device rd;
	mt19937 gen(rd());
	short int width = world->getWidth() - 2;
	short int height = world->getHeight() - 2;
	short int newX = x;
	short int newY = y;
	cout << "\nPlant roprzestrzanie" << name << " (x,y): " << x << ", " << y << endl;
	if ((x >= 1 && x <= width) && (y >= 1 && y <= height)) {
		if (y == 1) {
			if (x == 1) {
				uniform_int_distribution<> distr(1, 2);
				short int destination = distr(gen);
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
				short int destination = distr(gen);
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
				short int destination = distr(gen);
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
				short int destination = distr(gen);
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
				short int destination = distr(gen);
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
				short int destination = distr(gen);
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
			short int destination = distr(gen);
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
			short int destination = distr(gen);
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
			short int destination = distr(gen);
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
		cout << "\npoza granica (x,y): " << x << ", " << y << ")\n";
	}
	cout << "new x,y: " << newX << ", " << newX << "\n";
	world->setOrganism(this, newX, newY);
}

Plant::~Plant() {
	cout << "~Plant......\n";
}