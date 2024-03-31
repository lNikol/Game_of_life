#pragma once
#include "Animal.h"
class Fox : public Animal {
public:
	Fox(const std::string& ikona, const std::string& name, const short& power, const short& initiative,
		const short& age, const short& x, const short& y, World* world);
	void move() override;
};