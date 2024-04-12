#include "Organism.h"
#include <fstream>
#include <iostream>

Organism::Organism(const std::string& ikona, const std::string& name, const short& power, const short& initiative,
	const short& age, const short& x, const short& y, World* w) :
	ikona(ikona), name(name), power(power), initiative(initiative),
	age(age), x(x), y(y), world(w) {};

void Organism::deleteOrganism() {
	std::cout << "usuniecie organizmu: " << name << "(x,y): " << x << " " << y << std::endl;
	power = -1;
	initiative = -1;
	age = -1;
	x = -1;
	y = -1;
}

std::string Organism::getIkona() const {
	return ikona;
}

void Organism::writeToLog() {
	std::ofstream logFile("log.log", std::ios::app);
	if (!logFile.is_open()) {
		std::cout << "\n\n\nNie mozna otworzyc log.log\n\n\n";
	}
	else {
		logFile << name + "(x,y): " + std::to_string(x) + ", " + std::to_string(y) + ", power: " + std::to_string(power) + ", age: " + std::to_string(age) + "\n";
	}
}