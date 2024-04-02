#include "Sheep.h"

Sheep::Sheep(const short& x, const short& y, World* world) :
	Animal("S", "Sheep", 4, 4, 0, x, y, world) {
	std::cout << "Sheep (" << ikona << " " << name << ", " << x << ", " << y << ") was created\n";
}