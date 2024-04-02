#include "Mlecz.h"
using namespace std;

Mlecz::Mlecz(const short& x, const short& y, World* world) ://, World* world
	Plant("M", "Mlecz", 0, 0, 0, x, y, world) {//, world

	cout << "Mlecz (" << name << ", " << x << ", " << y << ") was created\n";
}

void Mlecz::action() {
	cout << "Action in Mlecz (" << name << ", " << x << ", " << y << ")\n";
	for (int i = 0; i < 3; ++i) {
		Plant::action();
	}
}