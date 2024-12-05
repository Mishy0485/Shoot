#pragma once
#ifndef JEU_H
#define JEU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "projectile.h"
#include "ennemi.h"
#include "avion.h"

using namespace std;
using namespace sf;



class Jeu 
{
public:

	vector<Ennemi*> ennemis;

	void spawnEnnemi(int n);

	bool isInCollision(Plane joueur, Projectile* currentBulleta);
	bool bottom(Projectile* currentBulleta);
	void collision(Plane joueur, Projectile* currentBulleta);
};

#endif