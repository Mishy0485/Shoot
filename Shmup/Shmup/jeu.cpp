#include "jeu.h"
#include "baseEnnemi.h"
#include "boss1.h"
#include "avancedEnnemi.h"
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
			boss.setString(" G�n�ral Butor ");
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

void Jeu::setGameOver(bool b){
	game_over = b; 
}

bool Jeu::getGameOver() {
	return game_over;
}

void Jeu::setBonusScreen(bool b) {
	bonus_screen_bool = b;
}

bool Jeu::getBonusScreen() {
	return bonus_screen_bool;
}

void Jeu::spawnEnnemi(int n, int type) {
	for (int i = 0; i < n; i++) {
		int coordx, coordy, speed;
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
			case 0: ennemis.push_back(new BaseEnnemi(coordx, coordy, 100, type, 1)); break;
			case 1: ennemis.push_back(new AdvancedEnnemi(coordx, coordy, 200, type, 1)); break;
			case 2: cout << "A FAIRE"; break;
			case 3: ennemis.push_back(new Boss1(coordx, 100, 50, type, 1)); break;
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
		joueur.setVie(-34);
		currentBulleta->setHitValue(true);
	}
}

void Jeu::collisionEnnemi(Ennemi* ennemi, Projectile* currentBulleta) {
	if (isInCollisionEnnemi(ennemi, currentBulleta) && currentBulleta->getHitValue() == false && currentBulleta->getSide()) {
		ennemi->degats(50);
		currentBulleta->setHitValue(true);
		ennemi->textureChange();
	}
}

void Jeu::bonus_screen(int i, RenderWindow& window, Plane& joueur) {

	powerup1_t.loadFromFile("powerup1.png");
	powerup2_t.loadFromFile("powerup2.png");
	powerup3_t.loadFromFile("powerup3.png");
	powerup1.setRadius(130);
	powerup1.setOrigin(65, 65);
	powerup1.setPosition(300, 500);
	powerup1.setTexture(&powerup1_t);
	
	powerup2.setRadius(130);
	powerup2.setOrigin(65, 65);
	powerup2.setPosition(900, 500);
	powerup2.setTexture(&powerup2_t);
	
	powerup3.setOrigin(65, 65);
	powerup3.setRadius(130);
	powerup3.setPosition(1500, 500);
	powerup3.setTexture(&powerup3_t);

	if (Mouse::isButtonPressed(Mouse::Left)) {
		if (powerup1.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
			joueur.setTir(1);
			joueur.setVie(joueur.getMaxVie()-joueur.getVie());
			bonus_screen_bool = false;
		}
		if (powerup2.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
			joueur.setMaxVie(50);
			joueur.setVie(joueur.getMaxVie() - joueur.getVie());
			bonus_screen_bool = false;
		}
		if (powerup3.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
			joueur.setVitesse(3);
			joueur.setVie(joueur.getMaxVie() - joueur.getVie());
			bonus_screen_bool = false;
		}

	}
}