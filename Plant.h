#pragma once
#include "Organism.h"
#include "World.h"
#include <iostream>
#include <random>

class Plant : public Organism {
public:
	Plant(const std::string& ikona, const std::string& name, const short& power,
		const short& initiative, const short& x, const short& y, World* world);
	void action() override;
	void collision(Organism* org) override;
	short getPower() const override;
	short getInitiative() const override;
	short getX() const override;
	short getY() const override;
	World* getWorld() const override;
	bool getIsMoved() const override;
	void setIsMoved(bool moved);
	~Plant();
};