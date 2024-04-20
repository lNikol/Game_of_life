#include "WilczeJagody.h"
using namespace std;

WilczeJagody::WilczeJagody(const short& x, const short& y, World* world) :
	Plant("J", "Jagody", 99, 0, x, y, world) {

	cout << "WilczeJagody (" << name << ", " << x << ", " << y << ") was created\n";
}

void WilczeJagody::collision(Organism* org) {
	auto cost = dynamic_cast<Animal*>(org);
	cout << "Animal " << "(" << cost->getName() << ", " << cost->getX() << ", " << cost->getY() << ")"
		<< " ate me (" << name << ", " << x << ", " << y << ") and was killed by me\n";
	world->deleteOrganism(cost, cost->getOldX(), cost->getOldY());
	world->deleteOrganism(this, x, y);
}