#include "Wolf.h"

Wolf::Wolf(const short& x, const short& y, World* world) :
	Animal("W", "Wolf", 9, 5, 0, x, y, world) {
	std::cout << "Wolf (" << name << ", " << x << ", " << y << ") was created\n";
}