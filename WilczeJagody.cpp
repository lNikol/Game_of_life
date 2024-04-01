#include "WilczeJagody.h"
using namespace std;

WilczeJagody::WilczeJagody(const string& ikona, const string& name, const short& power, const short& initiative,
	const short& age, const short& x, const short& y, World* world) ://, World* world
	Plant(ikona, name, power, initiative, age, x, y, world) {//, world

	cout << "WilczeJagody (" << name << ", " << x << ", " << y << ") was created\n";
}

void WilczeJagody::collision(Organism* org) {
	auto cost = dynamic_cast<Animal*>(org);
	cout << "Animal " << "(" << cost->getName() << ", " << cost->getX() << ", " << cost->getY() << ")"
		<< " ate me (" << name << ", " << x << ", " << y << ") and was killed by me\n";
	cout << "cost->name() cost->getOldX(), cost->getOldY(): " 
		<< cost->getName() << " " << cost->getOldX() << " " << cost->getOldY() << endl;
	world->deleteOrganism(cost, cost->getOldX(), cost->getOldY());
	cout << "this, x, y: " << name << " " << x << " " << y << endl;
	world->deleteOrganism(this, x, y);
}