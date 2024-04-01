#include "Sheep.h"

Sheep::Sheep(const std::string& ikona, const std::string& name, const short& power, const short& initiative,
	const short& age, const short& x, const short& y, World* world) :
	Animal(ikona, name, power, initiative, age, x, y, world) {
	std::cout << "Sheep (" << name << ", " << x << ", " << y << ") was created\n";
}