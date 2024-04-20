#include "Grass.h"
using namespace std;

Grass::Grass(const short& x, const short& y, World* world) :
	Plant("g", "Grass", 0, 0, x, y, world) {
	cout << "Grass (" << name << ", " << x << ", " << y << ") was created\n";
}
