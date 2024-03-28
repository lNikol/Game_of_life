#include "Animal.h"
#include <iostream>
#include <string>
using namespace std;
Animal::Animal(const string& ikona, const string& name, const short& power, const short& initiative,
	const short& age, const short& x, const short& y, World* world) :
	Organism(ikona, name, power, initiative, age, x, y, world) {

	cout << "Animal (" << name << ", " << initiative << ", "
		<< x << ", " << y << ") was created\n";
}

World* Animal::getWorld() const{
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
void Animal::setPosition(const short& xx, const short& yy) {
	x = xx;
	y = yy;
}
std::pair<const short, const short> Animal::getPosition() const {
	return std::make_pair<const short&, const short&>(x, y);
}

void Animal::drawOrganism() const {
	cout << "Animal\n";
}

void Animal::action() {
	cout << "action in Animal\n";
}