#pragma once
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include<vector>
#include <SFML/Graphics.hpp>
using namespace sf;

class Projectile {
protected:
	int x, y;
	int vitesse;
	int type;
	Sprite Bullety;

	vector<Projectile*> bulleta;

public:

	Texture bullet;

	Projectile(int x, int y, int v, int t);

	bool isInCollision(Sprite& sprite1);
	bool isInCollision1();
	void tir(Sprite& sprite2);

};

#endif
