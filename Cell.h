#pragma once
#include "Organism.h"
struct Cell {
	Organism* org = nullptr;
	short x = 0, y = 0;
	std::string symbol = "";
};