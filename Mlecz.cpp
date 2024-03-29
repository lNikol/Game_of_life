#include "Mlecz.h"

Mlecz::Mlecz(const std::string& ikona, const std::string& name, const short& power, const short& initiative,
	const short& age, const short& x, const short& y, World* world) ://, World* world
	Plant(ikona, name, power, initiative, age, x, y, world) {//, world

	std::cout << "Mlecz (" << name << ", " << initiative << ", "
		<< x << ", " << y << ") was created\n";
}