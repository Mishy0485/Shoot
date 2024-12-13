#pragma once
#ifndef JEU_H
#define JEU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "projectile.h"
#include "ennemi.h"
#include "avion.h"
#include "vecteurEnnemi.h"

using namespace std;
using namespace sf;

class Jeu 
{
private:
	bool game_over = false;
	bool bonus_screen_bool = false;

public:
	RectangleShape powerup1;
	RectangleShape powerup2;
	
	RectangleShape powerup3;

	RectangleShape end;

	Font police;

	Text vague;

	Text boss;
	
	int nb_vagues = 0;
	int bossTime;

	void incrVague();
	void bossT();

	void enTeteVague();
	void enTeteBoss();


	void setGameOver(bool b);
	bool getGameOver();

	void setBonusScreen(bool b);
	bool getBonusScreen();

	vector<Projectile*> bulleta;
	void spawnEnnemi(int n, int type);

	void bonus_screen(int i, RenderWindow& window, Plane joueur);
	bool isInCollisionPlane(Plane joueur, Projectile* currentBulleta);
	bool isInCollisionEnnemi(Ennemi* ennemi, Projectile* currentBulleta);
	void collisionEnnemi(Ennemi* ennemi, Projectile* currentBulleta);
	bool bottom(Projectile* currentBulleta);
	void collisionPlane(Plane& joueur, Projectile* currentBulleta);

};

#endif