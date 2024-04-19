#include "Turtle.h"
using namespace std;
Turtle::Turtle(const short& x, const short& y, World* world) :
	Animal("T", "Turtle", 2, 1, 0, x, y, world) {
	cout << "Turtle (" << name << ", " << x << ", " << y << ") was created\n";
}

void Turtle::action() {
	isMoved = true;
	srand(time(NULL));
	short destination = rand() % 4 + 1;
	if (destination == 4) {
		Animal::move();
		collision(world->getOrganism(x, y));
	}
	else {
		cout << "The turtle (" << name << ", " << x << ", " << y << ") stays in its place\n";
	}
}

bool Turtle::reboundAttack(Organism* org) {
	if (org->getPower() < 5) {
		return true;
	}
	else {
		return false;
	}
}