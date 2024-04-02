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
	short int N = 0, M = 0;
	//cout << "Write size of map (height x width):\n";
	//cin >> N >> M;
	//while ((N > 201 || N < 10) || (M > 201 || M < 10)) {
	//	cout << "Max size is 200, min size is 10, write again\n";
	//	cin >> N >> M;
	//}
	World game(6, 7);

	for (int i = 0; i < 30; i++) {
		game.takeATurn();
		cout << i << " end turn\n\n\n\n\n\n";
	}
	cout << endl;
}