#include "Organism.h"
Organism::Organism(const std::string& ikona, const std::string& name, const short& power, const short& initiative,
	const short& age, const short& x, const short& y, World* w) :
	ikona(ikona), name(name), power(power), initiative(initiative),
	age(age), x(x), y(y), world(w) {};

void Organism::deleteOrganism() {
	power = -1;
	initiative = -1;
	age = -1;
	x = -1;
	y = -1;
}

std::string Organism::getIkona() const {
	return ikona;
}
