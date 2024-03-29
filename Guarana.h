#pragma once
#include "Plant.h"
class Guarana : public Plant {
public:
	Guarana(const std::string& ikona, const std::string& name, const short& power, const short& initiative,
		const short& age, const short& x, const short& y, World* world);
};