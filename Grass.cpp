#include "Grass.h"
#include "Plant.h"

Grass::Grass(const std::string& ikona, const std::string& name, const short& power, const short& initiative,
	const short& age, const short& x, const short& y, World* world) ://, World* world
	Plant(ikona, name, power, initiative, age, x, y, world) {//, world

	std::cout << "Grass (" << name << ", " << initiative << ", "
		<< x << ", " << y << ") was created\n";
}