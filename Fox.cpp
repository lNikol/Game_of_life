#include "Fox.h"
using namespace std;

Fox::Fox(const short& x, const short& y, World* world) :
	Animal("F", "Fox", 3, 7, 0, x, y, world) {
	cout << "Fox (" << name << ", " << x << ", " << y << ") was created\n";
}

// kiedy lis znajdzie pusta komorke od poczatku to idzie tam

void Fox::action() {
	short tempX = x, tempY = y;
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
						// cout << "There are strong organisms around the fox, the fox stays in place\n";
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
						// cout << "There are strong organisms around the fox, the fox stays in place\n";
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
						// cout << "There are strong organisms around the fox, the fox stays in place\n";
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
						// cout << "There are strong organisms around the fox, the fox stays in place\n";
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
						// cout << "There are strong organisms around the fox, the fox stays in place\n";
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
						// cout << "There are strong organisms around the fox, the fox stays in place\n";
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
					// cout << "There are strong organisms around the fox, the fox stays in place\n";
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
					// cout << "There are strong organisms around the fox, the fox stays in place\n";
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
					// cout << "There are strong organisms around the fox, the fox stays in place\n";
				}
			}
		}
	}
	else {
		//cout << "\npoza granica (x,y): " << x << ", " << y << ")\n";
	}
	cout << "" << x << ", " << y << "\n";
}