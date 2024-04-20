#include "Mlecz.h"
using namespace std;

Mlecz::Mlecz(const short& x, const short& y, World* world) :
	Plant("M", "Mlecz", 0, 0, x, y, world) {
	cout << "Mlecz (" << name << ", " << x << ", " << y << ") was created\n";
}

void Mlecz::action() {
	for (int i = 0; i < 3; ++i) {
		Plant::action();
	}
}