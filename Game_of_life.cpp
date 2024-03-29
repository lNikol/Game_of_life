#include <iostream>
#include "Organism.h"
#include "Plant.h"
#include "Animal.h"
#include "World.h"
//#include <windows.h>

using namespace std;
int main()
{
	World gra(5, 5);

	//delete world.wek[0][0];
	//system("cls"); // czyszczenie konsoli
	for (int i = 0; i < 10; i++) {
		gra.takeATurn();
		cout << "end turn\n\n\n\n\n\n";
	}
	cout << endl;
}