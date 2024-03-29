#include "Animal.h"
#include "Plant.h"
#include <iostream>
using namespace std;
Animal::Animal(const string& ikona, const string& name, const short& power, const short& initiative,
	const short& age, const short& x, const short& y, World* world) :
	Organism(ikona, name, power, initiative, age, x, y, world), oldX(x), oldY(y) {
	oldX = x;
	oldY = y;
}


World* Animal::getWorld() const {
	return world;
}

std::string Animal::getName() const {
	return name;
};

short Animal::getPower() const {
	return power;
}

short Animal::getInitiative() const {
	return initiative;
}

short Animal::getX() const {
	return x;
}

short Animal::getY() const {
	return y;
}

short Animal::getAge() const {
	return age;
}

void Animal::setAge(const short& a) {
	age = a;
}


bool Animal::getIsMoved() const {
	return isMoved;
}

void Animal::setIsMoved(bool moved) {
	isMoved = moved;
}
std::pair<const short, const short> Animal::getPosition() const {
	return std::make_pair<const short&, const short&>(x, y);
}
void Animal::setPosition(const short& xx, const short& yy) {
	x = xx;
	y = yy;
}

void Animal::drawOrganism() const {
	cout << "Animal\n";
}


void Animal::move() {
	random_device rd;
	mt19937 gen(rd());

	oldX = x;
	oldY = y;
	short int width = world->getWidth() - 2;
	short int height = world->getHeight() - 2;
	cout << "\nanimal " << name << " (x,y): " << x << ", " << y << " -> ";
	if ((x >= 1 && x <= width) && (y >= 1 && y <= height)) {
		if (y == 1) {
			if (x == 1) {
				uniform_int_distribution<> distr(1, 2);
				short int destination = distr(gen);
				switch (destination) {
				case 1: { // down
					y += 1;
					break;
				}
				case 2: { // right
					x += 1;
					break;
				}
				}
			}
			else if (x == width) {
				uniform_int_distribution<> distr(1, 2);
				short int destination = distr(gen);
				switch (destination) {
				case 1: { // down
					y += 1;
					break;
				}
				case 2: { // left
					x -= 1;
					break;
				}
				}
			}
			else {
				uniform_int_distribution<> distr(1, 3);
				short int destination = distr(gen);
				switch (destination) {
				case 1: { // down
					y += 1;
					break;
				}
				case 2: { // right
					x += 1;
					break;
				}
				case 3: { // left
					x -= 1;
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
					y -= 1;
					break;
				}
				case 2: { // right
					x += 1;
					break;
				}
				}
			}
			else if (x == width) {
				uniform_int_distribution<> distr(1, 2);
				short int destination = distr(gen);
				switch (destination) {
				case 1: { // top
					y -= 1;
					break;
				}
				case 2: { // left
					x -= 1;
					y = y;
					break;
				}
				}
			}
			else {
				uniform_int_distribution<> distr(1, 3);
				short int destination = distr(gen);
				switch (destination) {
				case 1: { // top
					y -= 1;
					break;
				}
				case 2: { // left
					x -= 1;
					break;
				}
				case 3: { // right
					x += 1;
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
				y += 1;
				break;
			}
			case 2: { // top
				y -= 1;
				break;
			}
			case 3: { // left
				x -= 1;
				break;
			}
			}
		}
		else if (x == 1 && (y >= 2 && y < height)) {
			uniform_int_distribution<> distr(1, 3);
			short int destination = distr(gen);
			switch (destination) {
			case 1: { // down
				y += 1;
				break;
			}
			case 2: { // top
				y -= 1;
				break;
			}
			case 3: { // right
				x += 1;
				break;
			}
			}
		}
		else {
			uniform_int_distribution<> distr(1, 4);
			short int destination = distr(gen);
			switch (destination) {
			case 1: { // down
				y += 1;
				break;
			}
			case 2: { // top
				y -= 1;
				break;
			}
			case 3: { // right
				x += 1;
				break;
			}
			case 4: { // left
				x -= 1;
				break;
			}
			}
		}
	}
	else {
		cout << "\npoza granica (x,y): " << x << ", " << y << ")\n";
	}
	cout << "" << x << ", " << y << "\n";
}

void Animal::action() {
	isMoved = true;
	move();
	collision(world->getOrganism(x, y));
}

void Animal::collision(Organism* other) {
	//dodac warunki jesli organism == nullptr

	if (dynamic_cast<Animal*>(other)) {
		short otherAge = other->getAge();
		short otherInitiative = other->getInitiative();
		short otherPower = other->getPower();
		if (other == this) cout << "\n\nTO JA "<<other<<"\n\n";
		if (power >= otherPower) {
			cout << "I ("<<name<<", " << x << ", " << y << ") killed (" << other->getName() << ", "
				<< other->getX() << ", " << other->getY() << ") end go to the position(" << x << ", " << y << ")\n";
			world->deleteOrganism(other, other->getX(), other->getY());
			world->deleteOrganism(nullptr, oldX, oldY);
			world->replaceOrganism(this, x, y);

		}
		else {
			cout << "I (" << name << ") was killed by (" << other->getName() << ") clear map by my position\n";
			world->deleteOrganism(this, oldX, oldY);
			//world->replaceOrganism(this, x, y);
		}
	}
	else if (dynamic_cast<Plant*>(other)) {
		cout << "Plant: " << other->getName();
		cout << " my init and age: (" << initiative << ", " << age << ") other init and age: ("
			<< other->getInitiative() << ", " << other->getAge() << ")" << endl;
		world->replaceOrganism(this, x, y);
		world->replaceOrganism(nullptr, oldX, oldY);

		//dodac zmiane x y organizmu
		//napisac od nowa ten sytsem z roslinami w zaleznosci od roslin
	}
	else {
		world->replaceOrganism(this, x, y);
		world->replaceOrganism(nullptr, oldX, oldY);
	}
}


void Animal::deleteOrganism(){
	power = -1;
	initiative = -1;
	age = -1;
	x = -1;
	y = -1;
	oldX = -1;
	oldY = -1;
}


Animal::~Animal() {
	cout << "~Animal " << this << endl;
}