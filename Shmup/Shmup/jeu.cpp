#include "jeu.h"
using namespace sf;
using namespace std;

void Jeu::spawnEnnemi(int n) {
	for (int i = 0; i < n; i++) {
		int coordx = rand() % 1900;
		ennemis.push_back(new Ennemi(coordx, 200, 1, 100));
	}
}
