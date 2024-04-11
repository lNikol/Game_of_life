#pragma once
#include "Animal.h"
class Human : public Animal {
private:
	short turnCounter = 0;
	short counterAfterAbility = 0;
	bool isAbilityOn = false; 
	bool isAlive = true;
public:
	Human(const short& x, const short& y, World* world);
	void setIsAlive(bool alive);
	bool getIsAlive();
	void ability();
	void action() override;
};