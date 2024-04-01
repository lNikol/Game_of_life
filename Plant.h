#pragma once
#include "Organism.h"
#include "World.h"
#include <iostream>

class Plant : public Organism {

public:
	Plant(const std::string& ikona, const std::string& name, const short& power, const short& initiative,
		const short& age, const short& x, const short& y, World* world);
	void action() override;
	void collision(Organism* org) override;
	void drawOrganism() const override;
	std::string getName() const override;
	short getPower() const override;
	short getInitiative() const override;
	short getAge() const override;
	short getX() const override;
	short getY() const override;
	void setAge(const short& a) override;
	World* getWorld() const override;
	std::pair<const short, const short> getPosition() const override;
	void setPosition(const short x, const short y) override;
	~Plant();
};