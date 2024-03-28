#include <iostream>
#include <vector>
#include "Plant.h"
#include "Animal.h"
#include "Organism.h"
#include "World.h"
using namespace std;
int main()
{
	
	World world(10,10);
	delete world.wek[0][0];
	world.wek[0][0] = nullptr;
	cout << endl;
}