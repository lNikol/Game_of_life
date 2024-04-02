#pragma once
#include "Plant.h"
class BarszczSosnowskiego : public Plant {
public:
	BarszczSosnowskiego(const short& x, const short& y, World* world);
	void collision(Organism* org) override;
	void action() override;
};