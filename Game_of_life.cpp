#include <iostream>
#include "Organism.h"
#include "Plant.h"
#include "Animal.h"
#include "World.h"
#include <windows.h>
#include <conio.h>

using namespace std;
int main()
{
	cout << "\nI recommend setting the map size to at least 10x10 to get all kinds of organisms\n\n";
	short int N = 0, M = 0;
	int key;

	//std::cout << "Naciśnij klawisz (q - wyjście): ";

	//do {
	//	key = _getch();  // dla Windows
	//	//328 do gory
	//	//336 do dolu
	//	//331 w lewo
	//	//333 w prawo
	//	if (key == 224) {  // Sprawdzenie czy klawisz specjalny
	//		key = _getch();  // Pobranie rzeczywistego kodu klawisza
	//		std::cout << "sKod klawisza: " << key + 256 << std::endl;  // Dodanie 256, aby otrzymać kod > 255
	//	}
	//	else {
	//		std::cout << "Kod klawisza: " << key << std::endl;
	//	}

	//} while (key != 'q');
	//cout << "Write size  of map (width x height):\n";
	//cin >> N >> M;
	//while ((N > 201 || N < 10) || (M > 201 || M < 10)) {
	//	cout << "Max size is 200, min size is 10, write again\n";
	//	cin >> N >> M;
	//}

	World game(10, 10);

	for (int i = 0; i < 100; i++) {
		game.takeATurn();
		if (game.getIsEnd()) return 0;
		cout << i << " end turn\n\n\n\n\n\n";
	}
	cout << endl;
}