#include "BarszczSosnowskiego.h"
#include <vector>
using namespace std;
BarszczSosnowskiego::BarszczSosnowskiego(const short& x, const short& y, World* world) :
	Plant("B", "Barszcz", 10, 0, x, y, world) {
	cout << "BarszczSosnowskiego (" << name << ", " << x << ", " << y << ") was created\n";
}

void BarszczSosnowskiego::collision(Organism* org) {
	auto cost = dynamic_cast<Animal*>(org);
	cout << "Animal " << "(" << cost->getName() << ", " << cost->getX() << ", " << cost->getY() << ")"
		<< " ate me (" << name << ", " << x << ", " << y << ") and was killed by me\n";
	world->deleteOrganism(cost, cost->getOldX(), cost->getOldY());
	world->deleteOrganism(this, x, y);
}

void BarszczSosnowskiego::action() {
	Plant::action();
	short width = world->getWidth() - 2;
	short height = world->getHeight() - 2;
	vector<Organism*> neighbors;
	neighbors.push_back(world->getOrganism((x + 1), y));
	neighbors.push_back(world->getOrganism((x - 1), y));
	neighbors.push_back(world->getOrganism(x, (y + 1)));
	neighbors.push_back(world->getOrganism(x, (y - 1)));
	for (int i = 0; i < 4; ++i) {
		if (neighbors[i] != nullptr && dynamic_cast<Animal*>(neighbors[i])) {
			world->deleteOrganism(neighbors[i], neighbors[i]->getX(), neighbors[i]->getY());
		}
	}
};