#include "jeu.h"
using namespace sf;
using namespace std;

void Jeu::spawnEnnemi(int n) {
	for (int i = 0; i < n; i++) {
		int coordx = rand() % 1900;
		int coordy = rand() % (100, 300);
		ennemis.push_back(new Ennemi(coordx, coordy, 1, 100));
	}
}
