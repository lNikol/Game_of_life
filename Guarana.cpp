#include "Guarana.h"

Guarana::Guarana(const std::string& ikona, const std::string& name, const short& power, const short& initiative,
	const short& age, const short& x, const short& y, World* world) :
	Plant(ikona, name, power, initiative, age, x, y, world) {

	std::cout << "Guarana (" << name << ", " << initiative << ", "
		<< x << ", " << y << ") was created\n";
}