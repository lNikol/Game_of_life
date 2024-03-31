#include "Fox.h"
using namespace std;
Fox::Fox(const std::string& ikona, const std::string& name, const short& power, const short& initiative,
	const short& age, const short& x, const short& y, World* world) :
	Animal(ikona, name, power, initiative, age, x, y, world) {
	std::cout << "Fox (" << name << ", " << initiative << ", "
		<< x << ", " << y << ") was created\n";
}

void Fox::move() {
	isMoved = true;
	short width = world->getWidth() - 2;
	short height = world->getHeight() - 2;
	cout << "\nFox " << name << " (x,y): " << x << ", " << y << " -> ";
	if ((x >= 1 && x <= width) && (y >= 1 && y <= height)) {
		if (y == 1) {
			if (x == 1) {
				if (world->getOrganism(x, y + 1) != nullptr) {
					Organism* org = world->getOrganism(x, y + 1);
					if (org->getPower() <= power) {
						y += 1;
						collision(org);
					}
					else return;
				}
				else if (world->getOrganism(x + 1, y) != nullptr) {
					Organism* org = world->getOrganism(x + 1, y);
					if (org->getPower() <= power) {
						x += 1;
						collision(org);
					}
					else return;
				}
				else {
					Animal::move();
					//cout << "There are strong organisms around the fox, the fox stays in place\n";
				}
			}
			else if (x == width) {
				if (world->getOrganism(x, y + 1) != nullptr) {
					Organism* org = world->getOrganism(x, y + 1);
					if (org->getPower() <= power) {
						y += 1;
						collision(org);
					}
					else return;
				}
				else if (world->getOrganism(x - 1, y) != nullptr) {
					Organism* org = world->getOrganism(x - 1, y);
					if (org->getPower() <= power) {
						x -= 1;
						collision(org);
					}
					else return;
				}
				else {
					Animal::move(); 
					//cout << "There are strong organisms around the fox, the fox stays in place\n";
				}
			}
			else {
				if (world->getOrganism(x, y + 1) != nullptr) {
					Organism* org = world->getOrganism(x, y + 1);
					if (org->getPower() <= power) {
						y += 1;
						collision(org);
					}
					else return;
				}
				else if (world->getOrganism(x + 1, y) != nullptr) {
					Organism* org = world->getOrganism(x + 1, y);
					if (org->getPower() <= power) {
						x += 1;
						collision(org);
					}
					else return;
				}
				else if (world->getOrganism(x - 1, y) != nullptr) {
					Organism* org = world->getOrganism(x - 1, y);
					if (org->getPower() <= power) {
						x -= 1;
						collision(org);
					}
					else return;
				}
				else {
					Animal::move(); 
					//cout << "There are strong organisms around the fox, the fox stays in place\n";
				}
			}
		}
		else if (y == height) {
			if (x == 1) {
				if (world->getOrganism(x, y - 1) != nullptr) {
					Organism* org = world->getOrganism(x, y - 1);
					if (org->getPower() <= power) {
						y -= 1;
						collision(org);
					}
					else return;
				}
				else if (world->getOrganism(x + 1, y) != nullptr) {
				Organism* org = world->getOrganism(x + 1, y);
				if (org->getPower() <= power) {
					x += 1;
					collision(org);
				}
				else return;
				}
				else {
					Animal::move(); 
					//cout << "There are strong organisms around the fox, the fox stays in place\n";
				}
			}
			else if (x == width) {
				if (world->getOrganism(x, y - 1) != nullptr) {
					Organism* org = world->getOrganism(x, y - 1);
					if (org->getPower() <= power) {
						y -= 1;
						collision(org);
					}
					else return;
				}
				else if (world->getOrganism(x - 1, y) != nullptr) {
					Organism* org = world->getOrganism(x - 1, y);
					if (org->getPower() <= power) {
						x -= 1;
						collision(org);
					}
					else return;
				}
				else {
					Animal::move(); 
					//cout << "There are strong organisms around the fox, the fox stays in place\n";
				}
			}
			else {
				if (world->getOrganism(x, y - 1) != nullptr) {
					Organism* org = world->getOrganism(x, y - 1);
					if (org->getPower() <= power) {
						y -= 1;
						collision(org);
					}
					else return;
				}
				else if (world->getOrganism(x + 1, y) != nullptr) {
					Organism* org = world->getOrganism(x + 1, y);
					if (org->getPower() <= power) {
						x += 1;
						collision(org);
					}
					else return;
				}
				else if (world->getOrganism(x - 1, y) != nullptr) {
					Organism* org = world->getOrganism(x - 1, y);
					if (org->getPower() <= power) {
						x -= 1;
						collision(org);
					}
					else return;
				}
				else {
					Animal::Animal::move(); 
					//cout << "There are strong organisms around the fox, the fox stays in place\n";
				}
			}
		}
		else if (x == width && (y >= 2 && y < height)) {
			if (world->getOrganism(x, y + 1) != nullptr) {
				Organism* org = world->getOrganism(x, y + 1);
				if (org->getPower() <= power) {
					y += 1;
					collision(org);
				}
				else return;
			}
			else if (world->getOrganism(x, y - 1) != nullptr) {
				Organism* org = world->getOrganism(x, y - 1);
				if (org->getPower() <= power) {
					y -= 1;
					collision(org);
				}
				else return;
			}
			else if (world->getOrganism(x - 1, y) != nullptr) {
				Organism* org = world->getOrganism(x - 1, y);
				if (org->getPower() <= power) {
					x -= 1;
					collision(org);
				}
				else return;
			}
			else {
				Animal::move(); 
				//cout << "There are strong organisms around the fox, the fox stays in place\n";
			}
		}
		else if (x == 1 && (y >= 2 && y < height)) {
			if (world->getOrganism(x, y + 1) != nullptr) {
				Organism* org = world->getOrganism(x, y + 1);
				if (org->getPower() <= power) {
					y += 1;
					collision(org);
				}
				else return;
			}
			else if (world->getOrganism(x, y - 1) != nullptr) {
				Organism* org = world->getOrganism(x, y - 1);
				if (org->getPower() <= power) {
					y -= 1;
					collision(org);
				}
				else return;
			}
			else if (world->getOrganism(x + 1, y) != nullptr) {
				Organism* org = world->getOrganism(x + 1, y);
				if (org->getPower() <= power) {
					x += 1;
					collision(org);
				}
				else return;
			}
			else {
				Animal::move(); 
				//cout << "There are strong organisms around the fox, the fox stays in place\n";
			}
		}
		else {
			if (world->getOrganism(x, y + 1) != nullptr) {
				Organism* org = world->getOrganism(x, y + 1);
				if (org->getPower() <= power) {
					y += 1;
					collision(org);
				}
				else return;
			}
			else if (world->getOrganism(x, y - 1) != nullptr) {
				Organism* org = world->getOrganism(x, y - 1);
				if (org->getPower() <= power) {
					y -= 1;
					collision(org);
				}
				else return;
			}
			else if (world->getOrganism(x + 1, y) != nullptr) {
				Organism* org = world->getOrganism(x + 1, y);
				if (org->getPower() <= power) {
					x += 1;
					collision(org);
				}
				else {
					continue;
				}
			}
			else if (world->getOrganism(x - 1, y) != nullptr) {
				Organism* org = world->getOrganism(x - 1, y);
				if (org->getPower() <= power) {
					x -= 1;
					collision(org);
				}
				else return;
			}
			else {
				Animal::move();
				//cout << "There are strong organisms around the fox, the fox stays in place\n";
			}
		}
	}
	else {
		cout << "\npoza granica (x,y): " << x << ", " << y << ")\n";
	}
	cout << "" << x << ", " << y << "\n";
}