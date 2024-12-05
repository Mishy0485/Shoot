#pragma once
#ifndef JEU_H
#define JEU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

#include "projectile.h"
#include "ennemi.h"

using namespace std;
using namespace sf;


class Jeu {
	

public:
	vector<Projectile*> projectiles;
	vector<Ennemi*> ennemis;
	void spawnEnnemi(int n);

};

#endif