#pragma once
#include "Animal.h"
class Turtle : public Animal {
public:
	Turtle(const short& x, const short& y, World* world);
	void action() override;
	void collision(Organism* org) override;
	bool reboundAttack(Organism* org) override;
};