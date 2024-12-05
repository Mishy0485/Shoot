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

bool Jeu::isInCollision(Plane joueur, Projectile* currentBulleta)
{
	if (currentBulleta->getSprite().getGlobalBounds().intersects(joueur.getSprite().getGlobalBounds()))
	{
		return true;
	}
	return false;
}

bool Jeu::bottom(Projectile* currentBulleta)
{
	if (currentBulleta->getSprite().getPosition().y > 1079)
	{
		return true;
	}
	return false;
}
void Jeu::collision(Plane joueur, Projectile* currentBulleta)
{
	if (isInCollision( joueur, currentBulleta))
	{
		// perde de la vie 


			// ou meurt
		if (joueur.getVie() < 1)
		{
			// game over 
		}

		// bullet meurt
		delete(currentBulleta);
	}

	else if (bottom(currentBulleta))
	{
		// bullet meurt 
		delete(currentBulleta);
	}
}