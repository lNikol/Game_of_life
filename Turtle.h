#pragma once
#include "Animal.h"
class Turtle : public Animal {
public:
	Turtle(const std::string& ikona, const std::string& name, const short& power, const short& initiative,
		const short& age, const short& x, const short& y, World* world);
};