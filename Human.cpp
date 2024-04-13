#include "Human.h"
#include <iostream>
#include <conio.h>
using namespace std;

Human::Human(const short& x, const short& y, World* world) :
	Animal("H", "Human", 5, 4, 0, x, y, world) {
	cout << "Human (" << name << ", " << x << ", " << y << ") was created\n";
}


void Human::ability() {
	cout << "Human ability\n";
}

void Human::action() {
	srand(time(NULL));
	// zastanowic sie jak lepiej zrobic Animal::collision tutaj
	// wychodzą te same linijki w 3 miejscach w jednym if
	// dodac warunki na wlaczenie/wylaczenie umietnosci
	// counterAfterAbility
	oldX = x;
	oldY = y;
 
	short height = world->getHeight() - 2;
	short width = world->getWidth() - 2;
	short key;
	bool isPressed = false;
	if (counterAfterAbility >= 5) {
		isAbilityOn = false;
		isAbilityKeyOn = false;
		counterAfterAbility = 0;
	}
	do {
		key = _getch();  // dla Windows
		//328 do gory
		//336 do dolu
		//331 w lewo
		//333 w prawo
		if (key == 224) {  // Sprawdzenie czy klawisz specjalny
			key = _getch();  // Pobranie rzeczywistego kodu klawisza
			cout << "sKod klawisza: " << key + 256 << endl;  // Dodanie 256, aby otrzymać kod > 255
			key += 256;
			switch (key) {
			case 328: {
				// top
				if (y > 1 && y <= height) {
					isMoved = true;
					isPressed = true;
					if (isAbilityOn && counterAfterAbility <= 2) {
					inAbility_Y_minus_2:
						if (y - 2 >= 1) {
							y -= 2;
						}
						else {
							cout << "You cannot move two squares (you will move one square) because there is a border there \n";
							y -= 1;
						}
						Animal::collision(world->getOrganism(x, y));
					}
					else if (counterAfterAbility > 2 && isAbilityOn) {
						short r = rand() % 2;
						if (r == 1) {
							goto inAbility_Y_minus_2;
						}
						else {
							y -= 1;
							Animal::collision(world->getOrganism(x, y));
						}
					}
					else {
						y -= 1;
						Animal::collision(world->getOrganism(x, y));
					}
					turnCounter++;
					if (isAbilityOn) {
						counterAfterAbility++;
					}
				}
				else {
					cout << "You cannot move to the top, try again\n";
				}
				break;
			}
			case 336: {
				// down
				if (y >= 1 && y < height) {
					isMoved = true;
					isPressed = true;
					if (isAbilityOn && counterAfterAbility <= 2) {
					inAbility_Y_plus_2:
						if (y + 2 <= height) {
							y += 2;
						}
						else {
							cout << "You cannot move two squares (you will move one square) because there is a border there \n";
							y += 1;
						}
						Animal::collision(world->getOrganism(x, y));
					}
					else if (counterAfterAbility > 2 && isAbilityOn) {
						short r = rand() % 2;
						if (r == 1) {
							goto inAbility_Y_plus_2;
						}
						else {
							y += 1;
							Animal::collision(world->getOrganism(x, y));
						}
					}
					else {
						y += 1;
						Animal::collision(world->getOrganism(x, y));
					}
					turnCounter++; 
					if (isAbilityOn) {
						counterAfterAbility++;
					}
				}
				else {
					cout << "You cannot move to the down, try again\n";
				}
				break;
			}
			case 331: {
				// left
				if (x > 1 && x <= width) {
					isMoved = true;
					isPressed = true;
					if (isAbilityOn && counterAfterAbility <= 2) {
					inAbility_X_minus_2:
						if (x - 2 >= 1) {
							x -= 2;
						}
						else {
							cout << "You cannot move two squares (you will move one square) because there is a border there \n";
							x -= 1;
						}
						Animal::collision(world->getOrganism(x, y));
					}
					else if (counterAfterAbility > 2 && isAbilityOn) {
						short r = rand() % 2;
						if (r == 1) {
							goto inAbility_X_minus_2;
						}
						else {
							x -= 1;
							Animal::collision(world->getOrganism(x, y));
						}
					}
					else {
						x -= 1;
						Animal::collision(world->getOrganism(x, y));
					}
					turnCounter++; 
					if (isAbilityOn) {
						counterAfterAbility++;
					}
				}
				else {
					cout << "You cannot move to the left, try again\n";
				}
				break;
			}
			case 333: {
				// right
				if (x >= 1 && x < width) {
					isMoved = true;
					isPressed = true;
					if (isAbilityOn && counterAfterAbility <= 2) {
					inAbility_X_plus_2:
						if (x + 2 <= width) {
							x += 2;
						}
						else {
							cout << "You cannot move two squares (you will move one square) because there is a border there \n";
							x += 1;
						}
						Animal::collision(world->getOrganism(x, y));
					}
					else if (counterAfterAbility > 2 && isAbilityOn) {
						short r = rand() % 2;
						if (r == 1) {
							goto inAbility_X_plus_2;
						}
						else {
							x += 1;
							Animal::collision(world->getOrganism(x, y));
						}
					}
					else {
						x += 1;
						Animal::collision(world->getOrganism(x, y));
					}
					turnCounter++;
					if (isAbilityOn) {
						counterAfterAbility++;
					}
				}
				else {
					cout << "You cannot move to the right, try again\n";
				}
				break;
			}
			}
		}
		else if (key == 111) { // key o
			if (counterAfterAbility == 0 && !isAbilityKeyOn) {
				isAbilityKeyOn = true;
				counterAfterAbility = 0;
				isAbilityOn = true;
				cout << "\n\n\nThe ability was activated\n\n\n";
			}
			else {
				isAbilityKeyOn = false;
				cout << "\n\nThe ability cannot be activated\n\n";
			}
		}

	} while (!isPressed);
}