#include <iostream>
#include <vector>
#include "Organism.h"
#include "Plant.h"
#include "Animal.h"
#include "World.h"

using namespace std;
int main()
{
	
	World gra(10,10);
	//delete world.wek[0][0];
	cout << &gra << endl;
	cout << gra.wek[0][0]->getWorld();;
}