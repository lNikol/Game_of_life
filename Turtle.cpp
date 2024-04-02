#include "Turtle.h"
using namespace std;
Turtle::Turtle(const short& x, const short& y, World* world) :
	Animal("T", "Turtle", 2, 1, 0, x, y, world) {
	cout << "Turtle (" << name << ", " << x << ", " << y << ") was created\n";
}

void Turtle::action() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(1, 4);
	short destination = distr(gen);
	if (destination == 4) {
		Animal::move();
		collision(world->getOrganism(x, y));
	}
	else {
		cout << "The turtle (" << name << ", " << x << ", " << y << ") stays in its place\n";
	}
}

void Turtle::collision(Organism* org) {
	if (dynamic_cast<Animal*>(org)) {
		auto other = dynamic_cast<Animal*>(org);
		if (checkType(this, other)) {
			if (reproduction(this, oldX, oldY) == false) {
				if (reproduction(other, other->getX(), other->getY()) == false) {
					cout << "Couldn't add a child\n";
				}
				else {
					cout << "Child was added from second\n";
				}
			}
			else {
				cout << "Child was added from first\n";
			}
			x = oldX;
			y = oldY;
			return;
		}
		else {
			short otherInitiative = other->getInitiative();
			short otherPower = other->getPower();
			if (otherPower == -1) {
				world->replaceOrganism(this, x, y);
				world->replaceOrganism(nullptr, oldX, oldY);
				oldX = x;
				oldY = y;
			}
			else {
				if (power >= otherPower) {
					cout << "I (" << name << ", " << x << ", " << y << ") killed (" << other->getName() << ", "
						<< other->getX() << ", " << other->getY() << ") end go to the position (" << x << ", " << y << ")\n";
					world->deleteOrganism(other, other->getX(), other->getY());
					world->deleteOrganism(nullptr, oldX, oldY);
					world->replaceOrganism(this, x, y);
					oldX = x;
					oldY = y;
				}
				else {
					if (otherPower < 5) {
						cout << "I (" << name << ", " << x << ", " << y << ") repelled atack of the ("
							<< other->getName() << ", " << other->getX() << ", " << other->getY()
							<< ") end killed this organism and go to the position/stay in the position (" << x << ", " << y << ")\n";
						world->deleteOrganism(other, other->getOldX(), other->getOldY());
						world->replaceOrganism(this, x, y);
						oldX = x;
						oldY = y;
					}
					else {
						cout << "I (" << name << ", " << x << ", " << y << ") was killed by (" << other->getName()
							<< ", " << other->getX() << ", " << other->getY() << ") clear map by my old position\n";
						world->deleteOrganism(this, oldX, oldY);
						other->setPosition(other->getOldX(), other->getOldY());
					}
				}
			}
		}
	}
	else if (dynamic_cast<Plant*>(org)) {
		Animal::collision(org);
	}
}