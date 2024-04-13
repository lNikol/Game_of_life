#include <iostream>
#include "Organism.h"
#include "Plant.h"
#include "Animal.h"
#include "World.h"

using namespace std;
int main()
{
	cout << "\nI recommend setting the map size to at least 10x10 to get all kinds of organisms\n\n";
	short N = 0, M = 0;
	cout << "Write size of map (width x height):\n";
	cin >> N >> M;
	while ((N > 101 || N < 5) || (M > 101 || M < 5)) {
		cout << "Max size is 100, min size is 5, write again\n";
		cin >> N >> M;
	}

	World game(N, M);

	while(!game.getIsEnd()){
		game.takeATurn();
	}
}