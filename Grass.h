#pragma once
#include "Plant.h"

class Grass : public Plant{
public:
	Grass(const std::string& ikona, const std::string& name, const short& power, const short& initiative,
		const short& age, const short& x, const short& y, World* world);
};