#pragma once
#include "Plant.h"
class WilczeJagody : public Plant {
public:
	WilczeJagody(const short& x, const short& y, World* world);
	void collision(Organism* org) override;
};