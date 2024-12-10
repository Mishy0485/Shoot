#pragma once
#ifndef JEU_H
#define JEU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "projectile.h"
#include "ennemi.h"
#include "avion.h"

using namespace std;
using namespace sf;



class Jeu 
{
private:
	bool game_over = false;

public:
	RectangleShape end;

	Font police;

	Text vague;

	Text boss;
	
	int nb_vagues = 1;
	int bossTime;

	void incrVague();
	void bossT();

	void enTeteVague();
	void enTeteBoss();

	void setBool(bool b);
	bool getBool();
	vector<Ennemi*> ennemis;
	vector<Projectile*> bulleta;
	void spawnEnnemi(int n, int type);

	bool isInCollisionPlane(Plane joueur, Projectile* currentBulleta);
	bool isInCollisionEnnemi(Ennemi* ennemi, Projectile* currentBulleta);
	void collisionEnnemi(Ennemi* ennemi, Projectile* currentBulleta);
	bool bottom(Projectile* currentBulleta);
	void collisionPlane(Plane& joueur, Projectile* currentBulleta);
};

#endif