#pragma once
#include "Organism.h"
#include "World.h"
#include <iostream>
#include <random>

class Animal : public Organism {
protected:
	short oldX = -1, oldY = -1, age = -1;
public:
	Animal(const std::string& ikona, const std::string& name, const short& power, const short& initiative,
		const short& age, const short& x, const short& y, World* world);
	void action() override;
	virtual void move();
	void collision(Organism* org) override;
	short getX() const override;
	short getY() const override;
	short getOldX() const;
	short getOldY() const;
	short getPower() const override;
	short getInitiative() const override;
	short getAge() const;
	bool getIsMoved() const override;
	std::string getName() const;
	void setIsMoved(bool moved);
	void setAge(const short& a);
	void setPower(const short& pow);
	World* getWorld() const override;
	void deleteOrganism();
	bool checkType(Animal* animal, Animal* other);
	bool reproduction(Animal* other, const short& x, const short& y);
	virtual bool reboundAttack(Organism* org);
	Organism* createAnimalWithType(Organism* animal, const short& x, const short& y);
	~Animal();
};