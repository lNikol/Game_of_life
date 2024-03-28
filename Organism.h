#pragma once
#include <string>
//#include "World.h"
class World;

class Organism {
protected:
	std::string name = "", ikona = "";
	short power = -1, initiative = -1, age = -1, x = -1, y = -1;
	World* world;
public:
	Organism(const std::string& ikona, const std::string& name, const short& power, const short& initiative,
		const short& age, const short& x, const short& y, World* w) :
		ikona(ikona), name(name), power(power), initiative(initiative), age(age), x(x), y(y), world(w) {};
	virtual void action() = 0;
	//virtual void collision(Organism* org) = 0;
	virtual void drawOrganism() const = 0;
	virtual std::string getName() const = 0;
	virtual short getPower() const = 0;
	virtual short getInitiative() const = 0;
	virtual short getAge() const = 0;
	virtual void setAge(const short&) = 0;
	virtual World* getWorld() const = 0; // tutaj blad podczas build
	virtual std::pair<const short, const short> getPosition() const = 0;
	virtual void setPosition(const short& x, const short& y) = 0;
	//virtual ~Organism();

protected:
	//World* w = nullptr;

};