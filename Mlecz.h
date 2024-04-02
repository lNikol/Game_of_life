#pragma once
#include "Plant.h"

class Mlecz : public Plant {
public:
	Mlecz(const short& x, const short& y, World* world);
	void action() override;
};