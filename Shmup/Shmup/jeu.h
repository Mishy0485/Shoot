#pragma once
#ifndef JEU_H
#define JEU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "projectile.h"
#include "ennemi.h"
#include "avion.h"
#include "editeur.h"

using namespace std;
using namespace sf;

class Jeu 
{
private:
	bool game_over = false;
	bool bonus_screen_bool = false;

public:

	int score = 0;

	Text congrats;

	Texture powerup1_t;
	Texture powerup2_t;
	Texture powerup3_t;

	CircleShape powerup1;
	CircleShape powerup2;
	CircleShape powerup3;

	RectangleShape end;

	Font police;

	Text score_aff;

	Text vague;

	Text boss;

	vector<Ennemi*>& getEnnemis();
	
	void score_maj();

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
	vector<Ennemi*> ennemis;
	void spawnEnnemi(int n, int type);
	void manage_vague();
	void createLevel(int tab[6]);

	void bonus_screen(int i, RenderWindow& window, Plane& joueur);
	bool isInCollisionPlane(Plane joueur, Projectile* currentBulleta);
	bool isInCollisionEnnemi(Ennemi* ennemi, Projectile* currentBulleta);
	void collisionEnnemi(Ennemi* ennemi, Projectile* currentBulleta);
	bool bottom(Projectile* currentBulleta);
	void collisionPlane(Plane& joueur, Projectile* currentBulleta);

	void capaSpeBoss2(int x, int y, Ennemi* ennemi);

};

#endif