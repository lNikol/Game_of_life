#pragma once
#include "Animal.h"
class Antelope : public Animal {
public:
	Antelope(const short& x, const short& y, World* world);
	void action() override;
	void move() override;
	void collision(Organism* org) override;
	void checkCellsAround(Organism* org);
};