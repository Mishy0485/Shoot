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
	
	vector<Projectile*> bulleta;

public:

	Texture bullet;

	Projectile(int x, int y, int v, int t);

	void tir(Sprite& sprite2, Projectile* currentBulleta);

	Sprite getSprite();
};

#endif
