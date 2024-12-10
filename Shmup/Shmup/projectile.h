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
	bool hit = false;
	bool playerSide;
public:

	Texture bullet;
	Sprite getSprite();

	int getPositionX();
	int getPositionY();

	Projectile(int x, int y, int v, int t, bool s);

	bool isOutOfScreen();

	bool getSide();

	void setSide(bool b);

	bool getHitValue();

	void setHitValue(bool b);

	void fuse(bool up);

	void separation(vector<Projectile*>& bulleta, Projectile bullet);
};

#endif
