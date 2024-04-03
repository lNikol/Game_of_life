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

void Human::setIsAlive(bool alive) {

}

bool Human::getIsAlive() {
	return isAlive;
}

void Human::action() {
	oldX = x;
	oldY = y;
 
	short height = world->getHeight() - 2;
	short width = world->getWidth() - 2;
	short key;
	bool isPressed = false;
	do {
		key = _getch();  // dla Windows
		//328 do gory
		//336 do dolu
		//331 w lewo
		//333 w prawo
		if (key == 224) {  // Sprawdzenie czy klawisz specjalny
			key = _getch();  // Pobranie rzeczywistego kodu klawisza
			std::cout << "sKod klawisza: " << key + 256 << std::endl;  // Dodanie 256, aby otrzymać kod > 255
			key += 256;
			switch (key) {
			case 328: {
				// top
				if (y > 1 && y <= height) {
					isMoved = true; 
					isPressed = true;
					if (isAbilityOn) turnCounter++;
					y -= 1;
					Animal::collision(world->getOrganism(x, y));
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
					if (isAbilityOn) turnCounter++;
					y += 1;
					Animal::collision(world->getOrganism(x, y));
				}
				else {
					cout << "You cannot move to the down, try again\n";
				}
				break;
			}
			case 331: {
				// left
				if (x > 1 && x <= width ) {
					isMoved = true;
					isPressed = true;
					if (isAbilityOn) turnCounter++;
					x -= 1;
					Animal::collision(world->getOrganism(x, y));
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
					if (isAbilityOn) turnCounter++;
					x += 1;
					Animal::collision(world->getOrganism(x, y));
				}
				else {
					cout << "You cannot move to the right, try again\n";
				}
				break;
			}
			
			}
		}
		else if (key == 111) {
			//isAbilityOn = true;
		}

	} while (!isPressed );//&& !isAbilityOn
}