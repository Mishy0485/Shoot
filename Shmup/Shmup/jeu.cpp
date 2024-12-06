#include "jeu.h"
using namespace sf;
using namespace std;

bool Jeu::setBool() const { return true; }

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
		joueur.setVie(-34);

			// ou meurt
		if (joueur.getVie() < 1)
		{
			Jeu::setBool();

			Texture fin;
			fin.loadFromFile("game_over_final.png");
			Sprite end;
			end.setTexture(fin);

			RectangleShape end(Vector2f(442.f, 55.f));
			end.setPosition(Vector2f(739.f, 512.5f));
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