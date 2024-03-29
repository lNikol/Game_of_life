#include "Plant.h"
#include <iostream>
using namespace std;
Plant::Plant(const string& ikona, const string& name, const short& power, const short& initiative,
	const short& age, const short& x, const short& y, World* world) ://, World* world
	Organism(ikona, name, power, initiative, age, x, y, world) {//, world

	cout << "Plant (" << name << ", " << initiative << ", "
		<< x << ", " << y << ") was created\n";
}
void Plant::collision(Organism* other) {
	cout << other->getName() << endl;
}
World* Plant::getWorld() const {
	return world;
}
std::string Plant::getName() const {
	return name;
};

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
}