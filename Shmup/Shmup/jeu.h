#pragma once
#ifndef JEU_H
#define JEU_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

#include "projectile.h"
class Ennemi;

class Jeu {
private:
	vector<Projectile*> projectiles;
	vector<Ennemi*> ennemis;
};

#endif