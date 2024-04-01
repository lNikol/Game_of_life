#include "Guarana.h"
using namespace std;
Guarana::Guarana(const string& ikona, const string& name, const short& power, const short& initiative,
	const short& age, const short& x, const short& y, World* world) :
	Plant(ikona, name, power, initiative, age, x, y, world) {

	cout << "Guarana (" << name << ", " << x << ", " << y << ") was created\n";
}

void Guarana::collision(Organism* org) {
	auto cost = dynamic_cast<Animal*>(org);
	cout << "Animal " << "(" << cost->getName() << ", " << cost->getX() << ", " << cost->getY() << ")"
		<< " ate me (" << name << ", " << x << ", " << y << ") and I boost its power\n";
	world->deleteOrganism(this, x, y);
	cost->setPower(cost->getPower() + 3);
	world->replaceOrganism(cost, cost->getX(), cost->getY());
	world->deleteOrganism(nullptr, cost->getOldX(), cost->getOldY());
}
