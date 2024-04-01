#include "Mlecz.h"
using namespace std;

Mlecz::Mlecz(const string& ikona, const string& name, const short& power, const short& initiative,
	const short& age, const short& x, const short& y, World* world) ://, World* world
	Plant(ikona, name, power, initiative, age, x, y, world) {//, world

	cout << "Mlecz (" << name << ", " << x << ", " << y << ") was created\n";
}

void Mlecz::action() {
	cout << "Action in Mlecz (" << name << ", " << x << ", " << y << ")\n";
	for (int i = 0; i < 3; ++i) {
		Plant::action();
	}
}