#include <iostream>
#include "Organism.h"
#include "Plant.h"
#include "Animal.h"
#include "World.h"
//#include <windows.h>

using namespace std;
int main()
{
	cout << "\nI recommend setting the map size to at least 10x10 to get all kinds of organisms\n\n";

	World gra(10, 10);

	for (int i = 0; i < 30; i++) {
		gra.takeATurn();
		cout << i << " end turn\n\n\n\n\n\n";
	}
	cout << endl;
}