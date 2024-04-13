#include "Organism.h"
#include "Animal.h"
#include <fstream>
#include <iostream>

Organism::Organism(const std::string& ikona, const std::string& name, const short& power, 
	const short& initiative, const short& x, const short& y, World* w) :
	ikona(ikona), name(name), power(power), initiative(initiative), x(x), y(y), world(w) {
};

void Organism::deleteOrganism() {
	power = -1;
	initiative = -1;
	x = -1;
	y = -1;
}

std::string Organism::drawOrganism() const {
	return ikona;
}


void Organism::writeToLog() {
	std::ofstream logFile("log.log", std::ios::app);
	if (!logFile.is_open()) {
		std::cout << "\n\n\nNie mozna otworzyc log.log\n\n\n";
	}
	else {
		logFile << name + "(x,y): " + std::to_string(x) + ", " + std::to_string(y) + ", power: " + std::to_string(power);
		if (dynamic_cast<Animal*>(this)) {
			logFile << ", age: " + std::to_string(dynamic_cast<Animal*>(this)->getAge()) + "\n";
		}
		else {
			logFile << "\n";
		}
	}
}