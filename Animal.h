#pragma once
#include "Organism.h"
#include "World.h"
#include <iostream>

class Animal : public Organism {
protected:
	bool isMoved = false;
	short oldX = -1, oldY = -1;
public:
	Animal(const std::string& ikona, const std::string& name, const short& power, const short& initiative,
		const short& age, const short& x, const short& y, World* world);
	void action() override;
	virtual void move(); // 0
	void collision(Organism* org) override;
	void drawOrganism() const override;
	std::string getName() const override;
	short getX() const override;
	short getY() const override;
	short getOldX() const;
	short getOldY() const;
	short getPower() const override;
	short getInitiative() const override;
	short getAge() const override;
	bool getIsMoved() const;
	void setIsMoved(bool moved);
	void setAge(const short& a) override;
	World* getWorld() const override;
	std::pair<const short, const short> getPosition() const override;
	void setPosition(const short x, const short y) override;
	void deleteOrganism();
	bool checkType(Animal* animal, Animal* other);
	bool reproduction(Animal* other, const short& x, const short& y);
	Organism* createAnimalWithType(Organism* animal, const short& x, const short& y);
	~Animal();
};