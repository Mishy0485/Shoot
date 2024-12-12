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
	Sprite bombeRetard;
	Sprite bigBombe;

public:
	Texture boom;
	Texture capsmpl2;
	Texture capspe2;

	Bombe(int x, int y, int t, int v);

	void collisionRetard(Plane joueur);
	bool collisionOver();

};

#endif
