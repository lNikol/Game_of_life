#pragma once
#include "Animal.h"
class Fox : public Animal {
public:
	Fox(const short& x, const short& y, World* world);
	void action() override;
};