#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include "Organism.h"
#include "Plant.h"
#include "Animal.h"
#include "World.h"
using namespace std;


void readFile(bool& isFile, short& w, short& h) {
	ifstream file("log.log");
	string line;
	short height = 0, width = 0;
	if (file.is_open()) {
		// Czytanie wartości height i width z pierwszej linijki
		getline(file, line);
		regex dimensionsRegex(R"(height \((\d+)\) width \((\d+)\))");
		smatch match;
		if (regex_search(line, match, dimensionsRegex)) {
			height = stoi(match[1]);
			width = stoi(match[2]);
		}
		if (height > 0 && width > 0) {
			w = width;
			h = height;
			isFile = true;
		}
		else {
			isFile = false;
		}
		file.close();
	}
	else {
		isFile = false;
		file.close();
	}
}


int main()
{
	cout << "\nI recommend setting the map size to at least 10x10 to get all kinds of organisms\n\n";
	short N = -1, M = -1;
	cout << "Write size of map (width x height):\n";
	cout << "If you want to read the file with the world start state, write 0 0 (you have only one chance)\n";
	cin >> N >> M;
	bool isFile = false;
	if (N == 0 && M == 0) {
		readFile(isFile, N, M);
	}
	if (isFile == false) {
		while ((N > 101 || N < 5) || (M > 101 || M < 5)) {
			cout << "Max size is 100, min size is 5, write again\n";
			cin >> N >> M;
		}
	}
	


	// jesli wpisac np 0x0 sprawdzać czy jest plik log.log/world.log
	// jesli jest, to wczytac plik, inaczej poprosic rozmiar world

	World game(N, M, isFile);

	while(!game.getIsEnd()){
		game.takeATurn();
	}
}