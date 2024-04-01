#include "Grass.h"
using namespace std;

Grass::Grass(const string& ikona, const string& name, const short& power, const short& initiative,
	const short& age, const short& x, const short& y, World* world) ://, World* world
	Plant(ikona, name, power, initiative, age, x, y, world) {//, world

	cout << "Grass (" << name << ", " << x << ", " << y << ") was created\n";
}
