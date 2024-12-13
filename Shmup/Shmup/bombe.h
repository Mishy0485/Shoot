#pragma once
#ifndef BOMBE_H
#define BOMBE_H

#include <SFML/Graphics.hpp>
#include "ennemi.h"
#include"avion.h"

using namespace sf;

class Bombe
{
protected:
	int x, y;
	int taille;
	int vie;
	Sprite explosion;
	vector<Bombe*> &bombe;

public:
	Texture boom;

	Clock clockinette;

	int timeBomb;

	Bombe(int x, int y, int t, int v);

	void setBombe(vector<Bombe*>& bombeRetard);
	void setExplosion(CircleShape bombeRetard);

	void collisionRetard(Plane joueur);
	bool collisionOver(Plane joueur);

};

#endif
