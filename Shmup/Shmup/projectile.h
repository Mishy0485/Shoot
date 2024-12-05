#pragma once
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Projectile {
private:
	int x, y;
	int vitesse;
	int type;
public:

	Projectile(int x, int y, int v, int t);

};

#endif
