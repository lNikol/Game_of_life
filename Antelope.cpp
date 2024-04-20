#include "Antelope.h"
using namespace std;

Antelope::Antelope(const short& x, const short& y, World* world) :
	Animal("A", "Antelope", 4, 4, 0, x, y, world) {
	cout << "Antelope (" << name << ", " << x << ", " << y << ") was created\n";
}

void Antelope::action() {
	move();
	collision(world->getOrganism(x, y));
}

void Antelope::move() {
	cout << "\nAnimal (" << name << ") (x,y): " << x << ", " << y << " -> ";

	isMoved = true;
	random_device rd;
	mt19937 gen(rd());
	oldX = x;
	oldY = y;
	short width = world->getWidth() - 2;
	short height = world->getHeight() - 2;
	if ((x >= 1 && x <= width) && (y >= 1 && y <= height)) {
		if (y == 1) {
			if (x == 1) {
				uniform_int_distribution<> distr(1, 2);
				short destination = distr(gen);
				switch (destination) {
				case 1: { // down
					y += 2;
					break;
				}
				case 2: { // right
					x += 2;
					break;
				}
				}
			}
			else if (x == width) {
				uniform_int_distribution<> distr(1, 2);
				short destination = distr(gen);
				switch (destination) {
				case 1: { // down
					y += 2;
					break;
				}
				case 2: { // left
					x -= 2;
					break;
				}
				}
			}
			else {
				uniform_int_distribution<> distr(1, 3);
				short destination = distr(gen);
				switch (destination) {
				case 1: { // down
					y += 2;
					break;
				}
				case 2: { // right
					if (x + 2 <= width) {
						x += 2;
					}
					else {
						x += 1;
					}
					break;
				}
				case 3: { // left
					if (x - 2 >= 1) {
						x -= 2;
					}
					else {
						x -= 1;
					}
					break;
				}
				}
			}
		}
		else if (y == height) {
			if (x == 1) {
				uniform_int_distribution<> distr(1, 2);
				short destination = distr(gen);
				switch (destination) {
				case 1: { // top
					y -= 2;
					break;
				}
				case 2: { // right
					x += 2;
					break;
				}
				}
			}
			else if (x == width) {
				uniform_int_distribution<> distr(1, 2);
				short destination = distr(gen);
				switch (destination) {
				case 1: { // top
					y -= 2;
					break;
				}
				case 2: { // left
					x -= 2;
					break;
				}
				}
			}
			else {
				uniform_int_distribution<> distr(1, 3);
				short destination = distr(gen);
				switch (destination) {
				case 1: { // top
					y -= 2;
					break;
				}
				case 2: { // left
					if (x - 2 >= 1) {
						x -= 2;
					}
					else {
						x -= 1;
					}
					break;
				}
				case 3: { // right
					if (x + 2 <= width) {
						x += 2;
					}
					else {
						x += 1;
					}
					break;
				}
				}
			}
		}
		else if (x == width && (y >= 2 && y < height)) {
			uniform_int_distribution<> distr(1, 3);
			short destination = distr(gen);
			switch (destination) {
			case 1: { // down
				if (y + 2 <= height) {
					y += 2;
				}
				else {
					y += 1;
				}
				break;
			}
			case 2: { // top
				if (y - 2 >= 1) {
					y -= 2;
				}
				else {
					y -= 1;
				}
				break;
			}
			case 3: { // left
				x -= 2;
				break;
			}
			}
		}
		else if (x == 1 && (y >= 2 && y < height)) {
			uniform_int_distribution<> distr(1, 3);
			short destination = distr(gen);
			switch (destination) {
			case 1: { // down
				if (y + 2 <= height) {
					y += 2;
				}
				else {
					y += 1;
				}
				break;
			}
			case 2: { // top
				if (y - 2 >= 1) {
					y -= 2;
				}
				else {
					y -= 1;
				}
				break;
			}
			case 3: { // right
				x += 2;
				break;
			}
			}
		}
		else {
			uniform_int_distribution<> distr(1, 4);
			short destination = distr(gen);
			switch (destination) {
			case 1: { // down
				if (y + 2 <= height) {
					y += 2;
				}
				else {
					y += 1;
				}
				break;
			}
			case 2: { // top
				if (y - 2 >= 1) {
					y -= 2;
				}
				else {
					y -= 1;
				}
				break;
			}
			case 3: { // right
				if (x + 2 <= width) {
					x += 2;
				}
				else {
					x += 1;
				}
				break;
			}
			case 4: { // left
				if (x - 2 >= 1) {
					x -= 2;
				}
				else {
					x -= 1;
				}
				break;
			}
			}
		}
	}
	else {
		cout << "\nAntylopa poza granica (x,y): " << x << ", " << y << ")\n";
	}

	cout << x << ", " << y << endl;
}

void Antelope::collision(Organism* org) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(1, 2);
	short destination = distr(gen);
	short width = world->getWidth() - 2;
	short height = world->getHeight() - 2;
	if (org != nullptr) {
		if (destination == 2 && dynamic_cast<Animal*>(org)) {
			checkCellsAround(org);
		}
		else {
			// bedzie walka
			Animal::collision(org);
		}
	}
	else {
		Animal::collision(org);
	}
}

void Antelope::checkCellsAround(Organism* org) {
	short width = world->getWidth() - 2;
	short height = world->getHeight() - 2; 
	bool isNull = false;
	for (int i = -1; i < 2; ++i) {
		if (!isNull) {
			for (int j = -1; j < 2; ++j) {
				if (i == 0 && j == 0) continue;
				if ((x + j <= width && x + j > 0) && (y + i <= height && y + i > 0) && !isNull) {
					Organism* organism = world->getOrganism(x + j, y + i);
					if (organism == nullptr) {
						isNull = true;
						x += j;
						y += i;
						Animal::collision(organism);
						break;
					}
				}
			}
		}
		else {
			break;
		}
	}
	if (!isNull) {
		Animal::collision(org);
	}
}