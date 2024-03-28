#include "World.h"
#include <iostream>
using namespace std;

// posortować zwierząt względem inicjatywy (od min do max)

World::World(const short& N, const short& M) :N(N), M(M) {
	wek.resize(N, vector<Organism*>(M, nullptr));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (j % 2 == 0) {
				wek[i][j] = new Plant("nic","kwiat", j * 2 + 1, i * 2 + 2, 0, j, i);
				plants.push_back(wek[i][j]); // robię vector wskaźników na rośliny
			}
			else {
				wek[i][j] = new Animal("nic", "animal", j * 2 + 1, i * 2 + 2, 0, j, i);
				animals.push_back(wek[i][j]); // robię vector wskaźników na zwierzęta
			}
		}
	}

}

void World::drawWorld() {
	cout << "Author: Nikolai Lavrinov 201302\n";
}