#include "jeu.h"

using namespace sf;
using namespace std;

// Vagues

void Jeu::incrVague()
{
	Jeu::nb_vagues++;
}
void Jeu::bossT()
{
	Jeu::bossTime++;
}

void Jeu::enTeteVague()
{
	vague.setString(" Vague " + (nb_vagues));
	vague.setFont(police);
	vague.setCharacterSize(50);
	vague.setFillColor(Color(211, 211, 211));
}

void Jeu::enTeteBoss()
{
	switch (bossTime)
	{
		case 0:
		{
			boss.setString(" Colonel Zgorblux ");
			boss.setFont(police);
			boss.setCharacterSize(50);
			boss.setFillColor(Color(211, 211, 211));
			bossTime++;
				break;
		}
		case 1:
		{
			boss.setString(" Général Butor ");
			boss.setFont(police);
			boss.setCharacterSize(50);
			boss.setFillColor(Color(211, 211, 211));
			bossTime++;
				break;
		}
		case2:
		{
			boss.setString(" Roi Novax ");
			boss.setFont(police);
			boss.setCharacterSize(50);
			boss.setFillColor(Color(211, 211, 211));
				break;
		}
		default:
			break;
	}
}



void Jeu::setBool(bool b){
	game_over = b; 
}

bool Jeu::getBool() {
	return game_over;
}

void Jeu::spawnEnnemi(int n) {
	for (int i = 0; i < n; i++) {
		int coordx = rand() % 1900;
		int coordy = rand() % (100, 300);
		ennemis.push_back(new Ennemi(coordx, coordy, 1, 100));
	}
}

bool Jeu::isInCollisionPlane(Plane joueur, Projectile* currentBulleta)
{
	if (currentBulleta->getSprite().getGlobalBounds().intersects(joueur.getSprite().getGlobalBounds()) && !currentBulleta->getSide())
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
		currentBulleta->setHitValue(true);
			// ou meurt
		if (joueur.getVie() < 1)
		{
			Jeu::setBool(true);

		}
	}
}

void Jeu::collisionEnnemi(Ennemi* ennemi, Projectile* currentBulleta) {
	if (isInCollisionEnnemi(ennemi, currentBulleta) && currentBulleta->getHitValue() == false && currentBulleta->getSide()) {
		ennemi->degats(50);
		currentBulleta->setHitValue(true);
	}
}