#pragma once
#define USE_EMOJI 1
#include <string>
#include <random>
class World;

class Organism {
protected:
	std::string name = "", ikona = "";
	short power = -1, initiative = -1, age = -1;
	short x = -1, y = -1;
	World* world;
	bool isMoved = false;
public:
	Organism(const std::string& ikona, const std::string& name, const short& power, const short& initiative,
		const short& age, const short& x, const short& y, World* w);
	virtual void action() = 0;
	virtual void collision(Organism* org) = 0;
	virtual void drawOrganism() const = 0;
	virtual std::string getName() const = 0;
	virtual short getPower() const = 0;
	virtual short getInitiative() const = 0;
	virtual std::string getIkona() const;
	virtual short getAge() const = 0;
	virtual short getX() const = 0;
	virtual short getY() const = 0;
	virtual void setAge(const short&) = 0;
	virtual World* getWorld() const = 0; // tutaj blad podczas build
	virtual std::pair<const short, const short> getPosition() const = 0;
	virtual void setPosition(const short x, const short y) = 0;
	virtual void deleteOrganism();
	virtual bool getIsMoved() const = 0;
	virtual void setIsMoved(bool moved) = 0;
	//virtual ~Organism() = 0;

};