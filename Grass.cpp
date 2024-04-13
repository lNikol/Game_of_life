#include "Grass.h"
using namespace std;

Grass::Grass(const short& x, const short& y, World* world) ://, World* world
	Plant("g", "Grass", 0, 0, x, y, world) {//, world

	cout << "Grass (" << name << ", " << x << ", " << y << ") was created\n";
}
