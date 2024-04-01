#include "Fox.h"
using namespace std;
Fox::Fox(const std::string& ikona, const std::string& name, const short& power, const short& initiative,
	const short& age, const short& x, const short& y, World* world) :
	Animal(ikona, name, power, initiative, age, x, y, world) {
	std::cout << "Fox (" << name << ", " << x << ", " << y << ") was created\n";
}

// jesli okolo lisa sa kilka pustych komorek, to trzeba losowe wybrac czy pojsc do pierwszej pustej?
// zakladam, ze do piwerszej pustej komorki
// kiedy lis znajdzie pusta komorke od poczatku to idzie dotad

void Fox::action() {
	isMoved = true;
	short width = world->getWidth() - 2;
	short height = world->getHeight() - 2;
	cout << "\nFox " << name << " (x,y): " << x << ", " << y << " -> ";
	if ((x >= 1 && x <= width) && (y >= 1 && y <= height)) {
		if (y == 1) {
			if (x == 1) {
				if (world->getOrganism(x, y + 1) == nullptr) {
					y += 1;
					collision(world->getOrganism(x, y));
				}
				else if (world->getOrganism(x + 1, y) == nullptr) {
					x += 1;
					collision(world->getOrganism(x, y));
				}
				else {
					if (world->getOrganism(x, y + 1) != nullptr
						&& world->getOrganism(x, y + 1)->getPower() <= power) {
						y += 1;
						collision(world->getOrganism(x, y));
					}
					else if (world->getOrganism(x + 1, y) != nullptr
						&& world->getOrganism(x + 1, y)->getPower() <= power) {
						x += 1;
						collision(world->getOrganism(x, y));
					}
					else {
						cout << "There are strong organisms around the fox, the fox stays in place\n";
					}
				}
			}
			else if (x == width) {
				if (world->getOrganism(x, y + 1) == nullptr) {
					y += 1;
					collision(world->getOrganism(x, y));
				}
				else if (world->getOrganism(x - 1, y) == nullptr) {
					x -= 1;
					collision(world->getOrganism(x, y));
				}
				else {
					if (world->getOrganism(x, y + 1) != nullptr
						&& world->getOrganism(x, y + 1)->getPower() <= power) {
						y += 1;
						collision(world->getOrganism(x, y));
					}
					else if (world->getOrganism(x - 1, y) != nullptr
						&& world->getOrganism(x - 1, y)->getPower() <= power) {
						x -= 1;
						collision(world->getOrganism(x, y));
					}
					else {
						cout << "There are strong organisms around the fox, the fox stays in place\n";
					}
				}
			}
			else {
				if (world->getOrganism(x, y + 1) == nullptr) {
					y += 1;
					collision(world->getOrganism(x, y));
				}
				else if (world->getOrganism(x + 1, y) == nullptr) {
					x += 1;
					collision(world->getOrganism(x, y));
				}
				else if (world->getOrganism(x - 1, y) == nullptr) {
					x -= 1;
					collision(world->getOrganism(x, y));
				}
				else {
					if (world->getOrganism(x, y + 1) != nullptr
						&& world->getOrganism(x, y + 1)->getPower() <= power) {
						y += 1;
						collision(world->getOrganism(x, y));
					}
					else if (world->getOrganism(x + 1, y) != nullptr
						&& world->getOrganism(x + 1, y)->getPower() <= power) {
						x += 1;
						collision(world->getOrganism(x, y));
					}
					else if (world->getOrganism(x - 1, y) != nullptr
						&& world->getOrganism(x - 1, y)->getPower() <= power) {
						x -= 1;
						collision(world->getOrganism(x, y));
					}
					else {
						cout << "There are strong organisms around the fox, the fox stays in place\n";
					}
				}
			}
		}
		else if (y == height) {
			if (x == 1) {
				if (world->getOrganism(x, y - 1) == nullptr) {
					y -= 1;
					collision(world->getOrganism(x, y));
				}
				else if (world->getOrganism(x + 1, y) == nullptr) {
					x += 1;
					collision(world->getOrganism(x, y));
				}
				else {
					if (world->getOrganism(x, y - 1) != nullptr
						&& world->getOrganism(x, y - 1)->getPower() <= power) {
						y -= 1;
						collision(world->getOrganism(x, y));
					}
					else if (world->getOrganism(x + 1, y) != nullptr
						&& world->getOrganism(x + 1, y)->getPower() <= power) {
						x += 1;
						collision(world->getOrganism(x, y));
					}
					else {
						cout << "There are strong organisms around the fox, the fox stays in place\n";
					}
				}
			}
			else if (x == width) {
				if (world->getOrganism(x, y - 1) == nullptr) {
					y -= 1;
					collision(world->getOrganism(x, y));
				}
				else if (world->getOrganism(x - 1, y) == nullptr) {
					x -= 1;
					collision(world->getOrganism(x, y));
				}
				else {
					if (world->getOrganism(x, y - 1) != nullptr
						&& world->getOrganism(x, y - 1)->getPower() <= power) {
						y -= 1;
						collision(world->getOrganism(x, y));
					}
					else if (world->getOrganism(x - 1, y) != nullptr
						&& world->getOrganism(x - 1, y)->getPower() <= power) {
						x -= 1;
						collision(world->getOrganism(x, y));
					}
					else {
						cout << "There are strong organisms around the fox, the fox stays in place\n";
					}
				}
			}
			else {
				if (world->getOrganism(x, y - 1) == nullptr) {
					y -= 1;
					collision(world->getOrganism(x, y));
				}
				else if (world->getOrganism(x + 1, y) == nullptr) {
					x += 1;
					collision(world->getOrganism(x, y));
				}
				else if (world->getOrganism(x - 1, y) == nullptr) {
					x -= 1;
					collision(world->getOrganism(x, y));
				}
				else {
					if (world->getOrganism(x, y - 1) != nullptr
						&& world->getOrganism(x, y - 1)->getPower() <= power) {
						y -= 1;
						collision(world->getOrganism(x, y));
					}
					else if (world->getOrganism(x + 1, y) != nullptr
						&& world->getOrganism(x + 1, y)->getPower() <= power) {
						x += 1;
						collision(world->getOrganism(x, y));
					}
					else if (world->getOrganism(x - 1, y) != nullptr
						&& world->getOrganism(x - 1, y)->getPower() <= power) {
						x -= 1;
						collision(world->getOrganism(x, y));
					}
					else {
						cout << "There are strong organisms around the fox, the fox stays in place\n";
					}
				}
			}
		}
		else if (x == width && (y >= 2 && y < height)) {
			if (world->getOrganism(x, y + 1) == nullptr) {
				y += 1;
				collision(world->getOrganism(x, y));
			}
			else if (world->getOrganism(x, y - 1) == nullptr) {
				y -= 1;
				collision(world->getOrganism(x, y));
			}
			else if (world->getOrganism(x - 1, y) == nullptr) {
				x -= 1;
				collision(world->getOrganism(x, y));
			}
			else {
				if (world->getOrganism(x, y + 1) != nullptr
					&& world->getOrganism(x, y + 1)->getPower() <= power) {
					y += 1;
					collision(world->getOrganism(x, y));
				}
				else if (world->getOrganism(x, y - 1) != nullptr
					&& world->getOrganism(x, y - 1)->getPower() <= power) {
					y -= 1;
					collision(world->getOrganism(x, y));
				}
				else if (world->getOrganism(x - 1, y) != nullptr
					&& world->getOrganism(x - 1, y)->getPower() <= power) {
					x -= 1;
					collision(world->getOrganism(x, y));
				}
				else {
					cout << "There are strong organisms around the fox, the fox stays in place\n";
				}
			}
		}
		else if (x == 1 && (y >= 2 && y < height)) {
			if (world->getOrganism(x, y + 1) == nullptr) {
				y += 1;
				collision(world->getOrganism(x, y));
			}
			else if (world->getOrganism(x, y - 1) == nullptr) {
				y -= 1;
				collision(world->getOrganism(x, y));
			}
			else if (world->getOrganism(x + 1, y) == nullptr) {
				x += 1;
				collision(world->getOrganism(x, y));
			}
			else {
				if (world->getOrganism(x, y + 1) != nullptr
					&& world->getOrganism(x, y + 1)->getPower() <= power) {
					y += 1;
					collision(world->getOrganism(x, y));
				}
				else if (world->getOrganism(x, y - 1) != nullptr
					&& world->getOrganism(x, y - 1)->getPower() <= power) {
					y -= 1;
					collision(world->getOrganism(x, y));
				}
				else if (world->getOrganism(x + 1, y) != nullptr
					&& world->getOrganism(x + 1, y)->getPower() <= power) {
					x += 1;
					collision(world->getOrganism(x, y));
				}
				else {
					cout << "There are strong organisms around the fox, the fox stays in place\n";
				}
			}
		}
		else {
			if (world->getOrganism(x, y + 1) == nullptr) {
				y += 1;
				collision(world->getOrganism(x, y));
			}
			else if (world->getOrganism(x, y - 1) == nullptr) {
				y -= 1;
				collision(world->getOrganism(x, y));
			}
			else if (world->getOrganism(x + 1, y) == nullptr) {
				x += 1;
				collision(world->getOrganism(x, y));
			}
			else if (world->getOrganism(x - 1, y) == nullptr) {
				x -= 1;
				collision(world->getOrganism(x, y));
			}
			else {
				if (world->getOrganism(x, y + 1) != nullptr
					&& world->getOrganism(x, y + 1)->getPower() <= power) {
					y += 1;
					collision(world->getOrganism(x, y));
				}
				else if (world->getOrganism(x, y - 1) != nullptr
					&& world->getOrganism(x, y - 1)->getPower() <= power) {
					y -= 1;
					collision(world->getOrganism(x, y));
				}
				else if (world->getOrganism(x + 1, y) != nullptr
					&& world->getOrganism(x + 1, y)->getPower() <= power) {
					x += 1;
					collision(world->getOrganism(x, y));
				}
				else if (world->getOrganism(x - 1, y) != nullptr
					&& world->getOrganism(x - 1, y)->getPower() <= power) {
					x -= 1;
					collision(world->getOrganism(x, y));
				}
				else {
					cout << "There are strong organisms around the fox, the fox stays in place\n";
				}
			}
		}
	}
	else {
		cout << "\npoza granica (x,y): " << x << ", " << y << ")\n";
	}
	cout << "" << x << ", " << y << "\n";
}