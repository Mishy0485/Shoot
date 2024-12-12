#include "jeu.h"
#include "baseEnnemi.h"
#include "boss1.h"
#include "boss2.h"

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
	vague.setString(" Vague " + to_string((nb_vagues)));
	vague.setFont(police);
	vague.setCharacterSize(50);
	vague.setFillColor(Color(150, 150, 150));
	vague.setOutlineColor(Color(0, 0, 0));
	vague.setOutlineThickness(10);
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

void Jeu::spawnEnnemi(int n, int type) {
	for (int i = 0; i < n; i++) {
		int coordx, coordy;
		bool spawnPossible = false;

		while (!spawnPossible) {
			coordx = rand() % 1900;
			coordy = rand() % (400 - 100 + 1);

			bool tooClose = false;
			for (int i = 0; i < ennemis.size(); i++) {
				float dx = coordx - ennemis[i]->getX();
				float dy = coordy - ennemis[i]->getY();
				float distance = sqrt(dx * dx + dy * dy);

				if (distance < 300) {
					tooClose = true;
					break;
				}
			}

			if (!tooClose) {
				spawnPossible = true;
			}
		}
		switch (type)
		{
			case 0:ennemis.push_back(new BaseEnnemi(coordx, coordy, 100)); break;
			case 1: cout << "A FAIRE"; break;
			case 2: cout << "A FAIRE"; break;
			case 3:ennemis.push_back(new Boss1(coordx, coordy, 5000)); break;
			//case 4:ennemis.push_back(new Boss2(coordx, coordy, 100)); break;
		}
		
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

	return currentBulleta->getSprite().getGlobalBounds().intersects(ennemi->getSprite().getGlobalBounds());

}

bool Jeu::bottom(Projectile* currentBulleta)
{
	if (currentBulleta->getSprite().getPosition().y > 1079)
	{
		return true;
	}
	return false;
}
void Jeu::collisionPlane(Plane& joueur, Projectile* currentBulleta)
{
	if (isInCollisionPlane(joueur, currentBulleta))
	{
		joueur.degat(34);
		currentBulleta->setHitValue(true);
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
		ennemi->textureChange();
	}
}