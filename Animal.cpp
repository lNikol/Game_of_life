﻿#include "Animal.h"
#include "Antelope.h"
#include "Fox.h"
#include "Sheep.h"
#include "Turtle.h"
#include "Wolf.h"
#include "Plant.h"
#include <iostream>
#include <typeinfo>
using namespace std;

Animal::Animal(const string& ikona, const string& name, const short& power, const short& initiative,
	const short& age, const short& x, const short& y, World* world) :
	Organism(ikona, name, power, initiative, age, x, y, world), oldX(x), oldY(y) {
}

Organism* Animal::createAnimalWithType(Organism* animal, const short& x, const short& y) {
	auto cast = dynamic_cast<Animal*>(animal);
	if (dynamic_cast<Antelope*>(cast)) {
		return new Antelope(x, y, animal->getWorld());
	}
	else if (dynamic_cast<Fox*>(cast)) {
		return new Fox(x, y, animal->getWorld());
	}
	else if (dynamic_cast<Sheep*>(cast)) {
		return new Sheep(x, y, animal->getWorld());
	}
	else if (dynamic_cast<Turtle*>(cast)) {
		return new Turtle(x, y, animal->getWorld());
	}
	else if (dynamic_cast<Wolf*>(cast)) {
		return new Wolf(x, y, animal->getWorld());
	}
	else {
		cout << "\nThe absence of this type of animal or the organism is not an animal\n";
		return nullptr;
	}
}

bool Animal::checkType(Animal* animal, Animal* other) {
	return typeid(*animal) == typeid(*other);
}

World* Animal::getWorld() const {
	return world;
}

std::string Animal::getName() const {
	return name;
};

short Animal::getPower() const {
	return power;
}

short Animal::getInitiative() const {
	return initiative;
}

short Animal::getX() const {
	return this->x;
}

short Animal::getY() const {
	return this->y;
}

short Animal::getOldX() const {
	return oldX;
}

short Animal::getOldY() const {
	return oldY;
}

short Animal::getAge() const {
	return age;
}

void Animal::setAge(const short& a) {
	age = a;
}

void Animal::setPower(const short& pow) {
	power = pow;
}

bool Animal::getIsMoved() const {
	return isMoved;
}

void Animal::setIsMoved(bool moved) {
	isMoved = moved;
}

std::pair<const short, const short> Animal::getPosition() const {
	return std::make_pair<const short&, const short&>(x, y);
}

void Animal::setPosition(const short xx, const short yy) {
	x = xx;
	y = yy;
}

void Animal::drawOrganism() const {
	cout << "Animal\n";
}


bool Animal::reproduction(Animal* other, const short& x, const short& y) {
	short width = world->getWidth() - 2;
	short height = world->getHeight() - 2;
	// zostanie wywołana podczas sprawdzenia kto jest na klatce
	// zalozenie, ze [other] tego samego typu co i animal (wilk i wilk np.)
	if ((x >= 1 && x <= width) && (y >= 1 && y <= height)) {
		if (y == 1) {
			if (x == 1) {
				if (world->getOrganism(x + 1, y) == nullptr) {
					// jako opcja zamienić te dwie linijki na funkcję
					// world->addOrganism(createAnimalWithType(other, x + 1, y), x + 1 , y);
					Organism* child = createAnimalWithType(other, x + 1, y);
					world->addOrganism(child, x + 1, y);
					return true;
				}
				else if (world->getOrganism(x, y + 1) == nullptr) {
					Organism* child = createAnimalWithType(other, x, y + 1);
					world->addOrganism(child, x, y + 1);
					return true;
				}
				else {
					cout << "There are no empty cells around " << name << endl;
					return false;
				}
			}
			else if (x == width) {
				if (world->getOrganism(x - 1, y) == nullptr) {
					Organism* child = createAnimalWithType(other, x - 1, y);
					world->addOrganism(child, x - 1, y);
					return true;
				}
				else if (world->getOrganism(x, y + 1) == nullptr) {
					Organism* child = createAnimalWithType(other, x, y + 1);
					world->addOrganism(child, x, y + 1);
					return true;
				}
				else {
					cout << "There are no empty cells around " << name << endl;
					return false;
				}
			}
			else {
				if (world->getOrganism(x - 1, y) == nullptr) {
					Organism* child = createAnimalWithType(other, x - 1, y);
					world->addOrganism(child, x - 1, y);
					return true;
				}
				else if (world->getOrganism(x + 1, y) == nullptr) {
					Organism* child = createAnimalWithType(other, x + 1, y);
					world->addOrganism(child, x + 1, y);
					return true;
				}
				else if (world->getOrganism(x, y + 1) == nullptr) {
					Organism* child = createAnimalWithType(other, x, y + 1);
					world->addOrganism(child, x, y + 1);
					return true;
				}
				else {
					cout << "There are no empty cells around " << name << endl;
					return false;
				}
			}
		}
		else if (y == height) {
			if (x == 1) {
				if (world->getOrganism(x + 1, y) == nullptr) {
					Organism* child = createAnimalWithType(other, x + 1, y);
					world->addOrganism(child, x + 1, y);
					return true;
				}
				else if (world->getOrganism(x, y - 1) == nullptr) {
					Organism* child = createAnimalWithType(other, x, y - 1);
					world->addOrganism(child, x, y - 1);
					return true;
				}
				else {
					cout << "There are no empty cells around " << name << endl;
					return false;
				}
			}
			else if (x == width) {
				if (world->getOrganism(x, y - 1) == nullptr) {
					Organism* child = createAnimalWithType(other, x, y - 1);
					world->addOrganism(child, x, y - 1);
					return true;
				}
				else if (world->getOrganism(x - 1, y) == nullptr) {
					Organism* child = createAnimalWithType(other, x - 1, y);
					world->addOrganism(child, x - 1, y);
					return true;
				}
				else {
					cout << "There are no empty cells around " << name << endl;
					return false;
				}
			}
			else {
				if (world->getOrganism(x - 1, y) == nullptr) {
					Organism* child = createAnimalWithType(other, x - 1, y);
					world->addOrganism(child, x - 1, y);
					return true;
				}
				else if (world->getOrganism(x + 1, y) == nullptr) {
					Organism* child = createAnimalWithType(other, x + 1, y);
					world->addOrganism(child, x + 1, y);
					return true;
				}
				else if (world->getOrganism(x, y - 1) == nullptr) {
					Organism* child = createAnimalWithType(other, x, y - 1);
					world->addOrganism(child, x, y - 1);
					return true;
				}
				else {
					cout << "There are no empty cells around " << name << endl;
					return false;
				}
			}
		}
		else if (x == width && (y >= 2 && y < height)) {
			if (world->getOrganism(x - 1, y) == nullptr) {
				Organism* child = createAnimalWithType(other, x - 1, y);
				world->addOrganism(child, x - 1, y);
				return true;
			}
			else if (world->getOrganism(x, y - 1) == nullptr) {
				Organism* child = createAnimalWithType(other, x, y - 1);
				world->addOrganism(child, x, y - 1);
				return true;
			}
			else if (world->getOrganism(x, y + 1) == nullptr) {
				Organism* child = createAnimalWithType(other, x, y + 1);
				world->addOrganism(child, x, y + 1);
				return true;
			}
			else {
				cout << "There are no empty cells around " << name << endl;
				return false;
			}
		}
		else if (x == 1 && (y >= 2 && y < height)) {
			if (world->getOrganism(x + 1, y) == nullptr) {
				Organism* child = createAnimalWithType(other, x + 1, y);
				world->addOrganism(child, x + 1, y);
				return true;
			}
			else if (world->getOrganism(x, y - 1) == nullptr) {
				Organism* child = createAnimalWithType(other, x, y - 1);
				world->addOrganism(child, x, y - 1);
				return true;
			}
			else if (world->getOrganism(x, y + 1) == nullptr) {
				Organism* child = createAnimalWithType(other, x, y + 1);
				world->addOrganism(child, x, y + 1);
				return true;
			}
			else {
				cout << "There are no empty cells around " << name << endl;
				return false;
			}
		}
		else {
			if (world->getOrganism(x - 1, y) == nullptr) {
				Organism* child = createAnimalWithType(other, x - 1, y);
				world->addOrganism(child, x - 1, y);
				return true;
			}
			else if (world->getOrganism(x, y - 1) == nullptr) {
				Organism* child = createAnimalWithType(other, x, y - 1);
				world->addOrganism(child, x, y - 1);
				return true;
			}
			else if (world->getOrganism(x, y + 1) == nullptr) {
				Organism* child = createAnimalWithType(other, x, y + 1);
				world->addOrganism(child, x, y + 1);
				return true;
			}
			else if (world->getOrganism(x + 1, y) == nullptr) {
				Organism* child = createAnimalWithType(other, x + 1, y);
				world->addOrganism(child, x + 1, y);
				return true;
			}
			else {
				cout << "There are no empty cells around " << name << endl;
				return false;
			}
		}
		return false;
	}
	return false;
}

void Animal::move() {
	random_device rd;
	mt19937 gen(rd());

	oldX = x;
	oldY = y;
	short int width = world->getWidth() - 2;
	short int height = world->getHeight() - 2;
	cout << "\nanimal " << name << " (x,y): " << x << ", " << y << " -> ";
	if ((x >= 1 && x <= width) && (y >= 1 && y <= height)) {
		if (y == 1) {
			if (x == 1) {
				uniform_int_distribution<> distr(1, 2);
				short int destination = distr(gen);
				switch (destination) {
				case 1: { // down
					y += 1;
					break;
				}
				case 2: { // right
					x += 1;
					break;
				}
				}
			}
			else if (x == width) {
				uniform_int_distribution<> distr(1, 2);
				short int destination = distr(gen);
				switch (destination) {
				case 1: { // down
					y += 1;
					break;
				}
				case 2: { // left
					x -= 1;
					break;
				}
				}
			}
			else {
				uniform_int_distribution<> distr(1, 3);
				short int destination = distr(gen);
				switch (destination) {
				case 1: { // down
					y += 1;
					break;
				}
				case 2: { // right
					x += 1;
					break;
				}
				case 3: { // left
					x -= 1;
					break;
				}
				}
			}
		}
		else if (y == height) {
			if (x == 1) {
				uniform_int_distribution<> distr(1, 2);
				short int destination = distr(gen);
				switch (destination) {
				case 1: { // top
					y -= 1;
					break;
				}
				case 2: { // right
					x += 1;
					break;
				}
				}
			}
			else if (x == width) {
				uniform_int_distribution<> distr(1, 2);
				short int destination = distr(gen);
				switch (destination) {
				case 1: { // top
					y -= 1;
					break;
				}
				case 2: { // left
					x -= 1;
					break;
				}
				}
			}
			else {
				uniform_int_distribution<> distr(1, 3);
				short int destination = distr(gen);
				switch (destination) {
				case 1: { // top
					y -= 1;
					break;
				}
				case 2: { // left
					x -= 1;
					break;
				}
				case 3: { // right
					x += 1;
					break;
				}
				}
			}
		}
		else if (x == width && (y >= 2 && y < height)) {
			uniform_int_distribution<> distr(1, 3);
			short int destination = distr(gen);
			switch (destination) {
			case 1: { // down
				y += 1;
				break;
			}
			case 2: { // top
				y -= 1;
				break;
			}
			case 3: { // left
				x -= 1;
				break;
			}
			}
		}
		else if (x == 1 && (y >= 2 && y < height)) {
			uniform_int_distribution<> distr(1, 3);
			short int destination = distr(gen);
			switch (destination) {
			case 1: { // down
				y += 1;
				break;
			}
			case 2: { // top
				y -= 1;
				break;
			}
			case 3: { // right
				x += 1;
				break;
			}
			}
		}
		else {
			uniform_int_distribution<> distr(1, 4);
			short int destination = distr(gen);
			switch (destination) {
			case 1: { // down
				y += 1;
				break;
			}
			case 2: { // top
				y -= 1;
				break;
			}
			case 3: { // right
				x += 1;
				break;
			}
			case 4: { // left
				x -= 1;
				break;
			}
			}
		}
	}
	else {
		cout << "\npoza granica (x,y): " << x << ", " << y << ")\n";
	}
	cout << "" << x << ", " << y << "\n";
}

void Animal::action() {
	isMoved = true;
	move();
	collision(world->getOrganism(x, y));
}

void Animal::collision(Organism* other) {
	if (other != nullptr) cout << "animal::collision: " << other->getName() << " " << other->getX() << " " << other->getY() << endl;
	//dodac warunki jesli organism == nullptr
	if (dynamic_cast<Animal*>(other)) {
		if (checkType(this, dynamic_cast<Animal*>(other))) {
			if (reproduction(this, oldX, oldY) == false) {
				if (reproduction(dynamic_cast<Animal*>(other), other->getX(), other->getY()) == false) {
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
			short otherPower = other->getPower();
			cout << "otherPower: " << otherPower << " " << other->getX() << " " << other->getY() << endl;
			if (otherPower == -1) {
				world->replaceOrganism(this, x, y);
				world->replaceOrganism(nullptr, oldX, oldY);
			}
			else {
				if (dynamic_cast<Turtle*>(other)) {
					//	Zapytać: zamienić
					// Przykładowo błędem będzie zaimplementowanie w metodzie kolizja() klasy Zwierze
					// sprawdzania czy organizm z którym zderzył się organizm atakujący jest klasy Zolw, a
					// następnie porównywanie siły i pozostawanie na tym samym polu jeśli jest to konieczne.


					other->collision(this);
				}
				else if (dynamic_cast<Antelope*>(other)) {
					other->collision(this);
					if (other->getX() == -1) {
						world->replaceOrganism(this, x, y);
						world->deleteOrganism(nullptr, oldX, oldY);
					}
				}
				else {
					if (power >= otherPower) {
						cout << "I (" << name << ", " << x << ", " << y << ") killed (" << other->getName() << ", "
							<< other->getX() << ", " << other->getY() << ") end go to the position (" << x << ", " << y << ")\n";
						world->deleteOrganism(other, other->getX(), other->getY());
						world->replaceOrganism(this, x, y);
						oldX = x;
						oldY = y;
					}
					else {
						cout << "I (" << name << ", " << x << ", " << y << ") was killed by (" << other->getName()
							<< ", " << other->getX() << ", " << other->getY() << ") clear map by my old position\n";
						world->deleteOrganism(this, oldX, oldY);
					}
				}
			}
		}
	}
	else if (dynamic_cast<Plant*>(other)) {
		other->collision(this);
		if (x != -1) {
			oldX = x;
			oldY = y;
		}
	}
	else {
		world->replaceOrganism(this, x, y);
		world->replaceOrganism(nullptr, oldX, oldY);
		oldX = x;
		oldY = y;
	}
}


void Animal::deleteOrganism() {
	oldX = -1;
	oldY = -1;
	Organism::deleteOrganism();
}


Animal::~Animal() {
	cout << "~Animal " << this << endl;
}