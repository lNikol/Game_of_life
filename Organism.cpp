#include "Organism.h"
#include "Animal.h"
#include <fstream>
#include <iostream>
using namespace std;

Organism::Organism(const string& ikona, const string& name, const short& power, 
	const short& initiative, const short& x, const short& y, World* w) :
	ikona(ikona), name(name), power(power), initiative(initiative), x(x), y(y), world(w) {
};

void Organism::deleteOrganism() {
	power = -1;
	initiative = -1;
	x = -1;
	y = -1;
}

string Organism::drawOrganism() const {
	return ikona;
}


void Organism::writeToLog() {
	ofstream logFile("log.log", ios::app);
	if (!logFile.is_open()) {
		cout << "\n\n\nNie mozna otworzyc log.log\n\n\n";
	}
	else {
		logFile << name + "(x,y): " + to_string(x) + ", " + to_string(y) 
			+ ", power: " + to_string(power) + ", initiative: " + to_string(initiative);
		if (dynamic_cast<Animal*>(this)) {
			logFile << ", age: " + to_string(dynamic_cast<Animal*>(this)->getAge()) + "\n";
		}
		else {
			logFile << "\n";
		}
	}
}