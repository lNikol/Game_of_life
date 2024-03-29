#include "Animal.h"
#include "Plant.h"
#include <iostream>
using namespace std;
Animal::Animal(const string& ikona, const string& name, const short& power, const short& initiative,
	const short& age, const short& x, const short& y, World* world) :
	Organism(ikona, name, power, initiative, age, x, y, world) {

	cout << "Animal (" << name << ", " << initiative << ", "
		<< x << ", " << y << ") was created\n";
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

short Animal::getAge() const {
	return age;
}

void Animal::setAge(const short& a) {
	age = a;
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

void Animal::action() {
	random_device rd;
	mt19937 gen(rd());

	//world->animals
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
					x = x;
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
					x = x;
					y -= 1;
					break;
				}
				case 2: { // left
					x -= 1;
					y = y;
					break;
				}
				case 3: { // right
					x += 1;
					y = y;
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
	collision(world->getOrganism(x, y));
}

void Animal::collision(Organism* other) {
	if (dynamic_cast<Animal*>(other)) {
		cout << "Animal: " << other->getName();
		cout << " my init and age: (" << initiative<<", "<<age << ") other init and age: (" 
			<< other->getInitiative() << ", " << other->getAge() << ")" << endl;
	}
	else if (dynamic_cast<Plant*>(other)) {
		cout << "Plant: " << other->getName();
		cout << " my init and age: (" << initiative << ", " << age << ") other init and age: ("
			<< other->getInitiative() << ", " << other->getAge() << ")" << endl;
	}
	else {
		cout << "Inne lub brak \n";
	}
}