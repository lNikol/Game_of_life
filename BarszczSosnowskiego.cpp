#include "BarszczSosnowskiego.h"
#include <vector>
using namespace std;
BarszczSosnowskiego::BarszczSosnowskiego(const short& x, const short& y, World* world) :
	Plant("B", "Barszcz", 10, 0, x, y, world) {

	cout << "BarszczSosnowskiego (" << name << ", " << x << ", " << y << ") was created\n";
}

void BarszczSosnowskiego::collision(Organism* org) {
	auto cost = dynamic_cast<Animal*>(org);
	//cout << "Animal " << "(" << cost->getName() << ", " << cost->getX() << ", " << cost->getY() << ")"
		//<< " ate me (" << name << ", " << x << ", " << y << ") and was killed by me\n";
	//cout << "cost->name() cost->getOldX(), cost->getOldY(): "
		//<< cost->getName() << " " << cost->getOldX() << " " << cost->getOldY() << endl;
	world->deleteOrganism(cost, cost->getOldX(), cost->getOldY());
	//cout << "this, x, y: " << name << " " << x << " " << y << endl;
	world->deleteOrganism(this, x, y);
}

void BarszczSosnowskiego::action() {
	Plant::action();
	cout << "\nAction in (" << name << ", " << x << ", " << y << ") I'm starting to kill my animal neighbors\n";
	short width = world->getWidth() - 2;
	short height = world->getHeight() - 2;
	vector<Organism*> neighbors;
	neighbors.push_back(world->getOrganism((x + 1), y));
	neighbors.push_back(world->getOrganism((x - 1), y));
	neighbors.push_back(world->getOrganism(x, (y + 1)));
	neighbors.push_back(world->getOrganism(x, (y - 1)));
	for (int i = 0; i < 4; ++i) {
		if (neighbors[i] != nullptr && dynamic_cast<Animal*>(neighbors[i])) {
			cout << "\n" << name << ": Animal " << "(" << neighbors[i]->getName() << ", "
				<< neighbors[i]->getX() << ", " << neighbors[i]->getY() << ") was killed by me\n";
			world->deleteOrganism(neighbors[i], neighbors[i]->getX(), neighbors[i]->getY());
		}
	}
};