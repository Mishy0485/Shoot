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
	bool droite;
	bool separated = false;
public:

	Texture bullet;
	Sprite getSprite();

	int getPositionX();
	int getPositionY();

	int setPositionX(int n);
	int setPositionY(int n);

	bool getSepState();
	void setSepState();

	Projectile(int x, int y, int v, int t, bool s);

	bool isOutOfScreen();

	bool getSide();

	int getType();

	void setSide(bool b);

	bool getHitValue();

	void setHitValue(bool b);

	void fuse(bool up);

	void fuse1(bool up);

	void deplacementLaser();

	void separation(vector<Projectile*>& bulleta, Projectile bullet);
};

#endif
