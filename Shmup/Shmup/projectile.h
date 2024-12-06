#pragma once
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
using namespace sf;
#include<vector>
using namespace std;

class Projectile 
{
protected:
	int x, y;
	int vitesse;
	int type;
	Sprite Bullety;
	

public:

	Texture bullet;

	Projectile(int x, int y, int v, int t);

	bool isOutOfScreen();

	Sprite getSprite();

	void fuse(bool up);
};

#endif
