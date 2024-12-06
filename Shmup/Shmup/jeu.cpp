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

bool Jeu::isInCollisionPlane(Plane joueur, Projectile* currentBulleta)
{
	if (currentBulleta->getSprite().getGlobalBounds().intersects(joueur.getSprite().getGlobalBounds()))
	{
		return true;
	}
	return false;
}

bool Jeu::isInCollisionEnnemi(Ennemi* ennemi, Projectile* currentBulleta) {

	return currentBulleta->getSprite().getGlobalBounds().intersects(ennemi->getsprite().getGlobalBounds());

}

bool Jeu::bottom(Projectile* currentBulleta)
{
	if (currentBulleta->getSprite().getPosition().y > 1079)
	{
		return true;
	}
	return false;
}
void Jeu::collisionPlane(Plane joueur, Projectile* currentBulleta)
{
	if (isInCollisionPlane( joueur, currentBulleta))
	{
		// perde de la vie 
		joueur.setVie(-34);

			// ou meurt
		if (joueur.getVie() < 1)
		{
			// game over 
		}

		// bullet meurt
		delete(currentBulleta);
	}
}

void Jeu::collisionEnnemi(Ennemi* ennemi, Projectile* currentBulleta) {
	if (isInCollisionEnnemi(ennemi, currentBulleta) && currentBulleta->getHitValue() == false) {
		ennemi->degats(50);
		currentBulleta->setHitValue(true);
	}
}