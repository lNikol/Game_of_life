#pragma once
#include "Plant.h"
class Guarana : public Plant {
public:
	Guarana(const short& x, const short& y, World* world);
	void collision(Organism* org) override;
};