#include "Antelope.h"
using namespace std;
Antelope::Antelope(const short& x, const short& y, World* world) :
	Animal("A", "Antelope", 4, 4, 0, x, y, world) {
	cout << "Antelope (" << name << ", " << x << ", " << y << ") was created\n";
}

void Antelope::action() {
	move();
}

void Antelope::move() {
	isMoved = true;
	for (int i = 0; i < 2; i++) {
		if (x != -1) {
			Animal::move();
			collision(world->getOrganism(x, y));
		}
		
		//world->deleteOrganism(nullptr, oldX, oldY);
		//world->replaceOrganism(this, x, y);

	}
}


// czy poprawnie zrobilem ruch antylopy?
// po prostu dwa razy chodzi losowe, czyli nie dwie klatki do gory/dolu/w lewo/prawo
// jesli nie, to trzeba wtedy napisac dodatkowe warunki na sprawdzenie 
// czy za dwoma klatkami nie koniec karty

void Antelope::collision(Organism* org) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(1, 2);
	short destination = distr(gen);
	short width = world->getWidth() - 2;
	short height = world->getHeight() - 2;
	if (org != nullptr) {
		if (destination == 2 && dynamic_cast<Animal*>(org)) {
			//cout << "Maybe there won't be a battle for " << name << endl;
			// nie bedzie walki
			if ((x >= 1 && x <= width) && (y >= 1 && y <= height)) {
				if (y == 1) {
					if (x == 1) {
						if (world->getOrganism(x, y + 1) == nullptr) {
							y += 1;
							Animal::collision(world->getOrganism(x, y));
						}
						else if (world->getOrganism(x + 1, y) == nullptr) {
							x += 1;
							Animal::collision(world->getOrganism(x, y));
						}
						else {
							//cout << "There are no empty space around " << name << ", there will be a fight\n";
							Animal::collision(org);
						}
					}
					else if (x == width) {
						if (world->getOrganism(x, y + 1) == nullptr) {
							y += 1;
							Animal::collision(world->getOrganism(x, y));
						}
						else if (world->getOrganism(x - 1, y) == nullptr) {
							x -= 1;
							Animal::collision(world->getOrganism(x, y));
						}
						else {
							//cout << "There are no empty space around " << name << ", there will be a fight\n";
							Animal::collision(org);
						}
					}
					else {
						if (world->getOrganism(x, y + 1) == nullptr) {
							y += 1;
							Animal::collision(world->getOrganism(x, y));
						}
						else if (world->getOrganism(x + 1, y) == nullptr) {
							x += 1;
							Animal::collision(world->getOrganism(x, y));
						}
						else if (world->getOrganism(x - 1, y) == nullptr) {
							x -= 1;
							Animal::collision(world->getOrganism(x, y));
						}
						else {
							//cout << "There are no empty space around " << name << ", there will be a fight\n";
							Animal::collision(org);
						}
					}
				}
				else if (y == height) {
					if (x == 1) {
						if (world->getOrganism(x, y - 1) == nullptr) {
							y -= 1;
							Animal::collision(world->getOrganism(x, y));
						}
						else if (world->getOrganism(x + 1, y) == nullptr) {
							x += 1;
							Animal::collision(world->getOrganism(x, y));
						}
						else {
							//cout << "There are no empty space around " << name << ", there will be a fight\n";
							Animal::collision(org);
						}
					}
					else if (x == width) {
						if (world->getOrganism(x, y - 1) == nullptr) {
							y -= 1;
							Animal::collision(world->getOrganism(x, y));
						}
						else if (world->getOrganism(x - 1, y) == nullptr) {
							x -= 1;
							Animal::collision(world->getOrganism(x, y));
						}
						else {
							//cout << "There are no empty space around " << name << ", there will be a fight\n";
							Animal::collision(org);
						}
					}
					else {
						if (world->getOrganism(x, y - 1) == nullptr) {
							y -= 1;
							Animal::collision(world->getOrganism(x, y));
						}
						else if (world->getOrganism(x + 1, y) == nullptr) {
							x += 1;
							Animal::collision(world->getOrganism(x, y));
						}
						else if (world->getOrganism(x - 1, y) == nullptr) {
							x -= 1;
							Animal::collision(world->getOrganism(x, y));
						}
						else {
							//cout << "There are no empty space around " << name << ", there will be a fight\n";
							Animal::collision(org);
						}
					}
				}
				else if (x == width && (y >= 2 && y < height)) {
					if (world->getOrganism(x, y + 1) == nullptr) {
						y += 1;
						Animal::collision(world->getOrganism(x, y));
					}
					else if (world->getOrganism(x, y - 1) == nullptr) {
						y -= 1;
						Animal::collision(world->getOrganism(x, y));
					}
					else if (world->getOrganism(x - 1, y) == nullptr) {
						x -= 1;
						Animal::collision(world->getOrganism(x, y));
					}
					else {
						//cout << "There are no empty space around " << name << ", there will be a fight\n";
						Animal::collision(org);
					}
				}
				else if (x == 1 && (y >= 2 && y < height)) {
					if (world->getOrganism(x, y + 1) == nullptr) {
						y += 1;
						Animal::collision(world->getOrganism(x, y));
					}
					else if (world->getOrganism(x, y - 1) == nullptr) {
						y -= 1;
						Animal::collision(world->getOrganism(x, y));
					}
					else if (world->getOrganism(x + 1, y) == nullptr) {
						x += 1;
						Animal::collision(world->getOrganism(x, y));
					}
					else {
						//cout << "There are no empty space around " << name << ", there will be a fight\n";
						Animal::collision(org);
					}
				}
				else {
					if (world->getOrganism(x, y + 1) == nullptr) {
						y += 1;
						Animal::collision(world->getOrganism(x, y));
					}
					else if (world->getOrganism(x, y - 1) == nullptr) {
						y -= 1;
						Animal::collision(world->getOrganism(x, y));
					}
					else if (world->getOrganism(x + 1, y) == nullptr) {
						x += 1;
						Animal::collision(world->getOrganism(x, y));
					}
					else if (world->getOrganism(x - 1, y) == nullptr) {
						x -= 1;
						Animal::collision(world->getOrganism(x, y));
					}
					else {
						//cout << "There are no empty space around " << name << ", there will be a fight\n";
						Animal::collision(org);
					}
				}
			}
			else {
				//cout << "\npoza granica (x,y): " << x << ", " << y << ")\n";
			}
			cout << "" << x << ", " << y << "\n";
		}
		else {
			// bedzie walka
			//cout << "Failed to escape from battle for a " << name << endl;
			Animal::collision(org);
		}
	}
	else {
		Animal::collision(org);
	}
}