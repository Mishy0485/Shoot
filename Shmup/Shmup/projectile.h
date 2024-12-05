#pragma once
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Projectile {
protected:
	int x, y;
	int vitesse;
	int type;
	Sprite Bullety;

public:

	Texture bullet;

	Projectile(int x, int y, int v, int t);

	bool isInCollision(Sprite& sprite1);
	bool isInCollision();

};

#endif
